#pragma once
#include <opencv2\opencv.hpp>
#include <opencv2\ml.hpp>

using namespace std;

#define COLUMN_LAYER 1

class NeuralNetWork
{
public:
	NeuralNetWork();
	~NeuralNetWork();
public:
	void setLayerMatrix(vector<int> layers);
public:
	void setNeuralNetWorkModel(void);
	void loadDataSet(string fileName);
	void reTrainModel(std::string modelName);
	void loadModel(std::string modelName);
	cv::Mat  predictClasses(cv::Mat& data);

private:
	string nameDataSet = "trainmat.xml";
	string nameModel = "modelNeural";
	cv::Mat trainMat;
	cv::Mat labelMat;
	cv::Mat layerMat;
	cv::Ptr<cv::ml::ANN_MLP> mlp;
};

