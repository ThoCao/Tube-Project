#include "FilterClass.h"



FilterClass::FilterClass()
{
}


FilterClass::~FilterClass()
{
}

void FilterClass::findFeatures(cv::Mat & _image){
	/* Gray image*/
	cv::Mat gray_img;
	cv::cvtColor(_image.clone(), gray_img, cv::COLOR_BGR2GRAY);
	/* Gaussian Filter */

	cv::Mat binary = preProcessingFunc(gray_img.clone());

	/* Show */
	_show(binary);
	_wait(10);
}
