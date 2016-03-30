#include "vision_layers.h"

namespace jaffe {

	template <typename Dtype>
	bool JConvolutionLayer<Dtype>::Init(const vector<string> param){
		return m_param->SetParam(param);
	}

	template <typename Dtype>
	bool JConvolutionLayer<Dtype>::Show(){
		return m_param->Show();
	}
}
