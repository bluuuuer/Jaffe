#include "Blob.h"

using namespace std;

template <typename Dtype>
Blob<Dtype>::Blob(const vector<int>& shape_){
	Reshape(shape_);
}

template <typename Dtype>
bool Blob<Dtype>::Reshape(const vector<int>& shape_){
	this->shape.resize(shape_.size());
	count = 1;
	for(int i = 0; i <  shape.size(); i ++){
		count *= shape[i];
	}
	if(count > this->capacity){
		this->capacity = count;
		this->data.reset(new Dtype(this->capacity * sizeof(Dtype)));
		this->diff.reset(new Dtype(this->capacity * sizeof(Dtype)));
	}
	return true;
}