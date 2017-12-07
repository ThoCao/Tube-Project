#pragma once

#include <QWidget>
#include "ui_QtCurvature.h"
#include "opencv2\opencv.hpp"
#include "PreProcessing.h"
#include "GuiDataSet.h"

class QtCurvature : public QWidget 
{
	Q_OBJECT

public:
	QtCurvature(QWidget *parent = Q_NULLPTR);
	~QtCurvature();
public:
	void setImage(cv::Mat& data);
	void setCircles(std::vector<Circle>& data);
	void transformation(Contour& _data,cv::Point& _center);
	void setAllFeature();

private:
	void drawContour(cv::Mat& _image, Contour& _data);

	public slots:
	void on_btn_showImage_clicked(void);
	void on_btn_savedata_clicked(void);
	void on_btn_clearolddata_clicked(void);
private:
	Ui::QtCurvature ui;
	GuiDataSet * dataSet;

private:
	cv::Mat original_img;
	std::vector<Circle> setCircle;
	std::vector<float> minRadius;
	feature m_feature;

	std::string fileName = "lookupangle.xml";
	std::string lookUpTableFileName = "lookupfeature.xml";
};
