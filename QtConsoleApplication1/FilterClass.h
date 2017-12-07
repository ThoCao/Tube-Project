#pragma once

#include "PreProcessing.h"
#include "opencv2\opencv.hpp"


#define _scale(img) cv::resize(img,img,{1284,1024});

class FilterClass : PreProcessing
{
public:
	FilterClass();
	~FilterClass();

public:
	void findFeatures(cv::Mat& _image);
};

