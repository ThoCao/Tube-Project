#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>
#include "preHeader.h"
#include "QtHeader.h"

using namespace std;
using namespace cv;

bool flag_next_image = true;

//#define OKAY
#define GUI



int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// getpath
#ifdef OKAY
	string dirPath = getExePath() + "\\OKAY\\";
	QStringList listImages = getListImages(QString::fromStdString(dirPath));
#else
    string dirPath = getExePath() + "\\NotOKAY\\";
	QStringList listImages = getListImages(QString::fromStdString(dirPath));
#endif // OKAY

	namedWindow(windowName);
	setMouseCallback(windowName, CallBackFunc, NULL);

#ifdef GUI
	listScaledImages = new GuiListScaledImages();
	listScaledImages->show();
#endif // GUI
	int cnt = 0;
	
	while (1){
		cout << "image index: " << cnt << endl;

		if (cnt >= listImages.size()) a.exec();
		if (flag_next_image == true) {
			string imageNameP = dirPath + listImages[cnt].toStdString();
			readImage = imread(imageNameP, 1);
			
			flag_next_image = false;
			cnt += 1;
		}

		if (readImage.empty()) a.exec();
		Mat roi_image = getImageRoi(readImage, 124);
		listScaledImages->setImage(roi_image.clone());
		vector<int> listScaled = listScaledImages->getListScaleImages();
	
		/*vector<Mat> defect_img = getRois(roi_image.clone(), listScaled);
		if (found) {
			imshow(windowName, readImage);
			int index = 0;
			for (auto img : defect_img) {
				string name = "defective" + to_string(listScaled[index]) + ".bmp";
				imwrite(name, img);
				index++;
			}
			
			found = false;
		}*/
		
		char key = _wait();
		if (key == 'n') {
			flag_next_image = true;
		}
		
	}

	return a.exec();
}
