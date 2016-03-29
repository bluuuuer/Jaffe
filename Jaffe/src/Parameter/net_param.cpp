#include "net_param.h"

namespace jaffe {

	bool NPisleft(char c){
		return c == '{';
	}

	bool NPisright(char c){
		return c == '}';
	}

	bool JNetParameter::ReadParamFromText(){
		// 打开文件
		ifstream fin;
		fin.open(m_filepath);
		if (!fin.is_open()){
			cout << "Failed to Open Net Parameter Prototxt" << endl;
			return false;
		}

		// 逐行读取参数
		string line;
		bool enter_layer = false;
		int idex = 0;
		int left = 0;
		vector<string> layer_param_temp;
		while (getline(fin, line)){
			if (!enter_layer){// 防止同一 layer 中更深的位置有 name 参数出现
				if (line.find("name:") != string::npos)
					matchString(line, "name:", &m_name);
				if (line.find("layer") != string::npos){
					enter_layer = true;
					m_layer_num++;
					if (line.find("{") != string::npos)
						left += count_if(line.begin(), line.end(), NPisleft);
					continue;
				}
			}
			else{
				layer_param_temp.push_back(line);
				if (line.find("{") != string::npos)
					left += count_if(line.begin(), line.end(), NPisleft);
				if (line.find("}") != string::npos)
					left -= count_if(line.begin(), line.end(), NPisright);
				if (left == 0){
					layer_param_temp.pop_back();//最后一个“}”不要，因为第一个"{"没要
					m_layers_param.push_back(layer_param_temp);//各 layer 参数存于 layers_param 中 
					layer_param_temp.clear();
					enter_layer = false;
				}
			}
		}

		fin.close();
		return true;
	}
} // namespace jaffe