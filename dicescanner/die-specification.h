#pragma once

//////////////////////////////////////////////////////////
// DiceKeys Specification (NOT TO BE MODIFIED DIRECTLY!)
//////////////////////////////////////////////////////////
//
// This c++ header file specifies properties of DiceKeys,
// including:
//   -- The set of letters that uniquely identify each die
//   -- the set of digits (1-6) that identify the face of
//      each die
//   -- The encoding of bits into the underlines and overlines
//
// This file is generated automatically by the DiceKey
// specification generator, which is written in TypeScript.
// That program also generates:
//    -- The SVG file that renders the appearance of each die face
//    -- The TypeScript version of this specification file
//
// To change the DiceKey specification, you will need to change
// and re-run specification program in TypeSecript.
//
// To add additional definitions or help functions, create a new file
// that reads the contants you need from this file.
//
#include <string>
#include <vector>

const std::string DieLetters = "ABCDEFGHIJKLMNOPRSTUVWXYZ";
const std::string DieDigits = "123456";

const int NumberOfDotsInUndoverline = 11;
const int MinNumberOfBlackDotsInUndoverline = 4;
const int MinNumberOfWhiteDotsInUndoverline = 4;


struct DieFaceSpecification {
  char letter;
  char digit;
  unsigned char underlineCode;
  unsigned char overlineCode;
};

const DieFaceSpecification NullDieFaceSpecification = {'\0', '\0', 0, 0};

namespace DieDimensionsMm {
  const float size = float(8);
  const float fontSize = float(4.6);
  const float undoverlineLength = float(6.2);
  const float undoverlineThickness = float(1.1);
  const float overlineTop = float(0.9);
  const float undoverlineMarginAtLineStartAndEnd = float(0.35);
  const float undoverlineMarginAlongLength = float(0.3);
  const float textBaselineY = float(5.4);
  const float textRegionWidth = float(6);
  const float spaceBetweenLetterAndDigit = float(0.35);
  const float underlineTop = float(6);
  const float center = float(4);
  const float undoverlineLeftEdge = float(0.9);
  const float undoverlineFirstDotLeftEdge = float(1.25);
  const float undoverlineDotWidth = float(0.5);
  const float undoverlineDotHeight = float(0.5);
  const float centerOfUndoverlineToCenterOfDie = float(2.55);
  const float textRegionHeight = float(3.6);
  const float overlineDotTop = float(1.2);
  const float underlineDotTop = float(6.3);
};

namespace DieDimensionsFractional {
  const float size = float(1);
  const float center = float(0.5);
  const float centerOfUndoverlineToCenterOfDie = float(0.31875);
  const float undoverlineLength = float(0.775);
  const float undoverlineThickness = float(0.1375);
  const float overlineTop = float(0.1125);
  const float underlineTop = float(0.75);
  const float undoverlineMarginAtLineStartAndEnd = float(0.04375);
  const float undoverlineMarginAlongLength = float(0.0375);
  const float textBaselineY = float(0.675);
  const float textRegionHeight = float(0.45);
  const float textRegionWidth = float(0.75);
  const float fontSize = float(0.575);
  const float spaceBetweenLetterAndDigit = float(0.04375);
  const float undoverlineLeftEdge = float(0.1125);
  const float undoverlineFirstDotLeftEdge = float(0.15625);
  const float undoverlineDotWidth = float(0.0625);
  const float undoverlineDotHeight = float(0.0625);
  const float overlineDotTop = float(0.15);
  const float underlineDotTop = float(0.7875);
  const std::vector<float> dotCentersAsFractionOfUndoverline = {
    float(0.0967741935483871),
    float(0.1774193548387097),
    float(0.25806451612903225),
    float(0.33870967741935487),
    float(0.41935483870967744),
    float(0.5),
    float(0.5806451612903226),
    float(0.6612903225806451),
    float(0.7419354838709676),
    float(0.8225806451612903),
    float(0.9032258064516128),
  };
};

