/* example.proto

message ModelParameter{
	optional string param_s_o = 1;
	optional int32/sint32/uint32/fixed32 param_i_o  = 2[default = 3];
	optional float param_f_o = 3 [default = 0.5];
	optional bool param_b_o = 4 [default = true];
	optional double param_d_o = 5;
	optional int64/uint64/sint64/fixed64 param_l_o = 6;
	optional XxxParameter xxx_param = 7;

	repeated string param_s_r = 8;
	repeated int32/sint32/uint32/fixed32 param_i_r = 9;
	repeated float param_f_r = 10;
	repeated bool param_b_r = 11;
	repeated double param_d_r = 12;
	repeated int64/uint64/sint64/fixed64 param_l_r = 13;
	repeated YyyParameter yyy_param = 14;
}

*/

#ifndef MODEL_PARAM_H_H
#define MODEL_PARAM_H_H

#include <vector>
#include <string>
#include <iostream>

#include "jmatch.h" // 匹配用的一些库
#include "layer_param.h" // 基类

using std::string;
using std::cout;
using std::endl;
using std::vector;

namespace jaffe {

	class JModelParam : public JLayerParam{
	public:
		JModelParam(){
			m_param_s_o = "";
			m_param_i_o = 3; // 设置默认值
			m_param_f_o = 0.5;
			m_param_b_o = true;
			m_param_d_o = 0;
			m_param_l_o = 0;
		};
		~JModelParam(){
			delete[] m_xxx_param;

			vector<string>(m_param_s_r).swap(m_param_s_r);
			vector<int>(m_param_i_r).swap(m_param_i_r);
			vector<float>(m_param_f_r).swap(m_param_f_r);
			vector<bool>(m_param_b_r).swap(m_param_b_r);
			vector<double>(m_param_d_r).swap(m_param_d_r);
			vector<long>(m_param_l_r).swap(m_param_l_r);
			vector<YyyParam>(m_xxx_param).swap(m_yyy_param);
		};
		bool SetParam(const vector<string> param);
		bool Show();

	private:
		string m_param_s_o; // 成员变量前面加上 m_
		int m_param_i_o; // int32/sint32/uint32/fixed32 使用 int
		float m_param_f_o;
		bool m_param_b_o;
		double m_param_d_o;
		long m_param_l_o; // int64/uint64/sint64/fixed64 使用 long
		XxxxParam* m_xxx_param; // optional 初始化类为指针
		
		// repeated 初始化成 vector 变量
		vector<string> m_param_s_r;
		vector<int> m_param_i_r;
		vector<float> m_param_f_r;
		vector<bool> m_param_b_r;
		vector<double> m_param_d_r;
		vector<long> m_param_l_r;
		vector<YyyParam> m_yyy_param;

		bool SetUniqueParam(const vector<string> param);
	}; // class JModelParam

} // namespace jaffe


#endif