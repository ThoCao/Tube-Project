#include <QtCore/QCoreApplication>
#include <QtWidgets\QApplication>
#include <QFileDialog>
#include <QInputDialog>
#include <QFileSystemModel>

#include <string>
#include <windows.h>
#include <direct.h>
#include "FilterClass.h"

using namespace std;
using namespace cv;


#define windowName "ShowTube"

Mat image_img;

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
    string dirPath = getExePath() + "\\data\\";
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

/* Mouse */
void CallBackFunc(int event, int x, int y, int flags, void * userdata){

	if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_LBUTTON) {
		circle(image_img, { x,y }, 2, { 30,30,30 }, -1);
	}
	// imshow

	imshow(windowName,image_img); // show it to the user
};