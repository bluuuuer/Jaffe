#ifndef LRN_PARAM_H_H
#define LRN_PARAM_H_H

#include "layer_param.h"

namespace jaffe {

	class JLRNParam : public JLayerParam{
	public:
		JLRNParam(){
			m_local_size = 5;
			m_alpha = 1.0;
			m_beta = 0.75;
			m_norm_region = ACROSS_CHANNELS;
			m_k = 1.0;
			m_engine = DEFAULT;
		};
		~JLRNParam(){};
		bool SetParam(const vector<string> param);
		bool Show();
	private:
		int m_local_size;
		float m_alpha;
		float m_beta;
		enum NormRegion{
			ACROSS_CHANNELS = 0,
			WITHIN_CHANNEL = 1
		};
		NormRegion m_norm_region;
		float m_k;
		enum Engine{
			DEFAULT = 0,
			CAFFE = 1,
			CUDNN = 2
		};
		Engine m_engine;

		bool SetUniqueParam(const vector<string> param);
		bool ShowUniqueParam();
	};
} // namespace jaffe
#endif