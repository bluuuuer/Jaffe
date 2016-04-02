#ifndef INNER_PRODUCT_PARAM_H_H
#define INNER_PRODUCT_PARAM_H_H

#include "layer_param.h"
#include "filler_param.h"

namespace jaffe{
	
	class JInnerProductParam : public JLayerParam{
	public:
		JInnerProductParam(){
			m_num_output = 0;
			m_bias_term = true;
			m_axis = 1;
		};
		~JInnerProductParam(){
			if (m_weight_filler){
				delete m_weight_filler;
			}
			if (m_bias_filler){
				delete m_bias_filler;
			}
		};
		bool SetParam(const vector<string> param);
		bool Show();

	private:
		int m_num_output;
		bool m_bias_term;
		JFillerParam* m_weight_filler;
		JFillerParam* m_bias_filler;
		int m_axis;

		bool SetUniqueParam(const vector<string> param);
	};
} // namespace jaffe
#endif