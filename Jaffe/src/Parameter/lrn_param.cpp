#include "lrn_param.h"

namespace jaffe{

	bool LRPisleft(char c){
		return c == '{';
	}

	bool LRPisright(char c){
		return c == '}';
	}

	bool JLRNParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting LRN Layer (" << m_s_name << ")...";

		string line = "";
		vector<string> v_unique_param;
		bool b_enter = false;
		int i_left = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			if (line.find(" lrn_param") != string::npos){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(),
					LRPisleft);
			}
			else if (b_enter){
				v_unique_param.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					LRPisleft);
				i_left -= count_if(line.begin(), line.end(),
					LRPisright);
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

	bool JLRNParam::SetUniqueParam(const vector<string> param){
		string line = "";

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			matchInt(line, "local_size:", &m_local_size);
			matchFloat(line, "alpha:", &m_alpha);
			matchFloat(line, "beta:", &m_beta);

			if (line.find("norm_region:") != string::npos){
				if (line.find("WITHIN_CHANNEL") != string::npos){
					m_norm_region = WITHIN_CHANNEL;
				}
			}

			matchFloat(line, "k:", &m_k);

			if (line.find("engine:") != string::npos){
				if (line.find("CAFFE") != string::npos){
					m_engine = CAFFE;
				}
				else if (line.find("CUDNN") != string::npos){
					m_engine = CUDNN;
				}
			}
		}

		return true;
	}

	bool JLRNParam::Show(){
		cout << "LRN Layer (" << m_s_name << ")" << endl;
		ShowSharedParam();
		ShowUniqueParam();
		return true;
	}

	bool JLRNParam::ShowUniqueParam(){
		cout << "LRN parameter {" << endl;
		cout << "\tlocal_size: " << m_local_size << endl;
		cout << "\talpha: " << m_alpha << endl;
		cout << "\tbeta: " << m_beta << endl;
		cout << "\tnorm_region: " << m_norm_region << endl;
		cout << "\tk: " << m_k << endl;
		cout << "\tengine: " << m_engine << endl;
		cout << "}" << endl;

		return true;
	}

} // namespace jaffe