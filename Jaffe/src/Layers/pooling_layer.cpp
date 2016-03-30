#include "vision_layers.h"

namespace jaffe{

	template <typename Dtype>
	bool JPoolingLayer<Dtype>::Init(const vector<string> param){
		SetParam(param);
		ReadParam();
	}

	template <typename Dtype>
	bool JPoolingLayer<Dtype>::SetParam(const vector<string> param){
		return m_param->SetParam(param);
	}
	
	template <typename Dtype>
	bool JPoolingLayer<Dtype>::ReadParam(){

	}

	template <typename Dtype>
	bool JPoolingLayer<Dtype>::Show(){
		m_param->Show();
	}

} // namespace jaffe