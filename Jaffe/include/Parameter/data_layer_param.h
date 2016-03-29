#ifndef DATA_LAYER_PARAM_H_H
#define DATA_LAYER_PARAM_H_H

#include "layer_param.h"

namespace jaffe {
	class DataLayerParam : public LayerParam{
	public:
		DataLayerParam(){
			this->source = "";
			this->batch_size = 0;
			this->rank_skip = 0;
			this->backend = LEVELDB;
			this->scale = 1.0;
			this->mean_file = "";
			this->crop_size = 0;
			this->mirror = false;
			this->force_encoded_color = false;
			this->prefetch = 0;
		};
		~DataLayerParam(){};
		bool setParam(vector<string> param);
		bool show();
	private:
		enum DB{
			LEVELDB = 0,
			LMDB = 1
		};
		string source;
		int batch_size;
		int rank_skip;
		DB backend;
		float scale;
		string mean_file;
		int crop_size;
		bool mirror;
		bool force_encoded_color;
		int prefetch;
	};
}
#endif