#include "filler_param.h"

namespace jaffe {
	bool JFillerParam::SetParameter(const vector<string> param){
		string line;
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			matchString(line, "type:", &m_type);
			matchFloat(line, "value:", &m_value);
			matchFloat(line, "min:", &m_min);
			matchFloat(line, "max:", &m_max);
			matchFloat(line, "mean", &m_mean);
			matchFloat(line, "std:", &m_std);
			matchInt(line, "sparse:", &m_sparse);
		}
		return true;
	}

	void JFillerParam::Show(){
		cout << "Filler {" << endl;
		cout << "\ttype: " << m_type << endl;
		cout << "\tvalue: " << m_value << endl;
		cout << "\tmin: " << m_min << endl;
		cout << "\tmax: " << m_max << endl;
		cout << "\tmean: " << m_mean << endl;
		cout << "\tstd: " << m_std << endl;
		cout << "\tsparse: " << m_sparse << endl;
		cout << "\tVarianceNorm: " << m_variance_norm << endl;
		cout << "}" << endl;
	}
}  // namespace jaffe
