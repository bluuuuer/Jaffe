#include "LayerParameter.h"

bool LPisleft(char c){
	return c == '{';
}

bool LPisright(char c){
	return c == '}';
}


bool LayerParameter::SetSharedParam(const vector<string> param){
	string line;
	bool enter_param_spec = false;
	vector<string> temp_s_v;
	int left = 0;
	for (int i = 0; i < param.size(); i++){
		line = param.at(i);
		if (!enter_param_spec){
			if (!this->type_)
			if (match_s(line, "type:", &this->type))
				this->type_ = true;

			if (!this->name_)
			if (match_s(line, "name:", &this->name))
				this->name_ = true;

			if (line.find("top") != string::npos)
				this->top_num++;
			if (line.find("bottom") != string::npos)
				this->bottom_num++;
		}
		// 进入 param_spec 参数空间
		if (line.find("param") != string::npos &&
			line.find("convolution_param") == string::npos
			&& !enter_param_spec){
			enter_param_spec = true;
			left += count_if(line.begin(), line.end(), LPisleft);
		}
		else if (enter_param_spec){
			temp_s_v.push_back(line);
			left += count_if(line.begin(), line.end(), LPisleft);
			left -= count_if(line.begin(), line.end(), LPisright);
			if (left == 0){
				temp_s_v.pop_back();
				ParamSpec param_spec_temp;	// 可以有多个 param_spec 参数空间
				param_spec_temp.SetParam(temp_s_v);
				this->param_spec.push_back(param_spec_temp);
				temp_s_v.clear();
				enter_param_spec = false;
			}
		}

	}
	if (!this->type_ || this->name_)
		return false;

	return true;

}

/*-------将 line 中 key 后双引号中内容赋给 s，若没有 key 则返回 false-------*/
bool LayerParameter::match_s(const string line, const string key, string* s){
	const std::regex pattern(key + "( )?(\")(\\w+)(\")");
	std::match_results<string::const_iterator> result;
	bool vaild = std::regex_search(line, result, pattern);
	//cout << result[0] << endl;
	//cout << result[1] << endl;
	//cout << result[2] << endl;
	//cout << result[3] << endl;
	//cout << result[4] << endl;
	if (vaild)
		*s = result[3];
	return vaild;
}

bool LayerParameter::match_i(const string line, const string key, int* i){
	const std::regex pattern(key + "( )?(\\d{1,5})");
	std::match_results<string::const_iterator> result;
	bool vaild = std::regex_search(line, result, pattern);
	stringstream ss;
	ss << result[2];
	if (vaild)
		ss >> *i;
	return vaild;
}

bool LayerParameter::match_f(const string line, const string key, float* f){
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

bool LayerParameter::match_b(const string line, const string key, bool* b){
	if (line.find("true") != string::npos){
		*b = true;
		return true;
	}
	*b = false;
	return false;
}
