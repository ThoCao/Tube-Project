#pragma once
#include "PreProcessing.h"
#include "opencv2\opencv.hpp"
#include <iostream>
#include "GuiDataSet.h"
#include <opencv2\ml.hpp>

#define THRES_SIZE 10
#define ESPECT_RATIO 0.75
#define CIRCULARITY 0.5

class FindFeature : public PreProcessing
{
public:
	FindFeature();
	~FindFeature();

	/* Module Find Feature*/

public:
	void findFeatures(cv::Mat& _image);

private:
	cv::Mat getInnerImage(cv::Mat& _image);
	void normalizefeature(std::vector<float>& _data);

private:
	float scaled_factor = 1;

	/* Module Lookup Table */

	void  loadLookUpFeature(std::string fileName);
private:
	std::string _lookUpTableFileName_ = "lookupfeature.xml";
	int _num1D_ = 0;
	std::vector<int> _table1D_;
	std::vector<float> _feature1D_;
	std::vector<int> _maxValue1D_;

	/* Module Save Data */

	/* Neural Module */
private:
	bool neuralPredict(std::vector<float> & _data);
	cv::Mat neuralChecking(cv::Mat & input);

	cv::Ptr<cv::ml::ANN_MLP> _m_mlp_;
	std::string _modelName_ = "modelNeural7_20_2_";
public:

	GuiDataSet * dataset = new GuiDataSet();
private:

};

