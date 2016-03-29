#ifndef LAYER_H_H
#define LAYER_H_H

#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <sstream>

#include "LayerParameter.h"

using namespace std;

class Layer{
public:
	Layer(){
	};
	~Layer(){
		if(this->parameter.GetTopNum()){
			this->top.clear();
			vector<Layer*>(this->top).swap(this->top); 
		}
		if(this->parameter.GetBottomNum()){
			this->bottom.clear();
			vector<Layer*>(this->bottom).swap(this->bottom); 
		}
	};
	virtual bool SetSharedParam(const vector<string> param);
	virtual void Forward(){};
	string GetType(){ return this->parameter.GetType(); };
	virtual bool Show(){ return true; };

protected:
	string* top_s;
	vector<Layer*> top;

	string* bottom_s;
	vector<Layer*> bottom;

private:
	LayerParameter parameter;
};
#endif