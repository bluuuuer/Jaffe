#ifndef IMAGE_DATA_PARAM_H_H
#define IMAGE_DATA_PARAM_H_H

#include "layer_param.h"

namespace jaffe {

	class JImageDataParam : public JLayerParam{
	public:
		JImageDataParam(){
			m_source = "";
			m_batch_size = 1;
			m_rand_skip = 0;
			m_shuffle = false;
			m_new_height = 0;
			m_new_width = 0;
			m_is_color = true;
			m_scale = 1.0;
			m_mean_file = "";
			m_crop_size = 0;
			m_mirror = false;
			m_root_folder = "";
		};
		~JImageDataParam(){};
		bool SetParam(const vector<string> param);
		bool Show();

	private:
		string m_source;
		int m_batch_size;
		int m_rand_skip;
		bool m_shuffle;
		int m_new_height;
		int m_new_width;
		bool m_is_color;
		float m_scale;
		string m_mean_file;
		int m_crop_size;
		bool m_mirror;
		string m_root_folder;

		bool SetUniqueParam(const vector<string> param);
	}; // class JImageDataParam

} // namespace jaffe
#endif