#ifndef VISION_LAYERS_H_H
#define VISION_LAYERS_H_H

#include "layer.h"
#include "convolution_param.h"
#include "pooling_param.h"

namespace jaffe {

	template <typename Dtype>
	class JBaseConvolutionLayer : public JLayer<Dtype>{
	public:
		JBaseConvolutionLayer(){};

		~JBaseConvolutionLayer(){};

	};

	template <typename Dtype>
	class JConvolutionLayer : public JBaseConvolutionLayer<Dtype>{
	public:
		JConvolutionLayer(){
			m_param = new JConvolutionParam;
		};

		~JConvolutionLayer(){
			delete[] m_param;
		};

		bool Init(const vector<string> param);

		bool Show();

	private:

		JConvolutionParam* m_param;

	};

	template <typename Dtype>
	class JPoolingLayer : public JLayer<Dtype> {
	public:
		JPoolingLayer(){
			m_param = new JPoolingParam;
		};

		~JPoolingLayer(){
			delete[] m_param;
		};

		bool Init(const vector<string> param);

		bool SetParam(const vector<string> param);

		bool ReadParam();

		bool Show();

	private:
		JPoolingParam* m_param;

		int m_kernel_h, m_kernel_w;
		int m_stride_h, m_stride_w;
		int m_pad_h, m_pad_w;
		int m_channels;
		int m_height, m_width;
		int m_pooled_height, m_pooled_width;
		bool m_global_pooling;

	};
}
#endif