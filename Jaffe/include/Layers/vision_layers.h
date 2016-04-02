#ifndef VISION_LAYERS_H_H
#define VISION_LAYERS_H_H

#include "layer.h"
#include "convolution_param.h"
#include "pooling_param.h"
#include "lrn_param.h"

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
			delete m_param;
		};

		bool Init(const vector<string> param);

		bool SetParam(const vector<string> param);

		bool ReadParam();

		virtual bool Show();

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
			delete m_param;
		};

		bool Init(const vector<string> param);

		bool SetParam(const vector<string> param);

		bool ReadParam();

		virtual bool Show();

	private:
		JPoolingParam* m_param;

		int m_kernel_h, m_kernel_w;
		int m_stride_h, m_stride_w;
		int m_pad_h, m_pad_w;
		int m_channels;
		int m_height, m_width;
		int m_pooled_height, m_pooled_width;
		bool m_global_pooling;

	}; // class JPoolingLayer

	template <typename Dtype>
	class JLRNLayer : public JLayer<Dtype>{
	public:
		JLRNLayer(){
			m_param = new JLRNParam;
		};
		~JLRNLayer(){
			delete[] m_param;
		};
		
		bool Init(const vector<string> param);
		bool SetParam(const vector<string> param);
		bool ReadParam();
		virtual bool Show();

	private:
		JLRNParam* m_param;

		int m_size;
		int pre_pad;
		Dtype m_alpha;
		Dtype m_beta;
		Dtype m_k;
		int m_num;
		int m_channels;
		int m_height;
		int m_width;

		//Blob<Dtype> m_scale;

		//shared_ptr<SplitLayer<Dtype>> m_split_layer;
		//vector<Blob<Dtype>*> m_split_top_vec;
		//shared_ptr<PowerLayer<Dtype>> m_square_layer;
		//Blob<Dtype> m_square_input;
		//Blob<Dtype> m_square_output;
		//vector<Blob<Dtype>*> m_square_bottom_vec;
		//vector<Blob<Dtype>*> m_square_top_vec;
		//shared_ptr<PoolingLayer<Dtype>> m_pool_layer;
		//Blob<Dtype> m_power_output;
		//vecotr<Blob<Dtype>*> pool_top_vec;
		//shared_ptr<PowerLayer<Dtype>> m_power_layer;
		//Blob<Dtype> m_power_output;
		//vecotr<Blob<Dtype>*> m_power_top_vec;
		//shared_ptr<EltwiseLayer<Dtype>> m_product_layer;
		//Blob<Dtype> m_product_input;
		//vector<Blob<Dtype>*> m_product_bottom_vec;

	}; // JLRNLayer
}
#endif