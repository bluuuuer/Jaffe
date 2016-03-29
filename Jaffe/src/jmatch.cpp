#include "jmatch.h"

namespace jaffe{
	bool matchString(const string line, const string key, string* s){
		const std::regex pattern(key + "( )?(\")(\\w+)(\")");
		std::match_results<string::const_iterator> result;
		bool vaild = std::regex_search(line, result, pattern);
		if (vaild)
			*s = result[3];
		return vaild;
	}

	bool matchInt(const string line, const string key, int *i){
		const std::regex pattern(key + "( )?(\\d{1,5})");
		std::match_results<string::const_iterator> result;
		bool vaild = std::regex_search(line, result, pattern);
		stringstream ss;
		ss << result[2];
		if (vaild)
			ss >> *i;
		return vaild;
	}

	bool matchFloat(const string line, const string key, float* f){
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

	bool matchBool(const string line, const string key, bool* b){
		if (line.find("true") != string::npos){
			*b = true;
			return true;
		}
		*b = false;
		return false;
	}
}