const DieFaceSpecification letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[150] = {
    {'A', '1', 0x7, 0xe9},
    {'A', '2', 0xb, 0xf1},
    {'A', '3', 0xd, 0xe0},
    {'A', '4', 0x16, 0xf2},
    {'A', '5', 0x1a, 0xea},
    {'A', '6', 0x1e, 0xe1},
    {'B', '1', 0x1f, 0xe6},
    {'B', '2', 0x26, 0xc3},
    {'B', '3', 0x27, 0xc4},
    {'B', '4', 0x29, 0xc6},
    {'B', '5', 0x2b, 0xdc},
    {'B', '6', 0x2c, 0xca},
    {'C', '1', 0x2d, 0xcd},
    {'C', '2', 0x2e, 0xd0},
    {'C', '3', 0x31, 0xc9},
    {'C', '4', 0x32, 0xd4},
    {'C', '5', 0x33, 0xd3},
    {'C', '6', 0x34, 0xc5},
    {'D', '1', 0x35, 0xc2},
    {'D', '2', 0x37, 0xd8},
    {'D', '3', 0x39, 0xda},
    {'D', '4', 0x3a, 0xc7},
    {'D', '5', 0x3b, 0xc0},
    {'D', '6', 0x3c, 0xd6},
    {'E', '1', 0x3d, 0xd1},
    {'E', '2', 0x3e, 0xcc},
    {'E', '3', 0x3f, 0xcb},
    {'E', '4', 0x45, 0xa6},
    {'E', '5', 0x47, 0xbc},
    {'E', '6', 0x4a, 0xa3},
    {'F', '1', 0x4b, 0xa4},
    {'F', '2', 0x4c, 0xb2},
    {'F', '3', 0x4d, 0xb5},
    {'F', '4', 0x4e, 0xa8},
    {'F', '5', 0x51, 0xb1},
    {'F', '6', 0x52, 0xac},
    {'G', '1', 0x53, 0xab},
    {'G', '2', 0x55, 0xba},
    {'G', '3', 0x56, 0xa7},
    {'G', '4', 0x57, 0xa0},
    {'G', '5', 0x58, 0xa5},
    {'G', '6', 0x59, 0xa2},
    {'H', '1', 0x5b, 0xb8},
    {'H', '2', 0x5c, 0xae},
    {'H', '3', 0x5d, 0xa9},
    {'H', '4', 0x5e, 0xb4},
    {'H', '5', 0x5f, 0xb3},
    {'H', '6', 0x62, 0x9d},
    {'I', '1', 0x63, 0x9a},
    {'I', '2', 0x64, 0x8c},
    {'I', '3', 0x65, 0x8b},
    {'I', '4', 0x66, 0x96},
    {'I', '5', 0x67, 0x91},
    {'I', '6', 0x68, 0x94},
    {'J', '1', 0x69, 0x93},
    {'J', '2', 0x6a, 0x8e},
    {'J', '3', 0x6b, 0x89},
    {'J', '4', 0x6d, 0x98},
    {'J', '5', 0x6e, 0x85},
    {'J', '6', 0x6f, 0x82},
    {'K', '1', 0x70, 0x9b},
    {'K', '2', 0x71, 0x9c},
    {'K', '3', 0x72, 0x81},
    {'K', '4', 0x73, 0x86},
    {'K', '5', 0x74, 0x90},
    {'K', '6', 0x75, 0x97},
    {'L', '1', 0x76, 0x8a},
    {'L', '2', 0x77, 0x8d},
    {'L', '3', 0x78, 0x88},
    {'L', '4', 0x79, 0x8f},
    {'L', '5', 0x7a, 0x92},
    {'L', '6', 0x7b, 0x95},
    {'M', '1', 0x7c, 0x83},
    {'M', '2', 0x7d, 0x84},
    {'M', '3', 0x7e, 0x99},
    {'M', '4', 0x85, 0x6a},
    {'M', '5', 0x87, 0x70},
    {'M', '6', 0x89, 0x72},
    {'N', '1', 0x8b, 0x68},
    {'N', '2', 0x8d, 0x79},
    {'N', '3', 0x8e, 0x64},
    {'N', '4', 0x8f, 0x63},
    {'N', '5', 0x92, 0x60},
    {'N', '6', 0x93, 0x67},
    {'O', '1', 0x94, 0x71},
    {'O', '2', 0x95, 0x76},
    {'O', '3', 0x96, 0x6b},
    {'O', '4', 0x97, 0x6c},
    {'O', '5', 0x98, 0x69},
    {'O', '6', 0x99, 0x6e},
    {'P', '1', 0x9a, 0x73},
    {'P', '2', 0x9b, 0x74},
    {'P', '3', 0x9c, 0x62},
    {'P', '4', 0x9d, 0x65},
    {'P', '5', 0x9e, 0x78},
    {'P', '6', 0xa1, 0x4c},
    {'R', '1', 0xa2, 0x51},
    {'R', '2', 0xa3, 0x56},
    {'R', '3', 0xa5, 0x47},
    {'R', '4', 0xa6, 0x5a},
    {'R', '5', 0xa7, 0x5d},
    {'R', '6', 0xa8, 0x58},
    {'S', '1', 0xaa, 0x42},
    {'S', '2', 0xab, 0x45},
    {'S', '3', 0xac, 0x53},
    {'S', '4', 0xad, 0x54},
    {'S', '5', 0xae, 0x49},
    {'S', '6', 0xaf, 0x4e},
    {'T', '1', 0xb0, 0x57},
    {'T', '2', 0xb1, 0x50},
    {'T', '3', 0xb2, 0x4d},
    {'T', '4', 0xb3, 0x4a},
    {'T', '5', 0xb4, 0x5c},
    {'T', '6', 0xb5, 0x5b},
    {'U', '1', 0xb6, 0x46},
    {'U', '2', 0xb7, 0x41},
    {'U', '3', 0xb8, 0x44},
    {'U', '4', 0xb9, 0x43},
    {'U', '5', 0xba, 0x5e},
    {'U', '6', 0xbb, 0x59},
    {'V', '1', 0xbc, 0x4f},
    {'V', '2', 0xbd, 0x48},
    {'V', '3', 0xbe, 0x55},
    {'V', '4', 0xc1, 0x34},
    {'V', '5', 0xc2, 0x29},
    {'V', '6', 0xc3, 0x2e},
    {'W', '1', 0xc4, 0x38},
    {'W', '2', 0xc6, 0x22},
    {'W', '3', 0xc7, 0x25},
    {'W', '4', 0xc9, 0x27},
    {'W', '5', 0xca, 0x3a},
    {'W', '6', 0xcb, 0x3d},
    {'X', '1', 0xcc, 0x2b},
    {'X', '2', 0xcd, 0x2c},
    {'X', '3', 0xce, 0x31},
    {'X', '4', 0xcf, 0x36},
    {'X', '5', 0xd0, 0x2f},
    {'X', '6', 0xd1, 0x28},
    {'Y', '1', 0xd2, 0x35},
    {'Y', '2', 0xd3, 0x32},
    {'Y', '3', 0xd4, 0x24},
    {'Y', '4', 0xd5, 0x23},
    {'Y', '5', 0xd6, 0x3e},
    {'Y', '6', 0xd7, 0x39},
    {'Z', '1', 0xd8, 0x3c},
    {'Z', '2', 0xd9, 0x3b},
    {'Z', '3', 0xda, 0x26},
    {'Z', '4', 0xdb, 0x21},
    {'Z', '5', 0xdc, 0x37},
    {'Z', '6', 0xdd, 0x30}
};
const DieFaceSpecification* underlineCodeToDieFaceSpecification[256] = {
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[0]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[1]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[2]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[3]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[4]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[5]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[6]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[7]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[8]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[9]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[10]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[11]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[12]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[13]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[14]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[15]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[16]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[17]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[18]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[19]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[20]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[21]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[22]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[23]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[24]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[25]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[26]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[27]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[28]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[29]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[30]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[31]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[32]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[33]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[34]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[35]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[36]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[37]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[38]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[39]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[40]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[41]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[42]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[43]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[44]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[45]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[46]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[47]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[48]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[49]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[50]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[51]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[52]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[53]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[54]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[55]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[56]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[57]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[58]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[59]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[60]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[61]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[62]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[63]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[64]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[65]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[66]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[67]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[68]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[69]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[70]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[71]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[72]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[73]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[74]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[75]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[76]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[77]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[78]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[79]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[80]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[81]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[82]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[83]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[84]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[85]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[86]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[87]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[88]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[89]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[90]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[91]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[92]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[93]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[94]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[95]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[96]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[97]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[98]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[99]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[100]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[101]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[102]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[103]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[104]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[105]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[106]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[107]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[108]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[109]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[110]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[111]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[112]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[113]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[114]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[115]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[116]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[117]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[118]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[119]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[120]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[121]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[122]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[123]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[124]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[125]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[126]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[127]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[128]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[129]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[130]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[131]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[132]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[133]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[134]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[135]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[136]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[137]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[138]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[139]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[140]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[141]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[142]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[143]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[144]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[145]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[146]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[147]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[148]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[149]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification
};

