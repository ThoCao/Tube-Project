#include <QtCore/QCoreApplication>
#include <QtWidgets\QApplication>
#include <QFileDialog>
#include <QInputDialog>
#include <QFileSystemModel>

#include <string>
#include <windows.h>
#include <direct.h>
#include "FilterClass.h"

using namespace cv;
using namespace std;



#define windowName "tube"

int counter = 0;


cv::Mat image_img = cv::Mat();
cv::Mat roi_img = cv::Mat();
cv::Rect2d _roi_img_ = cv::Rect2d();
cv::Point _first_point_ = cv::Point();
cv::Point _second_point_ = cv::Point();
bool _flag_ = false;

void CallBackFunc(int event, int x, int y, int flags, void * userdata);



/* Pre Path */
string getExePath();
QStringList getListImages(QString folderName);

/* Mouse */
void CallBackFunc(int event, int x, int y, int flags, void * userdata);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	/* config path */

	bool isOkay;
	int cnt = 0;
	bool isNetImage = true;
#ifdef OKAY
	flag_okay = true;
	string dirPath = getExePath() + "\\33334_20mm\\";
	QStringList listImages = getListImages(QString::fromStdString(dirPath));
#else
	isOkay = false;
    string dirPath = getExePath() + "\\33334_20mm\\";
	QStringList listImages = getListImages(QString::fromStdString(dirPath));
#endif // OKAY

	/* Mouse */
	namedWindow(windowName);
	setMouseCallback(windowName, CallBackFunc, NULL);
	/* QT */

	/* Define Modeule */
	FilterClass * filterBinary = new FilterClass();

	/* Code Here */
	while (true)
	{
		/* Read Image Module */
		std::cout << std::endl;
	
		if (isNetImage == true) {

			string image_name = dirPath + listImages[cnt].toStdString();
			image_img = imread(image_name, 1);
			_scale(image_img);
			image_img.copyTo(roi_img);

			cnt++;
			if (image_img.empty()) break;

			isNetImage = false;
		}
		/* PreProcessing Module */

		filterBinary->findFeatures(image_img.clone());

		/* Display Image Module */

		
		cv::imshow(windowName, image_img);
		char key = _wait();

		if (key == 'n') isNetImage = true;
		if (key == 'c') {
			cout << "change object" << endl;
			cnt = 0;
			listImages.clear();
			if (isOkay == false) {

				dirPath = getExePath() + "\\OKAY\\";
				listImages = getListImages(QString::fromStdString(dirPath));
				isOkay = true;
			}
			else {
				dirPath = getExePath() + "\\NotOKAY\\";
				listImages = getListImages(QString::fromStdString(dirPath));
				isOkay = false;
			}
			
		}
		if (key == 'r') {
			cnt = 0;
		}
	}

	return a.exec();
}


/* Pre Path */

string getExePath(){
	char* cwd = _getcwd(0, 0); // **** microsoft specific ****
	std::string working_directory(cwd);
	std::free(cwd);
	return working_directory;
};

QStringList getListImages(QString folderName)
{

	QString dirPath = folderName;
	QDir sys_Dir(dirPath);
	QStringList listImages = sys_Dir.entryList(QDir::NoDotAndDotDot | QDir::Files);
	return listImages;
};

void CallBackFunc(int event, int x, int y, int flags, void * userdata){
	
	
	if (event == cv::EVENT_LBUTTONDOWN) {
		// Set Postion
		if (_flag_ == false) {
			_first_point_ = cv::Point(x, y);
			_flag_ = true;
		}
	}
	else if (event == cv::EVENT_RBUTTONDOWN)
	{
		_first_point_ = cv::Point(0, 0);
		_second_point_ = cv::Point(0, 0);
		// reset
		_flag_ = false;
		// save image

		cv::Mat roi = roi_img(_roi_img_);
		string name_img = "data//" + std::to_string(counter) + ".bmp";
		cv::imwrite(name_img, roi);
		counter++;
		cout << "number: " << counter << endl;

	}
	else if (event == cv::EVENT_LBUTTONUP) {
		// Set Second
		_second_point_ = cv::Point(x, y);
		// draw rectangle
		cv::Rect rect = cv::Rect();
		rect.x = _first_point_.x;
		rect.y = _first_point_.y;
		rect.width = abs(_first_point_.x - _second_point_.x);
		rect.height = abs(_first_point_.y - _second_point_.y);
		cv::Mat img_copy;
		image_img.copyTo(img_copy);
		cv::rectangle(img_copy, rect, { 255,0,0 }, 2);

		_roi_img_ = rect;
		_flag_ = false;
	}
	else if (event == cv::EVENT_MOUSEMOVE) {
		if (_flag_ == true) {
			// Set Second
			_second_point_ = cv::Point(x, y);
			// draw rectangle
			cv::Rect rect = cv::Rect();
			rect.x = _first_point_.x;
			rect.y = _first_point_.y;

			rect.width = abs(_first_point_.x - _second_point_.x);
			rect.height = abs(_first_point_.y - _second_point_.y);

			cv::Mat img_copy;
			image_img.copyTo(img_copy);
			cv::rectangle(img_copy, rect, { 255,0,0 }, 2);
			cv::imshow(windowName, img_copy);
			cv::waitKey(5);
		}

	}
	
}
