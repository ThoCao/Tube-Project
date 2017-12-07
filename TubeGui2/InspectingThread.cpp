#include "InspectingThread.h"


cv::Mat InspectingThread::mDownScaled_img = cv::Mat();
cv::Mat InspectingThread::mUpScaled_img = cv::Mat();

InspectingThread::InspectingThread(QObject *parent)
	: QObject(parent),_neuralnet_right_(new NeuralNets),_preProcessing_(new PreProcessing)
{
	mIsStopThread = false;

	/* data init */
	loadRoiData();
	/* Connect */
	connect(&mImageRoi, &RoiGUI::reLoadData, this, &InspectingThread::reloaddata);
}

InspectingThread::~InspectingThread(){
	
	this->mIsStopThread = false;
}

void InspectingThread::Inspecting(QString name){
	/* Main Processing */
	mIsStopThread = false;
	while (true){
		/* Quit The Thread */

		if (mIsStopThread == true) return;

		/* Doing Code Here */
		if (isBothCameraConnected == true) {
			try
					{
					cv::Mat down_cam_image,up_cam_image;
					bool found_down,found_up;
		
					found_up = this->mCameras.ReCeiveImage(UP_CAMERA,up_cam_image, 1);
					found_down = this->mCameras.ReCeiveImage(DOWN_CAMERA,down_cam_image, 1);
		

					/* Roi Module */

					if (found_up && found_down) {

						/* Get Image Module  */
						cv::resize(down_cam_image.clone(), mDownScaled_img, { SCALED_W,SCALED_H });
						cv::resize(up_cam_image.clone(), mUpScaled_img,{ SCALED_W,SCALED_H });

						/* Checking Module */

						/* Image View */
						if (mLUp_roi.width != 0 && mRUp_roi.width != 0 && !mUpScaled_img.empty() && mLDown_roi.width !=0 && mRUp_roi.width!=0) {

							/* Down Side */
							cv::Mat LDown_img = mDownScaled_img(mLDown_roi);
							cv::Mat RDown_img = mDownScaled_img(mRDown_roi);

							/* Up Side */
							cv::Mat LUp_img = mUpScaled_img(mLUp_roi);
							cv::Mat RUp_img = mUpScaled_img(mRUp_roi);

			#pragma region AUTO CONTROL
									/* Checking Left Circle */

									// Stage 1: Checking
									if (Isfoundcircle == false) {
					
										bool IsCircleFoundLeft = _preProcessing_->IsFoundCircle(LUp_img.clone());

										if (IsCircleFoundLeft == true) {

											/* Left Side*/

											cv::putText(LDown_img, "Detecting", { LDown_img.cols / 2,LDown_img.rows / 2 }, 1, 2, { 0,255,0 }, 2);
											cv::putText(RDown_img, "Detecting", { RDown_img.cols / 2,RDown_img.rows / 2 }, 1, 2, { 0,255,0 }, 2);

											/* Right Side */
											cv::putText(LUp_img, "Detecting", { LUp_img.cols / 2,LUp_img.rows / 2 }, 1, 2, { 0,255,0 }, 2);
											cv::putText(RUp_img, "Detecting", { RUp_img.cols / 2,RUp_img.rows / 2 }, 1, 2, { 0,255,0 }, 2);
											/* Auto Control */
											Isfoundcircle = true;
										}
									}
									else {
										_counter_timer++;

										if (_counter_timer == TIMER_TUBE) IsCounter = true;
									}
									// Stage 2: Timer and Checking

									if (IsCounter == true && IsChecking == false) {

										/* First: Right Check */
										Up_Checking(mUpScaled_img);
										/* Second: Left Check */
										Down_Checking(mDownScaled_img);


										IsChecking = true;
									}

									// Stage 3: 

									if (IsNextTube == false && IsChecking == true) {
					
										bool IsCircleFoundLeft = _preProcessing_->IsFoundCircle(LUp_img.clone());

										if (IsCircleFoundLeft == true) {

											/* Left Side*/
											cv::putText(LDown_img, "Replacing ", { LDown_img.cols / 2,LDown_img.rows / 2 }, 1, 2, { 0,255,0 }, 2);
											cv::putText(RDown_img, "Replacing", { RDown_img.cols / 2,RDown_img.rows / 2 }, 1, 2, { 0,255,0 }, 2);
											/* Right Side*/
											cv::putText(LUp_img, "Replacing ", { LUp_img.cols / 2,LUp_img.rows / 2 }, 1, 2, { 0,255,0 }, 2);
											cv::putText(RUp_img, "Replacing", { RUp_img.cols / 2,RUp_img.rows / 2 }, 1, 2, { 0,255,0 }, 2);

											/* Draw defect on Edge */
											/* Up Image */
											if (isLUp_edge == true) {
												cv::circle(LUp_img, LUp_edge_point, LUp_radius, { 0,0, 255 }, 2);
											}
											if (isRUp_edge == true) {
												cv::circle(RUp_img, LUp_edge_point, LUp_radius, { 0,0, 255 }, 2);
											}
											/* Down Image */

											if (isLDown_edge == true) {
												cv::circle(LDown_img, LDown_edge_point, LDown_radius, { 0,0, 255 }, 2);
											}

											if (isRDown_edge == true) {
												cv::circle(RDown_img, RDown_edge_point, RDown_radius, { 0,0, 255 }, 2);
											}

										}
										else {
											IsNextTube = true;
										}
									}

									/* Reset All Flag */
									if ( IsNextTube == true && IsChecking == true) {

										Isfoundcircle = false;
										IsChecking = false;
										IsCounter = false;
										IsNextTube = false;

										/* is Defect on edge */
										isLUp_edge = false;
										isRUp_edge = false;
										isLDown_edge = false;
										isRDown_edge = false;

										_counter_timer = 0;
									}
			#pragma endregion TUBE
									/* Left Side */
									cv::resize(LDown_img, LDown_img, { SHOW_W,SHOW_H });
									cv::resize(LUp_img, LUp_img, { SHOW_W,SHOW_H });
									cv::resize(RDown_img, RDown_img, { SHOW_W,SHOW_H });
									cv::resize(RUp_img, RUp_img, { SHOW_W,SHOW_H });

									

									emit on_send_image_v1(0, LUp_img);
									emit on_send_image_v1(1, RUp_img);
									emit on_send_image_v1(2, LDown_img);
									emit on_send_image_v1(3, RDown_img);

									/* Roi */
									IsRoi = false;

						}
		
					}
					}
					catch (const std::exception&)
					{

					}
		}

	}
}


