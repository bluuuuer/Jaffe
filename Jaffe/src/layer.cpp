#include <iostream>

#include "layer.h"

namespace jaffe {

	bool JLayer::SetSharedParam(const vector<string> param){
		return m_parameter->SetSharedParam(param);
	}
} // namespace jaffe