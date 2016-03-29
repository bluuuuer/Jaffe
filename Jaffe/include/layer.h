#ifndef LAYER_H_H
#define LAYER_H_H

#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <sstream>

#include "layer_param.h"

using std::string;
using std::cout;
using std::vector;
using std::endl;

namespace jaffe {

	class Layer{
	public:
		Layer(){
		};
		~Layer(){
			if (this->parameter->getTopNum()){
				this->top.clear();
				vector<Layer*>(this->top).swap(this->top);
			}
			if (this->parameter->getBottomNum()){
				this->bottom.clear();
				vector<Layer*>(this->bottom).swap(this->bottom);
			}
		};
		virtual bool setSharedParam(const vector<string> param);
		virtual void forward(){};
		string getType(){ return this->parameter->getType(); };
		virtual bool show(){ return this->parameter->show(); };

	protected:
		string* top_s;
		vector<Layer*> top;

		string* bottom_s;
		vector<Layer*> bottom;

	private:
		LayerParam* parameter;
	};
}
#endif