#ifndef CONVLAYERPARAMETER_H_H
#define CONVLAYERPARAMETER_H_H

#include "LayerParameter.h"
#include "FillerParameter.h"
#include "ParamSpec.h"

using namespace std;

class ConvLayerParameter : public LayerParameter{
public:
	ConvLayerParameter(){
		this->num_output = 0;
		this->bias_term = true;
		this->pad_h = 0;
		this->pad_w = 0;
		this->kernel_h = 0;
		this->kernel_w = 0;
		this->stride_h = 0;
		this->stride_w = 0;
		this->group = 1;
		this->engine = DEFAULT;
		this->axis = 1;
		this->force_nd_im2col = false;
	};
	~ConvLayerParameter(){
		delete[] this->weight_filler;
		delete[] this->bias_filler;
	};
	bool SetParam(vector<string> param);
	bool Show();

private:
	// 各种独有参数
	int num_output;
	bool bias_term;
	vector<int> pad;
	vector<int> kernel_size;
	vector<int> stride;
	int pad_h;
	int pad_w;
	int kernel_h;
	int kernel_w;
	int stride_h;
	int stride_w;
	int group;
	FillerParameter* weight_filler;
	FillerParameter* bias_filler;
	enum Engine{
		DEFAULT = 0,
		CAFFE = 1,
		CUDNN = 2
	};
	Engine engine;
	int axis;
	bool force_nd_im2col;
};
#endif