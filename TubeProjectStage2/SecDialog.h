#pragma once

#include <QWidget>
#include <QtCore>
#include "ui_SecDialog.h"
#include <iostream>
#include "NeuralNetWork.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QFileSystemModel>

#define LOOKUPTABLESIZE 1000
#define MAGICNUMBER     999

using namespace std;

class SecDialog : public QWidget
{
	Q_OBJECT

public:
	SecDialog(QWidget *parent = Q_NULLPTR);
	~SecDialog();

	public slots:
	void on_btn_show_clicked(void);
	void on_btn_save_clicked(void);

	void on_btn_showNet_clicked(void);
	void on_btn_saveNet_clicked(void);

	void on_btn_createNet_clicked(void);
	void on_btn_reTrain_clicked(void);
	void on_btn_loadModelNet_clicked(void);
	void on_btn_predict_clicked(void);
	void on_btn_lookuptable_clicked(void);
	void on_btn_lookuptable2D_clicked(void);

	void on_btn_showFeatureIndex_clicked(void);
	void on_btn_showFeatureIndex2D_clicked(void);
public:
	int  getNumbeofFeatures(QString& text);
	void readFeaturefromTextFile1D(QString text);
	void readFeaturefromTextFile2D(QString text);
	void readNeuralNetfromTextFile(QString fileName);

	vector<int> getValfromFeature(QString& text);
	vector<int> getValfromNetwork(QString& text);
private:
	void initialLookUpTable1D(void);
	void initialLookUpTabel2D(void);

	void configForLookUpTable1D(void);
	void configForLookUpTable2D(void);
private:
	string nameOfFeature = "lookupfeature.xml";
	int numberOfFeature1D = 0;
	int numberOfFeature2D = 0;
	vector<int> layers;
	vector<int> maximum_val_1D;
	vector<vector<int>> features1D;
	vector<vector<int>> features2D;
	vector<int> lookUpTable1D;
	vector<int> lookUpTable1Dto2D;
	vector<vector<int>> lookUpTable2D;
private:
	NeuralNetWork neuralNetWork;
private:
	Ui::SecDialog ui;

};
