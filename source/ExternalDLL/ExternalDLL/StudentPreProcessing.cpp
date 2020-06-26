#include "StudentPreProcessing.h"
#include "ImageFactory.h"
#include "ImageIO.h"
#include <iostream>
#include <fstream>


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImage * TempImage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());
	int size = TempImage->getWidth() * TempImage->getHeight();

	//std::ofstream myFileOld;
	//myFileOld.open("oldIntensity.txt");

	for (int i = 0; i < size; ++i) {
		RGB TempRGBPixel = image.getPixel(i);
		unsigned int R = TempRGBPixel.r;
		unsigned int G = TempRGBPixel.g;
		unsigned int B = TempRGBPixel.b;
		unsigned char Grey = (R * 0.21) + (G * 0.72) + (B * 0.07);
		//myFileOld << i << " " << R << " " << G << " " << B << "\n";
		//myFileOld << i << " " << int(Grey) << "\n";
		Intensity NewIntensityPixel = Grey;
		TempImage->setPixel(i, NewIntensityPixel);
	}
	//myFileOld.close();

	ImageIO::saveIntensityImage(*TempImage, "child_1_student.jpg");
	
	//std::ofstream myfile;
	//myfile.open("intensity.txt");
	for (int i = 0; i < size; ++i) {
		//myfile << i << " " << int(TempImage->getPixel(i)) << "\n";
	}

	//myfile.close();


	return TempImage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}


