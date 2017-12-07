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

void GuiDataSet::shuffleData(std::vector<feature>& m_data){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(m_data.begin(), m_data.end(), std::default_random_engine(seed));
}



#pragma endregion end

void GuiDataSet::on_btn_savealldata_clicked(void){
	saveData(file_train_,m_predata,true);
	cout << "Save Data!" << endl;
}

void GuiDataSet::on_btn_trainneural_clicked(void){

	QString fileName = QFileDialog::getOpenFileName(this, tr("TIFF (*.tif);; All files (*.*)"));

	cv::Ptr<cv::ml::ANN_MLP> mlp;

	 string modelName = fileName.toStdString();

	 mlp = cv::ml::ANN_MLP::load(modelName);
	 /* Load Data */
	 cv::FileStorage file(file_train_, cv::FileStorage::READ);
	 file["train_matrix"] >> prev_trainmat_;
	 file["label_matrix"] >> prev_labelmat_;
	 file.release();

	 cv::Ptr<cv::ml::TrainData> traindata = cv::ml::TrainData::create(prev_trainmat_, cv::ml::ROW_SAMPLE,prev_labelmat_);
	 mlp->train(traindata);
	 mlp->save(modelName);
	 std::cout << "Train Done!" << std::endl;
}

void GuiDataSet::on_btn_IsPushData_clicked(void){
	std::vector<int> lable;
	if (ui.IsPassed->isChecked()) {
		lable.push_back(1);
		lable.push_back(0);
	}
	else if (ui.IsFailed->isChecked()){
		lable.push_back(0);
		lable.push_back(1);
	}

	if (m_curFeature_.feature.size() > 0 && lable.size() > 0) {

		m_curFeature_.label = lable;
		// push back //
		m_predata.push_back(m_curFeature_);
	}
}

void GuiDataSet::on_btn_IsPopData_clicked(void){

	if (m_predata.size() > 0) {
		m_predata.pop_back();
		std::cout << "Pop Back" << std::endl;
	}
}
