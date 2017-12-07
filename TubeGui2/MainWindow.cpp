#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)/*,_pointgrey_camera_(new PointGreyCamera),_preProcessing_(new PreProcessing),
	_preProcessongData_(new PreProcessingData),_neuralnet_right_(new NeuralNets),_basler_cam_(new BaslerCam)*/
{
	ui.setupUi(this);
	/* Camera Module*/

	/* Neural Network Module*/

	/* Precessing Module */

	/* Runing Module */
	/*connect(_cameraTimer_, SIGNAL(timeout()), this, SLOT(runFunction()));*/

	/* User Module */
	/*loadRoiData();*/
}

void MainWindow::on_cameraOpen_clicked(void){

	

	///* poingrey */
	//if (_pointgrey_camera_->OpenCam()) {
	//	ui.textEdit->setText("Open PointGrey Camera Successed!");
	//}
	//else {
	//	ui.textEdit->setText("Failed To Open PointGrey Camera!");
	//}

	///* Basler*/
	//if (_basler_cam_->OpenCam()) {
	//	ui.textEdit->setText("Open Basler Camera Successed!");
	//}
	//else {
	//	ui.textEdit->setText("Failed To Open Basler Camera!");
	//}
	//
	///* Active Timer */
	//if (_cameraTimer_->isActive()) {
	//	_cameraTimer_->stop();
	//}
	//else {
	//	_cameraTimer_->start(TIMER_CAM);
	//}

	///* Delay */
	//_wait(1000);


	emit on_OpenCam();
}

MainWindow::~MainWindow(){
	emit on_StopThread();
}


void MainWindow::on_check_clicked(void){


	if (isFirstCheckingClick == false) {
		
		/* Checking Module */
		qRegisterMetaType<cv::Mat>("cv::Mat");
		connect(&mThread, &InspectingThread::on_send_image_v1, this, &MainWindow::getImageFromThread);

		connect(&mThread, &InspectingThread::on_send_prob_value, this, &MainWindow::getProbValue);
		connect(this, &MainWindow::on_StopThread, &mThread, &InspectingThread::stopThread);

		/* Control Camera */
		connect(this, &MainWindow::on_OpenCam, &mThread, &InspectingThread::openCam);
		connect(this, &MainWindow::on_CloseCam, &mThread, &InspectingThread::closeCam);
		/* Control USER Roi*/
		connect(this, &MainWindow::on_OpenUserRoi, &mThread, &InspectingThread::openRoiUser);

		/* Making New Thread */
		QFuture<void> test = QtConcurrent::run(&this->mThread, &InspectingThread::Inspecting, QString("Thread1"));
		

		isFirstCheckingClick = true;
		ui.check->setText("Stop");
	}
	else {
		emit on_StopThread();

		isFirstCheckingClick = false;
		ui.check->setText("Check");
	}
	
	

}

void MainWindow::getImageFromThread(unsigned int _id, cv::Mat _image){

	switch (_id)
	{
	case 0:
		ui.LUpImage->setImage(_image);
		break;
	case 1:
		ui.RUpImage->setImage(_image);
		break;
	case 2:
		ui.LDownImage->setImage(_image);
		break;
	case 3:
		ui.RDownImage->setImage(_image);
		break;
	default:
		break;
	}
}

void MainWindow::getProbValue(int id, float num1, float num2, float num3, float num4){
	if (id == 1) {// left - right 
		ui.edge_failed_left->setValue(num1);
		ui.edge_passed_left->setValue(num2);
		ui.inner_failed_left->setValue(num3);
		ui.inner_passed_left->setValue(num4);
	}
	else if (id == 2) {
		ui.edge_failed_right->setValue(num1);
		ui.edge_passed_right->setValue(num2);
		ui.inner_failed_right->setValue(num3);
		ui.inner_passed_right->setValue(num4);
	}
	else if (id == 3) {
		ui.edge_failed_left_2->setValue(num1);
		ui.edge_passed_left_2->setValue(num2);
		ui.inner_failed_left_2->setValue(num3);
		ui.inner_passed_left_2->setValue(num4);
	}
	else if (id == 4) {
		ui.edge_failed_right_2->setValue(num1);
		ui.edge_passed_right_2->setValue(num2);
		ui.inner_failed_right_2->setValue(num3);
		ui.inner_passed_right_2->setValue(num4);
	}
}

