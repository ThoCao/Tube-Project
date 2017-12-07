#include "NeuralFeature2.h"



NeuralFeature2::NeuralFeature2()
{
	// read storage file
	readLookUpFeatureFile(this->lookUpTableFileName);
}


NeuralFeature2::~NeuralFeature2()
{
}

void NeuralFeature2::Run1D(cv::Mat & image,const int diffRadius){
	Contours contours = PreProcessing::find_countours(image.clone());
	//std::cout <<"size: " <<contours.size() << std::endl;
	
	for (auto contour : contours) {
		if (contour.size() < 5) continue;
	
		cv::RotatedRect rectangle = cv::minAreaRect(contour);
		float feature1 = rectangle.size.height;
		float feature2 = rectangle.size.width;
	

		feature1 /= diffRadius;
		feature2 /= diffRadius;

		feature1 *= 100;
		feature2 *= 100;

		feature1 = roundf(feature1);
		feature2 = roundf(feature2);

		//std::cout << feature1 << " : " << feature2 << std::endl;

		if (feature1 >= 900) feature1 = 900;
		if (feature2 >= 900) feature2 = 900;
		// feature 1D;
		int max_feature = std::max(feature1, feature2);
		int index1D = this->lookUp1D[max_feature];
		if (index1D == 999) continue;
		this->feature1D[index1D] += 1;

	}
}

void NeuralFeature2::resetFeature(void){
	for (auto& p : this->feature1D) p = 0;
	for (auto& p : this->feature2D) p = 0;
}

std::vector<int> NeuralFeature2::getFeatureValue(int index)
{
	if (index == 1) {
		return this->feature1D;
	}
	else {
		return this->feature2D;
	}
}

void NeuralFeature2::saveFeatureToExcelFile(std::vector<int>& data, std::string  fileName){
	std::ofstream file;
	file.open(fileName);
	for (auto p : data) {
		file << p << std::endl;
	}
	file.close();
	
}

void NeuralFeature2::readLookUpFeatureFile(std::string fileName){
	cv::FileStorage fs(fileName, cv::FileStorage::READ);
	fs["Num1D"] >> this->numOfFeature1D;
	fs["Num2D"] >> this->numOfFeature2D;
	fs["Table1D"] >> this->lookUp1D;
	fs["Table2D"] >> this->lookUp2D;
	fs.release();

	this->feature1D.assign(this->numOfFeature1D, 0);
	this->feature2D.assign(this->numOfFeature2D*this->numOfFeature2D, 0);
}
