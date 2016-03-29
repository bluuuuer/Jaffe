#include "filler_param.h"

bool FillerParam::setParameter(const vector<string> param){
	string line;
	for (int i = 0; i < param.size(); i++){
		line = param.at(i);
		matchString(line, "type:", &this->type);
		matchFloat(line, "value:", &this->value);
		matchFloat(line, "min:", &this->min);
		matchFloat(line, "max:", &this->max);
		matchFloat(line, "mean", &this->mean);
		matchFloat(line, "std:", &this->std);
		matchInt(line, "sparse:", &this->sparse);
	}
	return true;
}

void FillerParam::show(){
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

bool FillerParam::matchString(const string line, const string key, string* s){
	const std::regex pattern(key + "( )?(\")(\\w+)(\")");
	std::match_results<string::const_iterator> result;
	bool vaild = std::regex_search(line, result, pattern);
	if (vaild)
		*s = result[3];
	return vaild;
}

bool FillerParam::matchInt(const string line, const string key, int* i){
	const std::regex pattern(key + "( )?(\\d{1,5})");
	std::match_results<string::const_iterator> result;
	bool vaild = std::regex_search(line, result, pattern);
	stringstream ss;
	ss << result[2];
	if (vaild)
		ss >> *i;
	return vaild;
}

bool FillerParam::matchFloat(const string line, const string key, float* f){
	const std::regex pattern(key + "( )?(\\d{1,5})(.)(\\d{1,5})");
	std::match_results<string::const_iterator> result;
	bool vaild = std::regex_search(line, result, pattern);
	string s = result[2];
	s += result[3];
	s += result[4];
	stringstream ss;
	ss << s;
	if (vaild)
		ss >> *f;
	return vaild;
}
