#include "dropout_param.h"

namespace jaffe {

	bool DRPisleft(char c){
		return c == '{';
	}

	bool DRPisright(char c){
		return c == '}';
	}

	bool JDropoutParam::SetParam(const vector<string> param){
		SetSharedParam(param);
		
		cout << "Initting Dropout Layer \"" << m_s_name
			<< "\"..." << endl;

		string line = "";
		vector<string> v_unique_param;
		bool b_enter = false;
		int i_left = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			if (line.find(" dropout_param") != string::npos){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(),
					DRPisleft);
			}
			else if (b_enter){
				v_unique_param.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					DRPisleft);
				i_left -= count_if(line.begin(), line.end(),
					DRPisright);
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

	bool JDropoutParam::SetUniqueParam(const vector<string> param){
		string line = "";

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			matchFloat(line, "dropout_ratio:", &m_dropout_ratio);
		}

		cout << "Done" << endl;
		return true;
	}
} // namespace jaffe