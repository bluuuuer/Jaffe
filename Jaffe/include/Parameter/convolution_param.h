#ifndef CONVOLUTION_PARAM_H_H
#define CONVOLUTION_PARAM_H_H

#include "layer_param.h"
#include "filler_param.h"

namespace jaffe {

	class JConvolutionParam : public JLayerParam{
	public:
		JConvolutionParam(){
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
		~JConvolutionParam(){
			vector<int>(m_pad).swap(m_pad);
			vector<int>(m_kernel_size).swap(m_kernel_size);
			vector<int>(m_stride).swap(m_stride);
			delete m_weight_filler;
			delete m_bias_filler;
		};
		bool SetParam(const vector<string> param);
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

		bool SetUniqueParam(const vector<string> param);
		bool ShowUniqueParam();
	};
}
#endif