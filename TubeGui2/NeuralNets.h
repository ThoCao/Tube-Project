#pragma once
#include "qmessagebox.h"
#include <opencv2\opencv.hpp>
#include <opencv2\ml.hpp>
#include "PreProcessingData.h"
#include "PreProcessing.h"

	
#define THRES_SIZE 10
#define CIRCULARITY 0.55

typedef std::vector<std::vector<float>> Inputs;
typedef std::vector<float> Input;

class NeuralNets : PreProcessingData, PreProcessing
{
public:
	NeuralNets();
	~NeuralNets();
public:
	void showResult_PERCENT();
	void clearResult_PERCENT();
public:
	float FAILED_EDGE = 0;
	float FAILED_INNER = 0;
	float PASSED_EDGE = 0;
	float PASSED_INNER = 0;

	bool isEdgeFailed = false;
	cv::Point edgePos;
	int edgeRadius = 0;

private:
	cv::Mat neuralChecking(cv::Ptr<cv::ml::ANN_MLP>& _neural, cv::Mat & input);
	void loadNeuralEdgeModel(std::string modelName);
	void loadNeuralInnerModel(std::string modelName);
	void loadDataSet(std::string fileName);
	
public:
	void setImage(cv::Mat& img);
	void setScaledFactor(float _val);
	bool getResultOnEdge(Circles& _circle_edges);
	bool getResultInner(cv::Mat & _image);
	void reTrainNeuralNet(std::string modelName);
	void saveNewData();

	/* Module Neural Edge Region */
private:
	cv::Ptr<cv::ml::ANN_MLP> _m_mlp_edge_;
	std::string _modelEdgeName_ = "modelNeural3_10_2_";
	cv::Mat _defect_img_;
	cv::Mat _trainningmat_;
	cv::Mat _labelmat_;
	
	/* Module Neural Inner Region */
private:
	cv::Ptr<cv::ml::ANN_MLP> _m_mlp_inner_;
	std::string _modelInnerName_ = "modelNeural7_20_2_";
	std::string _lookuptable_ = "lookupfeature.xml";
	int _num1D_ = 1;
	float scaled_factor = 1;

	std::vector<int> _table1D_;
	std::vector<float> _feature1D_;
	std::vector<int> _maxValue1D_;
private:
	void initialInnerRegion(void);
	void normalizeInnterFeature(std::vector<float> & _data);

};

