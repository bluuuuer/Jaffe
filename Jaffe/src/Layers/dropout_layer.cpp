#include "neuron_layers.h"

namespace jaffe {

	template class JDropoutLayer <int>;
	template class JDropoutLayer < float>;

	template <typename Dtype>
	bool JDropoutLayer<Dtype>::Init(const vector<string> param){
		SetParam(param);
		return true;
	}

	template <typename Dtype>
	bool JDropoutLayer<Dtype>::SetParam(const vector<string> param){
		return m_param->SetParam(param);
	}

	template <typename Dtype>
	bool JDropoutLayer<Dtype>::Show(){
		return m_param->Show();
	}

} // namespace jaffe