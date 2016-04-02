#ifndef NET_STATE_H_H
#define NET_STATE_H_H

#include <vector>
#include <string>

#include "jmatch.h"

using std::vector;
using std::string;

namespace jaffe {

	class JNetState{
	public:
		JNetState(){
			m_level = 0;
		};
		~JNetState(){
			vector<string>(m_stage).swap(m_stage);
		};
		bool SetParam(const vector<string> param);

	private:
		//Phase m_phase;
		int m_level;
		vector<string> m_stage;
	};

}
#endif