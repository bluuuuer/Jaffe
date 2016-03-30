#ifndef DATA_LAYERS_H_H
#define DATA_LAYERS_H_H

#include "layer.h"
#include "data_param.h"

namespace jaffe {
	template <typename Dtype>
	class JBaseDataLayer : public JLayer<Dtype>{
	public:
		JBaseDataLayer(){};
		~JBaseDataLayer(){};
	protected:
		//TransformationParameter transform_param;
		//vector<DataTransformer*> data_transformer;
	};

	template <typename Dtype>
	class JBasePrefetchingDataLayer : public JBaseDataLayer<Dtype>{
	public:
		JBasePrefetchingDataLayer(){};
		~JBasePrefetchingDataLayer(){};
	};

	template <typename Dtype>
	class JDataLayer : public  JBasePrefetchingDataLayer<Dtype>{
	public:
		JDataLayer(){
			m_param = new JDataParam;
		};
		~JDataLayer(){
			delete[] m_param;
		};
		bool Init(vector<string> param);
		virtual void Forward();
	private:
		JDataParam* m_param;
	};

}
#endif