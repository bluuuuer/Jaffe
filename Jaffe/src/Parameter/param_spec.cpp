#include "param_spec.h"

namespace jaffe {

	bool JParamSpec::SetParam(const vector<string> param){
		string line;
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			matchString(line, "name:", &m_name);
			
			if (line.find("share_mode:") != string::npos){
				if (line.find("PERMISSIVE") != string::npos){
					m_share_mode = PERMISSIVE;
				}
			}
			matchFloat(line, "lr_mult:", &m_lr_mult);
			matchFloat(line, "decay_mult:", &m_decay_mult);
		}

		return true;
	}

	void JParamSpec::Show(){
		cout << "ParamSpec {" << endl;
		cout << "\tname: " << m_name << endl;
		cout << "\tshare_mode: " << m_share_mode << endl;
		cout << "\tlr_mult: " << m_lr_mult << endl;
		cout << "\tdecay_mult: " << m_decay_mult << endl;
		cout << "}" << endl;
	}
} // namespace jaffe