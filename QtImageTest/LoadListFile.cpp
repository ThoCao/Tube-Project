#include "LoadListFile.h"

LoadListFile::LoadListFile(QWidget *parent): QObject(parent)
{
	
}

LoadListFile::~LoadListFile()
{
}

QStringList LoadListFile::getListImages(QString folderName)
{

	QString dirPath = folderName;
	QDir sys_Dir(dirPath);
	QStringList listImages = sys_Dir.entryList(QDir::NoDotAndDotDot | QDir::Files);
	return listImages;
}
