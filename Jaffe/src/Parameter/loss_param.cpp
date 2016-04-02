#include "loss_param.h"

namespace jaffe{

	bool JLossParam::SetParam(const vector<string> param){
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

		return true;
	}

	bool JLossParam::Show(){
		cout << "loss_parameter {" << endl;
		cout << "\tignore_label: " << m_ignore_label << endl;
		cout << "\tnormalization: " << m_normalization << endl;
		cout << "\tnormalize: " << m_normalize << endl;
		cout << "}" << endl;
		return true;
	}

} // namespace jaffe