#include "TestMultipleCameras.h"

TestMultipleCameras::TestMultipleCameras(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void TestMultipleCameras::on_btnOpenCam_clicked(void)
{
	bool isCamConnected = mCameras.OpenAllCameras();

	if (isCamConnected == true) qDebug() << "CAM OKAY!";
	else qDebug() << "CAM NOT OKAY!";
}

void TestMultipleCameras::on_btnCloseCam_clicked(void)
{

}

void TestMultipleCameras::on_btnShowImage_clicked(void){

	unsigned int numCams = mCameras.getNumCameras();
	for (unsigned int id = 0; id < numCams; id++) {

		std::string name = "Show Window " + std::to_string(id);

		cv::Mat image;
		bool isNotEmpty = mCameras.ReCeiveImage(id, image, 1);
		if (isNotEmpty == true) {
			cv::imshow(name, image);
			cv::waitKey(10);
		}
	}

}

void TestMultipleCameras::on_btnShowRoi_clicked(void){
	/* Roi Select Image and Chose */
	cv::Mat image = cv::imread("vitran.jpg", 1);

	mRoi.setImage(image, DOWN_CAMERA);
	mRoi.show();
}
