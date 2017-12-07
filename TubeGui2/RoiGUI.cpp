#include "RoiGUI.h"

RoiGUI::RoiGUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.label->installEventFilter(this);

	/* load data */
	loadRoiData();
}

RoiGUI::~RoiGUI()
{

}

void RoiGUI::setImage(cv::Mat & image, bool flag){

	image.copyTo(this->mImage);
	cv::resize(mImage, mImage, { SCALED_W / 2,SCALED_H / 2 });
	ui.label->setImage(mImage);
	// flag
	this->isUpCamera = flag;
}

void RoiGUI::loadRoiData(void){
	
	cv::FileStorage fs(_roi_data_name_, cv::FileStorage::READ);

	fs["left_R"] >> mLUp_roi;
	fs["right_R"] >> mRUp_roi;

	fs["left_L"] >> mLDown_roi;
	fs["right_L"] >> mRDown_roi;
	fs.release();
}

bool RoiGUI::eventFilter(QObject * obj, QEvent * ev){


	if (obj = ui.label) {

		if (ev->type() == QEvent::MouseButtonPress) {
			
			if (isFirst == false) {
				const QMouseEvent* const me_ptr = static_cast<const QMouseEvent*>(ev);
				mFirstPoint = me_ptr->pos();
				isFirst = true;
			}
			
		}
		else if (ev->type() == QEvent::MouseButtonRelease) {
			const QMouseEvent* const me_ptr = static_cast<const QMouseEvent*>(ev);
			mSecondPoint = me_ptr->pos();
		}
		else if (ev->type() == QEvent::MouseMove) {
			if (isFirst == true) {
				const QMouseEvent* const me_ptr = static_cast<const QMouseEvent*>(ev);
				mSecondPoint = me_ptr->pos();

				cv::Rect rect = cv::Rect();
				rect.x = mFirstPoint.x();
				rect.y = mFirstPoint.y();

				rect.width = abs(mFirstPoint.x() - mSecondPoint.x());
				rect.height = abs(mFirstPoint.y() - mSecondPoint.y());

				/* Get Rectange */
				mRect.x = rect.x*2;
				mRect.y = rect.y * 2;
				mRect.width = rect.width * 2;
				mRect.height = rect.height * 2;

				cv::Mat img = mImage.clone();
				cv::rectangle(img, rect, { 255,0,0 }, 2);
				ui.label->setImage(img);

			}
		}
		else if (ev->type() == QEvent::MouseButtonDblClick) {
			isFirst = false;
		}
		

		return 0;
	}
	else return RoiGUI::eventFilter(obj, ev);
	
}

void RoiGUI::reject(){
	emit reLoadData();
	QDialog::reject();
}


void RoiGUI::on_btnSaveRoi_clicked(void){

		
	std::string _roi_data_name_ = "roi.xml";

	if (isUpCamera) {
		if (ui.isOne->isChecked()) {
			mLUp_roi = mRect;
		}
		else if(ui.isTwo->isChecked()){
			mRUp_roi = mRect;
		}
	}
	else
	{
		if (ui.isOne->isChecked()) {
			mLDown_roi = mRect;
		}
		else if(ui.isTwo->isChecked()) {
			mRDown_roi = mRect;
		}
	}

	/* Save to File */
	cv::FileStorage fs(_roi_data_name_, cv::FileStorage::WRITE);

	fs << "left_R" << mLUp_roi;
	fs << "right_R" << mRUp_roi;
	fs << "left_L" << mLDown_roi;
	fs << "right_L" << mRDown_roi;
	fs.release();
}
