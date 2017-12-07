#include "PreProcessing.h"


int PreProcessing::gaussian_val = 2;
float PreProcessing::epsilon_radius = 10;

PreProcessing::PreProcessing()
{
}


PreProcessing::~PreProcessing()
{
}



cv::Mat PreProcessing::preProcessingFunc(cv::Mat & input){
	/* White balance */
	cv::Mat g1, g2;
	/* Bluring */
	cv::GaussianBlur(input.clone(), g1, { 7,7 }, 2);
	cv::GaussianBlur(input.clone(), g2, { 15,15 }, 7);
	cv::Mat output = g2 - g1;

	cv::imshow("DoG image", output*10);
	/* Threshold */
	cv::threshold(output, output, this->gaussian_val, 255, cv::THRESH_BINARY);
	
	cv::imshow("Edge image", output);
	return output;
}


std::tuple<Circle, Circle,bool> PreProcessing::Find2CirclesFunc(const cv::Mat & input){
	// copy to input_img
	cv::imshow("color image", input);
	input.copyTo(this->input_img);	
	// get binary threshold
	cv::Mat gray_img;
	cv::cvtColor(input, gray_img, cv::COLOR_BGR2GRAY);
	this->binary_img = preProcessingFunc(gray_img.clone());
	// find contours
	this->contours.clear();
	this->contours = find_countours(this->binary_img.clone());
	// find best circle
	Circles circles = find_circles(this->contours);
	std::sort(circles.begin(), circles.end(), [](Circle& a, Circle& b) {return a.R > b.R; });
	find_clusters(circles);
	// Cluster circle
	Circles small_circles;
	Circles big_circles;
	for (auto& c : circles) {
		if (c.cluster == 1) big_circles.push_back(c);
		else if (c.cluster == 0) small_circles.push_back(c);
	}
	// Sorting
	std::sort(big_circles.begin(),  big_circles.end(), [](Circle& a, Circle&b) { return a.R < b.R; });
	std::sort(small_circles.begin(),small_circles.end(),[](Circle& a, Circle& b){ return a.R > b.R; });

#ifdef SHOWSIGNAL
	// draw contour belong to small & big circle
	if (big_circles.size() > 0 && small_circles.size() > 0) {
		// big
		for (auto id = 0; id < big_circles[0].contour.size() - 1; id++) {
			cv::line(this->input_img, big_circles[0].contour[id], big_circles[0].contour[id + 1], { 100,200,100 }, 2);
		}
		for (auto id = 0; id < small_circles[0].contour.size() - 1; id++) {
			cv::line(this->input_img, small_circles[0].contour[id], small_circles[0].contour[id + 1], { 100,100,200 }, 2);
		}

	}
#endif // SIGNAL

	// return value
	if (big_circles.size() > 0 && small_circles.size() > 0) {
		return std::make_tuple(big_circles[0], small_circles[0],true);
	}
	else return std::tuple<Circle,Circle,bool>();

}

bool PreProcessing::IsFoundCircle(const cv::Mat & input){

	bool IsFound = false;
	
	// copy to input_img
	input.copyTo(this->input_img);	
	// get binary threshold
	cv::Mat gray_img;
	cv::cvtColor(input, gray_img, cv::COLOR_BGR2GRAY);
	this->binary_img = preProcessingFunc(gray_img.clone());
	// find contours
	this->contours.clear();
	this->contours = find_countours(this->binary_img.clone());
	// find best circle
	Circles circles = find_circles(this->contours);
	std::sort(circles.begin(), circles.end(), [](Circle& a, Circle& b) {return a.R > b.R; });
	find_clusters(circles);
	
	// Cluster circle
	Circles small_circles;
	Circles big_circles;
	for (auto& c : circles) {
		if (c.cluster == 1) big_circles.push_back(c);
		else if (c.cluster == 0) small_circles.push_back(c);
	}
	
	// Sorting
	std::sort(big_circles.begin(),  big_circles.end(), [](Circle& a, Circle&b) { return a.R < b.R; });
	std::sort(small_circles.begin(),small_circles.end(),[](Circle& a, Circle& b){ return a.R > b.R; });


	// return value
	if (big_circles.size() > 0 && small_circles.size() > 0) {
		IsFound = true;
	
	}
	return IsFound;
}