void InspectingThread::stopThread() {
	mIsStopThread = true;
}

void InspectingThread::openCam(){

	if (isBothCameraConnected == true) return;

	isBothCameraConnected = this->mCameras.OpenAllCameras();

}

void InspectingThread::closeCam(){

	/* Close Cam */
	bool isClose = this->mCameras.CloseAllCameras();
	if (isClose) {
		isBothCameraConnected = false;
	}

}

void InspectingThread::openRoiUser(bool _flag){
	
	if (isBothCameraConnected == false) return;
	
	if (_flag == UP_CAMERA) {
		bool found_up;
		cv::Mat up_cam_image;
		found_up = this->mCameras.ReCeiveImage(UP_CAMERA,up_cam_image, 1);

		if (found_up == true) {
			this->mImageRoi.setImage(up_cam_image, UP_CAMERA);
			this->mImageRoi.show();
		}
	}
	else if (_flag == DOWN_CAMERA) {
		
		bool found_down;
		cv::Mat down_cam_image;
		found_down = this->mCameras.ReCeiveImage(DOWN_CAMERA, down_cam_image, 1);

		if (found_down == true) {
			this->mImageRoi.setImage(down_cam_image, DOWN_CAMERA);
			this->mImageRoi.show();
		}
	}


}

bool InspectingThread::reloaddata(){
	loadRoiData();
	return true;
}

void InspectingThread::loadRoiData(void){
	
	cv::FileStorage fs(_roi_data_name_, cv::FileStorage::READ);

	fs["left_R"] >> mLUp_roi;
	fs["right_R"] >> mRUp_roi;

	fs["left_L"] >> mLDown_roi;
	fs["right_L"] >> mRDown_roi;
	fs.release();
}

bool InspectingThread::singleCheck(cv::Mat & _input_img){

	if (_input_img.empty()) return false;

	bool found_defect = false;
	/* code here */

	/* Precessing Module */
	bool isFound_tube = false;
	Circle outer_edge, inner_edge;
	_preProcessing_->setGaussianValue(3);
	_preProcessing_->setEpsilonRadius(25);
	std::tie(outer_edge, inner_edge, isFound_tube) = _preProcessing_->Find2CirclesFunc(_input_img.clone());

	cv::Mat inner_img;  _preProcessing_->getInnerMaskImage(outer_edge, inner_edge);

	std::vector<Circle> circles;
	
	float scaled_factor_radius = 1;

	if (isFound_tube) {
		/* Neural Outer */
		circles.push_back(outer_edge);
		circles.push_back(inner_edge);
		/* Neural Inner */
		scaled_factor_radius = abs(outer_edge.R - inner_edge.R);
		inner_img =  _preProcessing_->getInnerMaskImage(outer_edge, inner_edge);

	}

	/* PreProcessing Data */
	
	/* Neural Network Module */
	bool Isfound_edge_defective = false;
	bool Isfound_inner_defective = false;

	/* edge defective */
	if (isFound_tube) {
		_neuralnet_right_->setImage(_input_img.clone());
		Isfound_edge_defective = _neuralnet_right_->getResultOnEdge(circles);
		
	}

	/* inner defective */
	
	if (isFound_tube == true) {
		_neuralnet_right_->setScaledFactor(scaled_factor_radius);
		Isfound_inner_defective = _neuralnet_right_->getResultInner(inner_img.clone());
	}

	/* result */

	if (Isfound_edge_defective || Isfound_inner_defective) {
		found_defect = true;
	}
	
	
	if (isFound_tube == true) _neuralnet_right_->showResult_PERCENT();

	return found_defect;
}

