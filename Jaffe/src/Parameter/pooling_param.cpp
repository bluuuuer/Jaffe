#include "pooling_param.h"

namespace jaffe{

	bool PPisleft(char c){
		return c == '{';
	}

	bool PPisright(char c){
		return c == '}';
	}

	bool JPoolingParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting Pooling Layer (" << m_s_name
			<< ")...";

		string line = "";
		vector<string> v_unique_param;
		bool b_enter = false;
		int i_left = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			if (line.find(" pooling_param") != string::npos){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(),
					PPisleft);
			}
			else if (b_enter){
				v_unique_param.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					PPisleft);
				i_left -= count_if(line.begin(), line.end(),
					PPisright);
				if (i_left == 0){
					v_unique_param.pop_back();
					SetUniqueParam(v_unique_param);
					v_unique_param.clear();
					b_enter = false;
				}
			}
		}

		cout << "Done" << endl;

		return true;
	}

	bool JPoolingParam::SetUniqueParam(const vector<string> param){
		string line;
		int left = 0;
		vector<string> temp_s_v;
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			if (line.find("pool:") != string::npos){
				if (line.find("AVE") != string::npos){
					m_pool = AVE;
				}
				else if (line.find("STOCHASTIC") != string::npos){
					m_pool = STOCHASTIC;
				}
			}
			matchInt(line, "pad:", &m_pad);
			matchInt(line, "pad_h:", &m_pad_h);
			matchInt(line, "pad_w:", &m_pad_w);
			matchInt(line, "kernel_size:", &m_kernel_size);
			matchInt(line, "kernel_h:", &m_kernel_h);
			matchInt(line, "kernel_w:", &m_kernel_w);
			matchInt(line, "stride:", &m_stride);
			matchInt(line, "stride_h:", &m_stride_h);
			matchInt(line, "stride_w:", &m_stride_w);

			if (line.find("engine:") != string::npos){
				if (line.find("CAFFE") != string::npos){
					m_engine = CAFFE;
				}
				else if (line.find("CUDNN") != string::npos){
					m_engine = CUDNN;
				}
			}
			matchBool(line, "global_pooling:", &m_global_pooling);
		}

		return true;
	}

	bool JPoolingParam::Show(){
		cout << endl;
		cout << "Pooling Layer (" << m_s_name << "):" << endl;
		ShowSharedParam();
		ShowUniqueParam();
		return true;
	}

	bool JPoolingParam::ShowUniqueParam(){
		cout << "pooling_param {" << endl;
		cout << "\tpool: " << m_pool << endl;
		cout << "\tpad: " << m_pad << endl;
		cout << "\tpad_h: " << m_pad_h << endl;
		cout << "\tpad_w: " << m_pad_w << endl;
		cout << "\tkernel_size: " << m_kernel_size << endl;
		cout << "\tkernel_h: " << m_kernel_h << endl;
		cout << "\tkernel_w: " << m_kernel_w << endl; 
		cout << "\tstride: " << m_stride << endl;
		cout << "\tstride_h: " << m_stride_h << endl;
		cout << "\tstride_w: " << m_stride_w << endl;
		cout << "\tengine: " << m_engine << endl;
		cout << "\tglobal_pooling: " << m_global_pooling << endl;

		return true;
	}
} // namespace jaffe