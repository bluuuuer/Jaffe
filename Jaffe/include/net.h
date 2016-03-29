#ifndef NET_H_H
#define NET_H_H

#include <string>
#include <vector>

#include "layer.h"
#include "vision_layers.h"
#include "net_param.h"
#include "data_layers.h"

using std::string;
using std::cout;
using std::endl;

namespace jaffe {

	class JNet{
	public:
		JNet(){
			m_parameter = new JNetParameter;
			m_data_layer_num = 0;
			m_conv_layer_num = 0;
		};
		~JNet(){
			if (m_conv_layer_num)
				delete[] m_conv_layers;
			delete[] m_parameter;
		};
		bool Init();	// 分别给定义 layer 并设置参数
		bool SetFilePath(const string filename); // 一次性读入所有参数
		//void Info();
		JNetParameter GetParame(){ return *m_parameter; };
	private:
		vector<JLayer*> m_layers;

		int m_data_layer_num;
		JDataLayer* m_data_layers;

		int m_conv_layer_num;
		JConvolutionLayer* m_conv_layers;

		JNetParameter* m_parameter;
	};
}
#endif