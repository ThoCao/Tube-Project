#include "GuiNeuralNetwork.h"


GuiNeuralNetwork::GuiNeuralNetwork(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	LoadingModel("modelNeural3_10_2_");
}

GuiNeuralNetwork::~GuiNeuralNetwork()
{
}

void GuiNeuralNetwork::on_btn_LoadModelNet_clicked(void){
	std::cout << "Load Model NetWork" << std::endl;
    QString fileName = QFileDialog::getOpenFileName(this, tr("TIFF (*.tif);; All files (*.*)"));
    std::string modelName = fileName.toStdString();
	this->LoadingModel(modelName);
}

void GuiNeuralNetwork::on_btn_Predict_clicked(void){

	if (_input.size() == 0) return;
	std::cout << "Predict" << std::endl;
	cv::Mat samplemat = cv::Mat(1, _input.size(), CV_32FC1);
	std::memcpy(samplemat.data, _input.data(), _input.size() * sizeof(float));
	// move data

	cv::Mat response = this->neuralChecking(samplemat);

	float failed_val = response.at<float>(0, 1);
	float passed_val = response.at<float>(0, 0);
	std::cout << response << std::endl;

	if (failed_val > 0.85 ) {
		
		ui.textEdit->setText("AbNormal");
		this->result = false;
	}
	else
	{	
		ui.textEdit->setText("Normal");
		this->result = true;
	}
}

void GuiNeuralNetwork::on_btn_allpredict_clicked(void){
	bool found_defective = preDictAllInput(_allInput);
	if (found_defective == true) {
		ui.textEdit->setText("AbNormal");
	}
	else {
		ui.textEdit->setText("Normal");
	}

}

void GuiNeuralNetwork::on_btn_newretrainnet_clicked(void){
    std::cout << "new retrain model" << std::endl;
	QString fileName = QFileDialog::getOpenFileName(this, tr("TIFF (*.tif);; All files (*.*)"));
    std::string modelName = fileName.toStdString();
	// load new data
	LoadDateSet("newtrainmat.xml");
	m_mlp_ = cv::ml::ANN_MLP::load(modelName);
	cv::Ptr<cv::ml::TrainData> traindata = cv::ml::TrainData::create(trainningmat_, cv::ml::ROW_SAMPLE, labelmat_);
	m_mlp_->train(traindata);
	m_mlp_->save(modelName);
	std::cout << "Done!" << std::endl;


	
}

void GuiNeuralNetwork::on_btn_ReTrainNet_clicked(void){
	std::cout << "retrain model" << std::endl;
	QString fileName = QFileDialog::getOpenFileName(this, tr("TIFF (*.tif);; All files (*.*)"));
    std::string modelName = fileName.toStdString();
	this->ReTrainModel(modelName);
}

