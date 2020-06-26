#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : 
	IntensityImage() 
{ }

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : 
	IntensityImage(other.getWidth(), other.getHeight()),
	pixelMap(nullptr)
{
	const int size = other.getWidth() * other.getHeight();
	
	if (size > 0) {
		pixelMap = new Intensity[size];
		for (int i = 0; i < size; i++) {
			pixelMap[i] = other.getPixel(i);
		}
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : 
	IntensityImage(width, height),
	pixelMap(nullptr)
{
	const int size = width * height;
	if (size > 0) {
		pixelMap = new Intensity[size]{};
	}
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] pixelMap;	
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	const int size = (width * height);

	if (size > 0) {
		delete[] pixelMap;
		pixelMap = new Intensity[width * height];
	}
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	const int	size = other.getWidth() * other.getHeight();

	if (size > 0) {
		delete[] pixelMap;
		pixelMap = new Intensity[size];
		for (int i = 0; i < size; i++) {
			pixelMap[i] = other.getPixel(i);
		}
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixelMap[y * getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	pixelMap[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return pixelMap[y * getWidth() + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return pixelMap[i];
}

