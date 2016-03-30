#ifndef BLOB_SHAPE_H_H
#define BLOB_SHAPE_H_H

#include <vector>
#include <string>

#include "jmatch.h"

using std::vector;
using std::string;

namespace jaffe{

	class JBlobShape{
	public:
		JBlobShape(){};
		~JBlobShape(){
			vector<long>(m_dim).swap(m_dim);
		};
		bool SetParam(const vector<string> param);
	private:
		vector<long> m_dim;
	};

} // namespace jaffe
#endif