#include "GuiHomeWork1.h"

GuiHomeWork1::GuiHomeWork1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void GuiHomeWork1::on_btn_LoadImage_clicked(void)
{

	/* Get name of The Image */
	QString fileName = QFileDialog::getOpenFileName(this, tr("TIFF (*.tif);; All files (*.*)"));

	string image_name = fileName.toStdString();

	cv::Mat load_img = imread(image_name,1);
	if (load_img.empty()) return;

	load_img = getImage(load_img.clone());

	ui.label->setImage(load_img);
}

cv::Mat GuiHomeWork1::getImage(cv::Mat & image){
	
	cv::Mat color_img = image.clone();

	if ( color_img.empty()) return color_img;

	cv::Mat gray_img;

	/* Convert To Gray Scale */
	cvtColor(color_img, gray_img, CV_BGR2GRAY);
	/* Edge Detection */
	Canny(gray_img, gray_img, 100, 200, 5);
	/* Find Contour */
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	RNG rng(12345);
	findContours(gray_img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	for (unsigned int id = 0; id < contours.size();id++) {

		

		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(color_img, contours, id, color, 5, 8, hierarchy, 0, Point());

		/* Approximate the Contour */
		double peri = arcLength(contours[id], true);
		vector<Point> approx;
		approxPolyDP(contours[id], approx, EPSILON*peri, true);

		/* Calculate Angle */
		for (unsigned int id2 = 0; id2 < approx.size(); id2++) {
			
			int mpos = id2;
			int fpos = id2 - 1;
			int lpos = id2 + 1;

			if (fpos < 0) fpos = approx.size() - 1;
			if (lpos >= approx.size()) lpos = 0;

		    float angle = getAngle(QPoint(approx[fpos].x, approx[fpos].y),QPoint(approx[mpos].x, approx[mpos].y),  QPoint(approx[lpos].x, approx[lpos].y));

			
			string value = to_string((int)angle);

			putText(color_img, value, approx[mpos], 1, 2, { 255,0,0}, 2);
		}
	}
	return color_img;
}

float GuiHomeWork1::getAngle(QPoint _p1, QPoint _p2, QPoint _p3){

	QLineF first_line(_p1, _p2);
	QLineF sencond_line(_p3, _p2);

	float real_angle = first_line.angle(sencond_line);

	return real_angle;
}
