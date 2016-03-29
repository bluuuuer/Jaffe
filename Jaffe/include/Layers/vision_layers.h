#ifndef VISION_LAYERS_H_H
#define VISION_LAYERS_H_H

#include "layer.h"
#include "convolution_layer_param.h"

namespace jaffe {

	class JBaseConvolutionLayer : public JLayer{
	public:
		JBaseConvolutionLayer(){};
		~JBaseConvolutionLayer(){};
	};

	class JConvolutionLayer : public JBaseConvolutionLayer{
	public:
		JConvolutionLayer(){
			m_parameter = new JConvolutionLayerParam;
		};
		~JConvolutionLayer(){
			delete[] m_parameter;
		};
		virtual void Forward();
		bool SetParam(vector<string> param);
		// 输出显示所有参数，测试用
		virtual bool Show(){ return m_parameter->Show(); };
	private:
		JConvolutionLayerParam* m_parameter;
	};
}
#endif