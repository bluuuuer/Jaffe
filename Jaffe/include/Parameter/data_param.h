#ifndef DATA_PARAM_H_H
#define DATA_PARAM_H_H

#include "layer_param.h"

namespace jaffe {
	class JDataParam : public JLayerParam{
	public:
		JDataParam(){
			m_source = "";
			m_batch_size = 0;
			m_rand_skip = 0;
			m_backend = LEVELDB;
			m_scale = 1.0;
			m_mean_file = "";
			m_crop_size = 0;
			m_mirror = false;
			m_force_encoded_color = false;
			m_prefetch = 0;
		};
		~JDataParam(){};
		bool SetParam(const vector<string> param);
		bool Show();
	private:
		enum DB{
			LEVELDB = 0,
			LMDB = 1
		};
		string m_source;
		int m_batch_size;
		int m_rand_skip;
		DB m_backend;
		float m_scale;
		string m_mean_file;
		int m_crop_size;
		bool m_mirror;
		bool m_force_encoded_color;
		int m_prefetch;

		bool SetUniqueParam(const vector<string> param);
		bool ShowUniqueParam();
	};
}
#endif