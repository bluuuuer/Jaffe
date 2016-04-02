#include "accuracy_param.h"

namespace jaffe {

	bool APisleft(char c){
		return c == '{';
	}

	bool APisright(char c){
		return c == '}';
	}

	bool JAccuracyParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting Accuracy Layer (" << m_s_name
			<< ")...";

		string line = "";
		vector<string> v_unique_param;
		bool b_enter = false;
		int i_left = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			if (line.find("convolution_param {") != string::npos){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(),
					APisleft);
			}
			else if (b_enter){
				v_unique_param.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					APisleft);
				i_left -= count_if(line.begin(), line.end(),
					APisright);
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
	
	bool JAccuracyParam::SetUniqueParam(const vector<string> param){
		string line = "";
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			matchInt(line, "top_k", &m_top_k);
			matchInt(line, "axis", &m_axis);
			matchInt(line, "ignore_label", &m_ignore_label);
		}

		return true;
	}

	bool JAccuracyParam::Show(){
		cout << endl;
		cout << "Accuracy Layer (" << m_s_name << "):" << endl;
		ShowSharedParam();
		ShowUniqueParam();
		return true;
	}

	bool JAccuracyParam::ShowUniqueParam(){
		cout << "accuracy_param {" << endl;
		cout << "\ttop_k: " << m_top_k << endl;
		cout << "\taxis: " << m_axis << endl;
		cout << "\tignore_label: " << m_ignore_label << endl;
		cout << "}" << endl;
		return true;
	}

} // namespace jaffe