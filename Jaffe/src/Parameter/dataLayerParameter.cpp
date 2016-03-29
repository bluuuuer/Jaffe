#include "DataLayerParameter.h"

bool DataLayerParameter::SetParam(vector<string> param){
	SetSharedParam(param);
	
	cout << "Initting convolution layer \"" << this->name << "\"..."
		<< endl;

	string line;
	for (int i = 0; i < param.size(); i++){
		line = param.at(i);
		// 没有进入更深的参数
		match_s(line, "source:", &this->source);
		match_i(line, "batch_size:", &this->batch_size);
		match_i(line, "rank_skip:", &this->rank_skip);
		if (line.find("backend:") != string::npos){
			if (line.find("LEVELDB") != string::npos)
				this->backend = LEVELDB;
			else if (line.find("LMDB") != string::npos)
				this->backend = LMDB;
		}
		match_f(line, "scale:", &this->scale);
		match_s(line, "mean_file:", &this->mean_file);
		match_i(line, "crop_size:", &this->crop_size);
		match_b(line, "mirror:", &this->mirror);
		match_b(line, "force_encoded_color:", 
			&this->force_encoded_color);
		match_i(line, "prefetch:", &this->prefetch);
	}
	cout << "Done" << endl;
	return true;

}

bool DataLayerParameter::Show(){
	return true;
}