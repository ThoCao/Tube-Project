#include "NeuralNets.h"



NeuralNets::NeuralNets(){
	
	loadNeuralEdgeModel(_modelEdgeName_);
	initialInnerRegion();
}


NeuralNets::~NeuralNets()
{

}

void NeuralNets::showResult_PERCENT(){
	if (PASSED_EDGE >= 1) PASSED_EDGE = 1;
	if (PASSED_EDGE <= 0) PASSED_EDGE = 0; 

	if (PASSED_INNER >= 1) PASSED_INNER = 1;
	if (PASSED_INNER <= 0) PASSED_INNER = 0;


	if (FAILED_EDGE >= 1) FAILED_EDGE = 1;
	if (FAILED_EDGE <= 0) FAILED_EDGE = 0; 

	if (FAILED_INNER >= 1) FAILED_INNER = 1;
	if (FAILED_INNER <= 0) FAILED_INNER = 0;

	std::cout << "ON EDGE-->  PASSED : FAILED: " << roundf(100 * PASSED_EDGE) << " : " << roundf(100 * FAILED_EDGE) << " %" << std::endl;
	std::cout << "IN INNER--> PASSED : FAILED: " << roundf(100 * PASSED_INNER) << " : "<< roundf(100 * FAILED_INNER) << " %" << std::endl;
}

cv::Mat NeuralNets::neuralChecking(cv::Ptr<cv::ml::ANN_MLP>& _neural, cv::Mat & input){
	
	cv::Mat response;
	// predict
	_neural->predict(input, response);
	return response;
}

void NeuralNets::loadNeuralEdgeModel(std::string modelName){
	std::cout << "Neural Edge!" << std::endl;
	_m_mlp_edge_ = cv::ml::ANN_MLP::load(modelName);
	std::cout << _m_mlp_edge_->getLayerSizes() << std::endl;
}

void NeuralNets::loadNeuralInnerModel(std::string modelName){

	std::cout << "Neural Inner!" << std::endl;
	_m_mlp_inner_ = cv::ml::ANN_MLP::load(modelName);
	std::cout << _m_mlp_inner_->getLayerSizes() << std::endl;
}

void NeuralNets::loadDataSet(std::string fileName){
	cv::FileStorage file(fileName, cv::FileStorage::READ);

	file["train_matrix"] >> _trainningmat_;
	file["label_matrix"] >> _labelmat_;

	file.release();
}

void NeuralNets::setImage(cv::Mat & img){
	img.copyTo(_defect_img_);
}

void NeuralNets::setScaledFactor(float _val){
	this->scaled_factor = _val;
}

bool NeuralNets::getResultOnEdge(Circles & _circle_edges){

	bool found_defective_edge = false;

// segment vector inner and outer
	const float scaled_factor = abs(_circle_edges[0].R - _circle_edges[1].R) / 2;

	for (auto contour : _circle_edges) {
		const int max_index = contour.contour.size() / POINT_SIZE;

		for (auto index = 0; index < max_index; index++) {

		    int start = index*POINT_SIZE - POINT_SIZE/2;
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
				normalizeInput(feature_);

				/* checking by neural*/

				cv::Mat input_mat = cv::Mat(1, feature_.size(), CV_32FC1);

				std::memcpy(input_mat.data, feature_.data(), feature_.size() * sizeof(float));

				cv::Mat result_mat = this->neuralChecking(_m_mlp_edge_,input_mat);

				float failed_val = result_mat.at<float>(0, 1);
				float passed_val = result_mat.at<float>(0, 0);

				/* GET PERCENT % */
				FAILED_EDGE = failed_val;
				PASSED_EDGE = passed_val;

				if (failed_val > 0.92) {
					std::cout << "Passed: " << passed_val << "%" << " Failed: " << failed_val << "%" << std::endl;
					found_defective_edge = true;
					for (auto id = 0; id + 1 < setPoints.size(); id++) {
						cv::line(_defect_img_, setPoints[id], setPoints[id + 1], { 100,100,250 }, 2);
					}
					_show(_defect_img_);
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

bool NeuralNets::getResultInner(cv::Mat & _image){

	if (_image.empty()) return false;
	
	Contours contours = find_countours(_image.clone());
	/* clear old data */
	for (auto &p : _feature1D_) p = 0;
	/* Find New Data */
	for (auto contour : contours) {
		if (contour.size() < THRES_SIZE) continue;

		/* Feature Lenght */
		float featureLenght = cv::arcLength(contour, false);

		featureLenght /= scaled_factor;
		featureLenght *= 100;
		roundf(featureLenght);

		if (featureLenght >= 600) featureLenght = 600;

		/* Index From LookUp Table */
		int index = this->_table1D_[featureLenght];

		/* Filter 2: CIRCULARITY */
		float Per = cv::arcLength(contour, true);
		float area = cv::contourArea(contour, false);
		float circle_ratio = 4*CV_PI*area/(Per*Per);
		if (circle_ratio > CIRCULARITY) { // draw rectangle
			continue;
		}

		if (index == 999) continue;
		this->_feature1D_[index] += 1;
	}
	normalizeInnterFeature(_feature1D_);

	/* Neural Checing Inner */
	cv::Mat input_mat = cv::Mat(1, _feature1D_.size(), CV_32FC1);

	std::memcpy(input_mat.data, _feature1D_.data(), _feature1D_.size() * sizeof(float));

	cv::Mat result_mat = this->neuralChecking(_m_mlp_inner_,input_mat);

	float failed_val = result_mat.at<float>(0, 1);
	float passed_val = result_mat.at<float>(0, 0);
	
	/* GET PERCENT % */

	FAILED_INNER = failed_val;
	PASSED_INNER = passed_val;

	/* Result */
	bool isDefect = false;

	if (failed_val > 0.9) isDefect = true;

	return isDefect;
}

void NeuralNets::reTrainNeuralNet(std::string modelName){

	std::cout << "Retrain" << std::endl;

	loadDataSet("trainmat.xml");
	_m_mlp_edge_ = cv::ml::ANN_MLP::load(modelName);
	cv::Ptr<cv::ml::TrainData> traindata = cv::ml::TrainData::create(_trainningmat_, cv::ml::ROW_SAMPLE, _labelmat_);
	_m_mlp_edge_->train(traindata);
	_m_mlp_edge_->save(modelName);
	std::cout << "Re-Train has Done!" << std::endl;
}

void NeuralNets::saveNewData(){
	saveData("trainmat.xml", m_predata, true);
	m_predata.clear();
}

void NeuralNets::initialInnerRegion(void){
	/* Look Up Table */
	cv::FileStorage fs(_lookuptable_, cv::FileStorage::READ);
	fs["Num1D"] >> this->_num1D_;
	
	fs["Table1D"] >> this->_table1D_;

	fs["MAX1D"] >> this->_maxValue1D_;
	fs.release();
	this->_feature1D_.assign(this->_num1D_, 0);
	/* Load Neural Network */
	loadNeuralInnerModel(_modelInnerName_);
}

void NeuralNets::normalizeInnterFeature(std::vector<float>& _data){
	/* Code Here */
	for (auto id = 0; id < _data.size();id++) {
		_data[id] /= _maxValue1D_[id];
		if (_data[id] > 1) _data[id] = 1;
	}
}
