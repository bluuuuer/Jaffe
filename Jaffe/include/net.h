#ifndef NET_H_H
#define NET_H_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "net_param.h"
#include "layer.h"
#include "vision_layers.h"
#include "data_layers.h"
#include "common_layers.h"
#include "neuron_layers.h"

using std::string;
using std::cout;
using std::endl;

namespace jaffe {

	template <typename Dtype>
	class JNet{
	public:
		JNet(){
			m_param = new JNetParameter;
			m_data_layer_num = 0;
			m_convolution_layer_num = 0;
			m_pooling_layer_num = 0;
			m_softmax_layer_num = 0;
			m_innerproduct_layer_num = 0;
			m_relu_layer_num = 0;
		};

		~JNet(){
			vector<JLayer<Dtype>*>(m_layers).swap(m_layers);

			if (m_convolution_layer_num){
				delete[] m_convolution_layers;
			}
			if (m_data_layer_num){
				delete[] m_data_layers;
			}
			if (m_pooling_layer_num){
				delete[] m_pooling_layers;
			}
			if (m_softmax_layer_num){
				delete[] m_softmax_layers;
			}
			if (m_innerproduct_layer_num){
				delete[] m_innerproduct_layers;
			}
			if (m_relu_layer_num){
				delete[] m_relu_layers;
			}

			delete m_param;
		};

		int bullshit();

		// 分别定义 layer 并设置参数
		bool Init(const string filename);	
		// 一次性读入所有参数
		bool ReadParamFromText(const string filename); 
		

		JNetParameter GetParame(){ return *m_param; };

	private:
		vector<JLayer<Dtype>*> m_layers;

		int m_data_layer_num;
		JDataLayer<Dtype>* m_data_layers;

		int m_convolution_layer_num;
		JConvolutionLayer<Dtype>* m_convolution_layers;

		int m_pooling_layer_num;
		JPoolingLayer<Dtype>* m_pooling_layers;

		int m_softmax_layer_num;
		JSoftmaxLayer<Dtype>* m_softmax_layers;

		int m_innerproduct_layer_num;
		JInnerProductLayer<Dtype>* m_innerproduct_layers;

		int m_relu_layer_num;
		JReLULayer<Dtype>* m_relu_layers;

		JNetParameter* m_param;
	};
}
#endif