#ifndef FILLERPARAMETER_H_H
#define FILLERPARAMETER_H_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

class FillerParameter{
public:
	FillerParameter(){
		this->type = "constant";
		this->value = 0;
		this->min = 0;
		this->max = 1;
		this->mean = 0;
		this->std = 1;
		this->sparse = -1;
		this->variance_norm = FAN_IN;
	};
	~FillerParameter(){};
	bool SetParameter(const vector<string> param);
	void Show();
private:
	// 独有参数
	string type;
	float value;
	float min;
	float max;
	float mean;
	float std;
	int sparse;

	enum VarianceNorm{
		FAN_IN = 0,
		FAN_OUT = 1,
		AVERAGE = 2
	};
	VarianceNorm variance_norm;

	// 正则表达式匹配
	bool match_s(const string line, const string key, string* s);
	bool match_i(const string line, const string key, int *i);
	bool match_f(const string line, const string key, float* f);
};
#endif