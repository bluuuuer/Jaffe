#ifndef LOSS_PARAM_H_H
#define LOSS_PARAM_H_H

#include <vector>
#include <string>
#include <iostream>

#include "jmatch.h"

using std::vector; 
using std::string;
using std::cout;
using std::endl;

namespace jaffe{

	class JLossParam{
	public:
		JLossParam(){
			m_ignore_label = 0;
			m_normalization = VALID;
			m_normalize = false;
		};
		~JLossParam(){};
		bool SetParam(const vector<string> param);
		bool Show();

	private:
		int m_ignore_label;
		enum NormalizationMode{
			FULL = 0,
			VALID = 1,
			BATCH_SIZE = 2,
			NONE = 3
		};
		NormalizationMode m_normalization;
		bool m_normalize;
		
	};
} // namespace jaffe

#endif