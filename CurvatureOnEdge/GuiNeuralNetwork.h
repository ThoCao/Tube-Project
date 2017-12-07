#pragma once

#include <QWidget>
#include <QFileDialog>
#include <QInputDialog>
#include <QFileSystemModel>
#include "ui_GuiNeuralNetwork.h"
#include <opencv2\opencv.hpp>
#include <opencv2\ml.hpp>
#include "GuiDataSet.h"
#include "PreProcessing.h"

typedef std::vector<std::vector<float>> Inputs;
typedef std::vector<float> Input;
typedef std::vector<std::vector<cv::Point>> Contours;

class GuiNeuralNetwork : public QWidget
{
	Q_OBJECT

public:
	GuiNeuralNetwork(QWidget *parent = Q_NULLPTR);
	~GuiNeuralNetwork();

private:
	Ui::GuiNeuralNetwork ui;
	// QT method
	public slots:
	void on_btn_ReTrainNet_clicked(void);
	void on_btn_LoadModelNet_clicked(void);
	void on_btn_Predict_clicked(void);
	void on_btn_allpredict_clicked(void);
	void on_btn_newretrainnet_clicked(void);
	// C++ Method
private:
	std::string namemodel_ = "modelNeural3_10_2_";
	cv::Mat trainningmat_;
	cv::Mat labelmat_;
	cv::Ptr<cv::ml::ANN_MLP> m_mlp_;
	Input  _input;
	Inputs _allInput;
	Contours _allContour;
	bool result = false;
	cv::Mat _image_img;

private:
	void normalizeInputData(std::vector<float> &_data);
public:
	void LoadDateSet(std::string  fileName);
	void TrainingModel(void);
	void ReTrainModel(std::string modelName);
	void LoadingModel(std::string modelName);
	cv::Mat neuralChecking(cv::Mat & input);


	void setImage(cv::Mat& _image);
	
	bool getResultFromNeural();
	bool preDictAllInput(Inputs& _data);
	bool getResultOnEdge(Circles& _circle_edges);
};
