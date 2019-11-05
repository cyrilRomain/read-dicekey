//  © 2019 Stuart Edward Schechter (Github: @uppajung)

#pragma once

#include <cassert>
#include <type_traits>
#include <vector>
#include "face.h"

const int NumberOfFaces = 25;

inline const std::vector<unsigned char> getRotationIndexesFor5x5Square(int clockwiseTurns) {
  const std::vector<std::vector<unsigned char>> rotationIndexes = {
    {
      0,  1,  2,  3,  4,
      5,  6,  7,  8,  9,
      10, 11, 12, 13, 14,
      15, 16, 17, 18, 19,
      20, 21, 22, 23, 24
    },
    {
      20, 15, 10,  5,  0,
      21, 16, 11,  6,  1,
      22, 17, 12,  7,  2,
      23, 18, 13,  8,  3,
      24, 19, 14,  9,  4
    },
    {
      24, 23, 22, 21, 20,
      19, 18, 17, 16, 15,
      14, 13, 12, 11, 10,
        9,  8,  7,  6,  5,
        4,  3,  2,  1,  0
    },
    {
      4,  9, 14, 19, 24,
      3,  8, 13, 18, 23,
      2,  7, 12, 17, 22,
      1,  6, 11, 16, 21,
      0,  5, 10, 15, 20,
    }
  };
  return rotationIndexes[clockwiseTurnsToRange0To3(clockwiseTurns)];
}

inline std::string rotateHumanReadableForm(const std::string humanReadableForm, int clockwiseTurns) {
  assert((humanReadableForm.length() % NumberOfFaces) == 0);
  unsigned charsPerFace = (unsigned) (humanReadableForm.length() / (size_t) NumberOfFaces);
  assert (charsPerFace >= 2 && charsPerFace <= 3);
  const std::vector<unsigned char> &indexToMoveFaceFrom = getRotationIndexesFor5x5Square(clockwiseTurns);
  std::string rotatedHumanReadableForm = "";
  for (size_t i = 0; i < NumberOfFaces; i++) {
    std::string faceString = humanReadableForm.substr( ((unsigned)indexToMoveFaceFrom[i]) * charsPerFace, charsPerFace);
    if (faceString.length() == 3) {
      faceString[2] = rotateOrientationAsLowercaseLetterTRBL(faceString[2], clockwiseTurns);
    }
    rotatedHumanReadableForm += faceString;
  }
  return rotatedHumanReadableForm;
};

template<typename F, typename std::enable_if<std::is_base_of<Rotateable<F>, F>::value>::type* = nullptr>
inline const std::vector<F> rotateKeySqrFaces(const std::vector<F> &faces, int clockwiseTurns) {
  assert(faces.size() == NumberOfFaces);
  const unsigned clockwiseTurns0to3 = clockwiseTurnsToRange0To3(clockwiseTurns);
  const std::vector<unsigned char> &indexToMoveFaceFrom = getRotationIndexesFor5x5Square(clockwiseTurns0to3);
  std::vector<F> rotatedFaces;
  for (size_t i = 0; i < NumberOfFaces; i++) {
    rotatedFaces.push_back(faces[indexToMoveFaceFrom[i]].rotate(clockwiseTurns0to3));
  }
  return rotatedFaces;
};

template<typename F, typename std::enable_if<std::is_base_of<Face, F>::value>::type* = nullptr>
inline const std::string facesToHumanReadableForm(const std::vector<F> &faces, bool includeFaceOrientations) {
  assert(faces.size() == NumberOfFaces);
  std::string humanReadableForm = "";
  for (const F &face : faces) {
    humanReadableForm += face.toHumanReadableForm(includeFaceOrientations);
  }
  return humanReadableForm;
}

inline const int rotationsToCanonicalForm(std::string humanReadableForm) {
  std::string humanReadableFormFirstInSortOrder = humanReadableForm;
  int clockwiseTurnsToHumanReadableFormFirstInSortOrder = 0;
  for (int clockwise90DegreeTurns = 1; clockwise90DegreeTurns < 4; clockwise90DegreeTurns++) {
    std::string rotatedHumanReadableForm = rotateHumanReadableForm(humanReadableForm, clockwise90DegreeTurns);
    if (rotatedHumanReadableForm < humanReadableFormFirstInSortOrder) {
      humanReadableFormFirstInSortOrder = rotatedHumanReadableForm;
      clockwiseTurnsToHumanReadableFormFirstInSortOrder = clockwise90DegreeTurns;
    }
  }
  return clockwiseTurnsToHumanReadableFormFirstInSortOrder;
}

template<typename F, typename std::enable_if<std::is_base_of<Rotateable<F>, F>::value>::type* = nullptr>
inline const std::vector<F> toCanonicalOrientation(const std::vector<F> &faces)
{
  return rotateKeySqrFaces<F>(
    faces,
    rotationsToCanonicalForm(facesToHumanReadableForm(faces, true))
  );
}


 /*
 * This class represents a KeySqr that has been read by scanning one or more images.
 */
template<typename F, typename std::enable_if<std::is_base_of<Rotateable<F>, F>::value>::type* = nullptr>
class KeySqr {
  public:
    // const
    std::vector<F> faces;

    KeySqr() {
    }

    KeySqr(const F &copyFrom) {
      faces = copyFrom.faces;
    }

    KeySqr(const std::vector<F> _faces) : faces(_faces) {
      if (_faces.size() != NumberOfFaces) {
	    	throw std::string("A KeySqr must contain " + std::to_string(NumberOfFaces) + " faces but only has " + std::to_string(_faces.size()));
	    }
      // faces = _faces;
    }

    bool isInitialized() const {
      return faces.size() == NumberOfFaces;
    }

