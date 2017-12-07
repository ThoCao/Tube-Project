#include "QtCurvature.h"

QtCurvature::QtCurvature(QWidget *parent)
	: QWidget(parent), dataSet(new GuiDataSet)
{
	ui.setupUi(this);
	// show Gui
	dataSet->show();
}

QtCurvature::~QtCurvature()
{
}

void QtCurvature::setImage(cv::Mat & data){
	data.copyTo(this->original_img);
}

void QtCurvature::setCircles(std::vector<Circle>& data){
	this->setCircle.clear();
	for (auto c : data) {
		this->setCircle.push_back(c);
	}
}

void QtCurvature::transformation(Contour & _data,cv::Point& _center){
	// get center
	cv::Moments mu = cv::moments(_data,false);
	float px = mu.m10 / mu.m00 - _center.x;
	float py = mu.m01 / mu.m00 - _center.y;
	// get angle
	float angle = atan2f(py, px) + CV_PI/2;
	// get rotate matrix
	float sina = sin(angle);
	float cosa = cos(angle);
	// transform data
	for (auto& p : _data) {
		float px_ = p.x - _center.x;
		float py_ = p.y - _center.y;
		float npx_ = px_*cosa + py_*sina;
		float npy_ = -px_*sina + py_*cosa;

		p.x = npx_ +_center.x;
		p.y = npy_ +_center.y;
	}
}

void QtCurvature::setAllFeature(){

	std::vector<vector<float>> allFeature;
	std::vector<Contour> allContour;
	// segment vector inner and outer
	const float scaled_factor = abs(setCircle[0].R - setCircle[1].R) / 2;
    const int size_feature = ui.spin_size->value();
	for (auto contour : setCircle) {
		const int max_index = contour.contour.size() / size_feature;
		for (auto index = 0; index < max_index; index++) {

			const int start = index*size_feature / 2;
			const int end = start + size_feature;
			const int step_size = 2;
			Contour setPoints;
			for (auto id = start; id + step_size < end; id += step_size) {
				setPoints.push_back(contour.contour[id]);
			}
			// feature
			if (setPoints.size() == size_feature / 2 - 1) {
				std::vector<float> feature_;
				/* fix value */
				float epsilon = 0.9;// *cv::arcLength(setPoints, false);
				Contour approx;
				cv::approxPolyDP(setPoints, approx, epsilon,false);
				/* Area Feature */
				cv::RotatedRect rect = cv::minAreaRect(approx);

				/* Deviation Feature*/
				double sum_up = 0;
				std::vector<double> radius;
				for (auto p : setPoints) {
					double tmp = cv::norm(p - (cv::Point)contour.rect.center);
					radius.push_back(tmp);
					sum_up += tmp;
				}
				double avr_val = sum_up / radius.size();
				double error = 0;
				for (auto p : radius) {
					double tmp = (p - avr_val)*(p-avr_val);
					error += tmp;
				}

				float feature3 = std::sqrtf(error);
				
				feature_.push_back(approx.size());
				feature_.push_back(rect.size.area());
				feature_.push_back(feature3);

				// normalize
				dataSet->normalizeInputDataV2(feature_);
				// push back
				allFeature.push_back(feature_);
				allContour.push_back(setPoints);
			}
		}

	}

}


void QtCurvature::drawContour(cv::Mat & _image, Contour & _data){
	for (auto id = 0; id + 1 < _data.size(); id++) {
		cv::line(_image, _data[id], _data[id + 1], { 200,100,200 }, 3);
	}
}

void QtCurvature::on_btn_savedata_clicked(void){
	vector<int> label;
	if (ui.check_passed->isChecked()) {
		label.push_back(1);
		label.push_back(0);
	}
	else {
		label.push_back(0);
		label.push_back(1);
	}

	m_feature.label = label;
	//
	dataSet->m_predata.push_back(m_feature);
	
}

void QtCurvature::on_btn_clearolddata_clicked(void){
	dataSet->m_predata.clear();
}

void QtCurvature::on_btn_showImage_clicked(void) {

	/* Get Contour*/
	int index = ui.spin_index->value();
	ui.spin_index->setValue(index + 1);
	int sizePoint = ui.spin_size->value();
	cv::Mat contour_img;
	this->original_img.copyTo(contour_img);

	int idx = 0;
	if (ui.radio_outer->isChecked())idx = 0;
	else  idx = 1;
	
	// get data
	int start = index*sizePoint;
	int end = start + sizePoint;
	Contour setPoints;
	const int step_size = 2;
	for (auto id = start; id + step_size < end;id+=step_size) {

		if (id + step_size >= setCircle[idx].contour.size()) break;
		cv::line(contour_img, setCircle[idx].contour[id], setCircle[idx].contour[id + step_size], { 100,250,100 }, 2);
		setPoints.push_back(setCircle[idx].contour[id]);
	}
	/* End Geting Contour */

#pragma endregion Ending

	/* New Algorihtm here */
	if (setPoints.size() != 49) return;
	/* Approximate Contour */ // good feature
	/* fix value */
	float epsilon = 0.9;// *cv::arcLength(setPoints, false);
	Contour approx;
	cv::approxPolyDP(setPoints, approx, epsilon,false);
	/* Area Feature */
	cv::RotatedRect rect = cv::minAreaRect(approx);

	/* Deviation Feature*/
	double sum_up = 0;
	std::vector<double> radius;
	for (auto p : setPoints) {
		double tmp = cv::norm(p - (cv::Point)setCircle[idx].rect.center);
		radius.push_back(tmp);
		sum_up += tmp;
	}
	double avr_val = sum_up / radius.size();
	double error = 0;
	for (auto p : radius) {
		double tmp = (p - avr_val)*(p-avr_val);
		error += tmp;
	}

	float feature3 = std::sqrtf(error);


	/* Save Features */
	std::vector<float> feature_;
	feature_.push_back(approx.size());
	feature_.push_back(rect.size.area());
	feature_.push_back(feature3);
	/*feature_.push_back(feature4);*/

	
	dataSet->normalizeInputDataV2(feature_);
	m_feature.feature = feature_;

	/* Out Feature */
	for (auto p : feature_) std::cout << p << " ";
	std::cout << std::endl;

	cv::imshow("here contour", contour_img);
	_wait(10);
}
