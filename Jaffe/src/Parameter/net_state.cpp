#include "net_state.h"

namespace jaffe {

	bool JNetState::SetParam(const vector<string> param){
		string line = "";
		string str_temp;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			matchInt(line, "level:", &m_level);

			if (matchString(line, "stage:", &str_temp)){
				m_stage.push_back(str_temp);
			}
		}

		return true;
	}

} // namespace jaffe