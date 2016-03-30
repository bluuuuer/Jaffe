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
		string str_temp = "";
		int i_temp = 0;
		vector<string> layer_param_temp;
		while (getline(fin, line)){
			// 防止同一 layer 中更深的位置有同名参数出现
			if (!enter_layer){
				matchString(line, "name:", &m_name);

				if (matchString(line, "input:", &str_temp)){
					m_input.push_back(str_temp);
				}

				if (line.find("input_shape:") != string::npos){
					//待补充
				}

				if (matchInt(line, "input_dim:", &i_temp)){
					m_input_dim.push_back(i_temp);
				}

				matchBool(line, "force_backward:", 
					&m_force_backward);

				if (line.find("state:") != string::npos){
					//待补充
				}

				matchBool(line, "debug_info:", &m_debug_info);
				
				if (line.find("layer") != string::npos){
					enter_layer = true;
					m_layer_num++;
					if (line.find("{") != string::npos)
						left += count_if(line.begin(), 
						line.end(), NPisleft);
					continue;
				}
			}
			// 进入 layer 参数
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