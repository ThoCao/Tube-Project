#include "NeuralNetWork.h"



NeuralNetWork::NeuralNetWork()
{
}


NeuralNetWork::~NeuralNetWork()
{
}

void NeuralNetWork::setLayerMatrix(vector<int> layers){
	this->layerMat = cv::Mat(layers.size(),COLUMN_LAYER, CV_32SC1);
	int idx = 0;
	for (auto p : layers) {
		if(idx == 0) this->layerMat.row(idx) = cv::Scalar(p);// + bias
		else this->layerMat.row(idx) = cv::Scalar(p);
		idx++;
	}
}

void NeuralNetWork::setNeuralNetWorkModel(void){
    this->mlp = cv::ml::ANN_MLP::create();
	// configuration layer
	this->mlp->setLayerSizes(layerMat);
	this->mlp->setTrainMethod(cv::ml::ANN_MLP::BACKPROP, 0.001);
	this->mlp->setActivationFunction(cv::ml::ANN_MLP::SIGMOID_SYM, 0, 0);
	this->mlp->setBackpropWeightScale(0.01f);
	this->mlp->setBackpropMomentumScale(0.01f);
	this->mlp->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER, 100000, 0.0001));
	
	// savename
	std::string flusName = "";
	for (auto id = 0; id < layerMat.rows; id++) {
		int val = layerMat.at<int>(id,0);
		flusName += std::to_string(val);
		flusName += "_";
	}
	this->mlp->save(nameModel + flusName);
    std::cout << this->mlp->getLayerSizes();
}

void NeuralNetWork::loadDataSet(string fileName){
	cv::FileStorage file(fileName, cv::FileStorage::READ);

	file["train_matrix"] >> trainMat;
	file["label_matrix"] >> labelMat;
	file.release();
}



void NeuralNetWork::reTrainModel(std::string modelName){
	
	loadDataSet(nameDataSet);

	if (trainMat.empty() | labelMat.empty()) return;

    loadDataSet("trainmat.xml");
	mlp = cv::ml::ANN_MLP::load(modelName);
	cv::Ptr<cv::ml::TrainData> traindata = cv::ml::TrainData::create(trainMat, cv::ml::ROW_SAMPLE,labelMat);
	this->mlp->train(traindata);


	this->mlp->save(nameModel);
}

void NeuralNetWork::loadModel(std::string modelName){

    this->mlp = cv::ml::ANN_MLP::load(modelName);
	std::cout << this->mlp->getLayerSizes();
}

cv::Mat NeuralNetWork::predictClasses(cv::Mat & data){

	cv::Mat response;
	// predict
	this->mlp->predict(data, response);
	return response;
}
