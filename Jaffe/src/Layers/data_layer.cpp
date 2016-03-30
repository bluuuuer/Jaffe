#include "data_layers.h"

namespace jaffe {
	template <typename Dtype>
	bool JDataLayer::Init(vector<string> param){
		return m_param->SetParam(param);
	}

	template <typename Dtype>
	Dtype JDataLayer::Forward(){

	}
}