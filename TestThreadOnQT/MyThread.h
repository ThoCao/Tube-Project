#pragma once

#include <QObject>
#include <QtCore>
#include "opencv2\opencv.hpp"
#include "PointGreyCamera.h"
#include "BaslerCam.h"


using namespace cv;

class MyThread : public QObject
{
	Q_OBJECT
public:
	MyThread(QObject * parent =0);
	~MyThread();

	void start(QString name);

signals:
	void on_number(QString name, cv::Mat image1, cv::Mat image2);

	public slots:
	void stop();
	void openCam();
	void closeCam();

private:
	bool mStop;
	PointGreyCamera * mCam1;
	BaslerCam * mCam2;
	bool mIsCamConected;

	bool isCamera1 = false;
	bool isCamera2 = false;

};
