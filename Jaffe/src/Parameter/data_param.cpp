#include "data_param.h"

namespace jaffe {

	bool JDataParam::SetParam(vector<string> param){
		SetSharedParam(param);

		cout << "Initting convolution layer \"" << m_name << "\"..."
			<< endl;

		string line;
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			// 没有进入更深的参数
			matchString(line, "source:", &m_source);
			matchInt(line, "batch_size:", &m_batch_size);
			matchInt(line, "rank_skip:", &m_rank_skip);
			if (line.find("backend:") != string::npos){
				if (line.find("LEVELDB") != string::npos)
					m_backend = LEVELDB;
				else if (line.find("LMDB") != string::npos)
					m_backend = LMDB;
			}
			matchFloat(line, "scale:", &m_scale);
			matchString(line, "mean_file:", &m_mean_file);
			matchInt(line, "crop_size:", &m_crop_size);
			matchBool(line, "mirror:", &m_mirror);
			matchBool(line, "force_encoded_color:",
				&m_force_encoded_color);
			matchInt(line, "prefetch:", &m_prefetch);
		}
		cout << "Done" << endl;
		return true;

	}

	bool JDataParam::Show(){
		return true;
	}
}