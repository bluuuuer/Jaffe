#include "image_data_param.h"

namespace jaffe {

	bool IDPisleft(char c){
		return c == '{';
	}

	bool IDPisright(char c){
		return c == '}';
	}

	bool JImageDataParam::SetParam(const vector<string> param){
		SetSharedParam(param);

		cout << "Initting Image Data Layer \"" << m_s_name << "\"..."
			<< endl;

		string line = "";
		vector<string> v_str_temp;
		bool b_enter = false;
		int i_left = 0;

		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			if (line.find("image_data_param {")){
				b_enter = true;
				i_left += count_if(line.begin(), line.end(), 
					IDPisleft);
			}
			else if (b_enter){
				v_str_temp.push_back(line);
				i_left += count_if(line.begin(), line.end(),
					IDPisleft);
				i_left -= count_if(line.begin(), line.end(),
					IDPisright);
				if (i_left == 0){
					v_str_temp.pop_back();
					SetUniqueParam(v_str_temp);
					v_str_temp.clear();
					b_enter = false;
				}
			}
		}

		return true;
	}

	bool JImageDataParam::SetUniqueParam(const vector<string> param){
		string line = "";
		for (int i = 0; i < param.size(); i++){
			line = param.at(i);

			matchString(line, "source:", &m_source);
			matchInt(line, "batch_size:", &m_batch_size);
			matchInt(line, "rand_skip:", &m_rand_skip);
			matchBool(line, "shuffle:", &m_shuffle);
			matchInt(line, "new_height:", &m_new_height);
			matchInt(line, "new_width:", &m_new_width);
			matchBool(line, "is_color:", &m_is_color);
			matchFloat(line, "scale:", &m_scale);
			matchString(line, "mean_file:", &m_mean_file);
			matchInt(line, "crop_size:", &m_crop_size);
			matchBool(line, "mirror:", &m_mirror);
			matchString(line, "root_folder:", &m_root_folder);
		}

		cout << "Done" << endl;
		return true;
	}

	bool JImageDataParam::Show(){
		cout << endl;
		cout << "Image Data Layer(" << m_s_name << "):" << endl;
		cout << "\tsource: " << m_source << endl;
		cout << "\tbatch_size: " << m_batch_size << endl;
		cout << "\trand_skip: " << m_rand_skip << endl;
		cout << "\tshuffle: " << m_shuffle << endl;
		cout << "\tnew_height: " << m_new_height << endl;
		cout << "\tnew_width: " << m_new_width << endl;
		cout << "\tis_color: " << m_is_color << endl;
		cout << "\tscale: " << m_scale << endl;
		cout << "\tmean_file: " << m_mean_file << endl;
		cout << "\tcrop_size: " << m_crop_size << endl;
		cout << "\tmirror: " << m_mirror << endl;
		cout << "\troot_folder: " << m_root_folder << endl;

		return true;
	}

} // namespace jaffe