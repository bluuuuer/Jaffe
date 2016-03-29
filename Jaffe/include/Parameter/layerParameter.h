#ifndef LAYERPARAMETER_H_H
#define LAYERPARAMETER_H_H

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>

#include "ParamSpec.h"

using namespace std;

class LayerParameter{
public:
	LayerParameter(){
		this->type_ = false;
		this->name_ = false;
		this->top_num = 0;
		this->bottom_num = 0;
	};
	~LayerParameter(){};
	// 读取所有层都会有的共享参数， 每个 layer 都必须调用
	bool SetSharedParam(const vector<string> param);
	int GetTopNum(){ return this->top_num; };
	int GetBottomNum(){ return this->bottom_num; };
	string GetType(){ return this->type; };

protected:
	// 各种共享参数
	string name;
	bool name_;

	string type;
	bool type_;

	int top_num;
	int bottom_num;

	vector<ParamSpec> param_spec;

	// 正则表达式匹配
	bool match_s(const string line, const string key, string* s);
	bool match_i(const string line, const string key, int *i);
	bool match_f(const string line, const string key, float* f);
	bool match_b(const string line, const string key, bool* b);
private:
};
#endif