#include <iostream>

#include "Layer.h"

using namespace std;

bool Layer::SetSharedParam(const vector<string> param){
	return this->parameter.SetSharedParam(param);
}