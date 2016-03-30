#ifndef LAYER_H_H
#define LAYER_H_H

#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <sstream>

#include "layer_param.h"

using std::string;
using std::cout;
using std::vector;
using std::endl;

namespace jaffe {

	template <typename Dtype>
	class JLayer{
	public:
		JLayer(){
		};
		~JLayer(){
			if (m_parameter->GetTopNum()){
				m_top.clear();
				vector<JLayer*>(m_top).swap(m_top);
			}
			if (m_parameter->GetBottomNum()){
				m_bottom.clear();
				vector<JLayer*>(m_bottom).swap(m_bottom);
			}
		};
		virtual bool SetSharedParam(const vector<string> param);
		virtual Dtype Forward(){};
		string GetType(){ return m_parameter->GetType(); };
		virtual bool Show(){ return m_parameter->Show(); };

	protected:
		string* m_top_s;
		vector<JLayer*> m_top;

		string* m_bottom_s;
		vector<JLayer*> m_bottom;

	private:
		JLayerParam* m_parameter;
	};
}
#endif