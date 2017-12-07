#include "ImgView.h"

ImgView::ImgView(QWidget *parent)
	: QLabel(parent)
{

}

ImgView::~ImgView()
{

}

void ImgView::setImage(cv::Mat& image){
	//if(img.rows>512||img.cols>512);
	/*v::Mat image;
	if (width()<30)return;
	float r = cv::min(width() / (float)img.cols, height() / (float)img.rows)*0.95;
	cv::resize(img, image, cv::Size(), r, r);*/
	//pyrDown(img,image,Size(image.cols/2,image.rows/2));
	if (image.type() == CV_8UC1){
		QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_Indexed8);
		setPixmap(QPixmap::fromImage(qimg));
	}
	else {
		cvtColor(image, image, CV_BGR2RGB);
		QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
		setPixmap(QPixmap::fromImage(qimg));
	}
}
void ImgView::setImageScaled(cv::Mat & img){
	if(img.rows>512||img.cols>512);
	cv::Mat image;
	if (width()<30)return;
	float r = cv::min(width() / (float)img.cols, height() / (float)img.rows)*0.95;
	cv::resize(img, image, cv::Size(), r, r);
	//pyrDown(img,image,Size(image.cols/2,image.rows/2));
	if (image.type() == CV_8UC1) {
		QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_Indexed8);
		setPixmap(QPixmap::fromImage(qimg));
	}
	else {
		cvtColor(image, image, CV_BGR2RGB);
		QImage qimg(image.data, image.cols, image.rows, image.step, QImage::Format_RGB888);
		setPixmap(QPixmap::fromImage(qimg));
	}
}
void ImgView::setImage(QImage& image){
	image = image.scaledToWidth(width());
	setPixmap(QPixmap::fromImage(image));
}