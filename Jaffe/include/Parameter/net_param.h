//Net 参数头文件
#ifndef NET_PARAM_H_H
#define NET_PARAM_H_H

#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "jmatch.h"

using std::string; 
using std::cout;
using std::vector;
using std::ifstream;
using std::endl;

namespace jaffe {

	class NetParameter{
	public:
		NetParameter(){
			this->layer_num = 0;
		};
		~NetParameter(){};
		// 设置参数文件路径
		bool setFilePath(const string filepath){
			this->filepath = filepath;
			return readParamFromText();
		};
		// 从文件中读取所有 layer 参数
		bool readParamFromText();

		int getLayerNum(){ return this->layer_num; };
		// 返回指定索引位置的layer参数
		vector<string> getLayerParam(int idex){
			return this->layers_param[idex];
		}
	private:
		string filepath; // 文件路径
		string name; // 参数 name
		int layer_num; // 该 net 中 layer 的数量
		vector<vector<string>> layers_param;  // 所有的 layer 参数

		// 读取参数时使用正则表达式匹配
		//bool matchString(const string line, const string key, string* s);
	};
}

#endif