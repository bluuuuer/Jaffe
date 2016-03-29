#include <iostream>

#include "layer.h"

namespace jaffe {

	bool Layer::setSharedParam(const vector<string> param){
		return this->parameter->setSharedParam(param);
	}
}