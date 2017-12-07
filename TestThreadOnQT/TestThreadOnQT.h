#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestThreadOnQT.h"
#include <QtCore>
#include <QDebug>
#include <QtConcurrent>
#include "MyThread.h"




class MyThread;



class TestThreadOnQT : public QMainWindow
{
	Q_OBJECT

public:
	TestThreadOnQT(QWidget *parent = Q_NULLPTR);

	~TestThreadOnQT();

signals:
	void on_StopThread();
	void on_OpenCam();
	void on_CloseCam();

	public slots:
	void on_btn_openThread_clicked(void);
	void on_btn_closeThread_clicked(void);
	void on_btnOpenCam_clicked(void);
	void on_btnCloseCam_clicked(void);

	public slots:
	void newNumber(QString name, cv::Mat image1,cv::Mat image2);

private:
	MyThread mThread;


private:
	Ui::TestThreadOnQTClass ui;

};
