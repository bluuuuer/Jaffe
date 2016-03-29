#include "convolution_layer_param.h"

namespace jaffe {
	bool CLPisleft(char c){
		return c == '{';
	}

	bool CLPisright(char c){
		return c == '}';
	}

	bool ConvolutionLayerParam::setParam(vector<string> param){
		setSharedParam(param);

		cout << "Initting convolution layer \"" << this->name << "\"..."
			<< endl;

		string line;
		bool enter_weight_f = false;
		bool enter_bias_f = false;
		int left = 0;
		vector<string> temp_s_v;
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			// 没有进入更深的参数
			if (!enter_weight_f && !enter_bias_f){
				int temp = 0;

				matchInt(line, "num_output:", &this->num_output);
				matchBool(line, "bias_term:", &this->bias_term);

				if (matchInt(line, "pad:", &temp))
					this->pad.push_back(temp);

				if (matchInt(line, "kernel_size:", &temp))
					this->kernel_size.push_back(temp);

				if (matchInt(line, "stride:", &temp))
					this->stride.push_back(temp);
				matchInt(line, "pad_h:", &this->pad_h);
				matchInt(line, "pad_w:", &this->pad_w);
				matchInt(line, "kernel_h", &this->kernel_h);
				matchInt(line, "kernel_w", &this->kernel_w);
				matchInt(line, "stride_h", &this->stride_h);
				matchInt(line, "stride_w", &this->stride_w);
				matchInt(line, "group:", &this->group);
			}
			// 进入 weight_filler 参数空间
			if (line.find("weight_filler") != string::npos
				&& !enter_weight_f){
				enter_weight_f = true;
				this->weight_filler = new FillerParam;
				left += count_if(line.begin(), line.end(), CLPisleft);
			}
			else if (enter_weight_f){
				temp_s_v.push_back(line);
				left += count_if(line.begin(), line.end(), CLPisleft);
				left -= count_if(line.begin(), line.end(), CLPisright);
				if (left == 0){
					temp_s_v.pop_back();
					this->weight_filler->setParameter(temp_s_v);
					temp_s_v.clear();
					enter_weight_f = false;
				}
			}
			// 进入 bias_filler 参数空间
			if (line.find("bias_filler") != string::npos
				&& !enter_bias_f){
				enter_bias_f = true;
				this->bias_filler = new FillerParam;
				left += count_if(line.begin(), line.end(), CLPisleft);
			}
			else if (enter_bias_f){
				temp_s_v.push_back(line);
				left += count_if(line.begin(), line.end(), CLPisleft);
				left -= count_if(line.begin(), line.end(), CLPisright);
				if (left == 0){
					temp_s_v.pop_back();
					this->bias_filler->setParameter(temp_s_v);
					temp_s_v.clear();
					enter_bias_f = false;
				}
			}
		}
		cout << "Done" << endl;
		return true;
	}

	bool ConvolutionLayerParam::show(){
		cout << endl;
		cout << "name: " << this->name << endl;
		cout << "type: " << this->type << endl;
		cout << "num_output: " << this->num_output << endl;
		for (int i = 0; i < this->kernel_size.size(); i++)
			cout << "kernel_size[" << i << "]: " << this->kernel_size[i]
			<< endl;
		for (int i = 0; i < this->pad.size(); i++)
			cout << "pad[" << i << "]: " << this->pad[i] << endl;
		for (int i = 0; i < this->stride.size(); i++)
			cout << "stride[" << i << "]: " << this->stride[i] << endl;
		cout << "pad_h: " << this->pad_h << endl;
		cout << "pad_w: " << this->pad_w << endl;
		cout << "kernel_h: " << this->kernel_h << endl;
		cout << "kernel_w: " << this->kernel_w << endl;
		cout << "stride_h: " << this->stride_h << endl;
		cout << "stride_w: " << this->stride_w << endl;
		cout << "group: " << this->group << endl;
		this->weight_filler->show();
		this->bias_filler->show();
		cout << "engine: " << this->engine << endl;
		cout << "axis: " << this->axis << endl;
		cout << "force_nd_im2col: " << this->force_nd_im2col << endl;
		for (int i = 0; i < this->param_spec.size(); i++)
			this->param_spec.at(i).show();

		return true;
	}
}