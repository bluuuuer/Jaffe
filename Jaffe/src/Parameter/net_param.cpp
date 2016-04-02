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
		bool b_enter_layer = false;
		bool b_enter_input_shape = false;
		bool b_enter_state = false;
		int idex = 0;
		int left = 0;
		string str_temp = "";
		int i_temp = 0;
		vector<string> v_str_temp;
		while (getline(fin, line)){
			// 防止同一 layer 中更深的位置有同名参数出现
			bool b_enter_deep = b_enter_layer || 
				b_enter_input_shape || b_enter_state;
			if (!b_enter_deep){
				matchString(line, "name:", &m_name);

				if (matchString(line, "input:", &str_temp)){
					m_input.push_back(str_temp);
				}

				if (matchInt(line, "input_dim:", &i_temp)){
					m_input_dim.push_back(i_temp);
				}

				matchBool(line, "force_backward:", 
					&m_force_backward);

				matchBool(line, "debug_info:", &m_debug_info);
				
				
			}
			// 进入 BlobShape 参数空间
			if (line.find("input_shape {") != string::npos){
				b_enter_input_shape = true;
				left += count_if(line.begin(), line.end(), 
					NPisleft);
			}
			else if (b_enter_input_shape){
				v_str_temp.push_back(line);
				left += count_if(line.begin(), line.end(), NPisleft);
				left -= count_if(line.begin(), line.end(), NPisright);
				if (left == 0){
					v_str_temp.pop_back();//最后一个“}”不要，因为第一个"{"没要
					JBlobShape temp_blob_shape;
					temp_blob_shape.SetParam(v_str_temp);
					m_input_shape.push_back(temp_blob_shape);//各 layer 参数存于 layers_param 中 
					v_str_temp.clear();
					b_enter_input_shape = false;
				}
			}
			// 进入 LayerParameter 参数空间
			if (line.find("layer {") != string::npos){
				b_enter_layer = true;
				m_layer_num++;
				left += count_if(line.begin(), line.end(), 
					NPisleft);
			}
			else if (b_enter_layer){
				v_str_temp.push_back(line);
				left += count_if(line.begin(), line.end(), NPisleft);
				left -= count_if(line.begin(), line.end(), NPisright);
				if (left == 0){
					v_str_temp.pop_back();//最后一个“}”不要，因为第一个"{"没要
					m_layers_param.push_back(v_str_temp);//各 layer 参数存于 layers_param 中 
					v_str_temp.clear();
					b_enter_layer = false;
				}
			}
			// 进入 JNetState 参数空间
			if (line.find("state {") != string::npos){
				b_enter_state = true;
				m_state = new JNetState;
				left += count_if(line.begin(), line.end(), 
					NPisleft);
			}
			else if (b_enter_state){
				v_str_temp.push_back(line);
				left += count_if(line.begin(), line.end(), 
					NPisleft);
				left -= count_if(line.begin(), line.end(), 
					NPisright);
				if (left == 0){
					v_str_temp.pop_back();
					m_state->SetParam(v_str_temp);
					v_str_temp.clear();
					b_enter_state = false;
				}
			}
		}

		fin.close();
		return true;
	}
} // namespace jaffe