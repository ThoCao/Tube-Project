#pragma once

#include <QWidget>
#include "ui_GuiDataSet.h"
#include "opencv2\opencv.hpp"
#include <random>
#include <array>
#include <algorithm>
#include <chrono>


#define MAX_VAL 5;
#define MAX_AREA 2500;
#define MAX_APPROX 30;
#define MAX_DEVIATION 100;

#define FEATURE_SIZE 49
#define POINT_SIZE 100
#define POINT_SIZE 100

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
	void saveData(string fileName,std::vector<feature>& m_data,bool flag_old);
	void normolizeInputData(std::vector<float> &data);
	void normalizeInputDataV2(std::vector<float> &_data);
public:
	void setInputandOutPutSize(int input, int output);
public:
	void shuffleData(std::vector<feature> & m_data);
	public slots:
	void on_btn_savedata_clicked(void);
	void on_btn_retraindata_clicked(void);
	void on_btn_postsave_clicked(void);
	void on_btn_savenewdata_clicked(void);
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
