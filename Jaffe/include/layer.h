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
			vector<JLayer*>(m_top).swap(m_top);
			vector<JLayer*>(m_bottom).swap(m_bottom);

			delete[] m_param;
		};

		bool SetSharedParam(const vector<string> param);
		string GetType(){ return m_param->GetType(); };

	protected:
		string* m_top_s;
		vector<JLayer*> m_top;

		string* m_bottom_s;
		vector<JLayer*> m_bottom;

	private:
		JLayerParam* m_param;
	};
}
#endif