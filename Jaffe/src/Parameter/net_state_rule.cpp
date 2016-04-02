#include "net_state_rule.h"

namespace jaffe{

	bool JNetStateRule::SetParam(const vector<string> param){
		string line = "";
		string str_temp;
		
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			matchInt(line, "min_level:", &m_min_level);
			matchInt(line, "max_level:", &m_max_level);

			if (matchString(line, "stage:", &str_temp)){
				m_stage.push_back(str_temp);
			}

			if (matchString(line, "not_stage:", &str_temp)){
				m_not_stage.push_back(str_temp);
			}
		}

		return true;
	}

	bool JNetStateRule::Show(){
		cout << "net_state_rule: " << endl;
		cout << "\tmin_level: " << m_min_level << endl;
		cout << "\tmax_level: " << m_max_level << endl;
		for (int i = 0; i < m_stage.size(); i++){
			cout << "\tstage[" << i << "]: " << m_stage.at(i) 
				<< endl;
		}
		for (int i = 0; i < m_not_stage.size(); i++){
			cout << "\tsnot_tage[" << i << "]: " << 
				m_not_stage.at(i) << endl;
		}
		return true;
	}

} // namespace jaffe