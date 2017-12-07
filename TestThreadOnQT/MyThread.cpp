#include "MyThread.h"

MyThread::MyThread(QObject * parent): QObject(parent)
{
	mStop = false;

	mCam1 = new PointGreyCamera();

	mCam2 = new BaslerCam();

	/* get number of camera */
	FlyCapture2::BusManager busMgr;
	unsigned int numCameras;
	FlyCapture2::Error error;
	error = busMgr.GetNumOfCameras(&numCameras);
	qDebug() << "Number of PointGrey: " << numCameras;
	/* Balser */
	Pylon::PylonInitialize();
	try
	{
		Pylon::CTlFactory& tlFactory = Pylon::CTlFactory::GetInstance();
		// get all attached devices and exit application if no devices if found
		Pylon::DeviceInfoList_t devices;
		if (tlFactory.EnumerateDevices(devices) == 0) {
			qDebug() << "There are no basler";
		}
		qDebug() << "Number of Basler: " << devices.size();
	}
	catch (const std::exception&)
	{

	}
	
}

MyThread::~MyThread()
{
	if (mIsCamConected == true) {
		if (mCam1->CloseCam()) {
			qDebug() << "Closed Camera Success!";
		}
		else {
			qDebug() << " Failed to Close Camera!";
		}

		if (mCam2->CloseCam()) {
				qDebug() << "Closed Camera Success!";
		}
		else {
			qDebug() << " Failed to Close Camera!";
		}

	}
}

void MyThread::start(QString name){
	mStop = false;
	int i = 0;
	while (true)
	{
		if (mStop) return;
		qDebug() << "From Thread: " << i;
		//cv::Mat image = cv::imread("vitran.jpg", 1);

		if (mIsCamConected) {
			cv::Mat image1,image2;
			bool isReceiveImage1 = mCam1->ReCeiveImage(image1, 1);
			bool isReceiveImage2 = mCam2->ReceiveImage(image2);

			if(isReceiveImage1 && isReceiveImage2) emit on_number(name, image1,image2);
		}
		QThread::currentThread()->msleep(100);

		i++;
	}
}

void MyThread::openCam(){
	
		if (mCam1->OpenCam()) {
		cv::Mat image;
		isCamera1 = mCam1->ReCeiveImage(image, 1);
	}

	if (mCam2->OpenCam()) {
		cv::Mat image;
		isCamera2 = mCam2->ReceiveImage(image);
	}

	if (isCamera1 && isCamera2) {
		mIsCamConected = true;
		qDebug() << "Cam Okay";
	}
	else {
		mIsCamConected = false;
		qDebug() << "Cam Not Okay";
	}
}

void MyThread::closeCam(){
	
	if (mIsCamConected == true) {

		if (mCam1->CloseCam()){
			isCamera1 = false;

		}

		if (mCam2->CloseCam()) {
			isCamera2 = false;
		}

		mIsCamConected = false;
	}


}

void MyThread::stop() {
	mStop = true;
}
