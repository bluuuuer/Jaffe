#include "data_layers.h"

namespace jaffe {

	template <typename Dtype>
	bool JDataLayer<Dtype>::Init(vector<string> param){
		return m_param->SetParam(param);
	}

	template <typename Dtype>
	bool JDataLayer<Dtype>::Show(){
		return m_param->Show();
	}

} // namespace jaffe