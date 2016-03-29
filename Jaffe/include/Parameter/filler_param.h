#ifndef FILLE_RPARAM_H_H
#define FILLE_RPARAM_H_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

#include "jmatch.h"

using std::cout;
using std::string;
using std::vector;
using std::endl;

namespace jaffe {
	class JFillerParam{
	public:
		JFillerParam(){
			m_type = "constant";
			m_value = 0;
			m_min = 0;
			m_max = 1;
			m_mean = 0;
			m_std = 1;
			m_sparse = -1;
			m_variance_norm = FAN_IN;
		};
		~JFillerParam(){};
		bool SetParameter(const vector<string> param);
		void Show();
	private:
		// 独有参数
		string m_type;
		float m_value;
		float m_min;
		float m_max;
		float m_mean;
		float m_std;
		int m_sparse;

		enum VarianceNorm{
			FAN_IN = 0,
			FAN_OUT = 1,
			AVERAGE = 2
		};
		VarianceNorm m_variance_norm;

		// 正则表达式匹配
		//bool matchString(const string line, const string key, string* s);
		//bool matchInt(const string line, const string key, int *i);
		//bool matchFloat(const string line, const string key, float* f);
	};
}
#endif