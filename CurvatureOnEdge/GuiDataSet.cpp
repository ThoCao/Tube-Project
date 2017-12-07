#include "GuiDataSet.h"

GuiDataSet::GuiDataSet(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	// load old data
	cv::FileStorage file(file_train_, cv::FileStorage::READ);
	file["train_matrix"] >> prev_trainmat_;
	file["label_matrix"] >> prev_labelmat_;
	file.release();
	
}

GuiDataSet::~GuiDataSet()
{
}

#pragma region Not GUI
void GuiDataSet::saveData(string fileName,std::vector<feature>& m_data,bool flag_old){
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

void GuiDataSet::normolizeInputData(std::vector<float>& _data){
	// find index of max value
	int max_idx = std::distance(_data.begin(), std::max_element(_data.begin(), _data.end()));
	int size_val = _data.size() / 2 - 1;
	int angle_val = (size_val - max_idx);
	// rotate the vector
	if (angle_val > 0) {
		std::rotate(_data.rbegin(), _data.rbegin() + angle_val, _data.rend());
	}
	else {
		std::rotate(_data.begin(), _data.begin() + abs(angle_val), _data.end());
	}
	// find min value and subtract
	float min_val = *std::min_element(_data.begin(), _data.end());
	for (auto& p : _data) {
		p = p - min_val;
		p /= MAX_VAL;
	}
}

void GuiDataSet::normalizeInputDataV2(std::vector<float>& _data){

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

void GuiDataSet::setInputandOutPutSize(int input, int output){
	_inPutSize = input;
	_outPutSize = output;
}



void GuiDataSet::shuffleData(std::vector<feature>& m_data){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(m_data.begin(), m_data.end(), std::default_random_engine(seed));
}
void GuiDataSet::on_btn_retraindata_clicked(void){
	if (m_predata.size() == 0) return;

	feature temple_data = m_predata.back();
	if (ui.radio_true->isChecked()) {
		temple_data.label[0] = 1;
		temple_data.label[1] = 0;
	}
	else {
		temple_data.label[0] = 0;
		temple_data.label[1] = 1;
	}

	m_posdata.push_back(temple_data);

}
void GuiDataSet::on_btn_postsave_clicked(void){
	saveData(file_reTrain, m_posdata,true);
	cout << "re save data" << endl;
}
void GuiDataSet::on_btn_savenewdata_clicked(void){
	saveData("newtrainmat.xml", m_predata,false);
	cout << "save new data" << endl;
}
#pragma endregion end

void GuiDataSet::on_btn_savedata_clicked(void){
	saveData(file_train_,m_predata,true);
	cout << "save data" << endl;
}
