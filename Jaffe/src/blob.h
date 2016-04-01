// huangshize 2016.03.28

#ifndef JAFFE_BLOB_H_
#define JAFFE_BLOB_H_


#include "math_functions.h"
#include "common.h"
#include "rawdata.h"

namespace jaffe {

	template <typename Dtype>
	class JBlob
	{
	public:
		// 构造函数
		JBlob() : m_data(), m_diff(), m_count(0), m_capacity(0) {}
		explicit JBlob(const int num, const int channels, const int height,
			const int width);
		explicit JBlob(const vector<int>& shape);
		// 析构函数
		~JBlob();

		//  Reshape
		void Reshape(const int num, const int channels, const int height,
			const int width);
		void Reshape(const vector<int>& shape);
		
		//
		inline const vector<int>& shape() const { return m_shape; }
		// 输出第index个维度的维数，支持index小于0，反序查找
		inline int GetShape(int index) const
		{
			return m_shape[CannonicalAxisIndex(index)];
		}
		inline int CannonicalAxisIndex(int axis_index) const
		{
			if (axis_index < 0)
			{
				return axis_index + num_axes();
			}
			return axis_index;
		}
		// 获取数据指定维度的维数
		inline int GetNum() const { return GetShape(0); }
		inline int GetChannels() const { return GetShape(1); }
		inline int GetHeight() const { return GetShape(2); }
		inline int GetWidth() const { return GetShape(3); }

		inline int GetNumAxes() const { return m_shape.size(); }
		inline int GetCount() const { return m_count; }
		inline int GetCount(int start_axis, int end_axis) const
		{
			// 需要判断index范围
			int count = 1;
			for (int i = start_axis; i < end_axis; i++)
			{
				count *= GetShape(i);
			}
			return count;
		}
		inline int GetCount(int start_axis) const
		{
			// 需要判断index范围
			return GetCount(start_axis, GetNumAxes());
		}

		// 计算 offset 偏移量
		inline int CalOffset(const int n, const int c = 0, const int h = 0,
			const int w = 0) const
		{
			// 需要判断 n c h w 的大小有没有超出范围
			return ((n * channels() + c) * height() + h) * width() + w;
		}

		inline int CalOffset(const vector<int>& indices) const
		{
			int offset = 0;
			for (int i = 0; i < GetNumAxes(); i++)
			{
				offset *= GetShape(i);
				if (indices.size() > i)
				{
					offset += indices[i]
				}
			}
			return offset;
		}

		void CopyFrom(const JBlob<Dtype>& source, bool copy_diff = false, bool reshape = false);

		// 通过offset偏移来求具体数据
		inline Dtype DataAt(const int n, const int c, const int h, const int w) const
		{
			return Data()[offset(n, c, h, w)];
		}

		inline Dtype DiffAt(const int n, const int c, const int h, const int w) const
		{
			return Diff()[offset(n, c, h, w)];
		}

		inline Dtype DataAt(const vector<int>& index) const
		{
			return Data()[offset(index)];
		}

		inline Dtype DiffAt(const vector<int>& index) const
		{
			return Diff()[offset(index)];
		}

		inline const shared_ptr<JRawData>& GetBlobData() const
		{
			return m_data; 
		}
		inline const shared_ptr<JRawData>& GetBlobDiff() const
		{
			return m_diff;
		}

		//
		const Dtype* Data() const;	// 原blob.hpp中的cpu_data() / gpu_data()
		const Dtype* Diff() const;	// 原blob.hpp中的cpu_diff() / gpu_diff()
		Dtype* MutableData();
		Dtype* MutableDiff();

		void SetData(Dtype* data);

		void Update();
		// void FromProto(..)
		// void ToProto(..)

		// 分别计算data和diff的绝对值之和以及平方之和
		Dtype AsumData() const;
		Dtype AsumDiff() const;
		Dtype SumsqData() const;
		Dtype SumsqDiff() const;

		// 涉及cblas函数运算
		void scale_data(Dtype scale_factor);
		void scale_diff(Dtype scale_factor);

		//
		void ShareData(const JBlob& other);
		void ShareDiff(const JBlob& other);
		
		//bool ShapeEquals(const BlobProto& other);

	protected:
		shared_ptr<JRawData> m_data;
		shared_ptr<JRawData> m_diff;
		shared_ptr<JRawData> m_shape_data;
		vector<int> m_shape;
		int m_count;
		int m_capacity;  // 容量  暂时保留
	private:

	};



}

#endif