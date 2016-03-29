#ifndef DATALAYER_H_H
#define DATALAYER_H_H

#include "BaseDataLayer.h"
#include "DataLayerParameter.h"

class DataLayer : public BasePrefetchingDataLayer{
public:
	DataLayer(){};
	~DataLayer(){};
	bool SetParam(vector<string> param);
	virtual void Forward();
	virtual bool Show(){ return this->parameter->Show(); };
private:
	DataLayerParameter* parameter;
};

#endif