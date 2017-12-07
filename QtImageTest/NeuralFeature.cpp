#include "NeuralFeature.h"



NeuralFeature::NeuralFeature(){
	load();
}


NeuralFeature::~NeuralFeature(){
}

double NeuralFeature::getRatioWhitePixel(const cv::Mat & Image,const cv::Mat& maskImage){
	
	auto NUMBER_ROWS = NUM_ROWS(Image);
	auto NUMBER_COLS = NUM_COLS(Image);

	double totalWhitePixel = 0;
	for (auto i = 0; i < NUMBER_ROWS; i++) {
		const uchar * Mi = maskImage.ptr<uchar>(i);
		for (auto j = 0; j < NUMBER_COLS; j++) {
			if (Mi[j] > 0) totalWhitePixel++;
		}
	}
	double restWhitePixel = 0;
	for (auto i = 0; i < NUMBER_ROWS; i++) {
		const uchar * Mi = Image.ptr<uchar>(i);
		for (auto j = 0; j < NUMBER_COLS; j++) {
			if (Mi[j] > 0) restWhitePixel++;
		}
	}

	return restWhitePixel/ totalWhitePixel;
}

double NeuralFeature::getTotalArea(const cv::Mat & data){
	Contours contours;
	contours = find_contours(data.clone());
	double totalArea = 0;
	for (auto& cons : contours) {
		if (cons.size() >= 5) {
			totalArea += cv::contourArea(cons);
		}
	}
	return totalArea;
}

int NeuralFeature::getTotalNumberofContour(const cv::Mat & data){
	Contours contours;
	contours = find_contours(data.clone());
	return (int)contours.size();
}

double NeuralFeature::getEntropy(const cv::Mat & data,const cv::Point& pcenter){

	std::vector<double>  list_360;
	list_360.assign(360, 0);

	for (auto i = 0; i < data.rows; i++) {
		const uchar  * Mi = data.ptr<uchar>(i);
		for (auto j = 0; j < data.cols; j++) {
			if (Mi[j] > 0) {

				double px = j - pcenter.x;
				double py = i - pcenter.y;
				double radian = round(atan2(py, px) * 180 / CV_PI);
				if (radian > 0) {
					list_360[(int)radian] += 1;
				}
				else
				{
					list_360[(int)radian + 360] += 1;
				}
			}
		}
	}
	



	for (auto p : list_360) {
		if (p > MAXENTROPY) p = MAXENTROPY;
	}
	
	double SCALED = 108;

	for (auto &p : list_360) {
		p /= SCALED;
	}
	double entropy = 0;
	for (auto p : list_360) {
		if (p < 0.0005) entropy += 0;
		else entropy += -p*log2(p) ;
	}

	return entropy;
}

Contours NeuralFeature::find_contours(cv::Mat & input){
    Contours contours;
	cv::findContours(input.clone(), contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);
	return contours;
}

void NeuralFeature::setMaxArea(double val){
	this->max_area = val;
}

void NeuralFeature::setMaxNums(int val){
	this->max_numberofcontour = val;
}

void NeuralFeature::setMaxArea2(double val){
	this->max_area2 = val;
}

void NeuralFeature::setMaxNums2(int val){
	this->max_numberofcontour2 = val;
}

void NeuralFeature::setMaxSmootht(double val){
	this->max_smoothtly_distribution = val;
}

double NeuralFeature::getMaxArea(void){
	return this->max_area;
}

int NeuralFeature::getMaxNums(void){
	return this->max_numberofcontour;
}

double NeuralFeature::getMaxArea2(void)
{
	return this->max_area2;
}

int NeuralFeature::getMaxNums2(void)
{
	return this->max_numberofcontour2;
}

double NeuralFeature::getMaxSmootht(void){
	return this->max_smoothtly_distribution;
}

void NeuralFeature::save(){
	cv::FileStorage fs(this->name, cv::FileStorage::WRITE);
	fs << "max_area" << this->max_area;
	fs << "max_num" << this->max_numberofcontour;
	fs << "max_area2" << this->max_area2;
	fs << "max_num2" << this->max_numberofcontour2;
	fs << "max_smootht" << this->max_smoothtly_distribution;
	fs.release();
}

void NeuralFeature::load(){
	cv::FileStorage fs(this->name, cv::FileStorage::READ);
	fs["max_area"] >> this->max_area;
	fs["max_num"] >> this->max_numberofcontour;
	fs["max_area2"] >> this->max_area2;
	fs["max_num2"] >> this->max_numberofcontour2;
	fs["max_smootht"] >> this->max_smoothtly_distribution;
	fs.release();
}
