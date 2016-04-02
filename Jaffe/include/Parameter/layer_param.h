#ifndef LAYER_PARAM_H_H
#define LAYER_PARAM_H_H

#include <vector>
#include <string>
#include <iostream>

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
			m_s_name = "";
			m_s_type = "";
		};
		~JLayerParam(){
			vector<string>(m_s_bottom).swap(m_s_bottom);
			vector<string>(m_s_top).swap(m_s_top);
			vector<float>(m_s_loss_weight).swap(m_s_loss_weight);
			vector<JParamSpec>(m_s_param).swap(m_s_param);
			vector<JBlobProto>(m_s_blobs).swap(m_s_blobs);
			vector<bool>(m_s_propagate_down).swap(m_s_propagate_down);
			vector<JNetStateRule>(m_s_include).swap(m_s_include);
			vector<JNetStateRule>(m_s_exclude).swap(m_s_exclude);

			if (m_s_transform_param){
				delete m_s_transform_param;
			}
			if (m_s_loss_param){
				delete m_s_loss_param;
			}
		};
		// 读取所有层都会有的共享参数， 每个 layer 都必须调用
		bool SetType(const vector<string> param);
		bool SetSharedParam(const vector<string> param);
		bool ShowSharedParam();

		int GetTopNum(){ return m_s_top.size(); };
		int GetBottomNum(){ return m_s_bottom.size(); };
		string GetType(){ return m_s_type; };

	protected:
		// 各种共享参数
		string m_s_name;
		string m_s_type;
		vector<string> m_s_bottom;
		vector<string> m_s_top;
		//Phase m_phase;
		vector<float> m_s_loss_weight;
		vector<JParamSpec> m_s_param;
		vector<JBlobProto> m_s_blobs;
		vector<bool> m_s_propagate_down;
		vector<JNetStateRule> m_s_include;
		vector<JNetStateRule> m_s_exclude;
		JTransformationParam* m_s_transform_param;
		JLossParam* m_s_loss_param;
	};
}
#endif