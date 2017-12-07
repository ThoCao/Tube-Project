#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),neuralNetwork(new SecDialog())
{
	ui.setupUi(this);
}

void MainWindow::on_btnNeuralNet_clicked(void){
	this->neuralNetwork->show();
}
