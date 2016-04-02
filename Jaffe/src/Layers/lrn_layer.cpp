#include "vision_layers.h"

namespace jaffe {

	template <typename Dtype>
	bool JLRNLayer<Dtype>::Init(const vector<string> param){
		SetParam(param);
		return true;
	}

	template <typename Dtype>
	bool JLRNLayer<Dtype>::SetParam(const vector<string> param){
		return m_param->SetParam(param);
	}

	template <typename Dtype>
	bool JLRNLayer<Dtype>::Show(){
		return m_param->Show();
	}

	template class JLRNLayer <int>;

} // namespace jaffe