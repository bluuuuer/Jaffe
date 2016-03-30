#ifndef TRANSFORMATION_PARAM_H_H
#define TRANSFORMATION_PARAM_H_H

#include <vector>
#include <string>
#include <iostream>

#include "jmatch.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace jaffe{

	class JTransformationParam{
	public:
		JTransformationParam(){
			m_scale = 1.0;
			m_mirror = false;
			m_crop_size = 0;
			m_mean_file = "";
			m_force_color = false;
			m_force_gray = false;
		};
		~JTransformationParam(){
			vector<float>(m_mean_value).swap(m_mean_value);
		};
		bool SetParam(const vector<string> param);
		bool Show();
	private:
		float m_scale;
		bool m_mirror;
		int m_crop_size;
		string m_mean_file;
		vector<float> m_mean_value;
		bool m_force_color;
		bool m_force_gray;
	};

} // namespace jaffe
#endif