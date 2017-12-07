#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "SecDialog.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

	private slots:
	void on_btnNeuralNet_clicked(void);
private:
	SecDialog * neuralNetwork;
private:
	Ui::MainWindowClass ui;
};
