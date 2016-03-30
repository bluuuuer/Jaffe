#include "blob_proto.h"

namespace jaffe {

	bool JBlobProto::SetParam(const vector<string> param){
		string line = "";
		float f_temp;
		double d_temp;
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			matchFloat(line, "data:", &m_data);

			if (matchFloat(line, "diff:", &f_temp)){
				m_diff.push_back(f_temp);
			}

			if (matchDouble(line, "double_data", &d_temp)){
				m_double_data.push_back(d_temp);
			}

			if (matchDouble(line, "double_diff", &d_temp)){
				m_double_diff.push_back(d_temp);
			}

			matchInt(line, "num:", &m_num);
			matchInt(line, "channels:", &m_channels);
			matchInt(line, "height:", &m_height);
			matchInt(line, "width:", &m_width);
		}
		return true;
	}

} // namespace jaffe