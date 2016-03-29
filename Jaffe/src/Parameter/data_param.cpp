#include "data_layer_param.h"

bool DataLayerParam::setParam(vector<string> param){
	setSharedParam(param);
	
	cout << "Initting convolution layer \"" << this->name << "\"..."
		<< endl;

	string line;
	for (int i = 0; i < param.size(); i++){
		line = param.at(i);
		// 没有进入更深的参数
		matchString(line, "source:", &this->source);
		matchInt(line, "batch_size:", &this->batch_size);
		matchInt(line, "rank_skip:", &this->rank_skip);
		if (line.find("backend:") != string::npos){
			if (line.find("LEVELDB") != string::npos)
				this->backend = LEVELDB;
			else if (line.find("LMDB") != string::npos)
				this->backend = LMDB;
		}
		matchFloat(line, "scale:", &this->scale);
		matchString(line, "mean_file:", &this->mean_file);
		matchInt(line, "crop_size:", &this->crop_size);
		matchBool(line, "mirror:", &this->mirror);
		matchBool(line, "force_encoded_color:", 
			&this->force_encoded_color);
		matchInt(line, "prefetch:", &this->prefetch);
	}
	cout << "Done" << endl;
	return true;

}

bool DataLayerParam::show(){
	return true;
}