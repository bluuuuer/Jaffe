#include <iostream>
#include <fstream>

#include "net.h"

namespace jaffe {

	template <typename Dtype>
	bool JNet::Init(const string filename){
		SetFilePath(filename);

		// 遍历所有 layer 的 type 参数，统计不同种类 layer 个数
		for (int i = 0; i < m_parameter->GetLayerNum(); i++){
			JLayer<Dtype> layer_param_temp;
			layer_param_temp.SetSharedParam(
				m_parameter->GetLayerParam(i));
			if (layer_param_temp.GetType() == "Data")
				m_data_layer_num++;
			if (layer_param_temp.GetType() == "Convolution")
				m_convolution_layer_num++;
		}

		// 为所有不同类型 layer 开辟内存空间
		m_convolution_layers = new JConvolutionLayer<Dtype>[m_convolution_layer_num];
		m_data_layers = new JDataLayer<Dtype>[m_data_layer_num];
		m_pooling_layers = new JPoolingLayer<Dtype>[m_pooling_layer_num];

		// 分别设置所有 layer 的参数
		int i_convolution_layer_idex = 0;
		int i_data_layer_idex = 0;
		int i_pooling_layer_idex = 0;
		for (int i = 0; i < m_parameter->GetLayerNum(); i++){
			JLayer layer_param_temp;
			layer_param_temp.SetSharedParam(
				m_parameter->GetLayerParam(i));
			if (layer_param_temp.GetType() == "Data"){
				m_data_layers[i_data_layer_idex].Init(
					m_parameter->GetLayerParam(i));
				m_layers.push_back(
					&m_data_layers[i_data_layer_idex]);
				i_data_layer_idex++;
			}
			if (layer_param_temp.GetType() == "Convolution"){
				m_convolution_layers[i_convolution_layer_idex].Init(
					m_parameter->GetLayerParam(i));
				m_layers.push_back(
					&m_convolution_layers[i_convolution_layer_idex]);
				i_convolution_layer_idex++;
			}
			if (layer_param_temp.GetType() == "Pooling"){
				m_pooling_layers[i_pooling_layer_idex].Init(
					m_parameter->GetLayerParam(i));
				m_layers.push_back(
					&m_pooling_layers[i_pooling_layer_idex]);
				i_pooling_layer_idex++;
			}
			//if (layer_param_temp.GetType() == "ReLU"){
			//	m_conv_layers[i_relu_layer_idex].Init(
			//		m_parameter->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[i_relu_layer_idex]);
			//	i_relu_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "LRN"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_parameter->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "InnerProduct"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_parameter->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "Dropout"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_parameter->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "Softmax"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_parameter->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
		}

		//m_layers.at(0)->Show();
		//m_layers.at(1)->Show();
		//m_layers.at(2)->Show();
		//m_layers.at(3)->Show();
		//m_layers.at(4)->Show();

		return  true;
	}

	template <typename Dtype>
	bool JNet::SetFilePath(const string filename){
		// 从文件中读取所有 layer 参数
		if (m_parameter->SetFilePath(filename))
			return true;

		cout << "Failed to Read Deploy Prototxt" << endl;
		return false;
	}
} // namespace jaffe