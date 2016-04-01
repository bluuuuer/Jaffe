#include "net.h"

namespace jaffe {

	template <typename Dtype>
	int JNet<Dtype>::bullshit() {
		int i;
		i = 0;
		return i;
	}

	template <typename Dtype>
	bool JNet<Dtype>::Init(const string filename){
		cout << "Read Net Parameter From Prototxt ..." << endl;
		ReadParamFromText(filename);
		cout << "Done" << endl;
		cout << "Number of Layers: " << m_param->GetLayerNum() 
			<< endl << endl;

		// 遍历所有 layer 的 type 参数，统计不同种类 layer 个数
		cout << "Counting all Kinds of Layers ..." << endl;
		for (int i = 0; i < m_param->GetLayerNum(); i++){
			JLayer<Dtype> layer_temp;
			layer_temp.SetType(m_param->GetLayerParam(i));
			if (layer_temp.GetType() == "Data")
				m_data_layer_num++;
			if (layer_temp.GetType() == "Convolution")
				m_convolution_layer_num++;
			if (layer_temp.GetType() == "Pooling")
				m_pooling_layer_num++;
		}
		cout << "Done" << endl << endl;

		cout << "Data Layer: " << m_data_layer_num << endl;
		cout << "Convolution Layer: " << m_convolution_layer_num << endl;
		cout << "Pooling Layer: " << m_pooling_layer_num << endl;
		cout << endl;

		// 为所有不同类型 layer 开辟内存空间
		cout << "Set Memory for all Layers ..." << endl;
		m_convolution_layers = new JConvolutionLayer<Dtype>[m_convolution_layer_num];
		m_data_layers = new JDataLayer<Dtype>[m_data_layer_num];
		m_pooling_layers = new JPoolingLayer<Dtype>[m_pooling_layer_num];
		cout << "Done" << endl << endl;

		// 分别设置所有 layer 的参数
		int i_convolution_layer_idex = 0;
		int i_data_layer_idex = 0;
		int i_pooling_layer_idex = 0;
		for (int i = 0; i < m_param->GetLayerNum(); i++){
			JLayer<Dtype> layer_param_temp;
			layer_param_temp.SetType(m_param->GetLayerParam(i));
			if (layer_param_temp.GetType() == "Data"){
				m_data_layers[i_data_layer_idex].Init(
					m_param->GetLayerParam(i));
				m_layers.push_back(
					&m_data_layers[i_data_layer_idex]);
				i_data_layer_idex++;
			}
			if (layer_param_temp.GetType() == "Convolution"){
				m_convolution_layers[i_convolution_layer_idex].Init(
					m_param->GetLayerParam(i));
				m_layers.push_back(
					&m_convolution_layers[i_convolution_layer_idex]);
				i_convolution_layer_idex++;
			}
			if (layer_param_temp.GetType() == "Pooling"){
				m_pooling_layers[i_pooling_layer_idex].Init(
					m_param->GetLayerParam(i));
				m_layers.push_back(
					&m_pooling_layers[i_pooling_layer_idex]);
				i_pooling_layer_idex++;
			}
			//if (layer_param_temp.GetType() == "ReLU"){
			//	m_conv_layers[i_relu_layer_idex].Init(
			//		m_param->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[i_relu_layer_idex]);
			//	i_relu_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "LRN"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_param->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "InnerProduct"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_param->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "Dropout"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_param->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "Softmax"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_param->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
		}

		//for (int i = 0; i < m_layers.size(); i++){
		//	m_layers.at(i)->Show();
		//}

		return true;
	}

	template <typename Dtype>
	bool JNet<Dtype>::ReadParamFromText(const string filename){
		// 从文件中读取所有 layer 参数
		if (m_param->SetFilePath(filename))
			return true;

		cout << "Failed to Read Deploy Prototxt" << endl;
		return false;
	}

	template class JNet<int>;
} // namespace jaffe