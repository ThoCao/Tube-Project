#include "FilterClass.h"



FilterClass::FilterClass()
{
}


FilterClass::~FilterClass()
{
}

void FilterClass::findFeatures(cv::Mat & _image){
	// find circle
	Circle big_circle, small_circle;
	bool IsFound = false;

	setGaussianValue(2);
	setEpsilonRadius(25);
	std::tie(big_circle, small_circle, IsFound) = Find2CirclesFunc(_image.clone());

	if (IsFound == true) {
		cv::Mat inner_img = getInnerMaskImage(big_circle, small_circle);
		// draw contour
		for (auto id = 0; id + 1 < big_circle.contour.size(); id++) {
			cv::line(_image, big_circle.contour[id], big_circle.contour[id + 1], { 100,250,100 }, 2);
		}
		
		for (auto id = 0; id + 1 < small_circle.contour.size(); id++) {
			cv::line(_image, small_circle.contour[id], small_circle.contour[id + 1], { 240,100,100 }, 2);
		}
		_show(_image);
		_wait(10);
	}
}
