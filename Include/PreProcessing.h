#pragma once
#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

#define HIST
#define _show(img) cv::imshow(#img,img);
#define _wait(ms) cv::waitKey(ms);
//#define SHOWSIGNAL

#define MAX_VAL 5


typedef std::vector<std::vector<cv::Point>> Contours;
typedef std::vector<cv::Point> Contour;

typedef struct {
	float fitness;
	float R;
	cv::RotatedRect rect;
	bool cluster;
	Contour contour;
}Circle;

typedef std::vector<Circle> Circles;

class PreProcessing
{
public:
	PreProcessing();
	~PreProcessing();

private:
	cv::Mat    input_img;
	cv::Mat    binary_img;
	cv::Mat    ellipse_mask_img;
	static int gaussian_val;
	static float epsilon_radius;
	Contours     contours;
public:
	cv::Mat preProcessingFunc(cv::Mat& input);
	std::tuple<Circle, Circle,bool> Find2CirclesFunc(const cv::Mat & input);

	/* Fast Cỉrcle Detection */
	bool IsFoundCircle(const cv::Mat & input);

	void showContourOutlier(void);
	void drawContourOnTube(Circle & outer_edge, Circle & inner_edge);
public: 
	bool foundDefectiveOnEdge(Circle& data,float threshold);

public:
	void setGaussianValue(int val);
	void setEpsilonRadius(float val);
public:
	cv::Mat getBinaryImage(void);
	cv::Mat getMaskImage(Circle& big_circle, Circle& small_circle);
	cv::Mat getInnerMaskImage(Circle& outer, Circle& inner);
	cv::Mat getOuterMaskImage(Circle& outer, Circle& inner);
	cv::Mat getEllipseMaskImage(void);

public:
	Contours find_countours(cv::Mat & input);
	Circles  find_circles(Contours & contours);
	void     find_clusters(Circles & circles);
	void     calCurvature(Circle& data, const int cuv_size, std::string csv_name);
};

