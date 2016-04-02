#include "blob_shape.h"

namespace jaffe {

	bool JBlobShape::SetParam(const vector<string> param){
		string line = "";
		long l_temp;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			if (matchLong(line, "dim:", &l_temp)){
				m_dim.push_back(l_temp);
			}
		}

		return true;
	}

} // namespace jaffe