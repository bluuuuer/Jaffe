#ifndef DROPOUT_PARAM_H_H
#define DROPOUT_PARAM_H_H
 
#include "layer_param.h"

namespace jaffe {

	class JDropoutParam : public JLayerParam{
	public:
		JDropoutParam(){
			m_dropout_ratio = 0.5;
		};
		~JDropoutParam(){};
		bool SetParam(const vector<string> param);
		bool Show();

	private:
		float m_dropout_ratio;

		bool SetUniqueParam(const vector<string> param);
		bool ShowUniqueParam();
	};
} // namespace jaffe
#endif