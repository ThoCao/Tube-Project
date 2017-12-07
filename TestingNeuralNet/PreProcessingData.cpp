#include "PreProcessingData.h"



PreProcessingData::PreProcessingData(){

	/* Load Old Data */
	loadOldData(_file_train_);
}


PreProcessingData::~PreProcessingData()
{
}

void PreProcessingData::normalizeInput(std::vector<float>& _data)
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

void PreProcessingData::saveData(std::string fileName, std::vector<Feature>& m_data, bool flag_old){
	if (m_data.size() == 0) return;
	// Shuffle DataSet
	shuffleData(m_data);
	cv::Mat output_train_mat = cv::Mat::zeros(m_data.size(), m_data[0].feature.size(), CV_32FC1);
	cv::Mat output_label_mat = cv::Mat::zeros(m_data.size(), m_data[0].label.size(), CV_32FC1);

	// copy data
	// train
	for (int row = 0; row < output_label_mat.rows; row++) {
		for (int col = 0; col < output_train_mat.cols; col++) {
			output_train_mat.at<float>(row, col) = m_data[row].feature[col];
		}
	}
	// label
	for (int row = 0; row < output_label_mat.rows; row++) {
		for (int col = 0; col < output_label_mat.cols; col++) {
			output_label_mat.at<float>(row, col) = m_data[row].label[col];
		}
	}
	// add previous data
	if (flag_old) {
		if (prev_trainmat_.cols == output_train_mat.cols && prev_labelmat_.cols == output_label_mat.cols) {
		output_train_mat.push_back(prev_trainmat_);
		output_label_mat.push_back(prev_labelmat_);
	}
	}
	

	cv::FileStorage file(fileName, cv::FileStorage::WRITE);

	file << "train_matrix" << output_train_mat;
	file << "label_matrix" << output_label_mat;

	file.release();
}

void PreProcessingData::shuffleData(std::vector<Feature>& m_data){
	
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(m_data.begin(), m_data.end(), std::default_random_engine(seed));
}

void PreProcessingData::loadOldData(std::string fileName){
	
	// load old data
	cv::FileStorage file(fileName, cv::FileStorage::READ);
	file["train_matrix"] >> prev_trainmat_;
	file["label_matrix"] >> prev_labelmat_;
	file.release();
}

std::vector<std::vector<float>> PreProcessingData::getInputFeatures(Circles & _circle_edges)
{
	std::vector<std::vector<float>> allFeatures;
	std::vector<Contour> allContour;
	// segment vector inner and outer
	const float scaled_factor = abs(_circle_edges[0].R - _circle_edges[1].R) / 2;

	for (auto contour : _circle_edges) {
		const int max_index = contour.contour.size() / POINT_SIZE;
		for (auto index = 0; index < max_index; index++) {

			const int start = index*POINT_SIZE / 2;
			const int end = start + POINT_SIZE;
			const int step_size = 2;
			Contour setPoints;
			for (auto id = start; id + step_size < end; id += step_size) {
				setPoints.push_back(contour.contour[id]);
			}
			// feature
			if (setPoints.size() == FEATURE_SIZE) {
				std::vector<float> feature_;
				for (auto p : setPoints) {
					float r_val = cv::norm(p - (cv::Point)contour.rect.center);
					float dr_val = abs(r_val - contour.R);
					float sr_val = (int)dr_val / scaled_factor;
					sr_val *= 100;
					sr_val = roundf(sr_val);
					feature_.push_back((float)sr_val/10);
				}
				// normalize
				normalizeInput(feature_);
				// push back
				allFeatures.push_back(feature_);
				allContour.push_back(setPoints);
			}
		}

	}
	return allFeatures;
}
