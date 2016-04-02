#include "data_param.h"

namespace jaffe {

	bool DPisleft(char c){
		return c == '{';
	}

	bool DPisright(char c){
		return c == '}';
	}

	bool JDataParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting Data Layer (" << m_s_name << ")...";

		string line = "";
		vector<string> v_unique_param;
		bool b_enter = false;
		int i_left = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			if (line.find(" data_param") != string::npos){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(),
					DPisleft);
			}
			else if (b_enter){
				v_unique_param.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					DPisleft);
				i_left -= count_if(line.begin(), line.end(),
					DPisright);
				if (i_left == 0){
					v_unique_param.pop_back();
					SetUniqueParam(v_unique_param);
					v_unique_param.clear();
					b_enter = false;
				}
			}
		}

		cout << "Done" << endl;

		return true;
	}

	bool JDataParam::SetUniqueParam(const vector<string> param){
		string line = "";

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);
			// 没有进入更深的参数
			matchString(line, "source:", &m_source);
			matchInt(line, "batch_size:", &m_batch_size);
			matchInt(line, "rand_skip:", &m_rand_skip);
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

		return true;

	}

	bool JDataParam::Show(){
		cout << endl;
		cout << "Data Layer (" << m_s_name << "):" << endl;
		ShowSharedParam();
		ShowUniqueParam();
		return true;
	}

	bool JDataParam::ShowUniqueParam(){
		cout << "data_param {" << endl;
		cout << "\tsource: " << m_source << endl;
		cout << "\tbatch_size: " << m_batch_size << endl;
		cout << "\trand_skip: " << m_rand_skip << endl;
		cout << "\tbackend: " << m_backend << endl;
		cout << "\tscale: " << m_scale << endl;
		cout << "\tmean_file: " << m_mean_file << endl;
		cout << "\tcrop_size: " << m_crop_size << endl;
		cout << "\tmirror: " << m_mirror << endl;
		cout << "\tforce_encode_color: " << m_force_encoded_color
			<< endl;
		cout << "\tprefetch: " << m_prefetch << endl;
		cout << "}" << endl;
		return true;
	}
}