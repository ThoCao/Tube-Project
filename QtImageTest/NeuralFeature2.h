#pragma once
#include "opencv2\opencv.hpp"
#include <iostream>
#include <fstream>
#include <ostream>
#include <PreProcessing.h>

class NeuralFeature2 : public PreProcessing
{
public:
	NeuralFeature2();
	~NeuralFeature2();
public:
	void Run1D(cv::Mat& image,const int diffRadius);
	int getNumofFeature1D(void) { return this->numOfFeature1D; };
	void resetFeature(void);
	std::vector<int> getFeatureValue(int index);
public:
	void saveFeatureToExcelFile(std::vector<int> &data,std::string fileName);
private:
	void readLookUpFeatureFile(std::string fileName);
private:
	std::vector<int> feature1D;
	std::vector<int> feature2D;
private:
	std::string lookUpTableFileName = "lookupfeature.xml";
	int numOfFeature1D = 0;
	int numOfFeature2D = 0;
	std::vector<int> lookUp1D;
	std::vector<std::vector<int>> lookUp2D;
};

