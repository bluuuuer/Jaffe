#include "relu_param.h"

namespace jaffe{
	bool JReluParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting relu layer \"" << m_name
			<< "\"..." << endl;

		string line = "";
		
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			matchFloat(line, "negative_slope:", &m_negative_slope);

			if (line.find("engine:") != string::npos){
				if (line.find("CAFFE") != string::npos){
					m_engine = CAFFE;
				}
				else if (line.find("CUDNN") != string::npos){
					m_engine = CUDNN;
				}
			}
		}
		
		cout << "Done" << endl;
		return true;
	}
} // namespace jaffe