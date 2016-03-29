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

	class JParamSpec{
	public:
		JParamSpec(){
			m_name = "";
			m_lr_mult = 1.0;
			m_decay_mult = 1.0;
			m_share_mode = STRICT;
		};
		~JParamSpec(){};
		bool SetParam(const vector<string> param);
		void Show();
	private:
		// 独有参数
		string m_name;
		enum DimCheckMode{
			STRICT = 0,
			PERMISSIVE = 1
		};
		DimCheckMode m_share_mode;
		float m_lr_mult;
		float m_decay_mult;
		// 正则表达式匹配
		//bool matchString(const string line, const string key, string* s);
		//bool matchFloat(const string line, const string key, float* f);

	};
}
#endif