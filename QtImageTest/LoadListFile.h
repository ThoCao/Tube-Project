#pragma once

#include <QObject>
#include <QFileDialog>
#include <QInputDialog>
#include <QFileSystemModel>

class LoadListFile : public QObject
{
	Q_OBJECT

public:
	LoadListFile(QWidget *parent = 0);
	~LoadListFile();

public:
	QStringList getListImages(QString folderName);
};
