#pragma once

#include <QDialog>
#include "ui_RoiGUI.h"
#include <qdebug.h>
#include "opencv2\opencv.hpp"

#define SCALED_W 1280
#define SCALED_H 1024


class RoiGUI : public QDialog
{
	Q_OBJECT

public:
	RoiGUI(QWidget *parent = Q_NULLPTR);
	~RoiGUI();
	

private:
	cv::Mat mImage;
	QPoint mFirstPoint;
	QPoint mSecondPoint;
	bool isFirst = false;
	cv::Rect mRect;
	bool isUpCamera = true;
	
	cv::Rect2d mLDown_roi;
	cv::Rect2d mRDown_roi;

	cv::Rect2d mLUp_roi;
	cv::Rect2d mRUp_roi;
	std::string _roi_data_name_ = "roi.xml";	

public:
	void setImage(cv::Mat & image, bool flag);
private:
	/* Init Modulde */
	void loadRoiData(void);
protected:
	bool eventFilter(QObject *obj, QEvent * ev);
public slots:
	void on_btnSaveRoi_clicked(void);

protected:
	void reject() override;
signals:
	bool reLoadData();
private:
	Ui::RoiGUI ui;
};
