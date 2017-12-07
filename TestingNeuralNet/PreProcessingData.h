#pragma once
#include "PreProcessing.h"
#include <random>
#include <array>
#include <algorithm>
#include <chrono>

#define FEATURE_SIZE 49
#define POINT_SIZE 100

#define MAX_AREA 2500;
#define MAX_APPROX 30;
#define MAX_DEVIATION 100;

struct Feature
{
	std::vector<float> feature;
	std::vector<int> label;
};

typedef std::vector<Circle> Circles;


class PreProcessingData
{
public:
	PreProcessingData();
	~PreProcessingData();

public:
	void normalizeInput(std::vector<float> & _data);
	void saveData(std::string fileName,std::vector<Feature>& m_data,bool flag_old);
private:
	void shuffleData(std::vector<Feature> & m_data);
	void loadOldData(std::string fileName);
public:
	std::vector<std::vector<float>> getInputFeatures(Circles& _circle_edges);

private:
	std::string _file_train_ = "trainmat.xml";
	cv::Mat prev_trainmat_;
	cv::Mat prev_labelmat_;

public:
	std::vector<Feature> m_predata;
};

