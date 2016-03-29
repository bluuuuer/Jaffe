#ifndef DATA_LAYERS_H_H
#define DATA_LAYERS_H_H

#include "layer.h"
#include "data_layer_param.h"

namespace jaffe {
	class JBaseDataLayer : public JLayer{
	public:
		JBaseDataLayer(){};
		~JBaseDataLayer(){};
	protected:
		//TransformationParameter transform_param;
		//vector<DataTransformer*> data_transformer;
	};

	class JBasePrefetchingDataLayer : public JBaseDataLayer{
	public:
		JBasePrefetchingDataLayer(){};
		~JBasePrefetchingDataLayer(){};
	};

	class JDataLayer : public  JBasePrefetchingDataLayer{
	public:
		JDataLayer(){
			m_parameter = new JDataLayerParam;
		};
		~JDataLayer(){};
		bool SetParam(vector<string> param);
		virtual void Forward();
	private:
		JDataLayerParam* m_parameter;
	};

}
#endif