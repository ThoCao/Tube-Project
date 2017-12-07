#include "GuiNeuralNetwork.h"


GuiNeuralNetwork::GuiNeuralNetwork(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->LoadingModel();
}

GuiNeuralNetwork::~GuiNeuralNetwork()
{
}

void GuiNeuralNetwork::on_btn_LoadModelNet_clicked(void){
	std::cout << "Load Model NetWork" << std::endl;
	this->LoadingModel();
}

void GuiNeuralNetwork::on_btn_Predict_clicked(void){
	std::cout << "Predict" << std::endl;
	cv::Mat samplemat = cv::Mat::zeros(1, _input.size(), CV_32FC1);

	for (auto col = 0; col < samplemat.cols; col++) {
		samplemat.at<float>(0, col) = _input[col];
	}
	cv::Mat response = this->neuralChecking(samplemat);
	std::cout << samplemat << std::endl;
	std::cout << response << std::endl;
	if (response.at<float>(0, 0) > response.at<float>(0, 1)) {
		ui.textEdit->setText("Normal");
		this->result = true;
	}
	else
	{
		ui.textEdit->setText("AbNormal");
		this->result = false;
	}
}

void GuiNeuralNetwork::on_btn_ReTrainNet_clicked(void){
	std::cout << "retrain model" << std::endl;
	this->ReTrainModel();
}

void GuiNeuralNetwork::LoadDateSet(std::string fileName){
    cv::FileStorage file(fileName, cv::FileStorage::READ);

	file["train_matrix"] >> trainningmat_;
	file["label_matrix"] >> labelmat_;

	file.release();
}

void GuiNeuralNetwork::TrainingModel(void){
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

void GuiNeuralNetwork::ReTrainModel(void){
    LoadDateSet("trainmat.xml");
	m_mlp_ = cv::ml::ANN_MLP::load(namemodel_);
	cv::Ptr<cv::ml::TrainData> traindata = cv::ml::TrainData::create(trainningmat_, cv::ml::ROW_SAMPLE, labelmat_);
	m_mlp_->train(traindata);
	m_mlp_->save(namemodel_);
}

void GuiNeuralNetwork::LoadingModel(void){
    m_mlp_ = cv::ml::ANN_MLP::load(namemodel_);
	std::cout << m_mlp_->getLayerSizes();
}

cv::Mat GuiNeuralNetwork::neuralChecking(cv::Mat & input)
{
	cv::Mat response;
	// predict
	m_mlp_->predict(input, response);
	return response;
}

void GuiNeuralNetwork::setInput(std::vector<int>& data){
	this->_input.clear();
	for (auto p : data) {
		_input.push_back(p);
	}
}

bool GuiNeuralNetwork::getResultFromNeural()
{
	this->on_btn_Predict_clicked();
	return this->result;
}
