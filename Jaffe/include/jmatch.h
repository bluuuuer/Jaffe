#ifndef JMATCH_H
#define JMATCH_H

#include <string>
#include <regex>
#include <sstream>

using std::string;
using std::stringstream;

namespace jaffe {

	bool matchString(const string line, const string key, string* s);

	bool matchInt(const string line, const string key, int *i);

	bool matchFloat(const string line, const string key, float* f);

	bool matchBool(const string line, const string key, bool* b);
}	//	namespace jaffe
#endif
