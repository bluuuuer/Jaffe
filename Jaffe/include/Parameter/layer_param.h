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


	class JLayerParam{
	public:
		JLayerParam(){
			m_name = "";
			m_type = "";
			m_top_num = 0;
			m_bottom_num = 0;
		};
		~JLayerParam(){};
		// 读取所有层都会有的共享参数， 每个 layer 都必须调用
		bool SetSharedParam(const vector<string> param);
		int GetTopNum(){ return m_top_num; };
		int GetBottomNum(){ return m_bottom_num; };
		string GetType(){ return m_type; };
		bool Show(){ return true; };

	protected:
		// 各种共享参数
		string m_name;
		string m_type;
		int m_top_num;
		int m_bottom_num;
		vector<JParamSpec> m_param_spec;

		// 正则表达式匹配
		//bool matchString(const string line, const string key, string* s);
		//bool matchInt(const string line, const string key, int *i);
		//bool matchFloat(const string line, const string key, float* f);
		//bool matchBool(const string line, const string key, bool* b);
	private:
	};
}
#endif