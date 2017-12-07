#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>
#include <QTime>
#include "GuiDataSet.h"
#include "GuiNeuralNetwork.h"


#include "opencv2\opencv.hpp"
#include "PreProcessing.h"
#include <iostream>
#include "LoadListFile.h"
#include "NeuralFeature2.h"
#include <string>
#include <windows.h>
#include <direct.h>

using namespace std;
using namespace cv;

#define _show(img) cv::imshow(#img,img);
#define _wait(ms) cv::waitKey(ms);

#define OKAY
#define USERDATA
#define windowName "tube"
#define GUI
#define NEURAL


string  OKAYPATH;

PreProcessing preProcessing;
LoadListFile loadImages;
NeuralFeature2 neuralFeature2;
GuiDataSet * dataSet ;
GuiNeuralNetwork * neuralNetWork;

bool flag_next_image = true;

bool found = 0;
bool flag_change = 0;
bool flag_dont_save = false;
bool flag_okay = true;
int diffRadius = 1;
Mat inner_img;
Mat outer_img;
Mat readImage;
Point center;

string excelFile;

void ShowImage(Mat& readImage);
// Calback function
void CallBackFunc(int event, int x, int y, int flags, void* userdata);
// current path
string getExePath() {
	char* cwd = _getcwd(0, 0); // **** microsoft specific ****
	std::string working_directory(cwd);
	std::free(cwd);
	return working_directory;
}

int main(int argc, char *argv[])
{
	
    QApplication a(argc, argv);
	// load image files
#ifdef OKAY
	cout << "TESTING OKAY SAMPLES" << endl;
	string dirPath = getExePath() + "\\OKAY\\";
    QStringList listImages = loadImages.getListImages(QString::fromStdString(dirPath));
	excelFile = "nondefective.csv";
#else
	cout << "TESTING NOTOKAY SAMPLES" << endl;
	string dirPath = getExePath() + "\\NotOKAY\\";
    QStringList listImages = loadImages.getListImages(QString::fromStdString(dirPath));
	excelFile = "defective.csv";
#endif // OKAY

#ifdef USERDATA
	namedWindow(windowName);
	setMouseCallback(windowName, CallBackFunc, NULL);
#endif // USERDATA

#ifdef GUI
	dataSet = new GuiDataSet();
	dataSet->show();
#endif // GUI
#ifdef NEURAL
    neuralNetWork = new GuiNeuralNetwork();
	neuralNetWork->show();
#endif // NEURAL


	
	int cnt = 0;

	vector<vector<int>> totalData;
	while (true)
	{
 		if (cnt >= (listImages.size())) a.exec();
 		cout <<"Image: " << cnt << endl;
#ifdef USERDATA
		if (flag_next_image == true) {
			string nameImage = dirPath + listImages[cnt].toStdString();

			readImage = imread(nameImage, 1);
			cnt++;
			// reset flag
			flag_next_image = false;

		}
#endif // USERDATA

		if (readImage.empty()) a.exec();

		ShowImage(readImage);

		if (found) {
			neuralFeature2.resetFeature();
			neuralFeature2.Run1D(inner_img.clone(),diffRadius);
			
			vector<int> feature1D = neuralFeature2.getFeatureValue(1);
			vector<int> feature2D = neuralFeature2.getFeatureValue(2);
#ifdef GUI
		
            feature input;
			vector<float> data;
			for (auto p : feature1D) {

				data.push_back(p);
				//
				cout << p << " ";
			}		
            vector<int> label;
			if (flag_okay) {
				label.push_back(1);
				label.push_back(0);
			}
			else {
				label.push_back(0);
				label.push_back(1);
			}
               
			// save data into array	
			input.feature = data;
			input.label = label;

			if (flag_dont_save == true) {
				cout << "dont save" << endl;
				flag_dont_save = false;
			}
			else
			{
				dataSet->m_predata.push_back(input);
				cout << endl;
			}
			
	
#endif // GUI
			totalData.push_back(feature1D);

#ifdef NEURAL
			neuralNetWork->setInput(feature1D);
			if (neuralNetWork->getResultFromNeural() == true) {
				Rect rect;
				rect.x = center.x - 30;
				rect.y = center.y - 40;
				rect.width = 150 ;
				rect.height = 100;
				cv::rectangle(readImage, rect, {0,0,0},-1);
				cv::putText(readImage, "OKAY", center, 1, 1.5, { 0,255,0 });
			}
			else{
				Rect rect;
				rect.x = center.x - 30;
				rect.y = center.y - 40;
				rect.width = 150 ;
				rect.height = 100;
				cv::rectangle(readImage, rect, { 0,0,0 },-1);
				cv::putText(readImage, "Not OKAY", center, 1, 1.5, { 0,255,0 });
			}

#endif // NEURAL

			_show(inner_img);
			_show(outer_img);
			cv::imshow(windowName, readImage);
			// reset found flag
			found = false;
		}

		char key = _wait();
		if (key == 'n') {
			flag_next_image = true;
			if (flag_change == true) {
				// don't save into notokay first
				flag_dont_save = true;
			}
		}
		if (key == 's') {
			QString date_time = QTime::currentTime().toString();
			date_time.replace(":", "_");
			string imageName = "Artificial Data\\"+ date_time.toStdString() + "_image.bmp";
			cout << imageName << endl;
			imwrite(imageName, readImage);
		}
		if (key == 'q') a.exec();
		if (key == 'w') {
			ofstream file;
			file.open(excelFile);
			for (auto pp : totalData) {
				for (auto p : pp) {
					file << p << ",";
				}
				file << endl;
			}
			file.close();
		}
		if (key == 'c') {// change the object tube
			listImages.clear();
            dirPath = getExePath() + "\\NotOKAY\\";
            listImages = loadImages.getListImages(QString::fromStdString(dirPath));
			cnt = 0;
			flag_okay = false;
			flag_next_image = true;
			cout << "this not okay sample" << endl;

		}
		if (key == 'p') {
			//
			cout << "let draw some scratch on tube" << endl;
			dirPath = getExePath() + "\\OKAY\\";
			listImages.clear();
			listImages = loadImages.getListImages(QString::fromStdString(dirPath));
			cnt = 0;
            flag_okay = false;
			flag_next_image = false;
			flag_change = true;
		}

	}

	return a.exec();
}

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

		center = big_circle.rect.center;
		//
		diffRadius = abs(big_circle.R - small_circle.R)/2;
	}
	
}

void CallBackFunc(int event, int x, int y, int flags, void * userdata){

	if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_LBUTTON) {
		circle(readImage, { x,y }, 2, { 50,50,50 }, -1);
	}
	// imshow

	imshow(windowName, readImage); // show it to the user
}

