#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include "FlyCapture2.h"
#include <memory>

#include <iostream>

using namespace FlyCapture2;

class PointGreyCamV2
{
public:
	PointGreyCamV2();
	
	~PointGreyCamV2();

private:
	const int mUpSerialCam =  16401861;
	const int mDownSerialCam =  1640186100;
	static unsigned int mNumeCameras;
	bool mIsAllCamConnected = false;
private:
	Camera *mCameras;
public:
	int mDownCamId = 0;
	int mUpCamIId = 0;
public:
	int getNumCameras(void);
	int getDownCamIdSerial() { return mDownCamId; };
	int getUpCamIdSerial() { return mUpCamIId; };

	bool isAllCamConnected() { return mIsAllCamConnected; }

	bool OpenAllCameras(void);
	bool CloseAllCameras(void);

	bool ReCeiveImage(unsigned int id, cv::Mat& image, int typeImage);

};

