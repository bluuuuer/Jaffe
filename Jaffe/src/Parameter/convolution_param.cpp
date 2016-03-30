#include "convolution_param.h"

namespace jaffe {
	bool CLPisleft(char c){
		return c == '{';
	}

	bool CLPisright(char c){
		return c == '}';
	}

	bool JConvolutionParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting convolution layer \"" << m_name 
			<< "\"..."<< endl;

		string line = "";
		bool enter_weight_f = false;
		bool enter_bias_f = false;
		int left = 0;
		vector<string> temp_s_v;
		int i_temp = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			// 没有进入更深的参数
			if (!enter_weight_f && !enter_bias_f){

				matchInt(line, "num_output:", &m_num_output);
				matchBool(line, "bias_term:", &m_bias_term);

				if (matchInt(line, "pad:", &i_temp))
					m_pad.push_back(i_temp);

				if (matchInt(line, "kernel_size:", &i_temp))
					m_kernel_size.push_back(i_temp);

				if (matchInt(line, "stride:", &i_temp))
					m_stride.push_back(i_temp);

				matchInt(line, "pad_h:", &m_pad_h);
				matchInt(line, "pad_w:", &m_pad_w);
				matchInt(line, "kernel_h", &m_kernel_h);
				matchInt(line, "kernel_w", &m_kernel_w);
				matchInt(line, "stride_h", &m_stride_h);
				matchInt(line, "stride_w", &m_stride_w);
				matchInt(line, "group:", &m_group);
				if (line.find("engine:") != string::npos){
					if (line.find("CAFFE") != string::npos){
						m_engine = CAFFE;
					}
					else if (line.find("CUDNN") != string::npos){
						m_engine = CUDNN;
					}
				}
			}
			// 进入 weight_filler 参数空间
			if (line.find("weight_filler") != string::npos
				&& !enter_weight_f){
				enter_weight_f = true;
				m_weight_filler = new JFillerParam;
				left += count_if(line.begin(), line.end(), 
					CLPisleft);
			}
			else if (enter_weight_f){
				temp_s_v.push_back(line);
				left += count_if(line.begin(), line.end(), 
					CLPisleft);
				left -= count_if(line.begin(), line.end(), 
					CLPisright);
				if (left == 0){
					temp_s_v.pop_back();
					m_weight_filler->SetParameter(temp_s_v);
					temp_s_v.clear();
					enter_weight_f = false;
				}
			}
			// 进入 bias_filler 参数空间
			if (line.find("bias_filler") != string::npos
				&& !enter_bias_f){
				enter_bias_f = true;
				m_bias_filler = new JFillerParam;
				left += count_if(line.begin(), line.end(), 
					CLPisleft);
			}
			else if (enter_bias_f){
				temp_s_v.push_back(line);
				left += count_if(line.begin(), line.end(), 
					CLPisleft);
				left -= count_if(line.begin(), line.end(), 
					CLPisright);
				if (left == 0){
					temp_s_v.pop_back();
					m_bias_filler->SetParameter(temp_s_v);
					temp_s_v.clear();
					enter_bias_f = false;
				}
			}
		}
		cout << "Done" << endl;
		return true;
	}

	bool JConvolutionParam::Show(){
		cout << endl;
		cout << "name: " << m_name << endl;
		cout << "type: " << m_type << endl;
		cout << "num_output: " << m_num_output << endl;
		for (int i = 0; i < m_kernel_size.size(); i++)
			cout << "kernel_size[" << i << "]: " << 
			m_kernel_size[i]
			<< endl;
		for (int i = 0; i < m_pad.size(); i++)
			cout << "pad[" << i << "]: " << m_pad[i] << endl;
		for (int i = 0; i < m_stride.size(); i++)
			cout << "stride[" << i << "]: " << m_stride[i] << 
			endl;
		cout << "pad_h: " << m_pad_h << endl;
		cout << "pad_w: " << m_pad_w << endl;
		cout << "kernel_h: " << m_kernel_h << endl;
		cout << "kernel_w: " << m_kernel_w << endl;
		cout << "stride_h: " << m_stride_h << endl;
		cout << "stride_w: " << m_stride_w << endl;
		cout << "group: " << m_group << endl;
		m_weight_filler->Show();
		m_bias_filler->Show();
		cout << "engine: " << m_engine << endl;
		cout << "axis: " << m_axis << endl;
		cout << "force_nd_im2col: " << m_force_nd_im2col << 
			endl;
		for (int i = 0; i < m_param_spec.size(); i++)
			m_param_spec.at(i).Show();

		return true;
	}
}