void GuiNeuralNetwork::normalizeInputData(std::vector<float>& _data)
{
	float feature1 = _data[0];// approx
	float feature2 = _data[1];// area
	float feature3 = _data[2];// deviation
	 
	feature1 /= MAX_APPROX;
	if (feature1 > 1) feature1 = 1;

	feature2 /= MAX_AREA;
	if (feature2 > 1) feature2 = 1;

	feature3 /= MAX_DEVIATION;
	if (feature3 > 1) feature3 = 1;

	_data[0] = feature1;
	_data[1] = feature2;
	_data[2] = feature3;
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

void GuiNeuralNetwork::ReTrainModel(std::string modelName){
    LoadDateSet("trainmat.xml");
	m_mlp_ = cv::ml::ANN_MLP::load(modelName);
	cv::Ptr<cv::ml::TrainData> traindata = cv::ml::TrainData::create(trainningmat_, cv::ml::ROW_SAMPLE, labelmat_);
	m_mlp_->train(traindata);
	m_mlp_->save(modelName);
}

void GuiNeuralNetwork::LoadingModel(std::string modelName){
    m_mlp_ = cv::ml::ANN_MLP::load(modelName);
	std::cout << m_mlp_->getLayerSizes();
}

cv::Mat GuiNeuralNetwork::neuralChecking(cv::Mat & input)
{
	cv::Mat response;
	// predict
	m_mlp_->predict(input, response);
	return response;
}


void GuiNeuralNetwork::setImage(cv::Mat & _image){
	_image.copyTo(_image_img);
}


bool GuiNeuralNetwork::getResultFromNeural()
{
	this->on_btn_Predict_clicked();
	return this->result;
}

bool GuiNeuralNetwork::preDictAllInput(Inputs & _data){

	int cnt = 0;
	bool IsDefective = false;
	for (auto& p : _data) {
		std::cout << "number interation: " << cnt << std::endl;
		cv::Mat samplemat = cv::Mat(1, p.size(), CV_32FC1,p.data());
		std::memcpy(samplemat.data, p.data(), p.size() * sizeof(float));

		cv::Mat response = this->neuralChecking(samplemat);


		float failed_val = response.at<float>(0, 1);
		float passed_val = response.at<float>(0, 0);

		if (failed_val > 0.85 ) {
			
			IsDefective = true;
			// draw contour
			for (auto id = 0; id+1 < _allContour[cnt].size(); id++) {
				cv::line(_image_img, _allContour[cnt][id], _allContour[cnt][id + 1], { 0,255,255 }, 3);
			}
			cv::imshow("defect", _image_img);
			cv::waitKey(10);

			return IsDefective;
			
		}
		else
		{
			IsDefective = false;
		
		}
		cnt++;
	}
	return IsDefective;
}

bool GuiNeuralNetwork::getResultOnEdge(Circles & _circle_edges)
{
	bool found_defective_edge = false;

// segment vector inner and outer
	const float scaled_factor = abs(_circle_edges[0].R - _circle_edges[1].R) / 2;

	for (auto contour : _circle_edges) {
		const int max_index = contour.contour.size() / POINT_SIZE;

		for (auto index = 0; index < max_index; index++) {

			int start = index*POINT_SIZE  - POINT_SIZE/2;
			if (start < 0) start = 0;

			const int end = start + POINT_SIZE;
			const int step_size = 2;
			Contour setPoints;
			for (auto id = start; id + step_size < end; id += step_size) {
				setPoints.push_back(contour.contour[id]);
			}
			// feature
			if (setPoints.size() == FEATURE_SIZE) {
				std::vector<float> feature_;
				/* fix value */
				float epsilon = 0.9;// *cv::arcLength(setPoints, false);
				Contour approx;
				cv::approxPolyDP(setPoints, approx, epsilon,false);
				/* Area Feature */
				cv::RotatedRect rect = cv::minAreaRect(approx);

				/* Deviation Feature*/
				double sum_up = 0;
				std::vector<double> radius;
				for (auto p : setPoints) {
					double tmp = cv::norm(p - (cv::Point)contour.rect.center);
					radius.push_back(tmp);
					sum_up += tmp;
				}
				double avr_val = sum_up / radius.size();
				double error = 0;
				for (auto p : radius) {
					double tmp = (p - avr_val)*(p-avr_val);
					error += tmp;
				}

				float feature3 = std::sqrtf(error);
				
				feature_.push_back(approx.size());
				feature_.push_back(rect.size.area());
				feature_.push_back(feature3);
				// normalize
				normalizeInputData(feature_);

				/* checking by neural*/

				cv::Mat input_mat = cv::Mat(1, feature_.size(), CV_32FC1);

				std::memcpy(input_mat.data, feature_.data(), feature_.size() * sizeof(float));

				cv::Mat result_mat = this->neuralChecking(input_mat);

				float failed_val = result_mat.at<float>(0, 1);
				float passed_val = result_mat.at<float>(0, 0);


				if (failed_val > 0.62) {
					std::cout << "Passed: " << passed_val << "%" << " Failed: " << failed_val << "%" << std::endl;
					found_defective_edge = true;
					for (auto id = 0; id + 1 < setPoints.size(); id++) {
						cv::line(_image_img, setPoints[id], setPoints[id + 1], { 200,100,100 }, 3);
					}
					_show(_image_img);
					_wait(10);

				
				}

				if (found_defective_edge == true) {

					return found_defective_edge;
				}

			}
		}

	}

	return found_defective_edge;
}
