#pragma once
//  © 2019 Stuart Edward Schechter (Github: @uppajung)

#include <float.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

//#include <iostream>
#include "externally-generated/inconsolata-700.h"
#include "graphics/geometry.h"
#include "graphics/color.h"
#include "graphics/rotate.h"
#include "die-face-specification.h"
#include "simple-ocr.h"
#include "read-die-characters.h"

DieCharactersRead readDieCharacters(
	const cv::Mat& imageColor,
	const cv::Mat& grayscaleImage,
	cv::Point2f dieCenter,
	float angleRadians,
	float mmToPixels,
	unsigned char whiteBlackThreshold,
	std::string writeErrorUnlessThisLetterIsRead,
	std::string writeErrorUnlessThisDigitIsRead
) {
	// Rotate to remove the angle of the die
	const float degreesToRotateToRemoveAngleOfDie = radiansToDegrees(angleRadians);
	const int textHeightPixels = int(ceil(DieDimensionsMm::textRegionHeight * mmToPixels));
	// FIXME -- constant in next line is a hack
	int textWidthPixels = int(ceil(DieDimensionsMm::textRegionWidth * mmToPixels));
	// Use an even text region width so we can even split it in two at the center;
	if ((textWidthPixels % 2) == 1) {
		textWidthPixels += 1;
	}
	cv::Size textRegionSize = cv::Size(textWidthPixels, textHeightPixels);
	cv::Mat textEdges;
	const uchar valueRepresentingBlack = 255;

	const auto textImage = copyRotatedRectangle(grayscaleImage, dieCenter, degreesToRotateToRemoveAngleOfDie, textRegionSize);
	// Previously, we blurred image before thresholding.  It may make sense to do that
	// again when we get back images from real dice, so leaving this code here.
	// cv::Mat textBlurred
	// cv::medianBlur(textImage, textBlurred, 3);
	// cv::threshold(textBlurred, textEdges, whiteBlackThreshold, valueRepresentingBlack, cv::THRESH_BINARY);
	// at which point we'd remove the line below
	cv::threshold(textImage, textEdges, whiteBlackThreshold, valueRepresentingBlack, cv::THRESH_BINARY);

	// Setup a rectangle to define your region of interest
	int charWidth = int((textRegionSize.width - round(DieDimensionsMm::spaceBetweenLetterAndDigit * mmToPixels)) / 2);
	const cv::Rect letterRect(0, 0, charWidth, textRegionSize.height);
	const cv::Rect digitRect(textRegionSize.width - charWidth, 0, charWidth, textRegionSize.height);
	auto letterImage = textEdges(letterRect);
	auto digitImage = textEdges(digitRect);

	const OcrResult lettersMostLikelyFirst = readLetter(letterImage);
	const OcrResult digitsMostLikelyFirst = readDigit(digitImage);


	// FIXME -- remove after development debugging
	//cv::imwrite("temp/text-region.png", textImage);
	// //	cv::imwrite("temp/text-blurred.png", textBlurred);
	// cv::imwrite("temp/text-edges.png", textEdges);
	// cv::imwrite("temp/letter.png", letterImage);
	// cv::imwrite("temp/digit.png", digitImage);
	// cv::imwrite("temp/letter-error-map.png", ocrErrorHeatMap(Inconsolata700::letters, lettersMostLikelyFirst[0].character, letterImage));
	// cv::imwrite("temp/digit-error-map.png", ocrErrorHeatMap(Inconsolata700::letters, digitsMostLikelyFirst[0].character, digitImage));

	const char letter0 = lettersMostLikelyFirst[0].character;
	const char digit0 = digitsMostLikelyFirst[0].character;

	// FIXME -- remove after development debugging
	static int error = 1;
	if (writeErrorUnlessThisLetterIsRead.length() != 0 && writeErrorUnlessThisLetterIsRead != "--" && writeErrorUnlessThisLetterIsRead.find_first_of( letter0 ) == -1) {
		cv::imwrite(
			"out/tests/test-lib-read-dicekey/ocr-errors/error-" + std::to_string(error++) + "-read-" + writeErrorUnlessThisLetterIsRead +
			"-as-" + std::string(1, dashIfNull(letter0)) + ".png",
			letterImage);
	}
	if (writeErrorUnlessThisDigitIsRead.length() != 0 && writeErrorUnlessThisDigitIsRead != "--" && writeErrorUnlessThisDigitIsRead.find_first_of( digit0 ) == -1) {
		cv::imwrite(
			"out/tests/test-lib-read-dicekey/ocr-errors/error-" + std::to_string(error++) + "-read-" + writeErrorUnlessThisDigitIsRead +
			"-as-" + std::string(1, dashIfNull(digit0)) + ".png",
			digitImage);
	}

	return { lettersMostLikelyFirst, digitsMostLikelyFirst };
}