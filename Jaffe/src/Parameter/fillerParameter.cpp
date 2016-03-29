#include "FillerParameter.h"

bool FillerParameter::SetParameter(const vector<string> param){
	string line;
	for (int i = 0; i < param.size(); i++){
		line = param.at(i);
		match_s(line, "type:", &this->type);
		match_f(line, "value:", &this->value);
		match_f(line, "min:", &this->min);
		match_f(line, "max:", &this->max);
		match_f(line, "mean", &this->mean);
		match_f(line, "std:", &this->std);
		match_i(line, "sparse:", &this->sparse);
	}
	return true;
}

void FillerParameter::Show(){
	cout << "Filler {" << endl;
	cout << "\ttype: " << this->type << endl;
	cout << "\tvalue: " << this->value << endl;
	cout << "\tmin: " << this->min << endl;
	cout << "\tmax: " << this->max << endl;
	cout << "\tmean: " << this->mean << endl;
	cout << "\tstd: " << this->std << endl; 
	cout << "\tsparse: " << this->sparse << endl;
	cout << "\tVarianceNorm: " << this->variance_norm << endl;
	cout << "}" << endl;
}

bool FillerParameter::match_s(const string line, const string key, string* s){
	const std::regex pattern(key + "( )?(\")(\\w+)(\")");
	std::match_results<string::const_iterator> result;
	bool vaild = std::regex_search(line, result, pattern);
	if (vaild)
		*s = result[3];
	return vaild;
}

bool FillerParameter::match_i(const string line, const string key, int* i){
	const std::regex pattern(key + "( )?(\\d{1,5})");
	std::match_results<string::const_iterator> result;
	bool vaild = std::regex_search(line, result, pattern);
	stringstream ss;
	ss << result[2];
	if (vaild)
		ss >> *i;
	return vaild;
}

bool FillerParameter::match_f(const string line, const string key, float* f){
	const std::regex pattern(key + "( )?(\\d{1,5})(.)(\\d{1,5})");
	std::match_results<string::const_iterator> result;
	bool vaild = std::regex_search(line, result, pattern);
	//cout << result[0] << endl;
	//cout << result[1] << endl;
	//cout << result[2] << endl;
	//cout << result[3] << endl;
	//cout << result[4] << endl;
	string s = result[2];
	s += result[3];
	s += result[4];
	stringstream ss;
	ss << s;
	if (vaild)
		ss >> *f;
	return vaild;
}
