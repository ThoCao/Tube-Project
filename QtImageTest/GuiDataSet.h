#pragma once

#include <QWidget>
#include "ui_GuiDataSet.h"
#include "opencv2\opencv.hpp"
#include <random>
#include <array>
#include <algorithm>
#include <chrono>


using namespace std;
struct MyFeature
{
	std::vector<float> feature;
	std::vector<int> label;
};

typedef MyFeature feature;

class GuiDataSet : public QWidget
{
	Q_OBJECT

public:
	GuiDataSet(QWidget *parent = Q_NULLPTR);
	~GuiDataSet();
public:
	void saveData(string fileName,std::vector<feature>& m_data);
public:
	void setInputandOutPutSize(int input, int output);
public:
	void shuffleData(std::vector<feature> & m_data);
	public slots:
	void on_btn_savealldata_clicked(void);
	void on_btn_retraindata_clicked(void);
	void on_btn_postsave_clicked(void);
public:
	std::vector<feature> m_predata;
	std::vector<feature> m_posdata;
private:
	string file_train_ = "trainmat.xml";
	string file_reTrain = "retrainmat.xml";
	cv::Mat prev_trainmat_;
	cv::Mat prev_labelmat_;
	int _inPutSize = 0;
	int _outPutSize = 0;
private:
	Ui::GuiDataSet ui;
};
