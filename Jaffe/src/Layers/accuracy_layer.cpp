#include "loss_layers.h"

namespace jaffe {

	template class JAccuracyLayer <int>;
	template class JAccuracyLayer <float>;

	template <typename Dtype>
	bool JAccuracyLayer<Dtype>::Init(const vector<string> param){
		SetParam(param);
		return true;
	}

	template <typename Dtype>
	bool JAccuracyLayer<Dtype>::SetParam(const vector<string> param){
		return m_param->SetParam(param);
	}

	template <typename Dtype>
	bool JAccuracyLayer<Dtype>::Show(){
		return m_param->Show();
	}

} // namespace jaffe