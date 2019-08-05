#pragma once

#pragma once

#include <float.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <math.h>
#include "vfunctional.h"
#include "geometry.h"
#include "die-specification.h"
//#include "rotate.h"
//#include "sample-point.h"
#include "ocr.h"
#include "decode-die.h"
#include "find-undoverlines.h"
#include "value-clusters.h"



struct DieRead {
	Undoverline underline = { cv::Point2f({0,0}), cv::Point2f({0, 0}) };
	Undoverline overline = { cv::Point2f({0,0}), cv::Point2f({0, 0}) };
	cv::Point2f center = cv::Point2f{ 0, 0 };
	float inferredAngleInRadians = 0;
	cv::Point2f angleAdjustedCenter{ 0, 0 };
	ReadCharacterResult ocrLetter = { 0, 0 };
	ReadCharacterResult ocrDigit = { 0, 0 };
	unsigned char orientationAs0to3ClockwiseTurnsFromUpright;
};

struct FindDiceResult {
	std::vector<DieRead> diceFound;
	std::vector<Undoverline> strayUndoverlines;
	float pixelsPerMm;
};

static FindDiceResult findDice(cv::Mat colorImage, cv::Mat grayscaleImage, std::vector<RectangleDetected> candidateUndoverlineRects)
{
	const auto undoverlines = findReadableUndoverlines(colorImage, grayscaleImage, candidateUndoverlineRects);

	std::vector<Undoverline> underlines(undoverlines.underlines);
	std::vector<Undoverline> overlines(undoverlines.overlines);

	std::vector<float> underlineLengths = vmap<Undoverline, float>(underlines,
		[](Undoverline underline) { return lineLength(underline.line); });
	const float medianUnderlineLength = medianInPlace(underlineLengths);
	const float pixelsPerMm = medianUnderlineLength / DieDimensionsMm::undoverlineLength;
	const float maxDistanceBetweenInferredCenters = 2 * pixelsPerMm; // 2mm

	std::vector<Undoverline> strayUndoverlines(0);
	std::vector<DieRead> diceFound;

	for (auto underline : underlines) {
		// Search for overline with inferred die center near that of underline.
		bool found = false;
		for (size_t i = 0; i < overlines.size() && !found; i++) {
			if (distance2f(underline.inferredDieCenter, overlines[i].inferredDieCenter) <= maxDistanceBetweenInferredCenters) {
				// We have a match
				found = true;
				// Re-infer the center of the die and its angle by drawing a line from
				// the center of the to the center of the overline.
				const Line lineFromUnderlineCenterToOverlineCenter = {
					pointAtCenterOfLine(underline.line), pointAtCenterOfLine(overlines[i].line)
				};
				// The center of the die is the midpoint of that line.
				const cv::Point2f center = pointAtCenterOfLine(lineFromUnderlineCenterToOverlineCenter);
				// The angle of the die is the angle of that line, plus 90 degrees clockwise
				const float angleOfLineFromUnderlineToOverlineCenterInRadians =
					angleOfLineInSignedRadians2f(lineFromUnderlineCenterToOverlineCenter);
				float angleInRadians = angleOfLineFromUnderlineToOverlineCenterInRadians +
					NinetyDegreesAsRadians;
				if (angleInRadians > (M_PI)) {
					angleInRadians -= float(2 * M_PI);
				}
				const cv::Point2f angleAdjustedCenter = rotatePointAroundOrigin(center, normalizeAngleSignedRadians(angleInRadians));
				diceFound.push_back({
					underline, overlines[i], center, angleInRadians, angleAdjustedCenter,
					// letter read (not yet set)
					{0, 0},
					// digit read (not yet set)
					{0,0},
					0
					});
				// Remove the ith element of overlines
				overlines.erase(overlines.begin() + i);
			}
		}
		if (!found) {
			strayUndoverlines.push_back(underline);
		}
	}

	strayUndoverlines.insert(strayUndoverlines.end(), overlines.begin(), overlines.end());

	return { diceFound, strayUndoverlines, pixelsPerMm };
}


static std::vector<DieRead> readDice(cv::Mat colorImage, cv::Mat grayscaleImage, std::vector<RectangleDetected> candidateUndoverlineRects)
{
	FindDiceResult findDiceResult = findDice(colorImage, grayscaleImage, candidateUndoverlineRects);
	std::vector<DieRead>& diceFound = findDiceResult.diceFound;
	const float pixelsPerMm = findDiceResult.pixelsPerMm;
	const float halfDieSize = DieDimensionsMm::size * pixelsPerMm / 2.0f;

	std::vector<float> dieAnglesInRadians = vmap<DieRead, float>(diceFound,
		[](DieRead d) -> float { return normalizeAngleSignedRadians(d.inferredAngleInRadians); });
	// Get the angle of all dice
	float angleOfDiceInRadians = findPointOnCircularSignedNumberLineClosestToCenterOfMass(
		dieAnglesInRadians, FortyFiveDegreesAsRadians);


	for (auto &die : diceFound) {
		// Average the angle of the underline and overline
		const auto charsRead = readDieCharacters(colorImage, grayscaleImage, die.center, die.inferredAngleInRadians, findDiceResult.pixelsPerMm);
		const float orientationInRadians = die.inferredAngleInRadians - angleOfDiceInRadians;
		const float orientationInClockwiseRotationsFloat = orientationInRadians * float(4.0 / (2.0 * M_PI));
		const uchar orientationInClockwiseRotationsFromUpright = uchar(round(orientationInClockwiseRotationsFloat) + 4) % 4;
		die.orientationAs0to3ClockwiseTurnsFromUpright = orientationInClockwiseRotationsFromUpright;
		die.ocrLetter = charsRead.letter;
		die.ocrDigit = charsRead.digit;
	}
	// calculate the average angle mod 90 so we can generate a rotation function
	for (size_t i = 0; i < diceFound.size(); i++) {
		diceFound[i].angleAdjustedCenter = rotatePointAroundOrigin(diceFound[i].center, angleOfDiceInRadians);
	}

	// Sort the dice based on their positions after adjusting the angle
	std::sort(diceFound.begin(), diceFound.end(), [halfDieSize](DieRead a, DieRead b) {
		if (a.angleAdjustedCenter.y < (b.angleAdjustedCenter.y - halfDieSize)) {
			// Die a is at least a half die above die b, and therefore comes before it
			return true;
		}
		else if (b.angleAdjustedCenter.y < (a.angleAdjustedCenter.y - halfDieSize)) {
			// Die b is at least a half die above die a, and therefore comes before it
			return false;
		}
		// Die a and die b are roughly the same from top to bottom, so order left to right
		return a.angleAdjustedCenter.x < b.angleAdjustedCenter.x;
	});

	// Search for missing dice
	if (diceFound.size() < 25) {
		// FIXME
		// Add function for this dirty work.
	}

	return diceFound;
}
