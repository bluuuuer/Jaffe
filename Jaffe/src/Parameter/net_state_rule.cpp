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

} // namespace jaffe