#include "convolution_param.h"

namespace jaffe {

	bool CPisleft(char c){
		return c == '{';
	}

	bool CPisright(char c){
		return c == '}';
	}

	bool JConvolutionParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting Convolution Layer (" << m_s_name
			<< ")...";

		string line = "";
		vector<string> v_unique_param;
		bool b_enter = false;
		int i_left = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			if (line.find("convolution_param {") != string::npos){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(),
					CPisleft);
			}
			else if (b_enter){
				v_unique_param.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					CPisleft);
				i_left -= count_if(line.begin(), line.end(),
					CPisright);
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

	bool JConvolutionParam::SetUniqueParam(const vector<string> param){
		string line = "";
		bool b_enter_weight = false;
		bool b_enter_bias = false;
		int i_left = 0;
		vector<string> v_temp;
		int i_temp = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			// 没有进入更深的参数
			if (!b_enter_weight && !b_enter_bias){

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
			if (line.find("weight_filler") != string::npos){
				b_enter_weight = false;
				m_weight_filler = new JFillerParam;
				i_left += count_if(line.begin(), line.end(),
					CPisleft);
			}
			else if (b_enter_weight){
				v_temp.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					CPisleft);
				i_left -= count_if(line.begin(), line.end(),
					CPisright);
				if (i_left == 0){
					v_temp.pop_back();
					m_weight_filler->SetParameter(v_temp);
					v_temp.clear();
					b_enter_weight = false;
				}
			}
			// 进入 bias_filler 参数空间
			if (line.find("bias_filler") != string::npos){
				b_enter_bias = true;
				m_bias_filler = new JFillerParam;
				i_left += count_if(line.begin(), line.end(),
					CPisleft);
			}
			else if (b_enter_bias){
				v_temp.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					CPisleft);
				i_left -= count_if(line.begin(), line.end(),
					CPisright);
				if (i_left == 0){
					v_temp.pop_back();
					m_bias_filler->SetParameter(v_temp);
					v_temp.clear();
					b_enter_bias = false;
				}
			}
		}

		return true;
	}

	bool JConvolutionParam::Show(){
		cout << endl;
		cout << "Convolution Layer (" << m_s_name << "):" << endl;
		ShowSharedParam();
		ShowUniqueParam();
		return true;
	}

	bool JConvolutionParam::ShowUniqueParam(){

		cout << "conv_param: {" << endl;
		cout << "\tnum_output: " << m_num_output << endl;
		cout << "\tm_bias_term: " << m_bias_term << endl;
		for (int i = 0; i < m_kernel_size.size(); i++){
			cout << "\tkernel_size[" << i << "]: " <<
				m_kernel_size[i] << endl;
		}
		for (int i = 0; i < m_pad.size(); i++){
			cout << "\tpad[" << i << "]: " << m_pad[i] << endl;
		}
		for (int i = 0; i < m_stride.size(); i++){
			cout << "\tstride[" << i << "]: " << m_stride[i] <<
				endl;
		}
		cout << "\tpad_h: " << m_pad_h << endl;
		cout << "\tpad_w: " << m_pad_w << endl;
		cout << "\tkernel_h: " << m_kernel_h << endl;
		cout << "\tkernel_w: " << m_kernel_w << endl;
		cout << "\tstride_h: " << m_stride_h << endl;
		cout << "\tstride_w: " << m_stride_w << endl;
		cout << "\tgroup: " << m_group << endl;
		if (m_weight_filler){
			m_weight_filler->Show();
		}
		if (m_bias_filler){
			m_bias_filler->Show();
		}
		cout << "\tengine: " << m_engine << endl;
		cout << "\taxis: " << m_axis << endl;
		cout << "\tforce_nd_im2col: " << m_force_nd_im2col <<  endl;
		cout << "}" << endl;

		return true;
	}
}