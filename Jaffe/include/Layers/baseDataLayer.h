#ifndef BASEDATALAYER
#define BASEDATALAYER

#include "Layer.h"

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


#endif