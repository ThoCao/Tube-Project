#pragma once
#include <opencv2\opencv.hpp>
#include <opencv2\ml.hpp>

class NeuralNet
{
public:
	NeuralNet();
	~NeuralNet();
private:
	std::string namemodel_ = "myFirstModel";
	cv::Mat trainningmat_;
	cv::Mat labelmat_;
	cv::Ptr<cv::ml::ANN_MLP> m_mlp_;
public:
	void LoadDateSet(std::string  fileName);
	void TrainingModel(void);
	void ReTrainModel(void);
	void LoadingModel(void);
	cv::Mat PredictData(cv::Mat & input);
};

