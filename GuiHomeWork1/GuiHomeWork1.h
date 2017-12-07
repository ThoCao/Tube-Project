#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QInputDialog>
#include <QFileSystemModel>
#include "ui_GuiHomeWork1.h"
#include "opencv2\opencv.hpp"
#include <iostream>

#define EPSILON 0.04

using namespace std;
using namespace cv;

class GuiHomeWork1 : public QMainWindow
{
	Q_OBJECT

public:
	GuiHomeWork1(QWidget *parent = Q_NULLPTR);

private:
	Ui::GuiHomeWork1Class ui;

public slots:
	void on_btn_LoadImage_clicked(void);
private:
	cv::Mat getImage(cv::Mat & image);
	float getAngle(QPoint _p1, QPoint _p2, QPoint _p3);

};
