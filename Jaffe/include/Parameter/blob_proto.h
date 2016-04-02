#ifndef BLOBPROTO_H_H
#define BLOBPROTO_H_H

#include <vector>
#include <string>
#include <iostream>

#include "jmatch.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace jaffe {
	
	class JBlobProto{
	public:
		JBlobProto(){
			m_num = 0;
			m_channels = 0;
			m_height = 0;
			m_width = 0;
		};

		~JBlobProto(){
			vector<float>(m_diff).swap(m_diff);
			vector<double>(m_double_data).swap(m_double_data);
			vector<double>(m_double_diff).swap(m_double_diff);
		};

		bool SetParam(const vector<string> param);
		bool Show();

	private:
		//JBlobShape m_shape;
		float m_data;
		vector<float> m_diff;
		vector<double> m_double_data;
		vector<double> m_double_diff;
		int m_num;
		int m_channels;
		int m_height;
		int m_width;
	};

} // namespace jaffe
#endif