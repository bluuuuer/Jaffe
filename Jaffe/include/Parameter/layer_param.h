#ifndef LAYER_PARAM_H_H
#define LAYER_PARAM_H_H

#include <vector>
#include <string>
#include <regex>
#include <iostream>
#include <sstream>

#include "jmatch.h"
#include "param_spec.h"
#include "blob_proto.h"
#include "loss_param.h"
#include "net_state_rule.h"
#include "transformation_param.h"

using std::string;
using std::cout;
using std::vector;
using std::endl;

namespace jaffe {

	class JLayerParam{
	public:
		JLayerParam(){
			m_name = "";
			m_type = "";
			m_loss_param = new JLossParam;
		};
		~JLayerParam(){
			vector<string>(m_bottom).swap(m_bottom);
			vector<string>(m_top).swap(m_top);
			vector<float>(m_loss_weight).swap(m_loss_weight);
			vector<JParamSpec>(m_param_spec).swap(m_param_spec);
			vector<JBlobProto>(m_blobs).swap(m_blobs);
			vector<bool>(m_propagate_down).swap(m_propagate_down);
			vector<JNetStateRule>(m_include).swap(m_include);
			vector<JNetStateRule>(m_exclude).swap(m_exclude);

			delete[] m_loss_param;
		};
		// 读取所有层都会有的共享参数， 每个 layer 都必须调用
		bool SetSharedParam(const vector<string> param);
		bool Show(){ return true; };

		int GetTopNum(){ return m_top.size(); };
		int GetBottomNum(){ return m_bottom.size(); };
		string GetType(){ return m_type; };

	protected:
		// 各种共享参数
		string m_name;
		string m_type;
		vector<string> m_bottom;
		vector<string> m_top;
		//Phase m_phase;
		vector<float> m_loss_weight;
		vector<JParamSpec> m_param_spec;
		vector<JBlobProto> m_blobs;
		vector<bool> m_propagate_down;
		vector<JNetStateRule> m_include;
		vector<JNetStateRule> m_exclude;
		JTransformationParam* m_transfrom_param;
		JLossParam* m_loss_param;
	private:
	};
}
#endif