bool InspectingThread::Down_Checking(cv::Mat & input_img){

	/* Checking Module */
	bool Isfound_defective_left = false;
	bool Isfound_defective_right = false;
		
	if (!input_img.empty()) {


		cv::Mat left_img = input_img(mLUp_roi);
		cv::Mat right_img = input_img(mRUp_roi);

		/* Checking */

		/* Left */

		Isfound_defective_left = singleCheck(left_img.clone());

		float num1 = _neuralnet_right_->FAILED_EDGE*100;
		float num2 =_neuralnet_right_->PASSED_EDGE*100;
		float num3 =_neuralnet_right_->FAILED_INNER*100;
		float num4 = _neuralnet_right_->PASSED_INNER*100;

		emit on_send_prob_value(3, num1, num2, num3, num4);
		
		/* get position defect on edge */
		this->isLDown_edge = _neuralnet_right_->isEdgeFailed;
		this->LDown_edge_point = _neuralnet_right_->edgePos;
		this->LDown_radius = _neuralnet_right_->edgeRadius;

		_neuralnet_right_->clearResult_PERCENT();

		/* Right */
		Isfound_defective_right = singleCheck(right_img.clone());

		num1 = _neuralnet_right_->FAILED_EDGE*100;
		num2 =_neuralnet_right_->PASSED_EDGE*100;
		num3 =_neuralnet_right_->FAILED_INNER*100;
		num4 = _neuralnet_right_->PASSED_INNER*100;
		
		emit on_send_prob_value(4, num1, num2, num3, num4);
		
		/* get position defect on edge */
		this->isRDown_edge = _neuralnet_right_->isEdgeFailed;
		this->RDown_edge_point = _neuralnet_right_->edgePos;
		this->RDown_radius = _neuralnet_right_->edgeRadius;

		_neuralnet_right_->clearResult_PERCENT();

	}
		
	/* Display Module */

	if (Isfound_defective_left == true || Isfound_defective_right ==true ){
	/*	ui.textEdit->setText("Not Okay");*/

		return true;
	}
	else {
	/*	ui.textEdit->setText("OKay");*/

		return false;
	}
}

bool InspectingThread::Up_Checking(cv::Mat & input_img){

	/* Checking Module */
	bool Isfound_defective_left = false;
	bool Isfound_defective_right = false;
		
	if (!input_img.empty()) {


		cv::Mat left_img = input_img(mLUp_roi);
		cv::Mat right_img = input_img(mRUp_roi);

		/* Checking */

		/* Left */

		Isfound_defective_left = singleCheck(left_img.clone());

		float num1 = _neuralnet_right_->FAILED_EDGE*100;
		float num2 =_neuralnet_right_->PASSED_EDGE*100;
		float num3 =_neuralnet_right_->FAILED_INNER*100;
		float num4 = _neuralnet_right_->PASSED_INNER*100;

		emit on_send_prob_value(1, num1, num2, num3, num4);
		/* get position defect on edge */
		this->isLUp_edge = _neuralnet_right_->isEdgeFailed;
		this->LUp_edge_point = _neuralnet_right_->edgePos;
		this->LUp_radius = _neuralnet_right_->edgeRadius;

		_neuralnet_right_->clearResult_PERCENT();

		/* Right */
		Isfound_defective_right = singleCheck(right_img.clone());

		num1 = _neuralnet_right_->FAILED_EDGE*100;
		num2 =_neuralnet_right_->PASSED_EDGE*100;
		num3 =_neuralnet_right_->FAILED_INNER*100;
		num4 = _neuralnet_right_->PASSED_INNER*100;
		
		emit on_send_prob_value(2, num1, num2, num3, num4);
		
		/* get position defect on edge */
		this->isRUp_edge = _neuralnet_right_->isEdgeFailed;
		this->RUp_edge_point = _neuralnet_right_->edgePos;
		this->RUp_radius = _neuralnet_right_->edgeRadius;

		_neuralnet_right_->clearResult_PERCENT();

	}
		
	/* Display Module */

	if (Isfound_defective_left == true || Isfound_defective_right ==true ){
		/*ui.textEdit->setText("Not Okay");*/

		return true;
	}
	else {
		/*ui.textEdit->setText("OKay");*/

		return false;
	}
}
