#include "innerproduct_param.h"

namespace jaffe{

	bool IPisleft(char c){
		return c == '{';
	}

	bool IPisright(char c){
		return c == '}';
	}

	bool JInnerProductParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting InnerProduct Layer (" << m_s_name
			<< ")...";

		string line = "";
		vector<string> v_unique_param;
		bool b_enter = false;
		int i_left = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			if (line.find(" innerproduct_param") != string::npos){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(),
					IPisleft);
			}
			else if (b_enter){
				v_unique_param.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					IPisleft);
				i_left -= count_if(line.begin(), line.end(),
					IPisright);
				if (i_left == 0){
					v_unique_param.pop_back();
					SetUniqueParam(v_unique_param);
					v_unique_param.clear();
					b_enter = false;
				}
			}
		}

		cout << "Done" << endl;

		return true;
	}

	bool JInnerProductParam::SetUniqueParam(const vector<string> param){
		string line = "";
		bool b_enter_weight = false;
		bool b_enter_bias = false;
		int i_left = 0;
		vector<string> v_temp;
		
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			if (!b_enter_bias && !b_enter_weight){
				matchInt(line, "num_output:", &m_num_output);
				matchBool(line, "bias_term:", &m_bias_term);
				matchInt(line, "axis:", &m_axis);
			}
			// 进入 weight_filler 参数空间
			if (line.find("weight_filler") != string::npos){
				b_enter_weight = true;
				m_weight_filler = new JFillerParam;
				i_left += count_if(line.begin(), line.end(),
					IPisleft);
			}
			else if (b_enter_weight){
				v_temp.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					IPisleft);
				i_left -= count_if(line.begin(), line.end(),
					IPisright);
				if (i_left == 0){
					v_temp.pop_back();
					m_weight_filler->SetParameter(v_temp);
					v_temp.clear();
					b_enter_weight = false;
				}
			}
			// 进入 bias_filler 参数空间
			if (line.find("bias_filler") != string::npos){
				b_enter_bias = true;
				m_bias_filler = new JFillerParam;
				i_left += count_if(line.begin(), line.end(),
					IPisleft);
			}
			else if (b_enter_bias){
				v_temp.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					IPisleft);
				i_left -= count_if(line.begin(), line.end(),
					IPisright);
				if (i_left == 0){
					v_temp.pop_back();
					m_bias_filler->SetParameter(v_temp);
					v_temp.clear();
					b_enter_bias = false;
				}
			}
		}

		return true;
	}

	bool JInnerProductParam::Show(){
		cout << "InnerProduct Param {" << endl;
		cout << "\tnum_output: " << m_num_output << endl;
		cout << "\tbias_term: " << m_bias_term << endl;
		if (m_weight_filler){
			m_weight_filler->Show();
		}
		if (m_bias_filler){
			m_bias_filler->Show();
		}
		cout << "\taxis: " << m_axis << endl;
		cout << "}" << endl;

		return true;
	}
} // namespace jaffe