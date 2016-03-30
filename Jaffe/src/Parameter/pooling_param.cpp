#include "pooling_param.h"

namespace jaffe{

	bool JPoolingParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting pooling layer \"" << m_name
			<< "\"..." << endl;

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
		cout << "Done" << endl;
		return true;
	}
} // namespace jaffe