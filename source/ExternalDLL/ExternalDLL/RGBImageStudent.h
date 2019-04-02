/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include <vector>
#include "RGBImage.h"


struct RGB_student {

	RGB_student(uint_fast8_t r = 0, uint_fast8_t g = 0, uint_fast8_t b = 0)
		:r(r), g(g), b(b) {
	}

	uint_fast8_t r, g, b;
};


class RGBImageStudent : public RGBImage {
private:
	RGB_student RGB ;

public:

	RGBImageStudent();
	RGBImageStudent(const RGBImageStudent &other);
	RGBImageStudent(const int width, const int height);
	~RGBImageStudent();

	void set(const int width, const int height);
	void set(const RGBImageStudent &other);

	void setPixel(int x, int y, RGB pixel);
	void setPixel(int i, RGB pixel);

	RGB getPixel(int x, int y) const;
	RGB getPixel(int i) const;
};