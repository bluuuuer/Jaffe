#include "neuron_layers.h"

namespace jaffe {

	template <typename Dtype>
	bool JReLULayer<Dtype>::Init(const vector<string> param){
		SetParam(param);
		return true;
	}

	template <typename Dtype>
	bool JReLULayer<Dtype>::SetParam(const vector<string> param){
		return m_param->SetParam(param);
	}

	template <typename Dtype>
	bool JReLULayer<Dtype>::Show(){
		return m_param->Show();
	}

	template class JReLULayer <int>;

} // namespace jaffe