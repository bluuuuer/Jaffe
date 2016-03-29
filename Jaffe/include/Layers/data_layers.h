#ifndef DATA_LAYERS_H_H
#define DATA_LAYERS_H_H

#include "layer.h"
#include "data_layer_param.h"

namespace jaffe {
	class BaseDataLayer : public Layer{
	public:
		BaseDataLayer(){};
		~BaseDataLayer(){};
	protected:
		//TransformationParameter transform_param;
		//vector<DataTransformer*> data_transformer;
	};

	class BasePrefetchingDataLayer : public BaseDataLayer{
	public:
		BasePrefetchingDataLayer(){};
		~BasePrefetchingDataLayer(){};
	};

	class DataLayer : public  BasePrefetchingDataLayer{
	public:
		DataLayer(){
			this->parameter = new DataLayerParam;
		};
		~DataLayer(){};
		bool setParam(vector<string> param);
		virtual void forward();
	private:
		DataLayerParam* parameter;
	};

}
#endif