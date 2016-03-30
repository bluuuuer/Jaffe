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

	bool JBlobProto::Show(){
		cout << "blob_proto: " << endl;
		cout << "\tdata:" << m_data << endl;
		for (int i = 0; i < m_diff.size(); i++){
			cout << "\tdiff[" << i << "]: " << m_diff.at(i) << endl;
		}
		for (int i = 0; i < m_double_data.size(); i++){
			cout << "\tdouble_data[" << i << "]: " << 
				m_double_data.at(i) << endl;
		}
		for (int i = 0; i < m_double_diff.size(); i++){
			cout << "\tdouble_diff[" << i << "]: " <<
				m_double_diff.at(i) << endl;
		}
		cout << "\tnum: " << m_num << endl;
		cout << "\tchannels: " << m_channels << endl;
		cout << "\theight: " << m_height << endl;
		cout << "\twidth: " << m_width << endl;
		return true;
	}

} // namespace jaffe