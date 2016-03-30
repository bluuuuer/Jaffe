#ifndef LOSS_PARAM_H_H
#define LOSS_PARAM_H_H

#include "layer_param.h"

namespace jaffe{

	class JLossParam : public JLayerParam{
	public:
		JLossParam(){
			m_ignore_label = 0;
			m_normalization = VALID;
			m_normalize = false;
		};
		~JLossParam(){};
		bool SetParam(const vector<string> param);

	private:
		int m_ignore_label;
		enum NormalizationMode{
			FULL = 0,
			VALID = 1,
			BATCH_SIZE = 2,
			NONE = 3
		};
		NormalizationMode m_normalization;
		bool m_normalize;
		
		bool SetUniqueParam(const vector<string> param);
	};
} // namespace jaffe

#endif