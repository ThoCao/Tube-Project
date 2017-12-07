#include "SecDialog.h"

SecDialog::SecDialog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	// read feature
	readFeaturefromTextFile1D("feature1D.txt");
	readFeaturefromTextFile2D("feature2D.txt");
	readNeuralNetfromTextFile("neuralnet.txt");
	// 
	initialLookUpTable1D();
	initialLookUpTabel2D();
}

SecDialog::~SecDialog(){

}

void SecDialog::on_btn_show_clicked(void){
	QString text1D = ui.textEdit->toPlainText();
	QString text2D = ui.text2Dfeature->toPlainText();
	// Number of Feature
	this->numberOfFeature1D = getNumbeofFeatures(text1D);
	this->numberOfFeature2D = getNumbeofFeatures(text2D);
	cout << "Number of Feature1D: " << this->numberOfFeature1D << endl;
	cout << "Number of Feature2D: " << this->numberOfFeature2D << endl;
	// feature 1D
	QStringList list = text1D.split("\n");
	// Output
	this->features1D.clear();
	this->maximum_val_1D.clear();
	foreach(QString str, list) {
		vector<int> vals = getValfromFeature(str);
		if (vals.size() < 1) continue;

		this->maximum_val_1D.push_back(vals[2]);

		vector < int> f1D;
		f1D.push_back(vals[0]);
		f1D.push_back(vals[1]);
		this->features1D.push_back(f1D);
	}
	// feature 2D
	QStringList list2D = text2D.split("\n");
	this->features2D.clear();
	foreach(QString str, list2D) {
		vector<int> vals = getValfromFeature(str);
		if (vals.size() < 1) continue;
		this->features2D.push_back(vals);
	}
	// show feature
	cout << "1D" << endl;
	for (auto ff : this->features1D) {
		for (auto f : ff) cout << f << " ";
		cout << endl;
	}
	cout << "2D" << endl;
	for (auto ff : this->features2D) {
		for (auto f : ff) cout << f << " ";
		cout << endl;
	}
}

void SecDialog::on_btn_save_clicked(void){
	// topology of feature
	// feature 1D
	QString fileName = "feature1D.txt";
	QFile file(fileName);
	if (file.open(QIODevice::ReadWrite)) {
		QTextStream stream(&file);
		QStringList list = ui.textEdit->toPlainText().split("\n");
		foreach(QString str, list) {
			stream << str << endl;
		}
	}
	file.close();
	// feature 2D
    QString fileName2D = "feature2D.txt";
	QFile file2D(fileName2D);
	if (file2D.open(QIODevice::ReadWrite)) {
		QTextStream stream(&file2D);
		QStringList list = ui.text2Dfeature->toPlainText().split("\n");
		foreach(QString str, list) {
			stream << str << endl;
		}
	}
	file2D.close();
	// lookUpfeature
	cv::FileStorage fs(this->nameOfFeature, cv::FileStorage::WRITE);
	fs << "Num1D" << this->numberOfFeature1D;
	fs << "Num2D" << this->numberOfFeature2D;
	fs << "Table1D"  <<this->lookUpTable1D;
	fs << "Table2D" << this->lookUpTable2D;
	fs << "MAX1D" << this->maximum_val_1D;
	fs.release();

}

void SecDialog::on_btn_showNet_clicked(void){
QString text = ui.textEdit_NeuralNet->toPlainText();
	// Number of Feature
	cout << "Number of Layers: " << getNumbeofFeatures(text)<< endl;
	QStringList list = text.split("\n");
	// Output
	this->layers.clear();
	foreach(QString str, list) {
		vector<int> vals = getValfromNetwork(str);
		if (vals.size() < 1) continue;
		// neural layer
		this->layers.push_back(vals[0]);
	}
}

void SecDialog::on_btn_saveNet_clicked(void){
	QString fileName = "neuralnet.txt";
	QFile file(fileName);
	if (file.open(QIODevice::ReadWrite)) {
		QTextStream stream(&file);
		QStringList list = ui.textEdit_NeuralNet->toPlainText().split("\n");
		foreach(QString str, list) {
			stream << str << endl;
		}
	}
	file.close();
}

void SecDialog::on_btn_createNet_clicked(void){
	on_btn_showNet_clicked();

	this->neuralNetWork.setLayerMatrix(this->layers);
	this->neuralNetWork.setNeuralNetWorkModel();
	cout << "create neural net had done" << endl;
}

void SecDialog::on_btn_reTrain_clicked(void){

    QString fileName = QFileDialog::getOpenFileName(this, tr("TIFF (*.tif);; All files (*.*)"));

	std::string modelName = fileName.toStdString();
	this->neuralNetWork.reTrainModel(modelName);
}

void SecDialog::on_btn_loadModelNet_clicked(void){
	QString fileName = QFileDialog::getOpenFileName(this, tr("TIFF (*.tif);; All files (*.*)"));
    std::string modelName = fileName.toStdString();
	this->neuralNetWork.loadModel(modelName);
	cout << "load model net had done!" << endl;
}

void SecDialog::on_btn_predict_clicked(void){
	/* Write Something */
}

