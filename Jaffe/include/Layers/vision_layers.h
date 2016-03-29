#ifndef VISION_LAYERS_H_H
#define VISION_LAYERS_H_H

#include "layer.h"
#include "convolution_layer_param.h"

namespace jaffe {

	class BaseConvolutionLayer : public Layer{
	public:
		BaseConvolutionLayer(){};
		~BaseConvolutionLayer(){};
	};

	class ConvolutionLayer : public BaseConvolutionLayer{
	public:
		ConvolutionLayer(){
			this->parameter = new ConvolutionLayerParam;
		};
		~ConvolutionLayer(){
			delete[] this->parameter;
		};
		virtual void forward();
		bool setParam(vector<string> param);
		// 输出显示所有参数，测试用
		virtual bool show(){ return this->parameter->show(); };
	private:
		ConvolutionLayerParam* parameter;
	};
}
#endif