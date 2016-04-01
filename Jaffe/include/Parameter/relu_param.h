#ifndef RELU_PARAM_H_H
#define RELU_PARAM_H_H

#include "layer_param.h"

namespace jaffe{

	class JReluParam : public JLayerParam{
	public:
		JReluParam(){
			m_negative_slope = 0.0;
			m_engine = DEFAULT;
		};
		~JReluParam(){};
		bool SetParam(const vector<string> param);
	private:
		float m_negative_slope;
		enum Engine{
			DEFAULT = 0,
			CAFFE = 1,
			CUDNN = 2
		};
		Engine m_engine;

		bool SetUniqueParam(const vector<string> param);
	};
} // namespace jaffe
#endif