void PreProcessing::showContourOutlier(void){
	if (!this->input_img.empty()) {
		_show(this->input_img);
		_wait(10);
	}
}

void PreProcessing::drawContourOnTube(Circle & outer_edge, Circle & inner_edge){

	// epsilon raidus
	const float epsilon_radius = 3;
	const float epsilon_differential = abs(outer_edge.R - inner_edge.R)*0.35;
	for (auto id = 0; id < this->contours.size(); id++) {
		int pos = contours[id].size() / 2;
		float outer_radius = cv::norm(this->contours[id][pos] - (cv::Point)outer_edge.rect.center);
		float inner_radius = cv::norm(this->contours[id][pos] - (cv::Point)inner_edge.rect.center);

		if (outer_radius > (outer_edge.R - epsilon_radius) || inner_radius < (inner_edge.R + epsilon_radius) ) continue;
		//checking lenght
		float templ_lenght = cv::arcLength(this->contours[id], false);// just a curve
		templ_lenght /= 2;
		if (templ_lenght < epsilon_differential) continue;

		cv::drawContours(this->input_img, this->contours, id, { 255,0,0 }, 1);
	}
}

bool PreProcessing::foundDefectiveOnEdge(Circle & data, float threshold){

	bool found_output = true;
	float radius = data.R;
	cv::Point center_point = (cv::Point)data.rect.center;
	for (auto& p : data.contour) {
		float temple_val = cv::norm(p - center_point);
		temple_val = abs(temple_val - radius);
		if (temple_val >= threshold) {
			found_output = false;
			break;
		}
		else found_output = true;
	}

	return found_output;
}



cv::Mat PreProcessing::getBinaryImage(void){
	return this->binary_img;
}

cv::Mat PreProcessing::getMaskImage(Circle & big_circle, Circle & small_circle){

	cv::Mat output_img = cv::Mat::zeros(this->binary_img.size(),this-> binary_img.type());
	// epsilon radius
	const float epsilon_radius = 3;
	big_circle.rect.size.width -= epsilon_radius;
	big_circle.rect.size.height -= epsilon_radius;
	small_circle.rect.size.width += epsilon_radius;
	small_circle.rect.size.height += epsilon_radius;

	if (!this->binary_img.empty()) {
		cv::Mat outer_mask, inner_mask;
        outer_mask = cv::Mat::zeros(this->binary_img.size(), CV_8UC1);
	    inner_mask = cv::Mat::zeros(this->binary_img.size(), CV_8UC1);
	    cv::ellipse(outer_mask, big_circle.rect, { 255 }, -1);
        cv::ellipse(inner_mask, small_circle.rect, { 255 }, -1);
		this->ellipse_mask_img = outer_mask ^ inner_mask;
		output_img = this->binary_img & this->ellipse_mask_img;
		
	}
	return output_img;
}

cv::Mat PreProcessing::getInnerMaskImage(Circle & outer, Circle & inner){

	cv::Mat output_img = cv::Mat::zeros(this->binary_img.size(),this-> binary_img.type());
	// epsilon radius
	const float epsilon_radius = 3;
	outer.rect.size.width -= epsilon_radius;
	outer.rect.size.height -= epsilon_radius;
	inner.rect.size.width += epsilon_radius;
	inner.rect.size.height += epsilon_radius;

	if (!this->binary_img.empty()) {
		cv::RotatedRect edge_rect;
		edge_rect.center = (outer.rect.center + inner.rect.center) / 2;
		edge_rect.size.width = (outer.rect.size.width + inner.rect.size.width) / 2;
		edge_rect.size.height = (outer.rect.size.height + inner.rect.size.height) / 2;
		cv::Mat edge_mask = cv::Mat::zeros(this->binary_img.size(), CV_8UC1);
		const int thickness = abs(outer.R - inner.R)*0.7;
		cv::ellipse(edge_mask, edge_rect, { 255 }, thickness);

		output_img = this->binary_img & edge_mask;
		
	}
	return output_img;
}

