#include "softmax_param.h"

namespace jaffe {

	bool SPisleft(char c){
		return c == '{';
	}

	bool SPisright(char c){
		return c == '}';
	}

	bool JSoftmaxParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting Softmax Layer (" << m_s_name
			<< ")...";

		string line = "";
		vector<string> v_unique_param;
		bool b_enter = false;
		int i_left = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			if (line.find(" softmax_param") != string::npos){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(),
					SPisleft);
			}
			else if (b_enter){
				v_unique_param.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					SPisleft);
				i_left -= count_if(line.begin(), line.end(),
					SPisright);
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

	bool JSoftmaxParam::SetUniqueParam(const vector<string> param){
		string line = "";

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			if (line.find("engine") != string::npos){
				if (line.find("CAFFE") != string::npos){
					m_engine = CAFFE;
				}
				else if (line.find("CUDNN") != string::npos){
					m_engine = CUDNN;
				}
			}

			matchInt(line, "axis:", &m_axis);
		}

		return true;
	}

	bool JSoftmaxParam::Show(){
		cout << endl;
		cout << "Softmax Layer (" << m_s_name << ")" << endl;
		ShowSharedParam();
		ShowUniqueParam();
		return true;
	}

	bool JSoftmaxParam::ShowUniqueParam(){
		cout << "softmax_param: {" << endl;
		cout << "\tengine: " << m_engine << endl;
		cout << "\taxis: " << m_axis << endl;
		cout << "}" << endl;

		return true;
	}

} // namespace jaffe