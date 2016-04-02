#ifndef ACCURACY_PARAM_H_H
#define ACCURACY_PARAM_H_H

#include "layer_param.h"

namespace jaffe {

	class JAccuracyParam : public JLayerParam{
	public:
		JAccuracyParam(){
			m_top_k = 1;
			m_axis = 1;
			m_ignore_label = 0;
		};
		~JAccuracyParam(){};
		bool SetParam(const vector<string> param);
		bool Show();

	private:
		int m_top_k;
		int m_axis;
		int m_ignore_label;

		bool SetUniqueParam(const vector<string> param);
		bool ShowUniqueParam();
	};

} // namespace jaffe
#endif