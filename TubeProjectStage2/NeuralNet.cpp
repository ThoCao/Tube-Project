#include "NeuralNet.h"



NeuralNet::NeuralNet()
{
}


NeuralNet::~NeuralNet()
{
}

void NeuralNet::LoadDateSet(std::string  fileName){
	cv::FileStorage file(fileName, cv::FileStorage::READ);

	file["train_matrix"] >> trainningmat_;
	file["label_matrix"] >> labelmat_;

	file.release();
}

void NeuralNet::TrainingModel(void){
	// change the type of
	cv::Mat layers = cv::Mat(4, 1, CV_32SC1);
	layers.row(0) = cv::Scalar(trainningmat_.cols);
	layers.row(1) = cv::Scalar(20);
	layers.row(2) = cv::Scalar(10);
	layers.row(3) = cv::Scalar(labelmat_.cols);

	// generate network
	cv::Ptr<cv::ml::ANN_MLP> mlp = cv::ml::ANN_MLP::create();
	// configurate layer
	mlp->setLayerSizes(layers);
	mlp->setTrainMethod(cv::ml::ANN_MLP::BACKPROP, 0.001);
	mlp->setActivationFunction(cv::ml::ANN_MLP::SIGMOID_SYM, 0, 0);
	mlp->setBackpropWeightScale(0.01f);
	mlp->setBackpropMomentumScale(0.01f);
	mlp->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER, 100000, 0.0001));
	cv::Ptr<cv::ml::TrainData> traindata = cv::ml::TrainData::create(trainningmat_, cv::ml::ROW_SAMPLE, labelmat_);

	mlp->train(traindata);

	mlp->save("myFirstModel");

}

void NeuralNet::ReTrainModel(void){
	LoadDateSet("trainmat.xml");
	m_mlp_ = cv::ml::ANN_MLP::load(namemodel_);
	cv::Ptr<cv::ml::TrainData> traindata = cv::ml::TrainData::create(trainningmat_, cv::ml::ROW_SAMPLE, labelmat_);
	m_mlp_->train(traindata);
	m_mlp_->save("MyFirstModel");
}

void NeuralNet::LoadingModel(void){
	m_mlp_ = cv::ml::ANN_MLP::load(namemodel_);
	std::cout << m_mlp_->getLayerSizes();
}

cv::Mat NeuralNet::PredictData(cv::Mat & input)
{
	cv::Mat response;
	// predict
	m_mlp_->predict(input, response);
	return response;
}
