#include "vision_layers.h"

namespace jaffe{

	template <typename Dtype>
	bool JPoolingLayer<Dtype>::Init(const vector<string> param){
		SetParam(param);
		return ReadParam();
	}

	template <typename Dtype>
	bool JPoolingLayer<Dtype>::SetParam(const vector<string> param){
		return m_param->SetParam(param);
	}
	
	template <typename Dtype>
	bool JPoolingLayer<Dtype>::ReadParam(){
		return true;
	}

	template <typename Dtype>
	bool JPoolingLayer<Dtype>::Show(){
		return m_param->Show();
	}

	template class JPoolingLayer <int>;

} // namespace jaffe