#ifndef LAYER_PARAM_H_H
#define LAYER_PARAM_H_H

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>

#include "jmatch.h"
#include "param_spec.h"

using std::string;
using std::cout;
using std::vector;
using std::endl;

namespace jaffe {


	class LayerParam{
	public:
		LayerParam(){
			this->name = "";
			this->type = "";
			this->top_num = 0;
			this->bottom_num = 0;
		};
		~LayerParam(){};
		// 读取所有层都会有的共享参数， 每个 layer 都必须调用
		bool setSharedParam(const vector<string> param);
		int getTopNum(){ return this->top_num; };
		int getBottomNum(){ return this->bottom_num; };
		string getType(){ return this->type; };
		bool show(){ return true; };

	protected:
		// 各种共享参数
		string name;
		string type;
		int top_num;
		int bottom_num;
		vector<ParamSpec> param_spec;

		// 正则表达式匹配
		//bool matchString(const string line, const string key, string* s);
		//bool matchInt(const string line, const string key, int *i);
		//bool matchFloat(const string line, const string key, float* f);
		//bool matchBool(const string line, const string key, bool* b);
	private:
	};
}
#endif