const DieFaceSpecification* overlineCodeToDieFaceSpecification[256] = {
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[147]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[127]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[141]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[140]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[128]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[146]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[129]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[137]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[124]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[132]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[133]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[125]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[136]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[149]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[134]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[139]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[123]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[138]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[135]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[148]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[126]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[143]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[130]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[145]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[144]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[131]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[142]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[115]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[102]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[117]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[116]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[103]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[114]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[98]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[121]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[106]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[111]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[95]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[110]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[107]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[120]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[109]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[96]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[104]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[105]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[122]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[97]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[108]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[101]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[119]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[99]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[113]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[112]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[100]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[118]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[82]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[92]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[81]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[80]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[93]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[83]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[78]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[88]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[75]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[86]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[87]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[89]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[76]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[84]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[77]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[90]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[91]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[85]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[94]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[79]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[62]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[59]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[72]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[73]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[58]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[63]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[68]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[56]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[66]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[50]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[49]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[67]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[55]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[69]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[64]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[52]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[70]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[54]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[53]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[71]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[51]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[65]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[57]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[74]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[48]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[60]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[61]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[47]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[39]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[41]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[29]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[30]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[40]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[27]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[38]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[33]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[44]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[36]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[35]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[43]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[34]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[31]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[46]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[45]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[32]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[42]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[37]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[28]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[22]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[18]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[7]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[8]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[17]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[9]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[21]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[14]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[11]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[26]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[25]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[12]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[13]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[24]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[16]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[15]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[23]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[19]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[20]),
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[10]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[2]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[5]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[6]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[0]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[4]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[1]),
	&(letterIndexTimesSixPlusDigitIndexToDieFaceSpecification[3]),
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification,
	&NullDieFaceSpecification
};

// Get a pointer to a DieFaceSpecification for from the eight-bit letter digit encoding
// on an underline or overline.
// This function never returns null.  Rather, if the encoding does not map to one of the 150 valid
// die faces, the result will be a pointer to the NullDieFaceSpecification. 
inline const DieFaceSpecification* decodeUndoverlineByte(bool isOverline, unsigned char letterDigitEncodingByte) {
	assert(letterDigitEncodingByte < 256);
	return isOverline ?
		overlineCodeToDieFaceSpecification[letterDigitEncodingByte] :
		underlineCodeToDieFaceSpecification[letterDigitEncodingByte];
}