    /**
     * Return the KeySqr as a JSON array of 25 faces, or an empty array
     * if the KeySqr was not initialized
     * 
     * Each face follows the JSON format for Fs:
     *   inteface F {
     *     letter: Letter | "",
     *     digit: Digit | "",
     *     orientationAs0to3ClockwiseTurnsFromUpright: '0' | '1' | '2' | '3',
     *     error {
     *       magnitude: number,
     *       location: number
     *     }
     *   }
     * 
     */
    std::string toJson() const {
      std::string json = "[\n";
      for (int i = 0; i < NumberOfFaces; i++) {
        json += "\t" + faces[i].toJson() + "\n";
      }
      json += "]";
      return json;
    }

    /**
     * Convert a KeySqr to a human-readable format with 3 characters representing
     * each face as a letter, digit, and orientation.
     */
    std::string toHumanReadableForm(bool includeFaceOrientations) const {
      return facesToHumanReadableForm<F>(faces, includeFaceOrientations);
    }

    /**
     * Test to determine if every face in the KeySqr has a different (unique)
     * letter from all others.  If a letter were to appear twice, indicating the
     * same element (die or chip) appeared twice, we would conclude the key to be invalid.
     */
    bool areLettersUnique() const {
      std::vector<char> letters;
      for (int i = 0; i < NumberOfFaces; i++) {
        letters.push_back(faces[i].letter);
      }
      std::sort(letters.begin(), letters.end(), [](char a, char b) { return a < b; });
      for (int i = 0; i < NumberOfFaces; i++) {
        if (letters[i] != FaceLetters[i]) {
          return false;
        }
      }
      return true;
    }


  /**
   * Return a copy of this KeySqr that has been rotated by the specified
   * number of clockwise turns.
   */
  const KeySqr rotate(int clockwiseTurns) const {
    return KeySqr(rotateKeySqrFaces(faces, clockwiseTurns));
  }

  /**
   * Return a copy of this KeySqr rotated into the canonical orientation
   * where the corner with the earliest character in the alphabet is at the
   * top left of the 5x5 square.
   */
  const KeySqr rotateToCanonicalOrientation() const {
    return KeySqr(toCanonicalOrientation(faces));
  }

  bool isPotentialMatch(const KeySqr &other) const {
    int numMatchingFaces = 0;
    for (int i=0; i < NumberOfFaces; i++) {
      if (faces[i].equals(other.faces[i])) {
        numMatchingFaces++;
      } else {
        // faces don't match
        if (other.faces[i].errorSize() == 0 && faces[i].errorSize() == 0) {
          // The faces are different, but neither is supposed to be in error.
          // This means the entire grid must be different.  Either we're now
          // looking at another set of faces, the orientation rotated, or there
          // was an undetected face read error.
          return false;
        }
      }
    }
    return numMatchingFaces > 9;
  }

  /**
   * Merge an earlier-scanned KeySqr into this one if possible, so that we can
   * remove any errors that appear in the previous or current scan but appear to
   * be scanned without error in one of the two scans.
   **/
  const KeySqr<F> mergePrevious(const KeySqr<F> &previous) const {
    if (isPotentialMatch(previous)) {
      std::vector<F> newFaces;
      // There are enough matching faces in the previously-scanned KeySqr,
      // and no clear conflicts, so we can merge faces from the previous
      // KeySqr in cases where the face was scanned with fewer errors in the
      // past.
      for (int i=0; i < NumberOfFaces; i++) {
        // The face in this, the more-recent scan
        const F &face = faces[i];
        // The face from the previous scan
        const F &previousFace = previous.faces[i];

        newFaces.push_back(( 
            !previousFace.isDefined() ||
            (face.isDefined() && face.errorSize() <= previousFace.errorSize())
          ) ?
            face :
            previousFace
        );
      }
      return KeySqr<F>(newFaces);
    } else {
      // isPotentialMatch failed, so the previous scan was incompatable with the faces
      // from the current scan.  Perhaps the previous scan was at a different frame of
      // reference and the grid was rotated.
      for (int clockwiseTurns = 1; clockwiseTurns < 4; clockwiseTurns++) {
        // Since this rotation wasn't a potential match, try the 3 other potential
        // rotations and recurse a single time only if one is a match.
        // (where it will enter the above clause)
        KeySqr<F> rotatedKey = previous.rotate(clockwiseTurns);
        if (isPotentialMatch(rotatedKey)) {
          return mergePrevious(rotatedKey);
        }
      }
    }
  }
  
  /**
   * Calculate the sum of the errors over all faces.
   */
  unsigned int totalError() const
  {
    unsigned int sumOfFaceErrors = 0;
    for (const F &face: faces) {
      sumOfFaceErrors += (unsigned int) face.errorSize();
    }
    return sumOfFaceErrors;
  }

  /**
   * Find the maximum error at any individual face
   * (or return max error if two faces have the same letter, indicating
   *  on of them must have a fatal read error because all elements should be unique)
   **/
  unsigned int maxError() const
  {
    unsigned int max = 0;
    for (const F &face: faces) {
      if (face.errorSize() > max) {
        max = face.errorSize();
      }
    }
    return max;
  }

};


// template<typename F, typename std::enable_if<std::is_base_of<Face, F>::value>::type* = nullptr>
// class KeySqrA {
//   public:
//     const std::vector<F> faces[NumberOfFaces];

//     KeySqrA<F>(const std::vector<F> _faces) {
//       faces = _faces;
//     }

//     const KeySqrA<F> rotate(int clockwiseTurns) const;

//     const KeySqrA<F> rotateToCanonicalOrientation() const;

//     const std::string toHumanReadableForm(bool includeFaceOrientations) const;
// };
