#include "TestThreadOnQT.h"


TestThreadOnQT::TestThreadOnQT(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	
}





TestThreadOnQT::~TestThreadOnQT() {

	emit on_StopThread();
}



void TestThreadOnQT::on_btn_openThread_clicked(void)
{

	
	qRegisterMetaType<cv::Mat>("cv::Mat");
	/* Main Thread and Camera Thread */
	connect(&mThread, &MyThread::on_number, this, &TestThreadOnQT::newNumber);
	connect(this, &TestThreadOnQT::on_StopThread, &mThread, &MyThread::stop);
	/* Camera Thread Connection */
	connect(this, &TestThreadOnQT::on_OpenCam, &mThread, &MyThread::openCam);
	connect(this, &TestThreadOnQT::on_CloseCam, &mThread, &MyThread::closeCam);


	/* Making new Thread */
	QFuture<void> test = QtConcurrent::run(&this->mThread, &MyThread::start, QString("thocao"));

}


void TestThreadOnQT::on_btn_closeThread_clicked(void)
{
	emit on_StopThread();
	cv::destroyWindow("thocao");
}

void TestThreadOnQT::on_btnOpenCam_clicked(void){
	emit on_OpenCam();
}

void TestThreadOnQT::on_btnCloseCam_clicked(void){
	emit on_CloseCam();
}


void TestThreadOnQT::newNumber(QString name, cv::Mat image1,cv::Mat image2) {

	cv::resize(image1, image1, { 500,500 });
	cv::resize(image2, image2, { 500,500 });

	ui.image1->setImage(image1);
	ui.image2->setImage(image2);
}

