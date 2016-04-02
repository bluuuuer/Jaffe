#include <iostream>

#include "layer.h"

namespace jaffe {

	template <typename Dtype>
	bool JLayer<Dtype>::SetType(const vector<string> param){
		return m_param->SetType(param);
	}

	template <typename Dtype>
	bool JLayer<Dtype>::SetSharedParam(const vector<string> param){
		return m_param->SetSharedParam(param);
	}

	template class JLayer<int>;
} // namespace jaffe