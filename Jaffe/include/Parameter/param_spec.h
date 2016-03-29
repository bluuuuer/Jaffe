#ifndef PARAM_SPEC_H_H
#define PARAM_SPEC_H_H

#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <sstream>

#include "jmatch.h"

using std::string;
using std::cout;
using std::vector;
using std::endl;

namespace jaffe{

	class ParamSpec{
	public:
		ParamSpec(){
			this->name = "";
			this->lr_mult = 1.0;
			this->decay_mult = 1.0;
			this->share_mode = STRICT;
		};
		~ParamSpec(){};
		bool setParam(const vector<string> param);
		void show();
	private:
		// 独有参数
		string name;
		enum DimCheckMode{
			STRICT = 0,
			PERMISSIVE = 1
		};
		DimCheckMode share_mode;
		float lr_mult;
		float decay_mult;
		// 正则表达式匹配
		//bool matchString(const string line, const string key, string* s);
		//bool matchFloat(const string line, const string key, float* f);

	};
}
#endif