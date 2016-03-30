#include "vision_layers.h"

namespace jaffe {
	template <typename Dtype>
	bool JConvolutionLayer::Init(const vector<string> param){
		return m_param->SetParam(param);
	}

	template <typename Dtype>
	Dtype JConvolutionLayer::Forward(){

	}

	template <typename Dtype>
	bool JConvolutionLayer::Show(){
		return m_param->Show();
	}
	template <typename Dtype>
	bool JConvolutionLayer::ReadParam(){

	}
}
