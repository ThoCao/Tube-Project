#include "TestThreadOnQT.h"
#include <QtWidgets/QApplication>


Q_DECLARE_METATYPE(cv::Mat)

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	

	TestThreadOnQT w;
	w.show();
	return a.exec();
}