void SecDialog::on_btn_lookuptable_clicked(void){
	
	configForLookUpTable1D();
}

void SecDialog::on_btn_lookuptable2D_clicked(void){
	configForLookUpTable2D();
}

void SecDialog::on_btn_showFeatureIndex_clicked(void){
	int val = ui.featureRange->value();

	int featureIndex = this->lookUpTable1D[val];

	if (featureIndex == MAGICNUMBER) {
		cout << " Not located in range" << endl;
	}
	else {
		cout << " Index Feature: " << featureIndex << endl;
	}
}

void SecDialog::on_btn_showFeatureIndex2D_clicked(void){
	int val1D = ui.featureRange->value();
	int val2D = ui.featureRange2D->value();

	int featureIndex = this->lookUpTable2D[val1D][val2D];
	if (featureIndex == MAGICNUMBER) {
		cout << "2D: Not In Range!" << endl;
	}
	else {
		cout << "2D: Index Feature: " << featureIndex << endl;
	}
}

int SecDialog::getNumbeofFeatures(QString& text){
	return text.count(':');
}

void SecDialog::readFeaturefromTextFile1D(QString filename){
    // Read feature
	QStringList list;
	QFile textfile(filename);
	textfile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream textstream(&textfile);
	while (true)
	{
		QString line = textstream.readLine();
		if (line.isNull()) break;
		else
			list.append(line);
		ui.textEdit->append(line);
	}
	
}

void SecDialog::readFeaturefromTextFile2D(QString fileName){
 // Read feature
	QStringList list;
	QFile textfile(fileName);
	textfile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream textstream(&textfile);
	while (true)
	{
		QString line = textstream.readLine();
		if (line.isNull()) break;
		else
			list.append(line);
		ui.text2Dfeature->append(line);
	}
}

void SecDialog::readNeuralNetfromTextFile(QString fileName){
// Read feature
	QStringList list;
	QFile textfile(fileName);
	textfile.open(QIODevice::ReadOnly | QIODevice::Text);
	QTextStream textstream(&textfile);
	while (true)
	{
		QString line = textstream.readLine();
		if (line.isNull()) break;
		else
			list.append(line);
		ui.textEdit_NeuralNet->append(line);
	}
}

void SecDialog::initialLookUpTable1D(void){
	this->lookUpTable1D.assign(LOOKUPTABLESIZE, MAGICNUMBER);
}

void SecDialog::initialLookUpTabel2D(void){
	this->lookUpTable1Dto2D.assign(LOOKUPTABLESIZE, MAGICNUMBER);
	for (auto i = 0; i < LOOKUPTABLESIZE; i++) {
		vector<int> row;
		row.assign(LOOKUPTABLESIZE, MAGICNUMBER);
		this->lookUpTable2D.push_back(row);
	}
}

void SecDialog::configForLookUpTable1D(void){
	if (this->features1D.size() > 0) {
		int indexfeature = 0;
		for (auto ff : this->features1D) {

			if (ff.size() >= 2) {
				const int sta = ff[0];
				const int end = ff[1];

				for (auto i = sta; i < end; i++) {
					this->lookUpTable1D[i] = indexfeature;
				}
			}
			indexfeature++;
		}
	}
	cout << "1D Done!" << endl;
}

void SecDialog::configForLookUpTable2D(void){
        if (this->features2D.size() > 0) {
		int indexfeature = 0;
		for (auto ff : this->features2D) {

			if (ff.size() >= 2) {
				const int sta = ff[0];
				const int end = ff[1];

				for (auto i = sta; i < end; i++) {
					this->lookUpTable1Dto2D[i] = indexfeature;
				}
			}
			indexfeature++;
		}
	}


	if (this->features2D.size() > 0) {
		for (auto ff : this->features2D) {
			if (ff.size() >= 2) {
				const int staRow = ff[0];
				const int endRow = ff[1];
				for (auto i = staRow; i < endRow; i++) {
					for (auto ff2d : this->features2D){
						const int staCol = ff2d[0];
						const int endCol = ff2d[1];
						for (auto j = staCol; j < endCol; j++) {
							int indexRow = this->lookUpTable1Dto2D[i];
							int indexCol = this->lookUpTable1Dto2D[j];
							this->lookUpTable2D[i][j] = indexRow + indexCol*this->numberOfFeature2D;
						}
					}
				}
			}
		}
	}

	cout << "2D Done!" << endl;
}

vector<int> SecDialog::getValfromNetwork(QString & text){
	QStringList list = text.split(" ");
	vector<int> vals;
	foreach(QString str, list) {
		if (str.size() < 1) continue;
		if (str.at(0) != 'l') {
			int val = str.toInt();
			vals.push_back(val);
		}
	}
	return vals;
}

vector<int> SecDialog::getValfromFeature(QString & text)
{
	QStringList list = text.split(" ");
	vector<int> vals;
	foreach(QString str, list) {
		if (str.size() < 1) continue;
		if (str.at(0) != 'f') {
			int val = str.toInt();
			vals.push_back(val);
		}
	}
	return vals;
}

