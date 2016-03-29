#include <iostream>

#include "layer.h"

using namespace std;

bool Layer::setSharedParam(const vector<string> param){
	return this->parameter->setSharedParam(param);
}