#include "TestMultipleCameras.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TestMultipleCameras w;
	w.show();
	return a.exec();
}
