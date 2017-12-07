#pragma once

#include <QWidget>
#include "ui_GuiNeuralNetwork.h"
#include <opencv2\opencv.hpp>
#include <opencv2\ml.hpp>

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
	// C++ Method
private:
	std::string namemodel_ = "modelNeural";
	cv::Mat trainningmat_;
	cv::Mat labelmat_;
	cv::Ptr<cv::ml::ANN_MLP> m_mlp_;
	std::vector<float> _input;
	bool result = false;
public:
	void LoadDateSet(std::string  fileName);
	void TrainingModel(void);
	void ReTrainModel(void);
	void LoadingModel(void);
	cv::Mat neuralChecking(cv::Mat & input);

	void setInput(std::vector<int> & data);
	bool getResultFromNeural();
};
