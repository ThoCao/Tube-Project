#include "GuiListScaledImages.h"

GuiListScaledImages::GuiListScaledImages(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	readListScaledImage(listName);
	readKernelMask(kernekName);

	cv::FileStorage fs(nameListKernel, cv::FileStorage::READ);
	fs["kernel"] >> listKernels;
	fs.release();
}

GuiListScaledImages::~GuiListScaledImages()
{
}

void GuiListScaledImages::on_btn_save_clicked(void){
    QString fileName = listName;
	QFile file(fileName);
	if (file.open(QIODevice::ReadWrite)) {
		QTextStream stream(&file);
		QStringList list = ui.textEdit->toPlainText().split("\n");
		foreach(QString str, list) {
			stream << str << endl;
		}
	}
	file.close();
}

void GuiListScaledImages::on_btn_createkernel_clicked(void){
    QString text = ui.text_kernelmask->toPlainText();
    // Number of Feature
	std::cout << "Number of List: " << getNumList(text)<< std::endl;
	QStringList list = text.split("\n");
	// Output
	this->kernel.clear();
	foreach(QString str, list) {
		std::vector<int> vals = getValuefromList(str);
		if (vals.size() < 1) continue;
		// neural layer
		this->kernel.push_back(vals);
	}
	//
	const int _SIZER = kernel.size();
	const int _SIZEC = kernel[0].size();
	this->kernelMat = cv::Mat::zeros({_SIZEC,_SIZER}, CV_32F);
	for (auto row = 0; row < kernelMat.rows; row++) {
		for (auto col = 0; col < kernelMat.cols; col++) {
			kernelMat.at<float>(row, col) = kernel[row][col];
		}
	}
	// 
	this->kernelMat /= (kernelMat.rows*kernelMat.cols);
	std::cout << this->kernelMat << std::endl;
}

void GuiListScaledImages::on_btn_savekernel_clicked(void){
	// text file
	QString fileName = ui.line_nameKernel->text() + ".txt";
	QFile file(fileName);
	if (file.open(QIODevice::ReadWrite)) {
		QTextStream stream(&file);
		QStringList list = ui.text_kernelmask->toPlainText().split("\n");
		foreach(QString str, list) {
			stream << str << endl;
		}
	}
	file.close();
	// xml file
}

void GuiListScaledImages::on_btn_showimage_clicked(void){
	on_btn_createkernel_clicked();
	if (kernel_img.empty()) return;
	cv::Mat gray_img;
    cv::cvtColor(kernel_img, gray_img, cv::COLOR_BGR2GRAY);
	// appply filter
	cv::Point anchor = cv::Point(-1,-1);
	double delta = 0;;
	int ddepth =-1;
	cv::Mat dst;
	cv::filter2D(gray_img,dst, ddepth, kernelMat, anchor, delta, cv::BORDER_DEFAULT);

	int scaled_factor = ui.spin_scaledfactor->value();
	dst *= scaled_factor;
	_show(dst);
	_wait(10);
}

void GuiListScaledImages::on_btn_savelistkernel_clicked(void){
	if (this->kernelMat.empty()) return;
	cv::Mat temple_kernel;
	kernelMat.copyTo(temple_kernel);
	listKernels.push_back(temple_kernel);
	//
	cv::FileStorage fs(nameListKernel, cv::FileStorage::WRITE);
	fs << "kernel" << listKernels;
	fs.release();
}

void GuiListScaledImages::on_btn_showlistimage_clicked(void){
	if (this->kernel_img.empty()) return;
	int index = 1;
	for (auto kernel : listKernels) {
		cv::Mat gray_img;
		cv::cvtColor(kernel_img, gray_img, cv::COLOR_BGR2GRAY);
		// appply filter
		cv::Point anchor = cv::Point(-1,-1);
		double delta = 0;;
		int ddepth =-1;
		cv::Mat dst;
		cv::filter2D(gray_img,dst, ddepth,kernel, anchor, delta, cv::BORDER_DEFAULT);

		int scaled_factor = ui.spin_scaledfactor->value();
		dst *= scaled_factor;
		std::string nameImage = "number" + std::to_string(index);

		// draw mask inside image
		const int fix_val = 220;
		const int step_size = 40;
		int px = fix_val;
		int py = fix_val;
		for (auto row = 0; row < kernel.rows; row++) {
			px = fix_val;
			for (auto col = 0; col < kernel.cols; col++) {
				int val = kernel.at<float>(row, col)*10;
				std::string name = "    " + std::to_string(val) + "    ";
				cv::putText(dst, name, { px,py }, 1, 2, { 255 });
				px += step_size;
			}
			py += step_size;
		}

		// max pooling;
		cv::Mat max_img1 = getMaxPooling(dst, 2);
		cv::Mat max_img2 = getMaxPooling(max_img1.clone(), 2);
		cv::Mat max_img3 = getMaxPooling(max_img2.clone(), 2);

		cv::imshow("max1" + nameImage, max_img1);
		cv::imshow("max2" + nameImage, max_img2);
		cv::imshow("max3" + nameImage, max_img3);
		cv::imshow(nameImage, dst);
		_wait(10);
		// increase number
		index++;
	}
}

void GuiListScaledImages::on_btn_maxpooling_clicked(void){

}

void GuiListScaledImages::readListScaledImage(QString fileName){
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
		ui.textEdit->append(line);
	}
}

void GuiListScaledImages::readKernelMask(QString & fileName){
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
		ui.text_kernelmask->append(line);
	}
	
}

int GuiListScaledImages::getNumList(QString text)
{
	return text.count(':');
}

cv::Mat GuiListScaledImages::getMaxPooling(cv::Mat & data, const int _size){

	const int _rowSize = data.rows / _size;
	const int _colSize = data.cols / _size;
	cv::Mat max_img = cv::Mat::zeros({ _colSize,_rowSize }, data.type());

	int row = 0;
	for (auto idx = 0; idx +1 < data.rows; idx +=_size) {
 
		uchar *Mi1 = data.ptr<uchar>(idx);
		uchar *Mi2 = data.ptr<uchar>(idx + 1);
		uchar *Mo = max_img.ptr<uchar>(row);
		int col = 0;
		for (auto idy = 0; idy+1 < data.cols; idy += _size) {
			int val1 = Mi1[idy];
			int val2 = Mi1[idy + 1];
			int val3 = Mi2[idy];
			int val4 = Mi2[idy + 1];
			int val = 0;
			if (val1 > val) val = val1;
			if (val2 > val) val = val2;
			if (val3 > val) val = val3;
			if (val4 > val) val = val4;

			Mo[col] = val;
			col++;

		}
		row++;
	}

	return max_img;
}

std::vector<int> GuiListScaledImages::getValuefromList(QString & text)
{
	QStringList list = text.split(" ");
	std::vector<int> vals;
	foreach(QString str, list) {
		if (str.size() < 1) continue;
		if (str.at(0) != 'l') {
			int val = str.toInt();
			vals.push_back(val);
		}
	}
	return vals;
}

void GuiListScaledImages::on_btn_read_clicked(void){
	QString text = ui.textEdit->toPlainText();
// Number of Feature
	std::cout << "Number of List: " << getNumList(text)<< std::endl;
	QStringList list = text.split("\n");
	// Output
	this->lists.clear();
	foreach(QString str, list) {
		std::vector<int> vals = getValuefromList(str);
		if (vals.size() < 1) continue;
		// neural layer
		this->lists.push_back(vals[0]);
	}
}
