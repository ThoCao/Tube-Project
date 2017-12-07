#ifndef IMGVIEW_H
#define IMGVIEW_H

#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QtWidgets/QLabel>
#include <opencv2\opencv.hpp>
#include <QtWidgets/QApplication>


class ImgView : public QLabel
{
	Q_OBJECT

public:
	ImgView(QWidget *parent=0);
	~ImgView();

private:
protected:
	virtual void mouseMoveEvent(QMouseEvent * ev){
		emit mouseMove(ev);
	}

	virtual void mousePressEvent(QMouseEvent * ev){
		emit mousePressed(ev);
	}

	virtual void mouseReleaseEvent(QMouseEvent * ev){
		emit mouseReleased(ev);
	}
public:
	void setImage(cv::Mat& img);
	void setImageScaled(cv::Mat &img);
	void setImage(QImage& image);
	inline void updateView(){
		qApp->processEvents();
	}
signals:
	void mousePressed(QMouseEvent* ev);
	void mouseReleased(QMouseEvent* ev);
	void mouseMove(QMouseEvent* ev);

private:
	bool first_click_;
public:
	int firstX;
	int firstY;
};

#endif // IMGVIEW_H
