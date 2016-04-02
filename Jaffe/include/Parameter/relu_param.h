#ifndef RELU_PARAM_H_H
#define RELU_PARAM_H_H

#include "layer_param.h"

namespace jaffe{

	class JReLUParam : public JLayerParam{
	public:
		JReLUParam(){
			m_negative_slope = 0.0;
			m_engine = DEFAULT;
		};
		~JReLUParam(){};
		bool SetParam(const vector<string> param);
		bool Show();

	private:
		float m_negative_slope;
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