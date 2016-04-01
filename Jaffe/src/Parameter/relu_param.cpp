#include "relu_param.h"

namespace jaffe{

	bool RPisleft(char c){
		return c == '{';
	}

	bool RPisright(char c){
		return c == '}';
	}

	bool JReluParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting ReLU Layer \"" << m_s_name
			<< "\"..." << endl;

		string line = "";
		vector<string> v_unique_param;
		bool b_enter = false;
		int i_left = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			if (line.find("convolution_param") != string::npos){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(),
					RPisleft);
			}
			else if (b_enter){
				v_unique_param.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					RPisleft);
				i_left -= count_if(line.begin(), line.end(),
					RPisright);
				if (i_left == 0){
					v_unique_param.pop_back();
					SetUniqueParam(v_unique_param);
					v_unique_param.clear();
					b_enter = false;
				}
			}
		}

		return true;
	}

	bool JReluParam::SetUniqueParam(const vector<string> param){
		string line = "";
		
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			matchFloat(line, "negative_slope:", &m_negative_slope);

			if (line.find("engine:") != string::npos){
				if (line.find("CAFFE") != string::npos){
					m_engine = CAFFE;
				}
				else if (line.find("CUDNN") != string::npos){
					m_engine = CUDNN;
				}
			}
		}
		
		cout << "Done" << endl;
		return true;
	}
} // namespace jaffe