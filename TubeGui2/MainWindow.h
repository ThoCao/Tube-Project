#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QTimer>
#include <QFile>
#include <qdir.h>
#include <qdatetime.h>
#include <QtConcurrent>

#include "opencv2\opencv.hpp"
#include "PreProcessing.h"
#include "PointGreyCamera.h"
#include "BaslerCam.h"
#include "NeuralNets.h"
#include "PreProcessingData.h"

#include "InspectingThread.h"



#define imagewindow "WINDOW"

#define SCALED_W 1280
#define SCALED_H 1024

#define SHOW_W 500
#define SHOW_H 500

#define TIMER_TUBE 5
#define TIMER_CAM 132

#define UP_CAMERA 1
#define DOWN_CAMERA 0


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private:
	Ui::MainWindowClass ui;


	/* Camera Module*/
public slots :
	void on_cameraOpen_clicked(void);
	void on_check_clicked(void);
	/* User Module */

	void on_btn_LUpPassed_clicked(void);
	void on_btn_LUpFailed_clicked(void);


	void on_btn_RUpPassed_clicked(void);
	void on_btn_RUpFailed_clicked(void);

	void on_btn_LDownPassed_clicked(void);
	void on_btn_LDownFailed_clicked(void);
	
	void on_btn_RDownPassed_clicked(void);
	void on_btn_RDownFailed_clicked(void);

	void on_btn_OpenRoi_clicked(void);
private:
	char* MyMakeFolder(QString nameFolder);
	void SaveImage(QString saveName, QString tailName, cv::Mat & image, bool flag);

	/* New Update */
private:
	bool isFirstCheckingClick = false;
	
	cv::Mat mLUpimg;
	cv::Mat mRUpimg;
	cv::Mat mLDownimg;
	cv::Mat mRDownimg;
private:
	InspectingThread mThread;
signals:
	void on_StopThread();
	void on_OpenCam();
	void on_CloseCam();
	void on_OpenUserRoi(bool _flag);

public slots:
	void getImageFromThread(unsigned int _id, cv::Mat _image);
	void getProbValue(int id, float num1, float num2, float num3, float num4);

};
