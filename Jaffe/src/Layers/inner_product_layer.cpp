#include "common_layers.h"

namespace jaffe {

	template <typename Dtype>
	bool JInnerProductLayer<Dtype>::Init(const vector<string> param){
		SetParam(param);

		return true;
	}

	template <typename Dtype>
	bool JInnerProductLayer<Dtype>::SetParam(const vector<string> param){
		return m_param->SetParam(param);
	}

	template <typename Dtype>
	bool JInnerProductLayer<Dtype>::Show(){
		return m_param->Show();
	}

	template class JInnerProductLayer <int>;

} // namespace jaffe