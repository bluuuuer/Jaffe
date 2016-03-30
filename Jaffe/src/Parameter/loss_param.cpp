#include "loss_param.h"

namespace jaffe{

	bool LOPisleft(char c){
		return c == '{';
	}

	bool LOPisright(char c){
		return c == '}';
	}

	bool JLossParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting Loss Layer \"" << m_name
			<< "\"..." << endl;

		string line = "";
		vector<string> v_unique_param;
		bool b_enter = false;
		int i_left = 0;
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			if (line.find("loss_param") != string::npos){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(),
					LOPisleft);
			}
			else if (b_enter){
				v_unique_param.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					LOPisleft);
				i_left -= count_if(line.begin(), line.end(),
					LOPisright);
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

	bool JLossParam::SetUniqueParam(const vector<string> param){
		string line = "";
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			matchInt(line, "ignore_label:", &m_ignore_label);
			
			if (line.find("normalization:") != string::npos){
				if (line.find("FULL") != string::npos){
					m_normalization = FULL;
				}
				else if (line.find("BATCH_SIZE") != string::npos){
					m_normalization = BATCH_SIZE;
				}
				else if (line.find("NONE") != string::npos){
					m_normalization = NONE;
				}
			}

			matchBool(line, "normalize:", &m_normalize);
		}

		cout << "Done" << endl;
		return true;
	}
} // namespace jaffe