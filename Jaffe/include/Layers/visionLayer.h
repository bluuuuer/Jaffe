#ifndef VISION_LAYERS_H_H
#define VISION_LAYERS_H_H

#include "Layer.h"
#include "ConvLayerParameter.h"

using namespace std;

class BaseConvolutionLayer : public Layer{
public:
	BaseConvolutionLayer(){};
	~BaseConvolutionLayer(){};
};

class ConvolutionLayer : public BaseConvolutionLayer{
public:
	ConvolutionLayer(){
		this->parameter = new ConvLayerParameter;
	};
	~ConvolutionLayer(){
		delete[] this->parameter;
	};
	virtual void Forward();
	bool SetParam(vector<string> param);
	// 输出显示所有参数，测试用
	virtual bool Show(){ return this->parameter->Show(); };
private:
	ConvLayerParameter* parameter;
};
#endif