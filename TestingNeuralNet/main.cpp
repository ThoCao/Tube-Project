#include <QtCore/QCoreApplication>
#include <QtWidgets\QApplication>
#include <QFileDialog>
#include <QInputDialog>
#include <QFileSystemModel>

#include <string>
#include <windows.h>
#include <direct.h>
#include "NeuralNets.h"

using namespace std;
using namespace cv;



#define windowName "ShowTube"

Mat image_img;

//#define OKAY

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
	isOkay = true;
	string dirPath = getExePath() + "\\OKAY\\";
	QStringList listImages = getListImages(QString::fromStdString(dirPath));
#else
	isOkay = false;
    string dirPath = getExePath() + "\\NotOKAY\\";
	QStringList listImages = getListImages(QString::fromStdString(dirPath));
#endif // OKAY

	/* Mouse */
	namedWindow(windowName);
	setMouseCallback(windowName, CallBackFunc, NULL);
	/* QT */

	/* PreProcessing Module */

	PreProcessing * preProcessImage = new PreProcessing();
	/* Neural Module */

	NeuralNets * neuralNet = new NeuralNets();

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
		bool IsFound_Tube = false;
		Circle outer_edge, inner_edge;
		preProcessImage->setGaussianValue(3);
		preProcessImage->setEpsilonRadius(25);
		std::tie(outer_edge, inner_edge, IsFound_Tube) = preProcessImage->Find2CirclesFunc(image_img.clone());

		cv::Mat inner_img;  preProcessImage->getInnerMaskImage(outer_edge, inner_edge);

		std::vector<Circle> circles;
	
		float scaled_factor_radius = 1;

		if (IsFound_Tube) {
			/* Neural Outer */
			circles.push_back(outer_edge);
			circles.push_back(inner_edge);
			/* Neural Inner */
			scaled_factor_radius = abs(outer_edge.R - inner_edge.R);
			inner_img =  preProcessImage->getInnerMaskImage(outer_edge, inner_edge);

			/* Contour on edge */
			vector<vector<Point>> contours;
			contours.push_back(outer_edge.contour);
			contours.push_back(inner_edge.contour);
			cv::Mat contour_img = cv::Mat::zeros(inner_img.size(), inner_img.type());

			for (int id = 0; id < contours.size(); id++) {
				drawContours(contour_img, contours, id, { 255 }, 3);
			}

			cv::imshow("contour image", contour_img);
			/* Draw Circle */
			ellipse(image_img, outer_edge.rect, { 0,255,0 }, 2);
			ellipse(image_img, inner_edge.rect, { 0,255,0 }, 2);
			cv::imshow("circle image", image_img);
		}

		/* Neural Module */
		
		bool Isfound_edge_defective = false;
		bool Isfound_inner_defective = false;

		/* Edge Defective */
		if (IsFound_Tube) {
			neuralNet->setImage(image_img.clone());
			Isfound_edge_defective = neuralNet->getResultOnEdge(circles);
		}

		/* inner defective */
	
		if (IsFound_Tube == true) {
			neuralNet->setScaledFactor(scaled_factor_radius);
			Isfound_inner_defective = neuralNet->getResultInner(inner_img.clone());
		}


		/* PERCENT PASSED : FAILED % */

		if (IsFound_Tube == true) neuralNet->showResult_PERCENT();

		if (Isfound_edge_defective || Isfound_inner_defective) {
			std::cout << "This Is Not OKay!" << std::endl;
		}
		else {
			std::cout << "This is OKay!" << std::endl;
		}


		/* Display Image Module */

		cv::imshow("Inner Image", inner_img);
		cv::imshow(windowName, image_img);
		char key = _wait();

		if (key == 'n') {
			isNetImage = true;
		}
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
