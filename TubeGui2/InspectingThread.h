#pragma once

#include <QObject>
#include <QtCore>
#include "NeuralNets.h"
#include "PreProcessingData.h"
#include "PreProcessing.h"
#include "PointGreyCamV2.h"
#include "RoiGUI.h"

#define imagewindow "WINDOW"
#define SCALED_W 1280
#define SCALED_H 1024

#define SHOW_W 500
#define SHOW_H 500

#define TIMER_TUBE 5


#define UP_CAMERA 1
#define DOWN_CAMERA 0

class InspectingThread : public QObject
{
	Q_OBJECT

public:
	InspectingThread(QObject *parent = 0);
	~InspectingThread();

	void Inspecting(QString name);

signals: 
	void on_send_image_v1(unsigned int _id, cv::Mat _image);
	void on_send_prob_value(int id, float num1, float num2, float num3, float num4);

public slots:
	void stopThread();
	void openCam();
	void closeCam();
	void openRoiUser(bool _flag);
	bool reloaddata();

private:
	bool mIsStopThread;

private:
	
	PointGreyCamV2 mCameras;

	bool isCameraConnected1 = false;
	bool isCameraConnected2 = false;
	bool isBothCameraConnected = false;

private:
	/* Init Modulde */
	void loadRoiData(void);

	/* Image Module */
private:
	bool singleCheck(cv::Mat& _input_img);
	
	bool Down_Checking(cv::Mat& input_img);
	bool Up_Checking(cv::Mat& input_img);

	/* Neural Module */
	NeuralNets * _neuralnet_right_;

	/* Processing Module */
	PreProcessing * _preProcessing_;

	/* Roi Image */
	bool IsRoi = false;
	static bool isLeft_tube_roi;


	static cv::Mat mUpScaled_img;
	static cv::Mat mDownScaled_img;

	cv::Rect2d mLDown_roi;
	cv::Rect2d mRDown_roi;

	cv::Rect2d mLUp_roi;
	cv::Rect2d mRUp_roi;

	std::string _roi_data_name_ = "roi.xml";
	
	/* Image Roi Selection */
	RoiGUI mImageRoi;


/* Auto Control Module */

	bool Isfoundcircle = false;
	bool IsChecking = false;
	bool IsCounter = false;
	bool IsNextTube = false;
	int  _counter_timer = 0;


	/* Draw Defect On Edge */
	bool isLUp_edge = false;
	cv::Point LUp_edge_point;
	int LUp_radius = 0;

	bool isRUp_edge = false;
	cv::Point RUp_edge_point;
	int RUp_radius = 0;
	
	bool isLDown_edge = false;
	cv::Point LDown_edge_point;
	int LDown_radius = 0;

	bool isRDown_edge = false;
	cv::Point RDown_edge_point;
	int RDown_radius = 0;

	
};
