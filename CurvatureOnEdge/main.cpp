#include <QtWidgets\QApplication> 
#include <QtCore/QCoreApplication> 
#include "PreProcessing.h"
#include "preHeader.h"
#include <iostream>
#include "main.h"
#include "QtCurvature.h"
#include "GuiNeuralNetwork.h"

using namespace std;
using namespace cv;

//#define OKAY

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	/* config directory */
	// getpath
	bool flag_okay;
#ifdef OKAY
	flag_okay = true;
	string dirPath = getExePath() + "\\OKAY\\";
	QStringList listImages = getListImages(QString::fromStdString(dirPath));
#else
	flag_okay = false;
    string dirPath = getExePath() + "\\NotOKAY\\";
	QStringList listImages = getListImages(QString::fromStdString(dirPath));
#endif // OKAY
	namedWindow(windowName);
	setMouseCallback(windowName, CallBackFunc, NULL);
	/* config QT*/
	QtCurvature * qtCurvature = new QtCurvature();
	qtCurvature->show();
	GuiNeuralNetwork * neuralNet = new GuiNeuralNetwork();
	neuralNet->show();
	/* get loop */
	int cnt = 0;
	bool flagNextImage = true;

	while (true){
		cout << "Index Image: " << cnt << endl;
		if (flagNextImage == true) {
			string image_name = dirPath + listImages[cnt].toStdString();
			image_img = imread(image_name, 1);
			cnt++;
			if (image_img.empty()) break;
			flagNextImage = false;
		}
		
		/* PrePoccessing */
		bool IsFound = false;
		vector<Circle> theSetPoint = getSetPointOnEdge(image_img.clone(),IsFound);
		if (IsFound) {
          	cv::Mat contour_img = image_img.clone();
			for (auto p : theSetPoint) {
			
				for (auto id = 0; id + 1 < p.contour.size(); id++) {
					line(contour_img, p.contour[id], p.contour[id + 1], { 100,250,100 }, 2);
				}
			}
			_show(contour_img);
			_wait(10);
		}
		/* QT */
		if (IsFound) {
			qtCurvature->setCircles(theSetPoint);
			qtCurvature->setImage(image_img);

			neuralNet->setImage(image_img.clone());
			bool IsDefective = neuralNet->getResultOnEdge(theSetPoint);
			if (IsDefective == true) {
				std::cout << "This Is NotOKay" << std::endl;
			}
			else std::cout << "This Is Okay" << std::endl;
		}

		imshow(windowName, image_img);
		
		char key = _wait();

		if (key == 'n') flagNextImage = true;
		if (key == 'c') {
			cout << "change object" << endl;
			listImages.clear();
			if (flag_okay == false) {
				dirPath = getExePath() + "\\OKAY\\";
				listImages = getListImages(QString::fromStdString(dirPath));
				flag_okay = true;
			}
			else {
				dirPath = getExePath() + "\\NotOKAY\\";
				listImages = getListImages(QString::fromStdString(dirPath));
				flag_okay = false;
			}
			
		}
		if (key == 'r') {
			cnt = 0;
		}

	}
	return a.exec();
}

vector<Circle> getSetPointOnEdge(Mat & data_img,bool& pfound)
{
	vector<Circle> contours;
    // find circle
	Circle big_circle, small_circle;
	// set gaussian threshold
	preProcessing.setGaussianValue(2);
	preProcessing.setEpsilonRadius(25);
	std::tie(big_circle, small_circle, pfound) = preProcessing.Find2CirclesFunc(data_img.clone());

	contours.push_back(big_circle);
	contours.push_back(small_circle);

	return contours;
}
