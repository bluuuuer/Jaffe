#ifndef SOFTMAX_PARAM_H_H
#define SOFTMAX_PARAM_H_H

#include "layer_param.h"

namespace jaffe {
	
	class JSoftmaxParam : public JLayerParam{
	public:
		JSoftmaxParam(){
			m_engine = DEFAULT;
			m_axis = 1;
		};
		~JSoftmaxParam(){};
		bool SetParam(const vector<string> param);
		bool Show();

	private:
		enum Engine{
			DEFAULT = 0,
			CAFFE = 1,
			CUDNN = 2
		};
		Engine m_engine;
		int m_axis;
		
		bool SetUniqueParam(const vector<string> param);
		bool ShowUniqueParam();
	};
} // namespace jaffe
#endif