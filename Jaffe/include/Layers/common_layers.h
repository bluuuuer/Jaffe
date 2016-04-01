#ifndef COMMON_LAYERS_H_H
#define COMMON_LAYERS_H_H

#include "layer.h"
#include "softmax_param.h"

namespace jaffe {

	template <typename Dtype>
	class JSoftmaxLayer : public JLayer<Dtype>{
	public:
		JSoftmaxLayer(){
			m_param = new JSoftmaxParam;
		};
		~JSoftmaxLayer(){
			delete m_param;
		};

		bool Init(const vector<string> param); 

		bool SetParam(const vector<string> param);

		bool ReadParam();

		virtual bool Show();

	private:
		JSoftmaxParam* m_param;
	};

} // namespace jaffe
#endif