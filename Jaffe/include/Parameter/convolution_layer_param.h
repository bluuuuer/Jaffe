#ifndef CONVOLUTION_LAYER_PARAM_H_H
#define CONVOLUTION_LAYER_PARAM_H_H

#include "layer_param.h"
#include "filler_param.h"
#include "param_spec.h"

namespace jaffe {

	class JConvolutionLayerParam : public JLayerParam{
	public:
		JConvolutionLayerParam(){
			m_num_output = 0;
			m_bias_term = true;
			m_pad_h = 0;
			m_pad_w = 0;
			m_kernel_h = 0;
			m_kernel_w = 0;
			m_stride_h = 0;
			m_stride_w = 0;
			m_group = 1;
			m_engine = DEFAULT;
			m_axis = 1;
			m_force_nd_im2col = false;
		};
		~JConvolutionLayerParam(){
			delete[] m_weight_filler;
			delete[] m_bias_filler;
		};
		bool SetParam(vector<string> param);
		bool Show();

	private:
		// 各种独有参数
		int m_num_output;
		bool m_bias_term;
		vector<int> m_pad;
		vector<int> m_kernel_size;
		vector<int> m_stride;
		int m_pad_h;
		int m_pad_w;
		int m_kernel_h;
		int m_kernel_w;
		int m_stride_h;
		int m_stride_w;
		int m_group;
		JFillerParam* m_weight_filler;
		JFillerParam* m_bias_filler;
		enum Engine{
			DEFAULT = 0,
			CAFFE = 1,
			CUDNN = 2
		};
		Engine m_engine;
		int m_axis;
		bool m_force_nd_im2col;
	};
}
#endif