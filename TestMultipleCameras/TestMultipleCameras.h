#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestMultipleCameras.h"
#include <QtCore>
#include <QDebug>
#include "RoiGUI.h"
#include "PointGreyCamV2.h"

#define imagewindow "WINDOW"
#define SCALED_W 1280
#define SCALED_H 1024

#define SHOW_W 500
#define SHOW_H 500

#define UP_CAMERA 1
#define DOWN_CAMERA 0

class TestMultipleCameras : public QMainWindow
{
	Q_OBJECT

public:
	TestMultipleCameras(QWidget *parent = Q_NULLPTR);

public slots:
	void on_btnOpenCam_clicked(void);
	void on_btnCloseCam_clicked(void);
	void on_btnShowImage_clicked(void);
	void on_btnShowRoi_clicked(void);

private:
	Ui::TestMultipleCamerasClass ui;

	RoiGUI mRoi;


	PointGreyCamV2 mCameras;
};
