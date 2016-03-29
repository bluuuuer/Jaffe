#include "param_spec.h"

bool ParamSpec::setParam(const vector<string> param){
	string line;
	for (int i = 0; i < param.size(); i++){
		line = param.at(i);
		matchString(line, "name:", &this->name);
		matchFloat(line, "lr_mult:", &this->lr_mult);
		matchFloat(line, "decay_mult:", &this->decay_mult);
	}

	return true;
}

void ParamSpec::show(){
	cout << "ParamSpec {" << endl;
	cout << "\tname: " << this->name << endl;
	cout << "\tshare_mode: " << this->share_mode << endl;
	cout << "\tlr_mult: " << this->lr_mult << endl;
	cout << "\tdecay_mult: " << this->decay_mult << endl;
	cout << "}" << endl;
}

bool ParamSpec::matchString(const string line, const string key, string* s){
	const std::regex pattern(key + "( )?(\")(\\w+)(\")");
	std::match_results<string::const_iterator> result;
	bool vaild = std::regex_search(line, result, pattern);
	if (vaild)
		*s = result[3];
	return vaild;
}

bool ParamSpec::matchFloat(const string line, const string key, float* f){
	const std::regex pattern(key + "( )?(\\d{1,5})(.)?(\\d{1,5})?");
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