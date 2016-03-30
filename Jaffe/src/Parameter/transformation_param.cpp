#include "transformation_param.h"

namespace jaffe {

	bool JTransformationParam::SetParam(const vector<string> param){
		string line = "";
		float f_temp;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			matchFloat(line, "scale:", &m_scale);
			matchBool(line, "mirror", &m_mirror);
			matchInt(line, "crop_size:", &m_crop_size);
			matchString(line, "mean_file", &m_mean_file);

			if (matchFloat(line, "mean_value:", &f_temp)){
				m_mean_value.push_back(f_temp);
			}

			matchBool(line, "force_color:", &m_force_color);
			matchBool(line, "force_gray", &m_force_gray);
		}

		return true;
	}

} // namespace jaffe