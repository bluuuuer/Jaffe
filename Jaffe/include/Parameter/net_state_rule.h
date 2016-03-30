#ifndef NET_STATE_RULE_H_H
#define NET_STATE_RULE_H_H

#include <vector>
#include <string>
#include <iostream>

#include "jmatch.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

namespace jaffe{

	class JNetStateRule{
	public:
		JNetStateRule(){
			m_min_level = 0;
			m_max_level = 0;
		};
		~JNetStateRule(){
			vector<string>(m_stage).swap(m_stage);
			vector<string>(m_not_stage).swap(m_not_stage);
		};

		bool SetParam(const vector<string> param);

		bool Show();
	private:
		//Phase m_phase;
		int m_min_level;
		int m_max_level;
		vector<string> m_stage;
		vector<string> m_not_stage;
	};

} // namespace jaffe
#endif