cv::Mat PreProcessing::getOuterMaskImage(Circle & outer, Circle & inner){
	cv::Mat output_img = cv::Mat::zeros(this->binary_img.size(),this-> binary_img.type());
	// epsilon radius
	const float epsilon_radius = 3;
	outer.rect.size.width -= epsilon_radius;
	outer.rect.size.height -= epsilon_radius;
	inner.rect.size.width += epsilon_radius;
	inner.rect.size.height += epsilon_radius;

	if (!this->binary_img.empty()) {
		cv::Mat outer_mask, inner_mask;
        outer_mask = cv::Mat::zeros(this->binary_img.size(), CV_8UC1);
	    inner_mask = cv::Mat::zeros(this->binary_img.size(), CV_8UC1);
	    cv::ellipse(outer_mask, outer.rect, { 255 }, -1);
        cv::ellipse(inner_mask, inner.rect, { 255 }, -1);
		this->ellipse_mask_img = outer_mask ^ inner_mask;
		
		cv::Mat outer_mask2, inner_mask2;
        outer_mask2 = cv::Mat::zeros(this->binary_img.size(), CV_8UC1);
	    inner_mask2 = cv::Mat::zeros(this->binary_img.size(), CV_8UC1);
		const int thickness = abs(outer.R - inner.R)*0.3;

	    cv::ellipse(outer_mask2, outer.rect, { 255 }, thickness);
        cv::ellipse(inner_mask2, inner.rect, { 255 }, thickness);

		cv::Mat edge_mask = outer_mask2 + inner_mask2;
		
		cv::Mat o1 = (this->binary_img & ellipse_mask_img);
		output_img = o1 & edge_mask;
		
	}
	return output_img;
}

cv::Mat PreProcessing::getEllipseMaskImage(void){
	return this->ellipse_mask_img;
}


void PreProcessing::setGaussianValue(int val){
	this->gaussian_val = val;
}

void PreProcessing::setEpsilonRadius(float val){
	this->epsilon_radius = val;
}


Contours PreProcessing::find_countours(cv::Mat & input){
	Contours contours;
	cv::findContours(input.clone(), contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);

	return contours;
}

Circles PreProcessing::find_circles(Contours & contours){
	std::vector<Circle> circles;
	// define some parameter setting
	const float min_rad = 50.0f;
	const float max_rad = 1000.0f;
	const float epsilon_rad = 5;
	const float min_fitness = 0.85f;
	for (auto& contour : contours) {
		if (contour.size() > 10) {
		
            // calc information about rectangle
			cv::RotatedRect rotaterect = cv::fitEllipse(contour);
			float side_x = rotaterect.size.height;
			float side_y = rotaterect.size.width;

			float R = (side_x + side_y) / 4;
			if (R < min_rad || R> max_rad) continue;
			// calc fitness 360 degree
			cv::Point center = rotaterect.center;
			const float perimeter = 360;
			std::vector<bool> list_360;
			list_360.assign(360, 0);
			
			float cnt = 0;
			for (auto& p : contour) {
				int px = p.x - center.x;
				int py = p.y - center.y;
				double radian = round(atan2(py, px)*180/CV_PI);
			
				if (radian > 0) {
					int index = (int)radian;
					list_360[index] = 1;
				}
				else
				{
					int index = (int)radian + 360;
					if (index == 360) index = 359;
					list_360[index] = 1;
				}
			}
			// sum up
          
			for (auto p : list_360) {
				if (p == 1) cnt++;
			}
			list_360.clear();
			// comp fitness value
			float fitness = cnt / perimeter;
			if (fitness > min_fitness){
				bool non_cluster = 0;
				circles.push_back({ fitness,R,rotaterect,non_cluster,contour});
			}
            
		}
			
	}

	return circles;
}

void PreProcessing::find_clusters(Circles & circles){

	if (circles.size() < 2) return ;

	const float ref_radius = circles[0].R;
	for (auto& c : circles) {
		if (abs(c.R - ref_radius) < this->epsilon_radius) c.cluster = 1;
		else c.cluster = 0;
	}
}

void PreProcessing::calCurvature(Circle & data, const int cuv_size, std::string csv_name){
	std::ofstream file;
	file.open(csv_name);
    for (auto id = 0; id < data.contour.size(); id += cuv_size) {
			std::vector<cv::Point> curvs;
			for (auto num = 0; num < cuv_size; num++) {
				if ((id + num) >= data.contour.size()) continue;
				curvs.push_back(data.contour[id + num]);
			}
			float radius = 0;
			cv::Point2f center;
			cv::minEnclosingCircle(curvs, center, radius);
			file << radius << std::endl;
		}
	file.close();
}


