#include "layer_param.h"

namespace jaffe {

	bool LPisleft(char c){
		return c == '{';
	}

	bool LPisright(char c){
		return c == '}';
	}


	bool JLayerParam::SetSharedParam(const vector<string> param){
		string line;
		bool enter_param_spec = false;
		vector<string> temp_s_v;
		int left = 0;
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			if (!enter_param_spec){
				if (matchString(line, "type:", &m_type))
					m_type = true;

				if (matchString(line, "name:", &m_name))
					m_name = true;

				if (line.find("top") != string::npos)
					m_top_num++;
				if (line.find("bottom") != string::npos)
					m_bottom_num++;
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
					JParamSpec param_spec_temp;	// 可以有多个 param_spec 参数空间
					param_spec_temp.SetParam(temp_s_v);
					m_param_spec.push_back(param_spec_temp);
					temp_s_v.clear();
					enter_param_spec = false;
				}
			}

		}

		return true;

	}
} // namespace jaffe
