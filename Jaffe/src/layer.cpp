#include <iostream>

#include "layer.h"

namespace jaffe {

	template <typename Dtype>
	bool JLayer<Dtype>::SetSharedParam(const vector<string> param){
		return m_param->SetSharedParam(param);
	}

} // namespace jaffe