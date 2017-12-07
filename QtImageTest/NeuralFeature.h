#pragma once
#include "opencv2\opencv.hpp"
#include <iostream>
#include "PreProcessing.h"

#define NUM_ROWS(image) image.rows
#define NUM_COLS(image) image.cols
#define MAXENTROPY 30

class NeuralFeature
{
public:
	NeuralFeature();
	~NeuralFeature();
private:
	std::string name = "neural.xml";
private:
	double max_area = 0;
	int    max_numberofcontour = 0;
	double max_area2 = 0;
	int    max_numberofcontour2 = 0;
	double max_smoothtly_distribution = 0;
	
public:
	double getRatioWhitePixel(const cv::Mat& Image,const cv::Mat& maskImage);
	double getTotalArea(const cv::Mat& data);
	int    getTotalNumberofContour(const cv::Mat& data);
	double getEntropy(const cv::Mat& data,const cv::Point& pcenter);
private:
	Contours find_contours(cv::Mat& input);
public:
	void setMaxArea(double val);
	void setMaxNums(int val);
	void setMaxArea2(double val);
	void setMaxNums2(int val);
	void setMaxSmootht(double val);
public:
	double getMaxArea(void);
	int    getMaxNums(void);
	double getMaxArea2(void);
	int    getMaxNums2(void);
	double getMaxSmootht(void);

	void save();
	void load();
};

