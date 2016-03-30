#ifndef DATA_LAYERS_H_H
#define DATA_LAYERS_H_H

#include "layer.h"
#include "data_param.h"

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
			m_parameter = new JDataParam;
		};
		~JDataLayer(){};
		bool SetParam(vector<string> param);
		virtual void Forward();
	private:
		JDataParam* m_parameter;
	};

}
#endif