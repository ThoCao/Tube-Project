#pragma once
#include <string>
#include <windows.h>
#include <direct.h>
#include "PreProcessing.h"

using namespace std;
using namespace cv;

#define windowName "tube"

Mat inner_img;
Mat outer_img;
Mat image_img;

bool found = false;
int diffRadius = 1;

PreProcessing preProcessing;
// current path
string getExePath(){
	char* cwd = _getcwd(0, 0); // **** microsoft specific ****
	std::string working_directory(cwd);
	std::free(cwd);
	return working_directory;
};

void ShowImage(Mat & readImage){
	// find circle
	Circle big_circle, small_circle;
	// set gaussian threshold
	preProcessing.setGaussianValue(2);
	preProcessing.setEpsilonRadius(25);
	std::tie(big_circle, small_circle, found) = preProcessing.Find2CirclesFunc(readImage.clone());

	if (found) {
		// edge
		inner_img = preProcessing.getInnerMaskImage(big_circle, small_circle);
		outer_img = preProcessing.getOuterMaskImage(big_circle, small_circle);
		//
		diffRadius = abs(big_circle.R - small_circle.R)/2;
	}
	
};

Mat getImageRoi(Mat& image,const int sizeI) {
    // find circle
	Circle big_circle, small_circle;
	// set gaussian threshold
	preProcessing.setGaussianValue(2);
	preProcessing.setEpsilonRadius(25);
	std::tie(big_circle, small_circle, found) = preProcessing.Find2CirclesFunc(image.clone());

	Mat output;
	
	if (found) {
		Rect2f rect;
		rect.x = big_circle.rect.center.x - big_circle.rect.size.width/2;
		rect.y = big_circle.rect.center.y - big_circle.rect.size.height/2;
	
		rect.width =  big_circle.rect.size.width;
		rect.height = big_circle.rect.size.height;

		output = image(rect);
		resize(output, output, { sizeI,sizeI }, 0, 0);

		found = true;
		
	}

	return output;
};

vector<Mat> getRois(cv::Mat& image, std::vector<int> listSize) {
    // find circle
	Circle big_circle, small_circle;
	// set gaussian threshold
	preProcessing.setGaussianValue(2);
	preProcessing.setEpsilonRadius(25);
	std::tie(big_circle, small_circle, found) = preProcessing.Find2CirclesFunc(image.clone());

	vector<Mat> output;
	
	if (found) {
		Rect2f rect;
		rect.x = big_circle.rect.center.x - big_circle.rect.size.width/2;
		rect.y = big_circle.rect.center.y - big_circle.rect.size.height/2;
	
		rect.width =  big_circle.rect.size.width;
		rect.height = big_circle.rect.size.height;

		Mat big_roi = image(rect);

		for (auto p : listSize) {
			cv::Mat roi_img;
			resize(big_roi, roi_img, { p,p });
			output.push_back(roi_img);
		}
		found = true;
	}
	return output;
}

void CallBackFunc(int event, int x, int y, int flags, void * userdata){

	if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_LBUTTON) {
		circle(image_img, { x,y }, 2, { 30,30,30 }, -1);
	}
	// imshow

	imshow(windowName,image_img); // show it to the user
};

// QT
#include <QFileDialog>
#include <QInputDialog>
#include <QFileSystemModel>
QStringList getListImages(QString folderName)
{

	QString dirPath = folderName;
	QDir sys_Dir(dirPath);
	QStringList listImages = sys_Dir.entryList(QDir::NoDotAndDotDot | QDir::Files);
	return listImages;
};
