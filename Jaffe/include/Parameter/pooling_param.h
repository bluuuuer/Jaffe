#ifndef POOLING_PARAM_H_H
#define POOLING_PARAM_H_H

#include "layer_param.h"

namespace jaffe{

	class JPoolingParam : public JLayerParam{
	public:
		JPoolingParam(){
			m_pool = MAX;
			m_pad = 0;
			m_pad_h = 0;
			m_pad_w = 0;
			m_kernel_size = 0;
			m_kernel_h = 0;
			m_kernel_w = 0;
			m_stride = 1;
			m_stride_h = 0;
			m_stride_w = 0;
			m_engine = DEFAULT;
			m_global_pooling = false;
		};
		~JPoolingParam(){};
		bool SetParam(const vector<string> param);
		bool Show();
	private:
		enum PoolMethod{
			MAX = 0,
			AVE = 1,
			STOCHASTIC = 2
		};
		PoolMethod m_pool;
		int m_pad;
		int m_pad_h;
		int m_pad_w;
		int m_kernel_size;
		int m_kernel_h;
		int m_kernel_w;
		int m_stride;
		int m_stride_h;
		int m_stride_w;
		enum Engine{
			DEFAULT = 0,
			CAFFE = 1,
			CUDNN = 2
		};
		Engine m_engine;
		bool m_global_pooling;

		bool SetUniqueParam(const vector<string> param);
		bool ShowUniqueParam();
	};
} // namespace jaffe
#endif