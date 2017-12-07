#include "PointGreyCamera.h"



PointGreyCamera::PointGreyCamera()
{
	
}


PointGreyCamera::~PointGreyCamera()
{
	if (_disconnect_flag == 0) {
		Error error;
		error = _camera.StopCapture();
		if (error != PGRERROR_OK) {
			std::cout << "This may fail when the camera was removed, so don't show" << std::endl;
		}
		_camera.Disconnect();
	}
}

bool PointGreyCamera::OpenCam(const int id){

	Error error;
	// Connect the camera
	BusManager busMgr;
	unsigned int numCameras;
	error = busMgr.GetNumOfCameras(&numCameras);
	if (numCameras == 0) return false;

	PGRGuid guid;
	error = busMgr.GetCameraFromIndex(0, &guid);
	error = _camera.Connect(&guid);
	if (error != PGRERROR_OK) {
		std::cout << "Failed to connect to camera" << std::endl;
		return false;
	}
	// Get camera info and print out
	error = _camera.GetCameraInfo(&_camInfo);
	if (error != PGRERROR_OK) {
		std::cout << "Failed to get camera info from camera" << std::endl;
		return false;
	}
	std::cout << _camInfo.vendorName << " "<< _camInfo.modelName << " "<< _camInfo.serialNumber << std::endl;
	error = _camera.StartCapture();

	if (error == PGRERROR_ISOCH_BANDWIDTH_EXCEEDED)
	{
		std::cout << "Bandwidth exceeded" << std::endl;
		return false;
	}
	else if (error != PGRERROR_OK)
	{
		std::cout << "Failed to start image capture" << std::endl;
		return false;
	}
	return true;
}

bool PointGreyCamera::CloseCam()
{
	_disconnect_flag = 1;
	Error error;
	error = _camera.StopCapture();
	if (error != PGRERROR_OK) {
		std::cout << "This may fail when the camera was removed, so don't show" << std::endl;
		return false;
	}
	_camera.Disconnect();
	return true;
}

bool PointGreyCamera::ReCeiveImage(cv::Mat & image,int typeImg)
{
	Image rawImage;
	Error error = _camera.RetrieveBuffer(&rawImage);
	if (error != PGRERROR_OK) {
		std::cout << "Capture error" << std::endl;
		return false;
	}
	Image rgbImage;
	rawImage.Convert(FlyCapture2::PIXEL_FORMAT_BGR, &rgbImage);
	// Convert to OpenCV Mat
	unsigned int rowBytes = (double)rgbImage.GetReceivedDataSize() / (double)rgbImage.GetRows();
	cv::Mat imgGrab;
	if (typeImg == 1) {
	imgGrab = cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC3, rgbImage.GetData(), rowBytes);
	}
	else {
		imgGrab = cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC1, rgbImage.GetData(), rowBytes);
	}
	// copy to reference image
	imgGrab.copyTo(image);
	return true;
}
