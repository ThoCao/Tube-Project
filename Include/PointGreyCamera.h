#pragma once
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include "FlyCapture2.h"

#include <iostream>

using namespace FlyCapture2;

class PointGreyCamera
{
public:
	enum PGCOLOR{ RGB =1,
		          GRAY=0
	 };
public:
	PointGreyCamera();
	~PointGreyCamera();
private:
	Camera     _camera;
	CameraInfo _camInfo;
private:// control flag
	bool _disconnect_flag = 0;
public:
	bool OpenCam(const int id=0);
	bool CloseCam();
	bool ReCeiveImage(cv::Mat &image, int typeImg);
};

