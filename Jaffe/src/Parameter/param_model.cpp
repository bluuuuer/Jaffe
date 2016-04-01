#include "param_model.h"

namespace jaffe {

	bool MPisleft(char c){
		return c == '{';
	}

	bool MPisright(char c){
		return c == '}';
	}

	bool JModelParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting Model Layer \"" << m_name << "\"..."
			<< endl;

		string line = "";
		bool b_enter = false;
		int i_left = 0;
		vector<string> v_str_temp;
		
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);


			if (line.find("model_param {")){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(),
					MPisleft);
			}
			else if (b_enter){
				v_str_temp.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					MPisleft);
				i_left -= count_if(line.begin(), line.end(),
					MPisright);
				if (i_left == 0){
					v_str_temp.pop_back();
					SetUniqueParam(v_str_temp);
					v_str_temp.clear();
					b_enter = false;
				}
			}
		}

		return true;
	}

	bool JModelParam::SetUniqueParam(const vector<string> param){
		string line = "";

		bool b_enter_xxx_param = false;
		bool b_enter_yyy_param = false;
		bool b_enter_deep = false;
		int left = 0;
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			if (!b_enter_deep){
				matchString(line, "param_s_o:", &m_param_s_o);
				matchInt(line, "param_i_o:", &m_param_i_o);
				matchFloat(line, "param_f_o:", &m_param_f_o);
				matchBool(line, "param_b_o:", &m_param_b_o);
				matchDouble(line, "param_d_o:", &m_param_d_o);
				matchLong(line, "param_l_o:", &m_param_l_o);

			}
			if (line.find("xxx_param {") != string::npos){

			}
			else if (b_enter_xxx_param){

			}
			if (line.find("yyy_param {") != string::npos){

			}
			else if (b_enter_yyy_param){

			}
		}

		cout << "Done" << endl;
		return true;
	}

	bool JModelParam::Show(){
		ShowSharedParam();
		
		cout << "Model Parameter (" << m_name << "):" << endl;
		cout << "\tparam_s_o: " << m_param_s_o << endl; // Ëõ½ø
		//....
		cout << "\tparam_l_o: " << m_param_l_o << endl;
		m_xxx_param->Show();

		for (int i = 0; i < m_param_s_r.size(); i++){
			cout << "\tparam_s_r[" << i << "]: " << 
				m_param_s_r.at(i) << endl;
		}
		//....
		for (int i = 0; i < m_yyy_param.size(); i++){
			m_yyy_param.at(i).Show();
		}

		return true;
	}

} // namespace jaffe