/* End Camera Module */

/* User Module */

void MainWindow::on_btn_LUpPassed_clicked(void){
	if (!mLUpimg.empty()) {
		QString date_time = QTime::currentTime().toString();
		SaveImage(date_time, "_image.bmp",mLUpimg.clone(), true);
	}
}

void MainWindow::on_btn_LUpFailed_clicked(void)
{
	if (!mLUpimg.empty()) {
		QString date_time = QTime::currentTime().toString();
		SaveImage(date_time, "_image.bmp",mLUpimg.clone(), false);
	}
}

void MainWindow::on_btn_RUpPassed_clicked(void){
	
	if (!mRUpimg.empty()) {
		QString date_time = QTime::currentTime().toString();
		SaveImage(date_time, "_image.bmp",mRUpimg.clone(), true);
	}
}

void MainWindow::on_btn_RUpFailed_clicked(void){
	
	if (!mRUpimg.empty()) {
		QString date_time = QTime::currentTime().toString();
		SaveImage(date_time, "_image.bmp",mRUpimg.clone(), false);
	}
}

void MainWindow::on_btn_LDownPassed_clicked(void)
{
	if (!mLDownimg.empty()) {
		QString date_time = QTime::currentTime().toString();
		SaveImage(date_time, "_image.bmp",mLDownimg.clone(), true);
	}
}

void MainWindow::on_btn_LDownFailed_clicked(void){
	
	if (!mLDownimg.empty()) {
		QString date_time = QTime::currentTime().toString();
		SaveImage(date_time, "_image.bmp",mLDownimg.clone(), false);
	}
}

void MainWindow::on_btn_RDownPassed_clicked(void){
	
	if (!mRDownimg.empty()) {
		QString date_time = QTime::currentTime().toString();
		SaveImage(date_time, "_image.bmp",mRDownimg.clone(), true);
	}
}

void MainWindow::on_btn_RDownFailed_clicked(void){
	
	if (!mRDownimg.empty()) {
		QString date_time = QTime::currentTime().toString();
		SaveImage(date_time, "_image.bmp",mRDownimg.clone(), false);
	}
}

/* End of User Module */

void MainWindow::on_btn_OpenRoi_clicked(void){
	/* Up Camera */
	if (ui.isUpCamera->isChecked()) {
		emit on_OpenUserRoi(UP_CAMERA);
	}
	/* Down Camera */
	if (ui.isDownCamera->isChecked()) {
		emit on_OpenUserRoi(DOWN_CAMERA);
	}
}

char * MainWindow::MyMakeFolder(QString nameFolder)
{
	QByteArray l_byteName = nameFolder.toLocal8Bit();
	char *l_pathname = l_byteName.data();

	// Edited by Tho
	QDir makeFolder(nameFolder);
	if (!makeFolder.exists()) {
		makeFolder.mkpath(".");
	}
	//else QMessageBox::critical(this, "Create Folder ", "This Folder Already Avalible: ");
	return l_pathname;
}

void MainWindow::SaveImage(QString saveName, QString tailName, cv::Mat & image, bool flag){
	QString folderName;

	QDate date = QDate::currentDate();

	if (flag == true) {
		folderName = "Data/" + date.toString("yyyy.MM.dd") + "/OKAY";
	}
	else {
		folderName = "Data/" + date.toString("yyyy.MM.dd") + "/NotOKAY";
	}
	folderName.remove(" ");
	MyMakeFolder(folderName);

	QString fileName = date.toString("yyyy.mm.dd") + "_" + saveName + "_" + tailName;

	fileName.remove(" ");
	fileName.remove(":");

	fileName = folderName + "/" + fileName;
	cv::imwrite(tailName.toStdString(), image);

	QFile t_file(fileName);
	QPixmap pixmap(tailName);
	pixmap.save(fileName);

	QFile file(tailName);
	file.remove();
}

/* Run Module */
