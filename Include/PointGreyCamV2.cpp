#include "PointGreyCamV2.h"



unsigned int PointGreyCamV2::mNumeCameras = 0;

PointGreyCamV2::PointGreyCamV2(){

}


PointGreyCamV2::~PointGreyCamV2(){
	/* Close all Camera */
	bool isClose = CloseAllCameras();
}

int PointGreyCamV2::getNumCameras(void){
	
	Error error;
	// Connect the camera
	BusManager busMgr;
	error = busMgr.GetNumOfCameras(&mNumeCameras);

	return mNumeCameras;
}

bool PointGreyCamV2::OpenAllCameras(void){

	mIsAllCamConnected = false;
	Error error;
	// Connect the camera
	BusManager busMgr;
	error = busMgr.GetNumOfCameras(&mNumeCameras);


	mCameras = new Camera[mNumeCameras];
	for (unsigned int id = 0; id < mNumeCameras; id++) {
		PGRGuid guid;
		error = busMgr.GetCameraFromIndex(id, &guid);
		if (error != PGRERROR_OK) {
			delete[] mCameras;

			return 0;
		}

		// connect to camera
		error = mCameras[id].Connect(&guid);

		if (error != PGRERROR_OK) {
			
			delete[] mCameras;
			std::cout << "Failed to connect to camera" << std::endl;
			return false;
		}
		// Get camera info and print out
		CameraInfo camInfo;
		error = mCameras[id].GetCameraInfo(&camInfo);
		if (error != PGRERROR_OK) {
			
			delete[] mCameras;
			std::cout << "Failed to get camera info from camera" << std::endl;
			return false;
		}
		
		/* Checking ID */
		if (camInfo.serialNumber == mUpSerialCam) {
			mUpCamId = id;
		}
		else if (camInfo.serialNumber == mDownSerialCam) {
			mDownCamId = id;
		}

		error = mCameras[id].StartCapture();

		if (error == PGRERROR_ISOCH_BANDWIDTH_EXCEEDED)
		{
			delete[] mCameras;
			std::cout << "Bandwidth exceeded" << std::endl;
			return false;
		}
		else if (error != PGRERROR_OK)
		{
			delete[] mCameras;
			std::cout << "Failed to start image capture" << std::endl;
			return false;
		}
	}

	if (mNumeCameras == 0) mIsAllCamConnected = false;
	else mIsAllCamConnected = true;

	return mIsAllCamConnected;
}

bool PointGreyCamV2::CloseAllCameras(void){

	if (mIsAllCamConnected == true) {
		for (unsigned int id = 0; id < mNumeCameras; id++) {
			mCameras[id].StopCapture();
			mCameras[id].Disconnect();
		}

		delete[] mCameras;

		mIsAllCamConnected = false;
	}
	else return false;

	return true;
}

bool PointGreyCamV2::ReCeiveImage(unsigned int id, cv::Mat & image, int typeImage){

	Image rawImage;
	if (mNumeCameras < id) return false;

	unsigned int indexCam = 0;
	if (id == UP_CAMERA) indexCam = getUpCamIdSerial();
	else if (id == DOWN_CAMERA) indexCam = getDownCamIdSerial();
	else return false;

	Error error = mCameras[indexCam].RetrieveBuffer(&rawImage);

	if (error != PGRERROR_OK) {
		std::cout << "Capture error" << std::endl;
		return false;
	}
	Image rgbImage;
	rawImage.Convert(FlyCapture2::PIXEL_FORMAT_BGR, &rgbImage);
	// Convert to OpenCV Mat
	unsigned int rowBytes = (double)rgbImage.GetReceivedDataSize() / (double)rgbImage.GetRows();
	cv::Mat imgGrab;
	if (typeImage == 1) {
	imgGrab = cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC3, rgbImage.GetData(), rowBytes);
	}
	else {
		imgGrab = cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC1, rgbImage.GetData(), rowBytes);
	}
	// copy to reference image
	imgGrab.copyTo(image);
	return true;
}
