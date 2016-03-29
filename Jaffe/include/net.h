#ifndef NET_H_H
#define NET_H_H

#include <string>
#include <vector>

#include "Layer.h"
#include "VisionLayer.h"
#include "NetParameter.h"
#include "DataLayer.h"

using namespace std;

class Net{
public:
	Net(){
		parameter = new NetParameter;
		this->data_layer_num = 0;
		this->conv_layer_num = 0;
	};
	~Net(){
		if (this->conv_layer_num)
			delete[] this->conv_layers;
		delete [] parameter;
	};
	bool Init();	// 分别给定义 layer 并设置参数
	bool SetFilePath(const string filename); // 一次性读入所有参数
	//void Info();
	NetParameter GetParame(){ return *this->parameter; };
private:
	vector<Layer*> layers;

	int data_layer_num;
	DataLayer* data_layers;

	int conv_layer_num;
	ConvolutionLayer* conv_layers;

	NetParameter* parameter;
};
#endif