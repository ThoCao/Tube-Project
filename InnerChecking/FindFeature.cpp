#include "FindFeature.h"



FindFeature::FindFeature()
{
	loadLookUpFeature(this->_lookUpTableFileName_);
	/* DataSet */

	dataset->show();

	/* Neural Module */
	
	_m_mlp_ = cv::ml::ANN_MLP::load(_modelName_);
	std::cout << _m_mlp_->getLayerSizes();
}


FindFeature::~FindFeature()
{
}

void FindFeature::loadLookUpFeature(std::string fileName){
	
	cv::FileStorage fs(fileName, cv::FileStorage::READ);
	fs["Num1D"] >> this->_num1D_;
	
	fs["Table1D"] >> this->_table1D_;

	fs["MAX1D"] >> this->_maxValue1D_;

	fs.release();

	this->_feature1D_.assign(this->_num1D_, 0);
}

bool FindFeature::neuralPredict(std::vector<float>& _data)
{
	bool isDefect = false;
	cv::Mat input_mat = cv::Mat(1, _data.size(), CV_32FC1);
	std::memcpy(input_mat.data, _data.data(), _data.size() * sizeof(float));

	cv::Mat result_mat = this->neuralChecking(input_mat);

	std::cout << result_mat << std::endl;

	float failed_val = result_mat.at<float>(0, 1);
	float passed_val = result_mat.at<float>(0, 0);

	if (failed_val > 0.9) isDefect = true;
	
	return isDefect;
}

cv::Mat FindFeature::neuralChecking(cv::Mat & input)
{
	cv::Mat response;
	// predict
	_m_mlp_->predict(input, response);
	return response;
}

cv::Mat FindFeature::getInnerImage(cv::Mat & _image){
	// find circle
	Circle big_circle, small_circle;
	bool IsFound = false;

	setGaussianValue(2);
	setEpsilonRadius(25);
	std::tie(big_circle, small_circle, IsFound) = Find2CirclesFunc(_image.clone());

	if (IsFound == true) {
		cv::Mat inner_img = getInnerMaskImage(big_circle, small_circle);

		scaled_factor = abs(big_circle.R - small_circle.R);

		return inner_img;
	}

	return cv::Mat();
}

void FindFeature::normalizefeature(std::vector<float>& _data){
	/* Code Here */
	for (auto id = 0; id < _data.size();id++) {
		_data[id] /= _maxValue1D_[id];
		if (_data[id] > 1) _data[id] = 1;
	}
}


void FindFeature::findFeatures(cv::Mat & _image){
	/* clear old data */
	for (auto &p : _feature1D_) p = 0;
	
	cv::Mat mask_img = getInnerImage(_image.clone());

	if (mask_img.empty()) return;

	Contours contours = find_countours(mask_img.clone());

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
		if (index == 999) continue;
		
		/* Filter Feature*/
		
		/* Filter 1: Aspect Ratio */
		cv::Rect rect = cv::boundingRect(contour);
		//float min_w = std::min(rect.width, rect.height);
		//float max_h = std::max(rect.width, rect.height);
		//float aspect_ratio = float(min_w) / max_h;
		//if (aspect_ratio > ESPECT_RATIO) { //draw rectangle
		//	cv::rectangle(_image, rect, { 0,255,0 }, 1);
		//}

		/* Filter 2: CIRCULARITY */
		float Per = cv::arcLength(contour, true);
		float area = cv::contourArea(contour, false);
		float circle_ratio = 4*CV_PI*area/(Per*Per);
		if (circle_ratio > CIRCULARITY) { // draw rectangle
			cv::rectangle(_image, rect, { 0,255,0 }, 1);
			continue;
		}

		/* Push Back Feature */
		this->_feature1D_[index] += 1;
	}

	/* Normalize Feature */
	dataset->m_curFeature_.feature.clear();
	dataset->m_curFeature_.feature.clear();

	normalizefeature(_feature1D_);

	/* Save Data */

	dataset->m_curFeature_.feature = _feature1D_;

	for (auto p : _feature1D_) std::cout << p << " ";
	std::cout << std::endl;
	bool isDefecive = neuralPredict(_feature1D_);
	if (isDefecive) {
		std::cout << "This Is Not OKay" << std::endl;
	}
	else
	{
		std::cout << "This Is OKay" << std::endl;
	}

	_show(_image);
	_show(mask_img);
	_wait(10);
}



