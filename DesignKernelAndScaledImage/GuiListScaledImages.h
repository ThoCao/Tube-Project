#pragma once

#include <QWidget>
#include "ui_GuiListScaledImages.h"
#include <QtCore>
#include "opencv2\opencv.hpp"
#include <iostream>

#define _show(img) cv::imshow(#img,img);
#define _wait(ms) cv::waitKey(ms);

class GuiListScaledImages : public QWidget
{
	Q_OBJECT

public:
	GuiListScaledImages(QWidget *parent = Q_NULLPTR);
	~GuiListScaledImages();
public:
	std::vector<int> getListScaleImages() { return this->lists; };
	void setImage(cv::Mat& image) { image.copyTo(this->kernel_img); };

private:
	Ui::GuiListScaledImages ui;
	public slots:
	void on_btn_read_clicked(void);
	void on_btn_save_clicked(void);
	void on_btn_createkernel_clicked(void);
	void on_btn_savekernel_clicked(void);
	void on_btn_showimage_clicked(void);
	void on_btn_savelistkernel_clicked(void);
	void on_btn_showlistimage_clicked(void);
	void on_btn_maxpooling_clicked(void);
private:
	void readListScaledImage(QString fileName);
	void readKernelMask(QString& fileName);
	int getNumList(QString text);
	std::vector<int> getValuefromList(QString& text);

private:
	cv::Mat getMaxPooling(cv::Mat& data, const int _size);

private:
	std::vector<int> lists;
	std::vector<std::vector<int>> kernel;
	cv::Mat kernelMat;
	std::vector<cv::Mat> listKernels;
	cv::Mat kernel_img;

	std::string nameListKernel = "kernels.xml";
	QString kernekName = "kernel3x3.txt";
	QString listName = "listscaled.txt";
};
