// huangshize 2016.03.28

#include <string>
#include <vector>
//#include "math_functions.h"
namespace jaffe {

	template <typename DataType>
	class BLob
	{
	public:
		// 构造函数
		BLob() : data_(), diff_(), count_(0), capacity_(0) {}
		explicit Blob(const int num, const int channels, const int height,
			const int width);
		explicit Blob(const vector<int>& shape);
		// 析构函数
		~BLob();

		//  Reshape
		void Reshape(const int num, const int channels, const int height,
			const int width);
		void Reshape(const vector<int>& shape);
		
		//
		inline const vector<int>& shape() const { return shape_; }
		// 输出第index个维度的维数，支持index小于0，反序查找
		inline int shape(int index) const
		{
			return shape_[CannonicalAxisIndex(index)];
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
		inline int num() const { return shape(0); }
		inline int channels() const { return shape(1); }
		inline int height() const { return shape(2); }
		inline int width() const { return shape(3); }

		inline int num_axes() const { return shape_.size(); }
		inline int count() const { return count_; }
		inline int count(int start_axis, int end_axis) const
		{
			// 需要判断index范围
			int count = 1;
			for (int i = start_axis; i < end_axis; i++)
			{
				count *= shape(i);
			}
			return count;
		}
		inline int count(int start_axis) const
		{
			// 需要判断index范围
			return count(start_axis, num_axes());
		}

		// offset 偏移量
		inline int offset(const int n, const int c = 0, const int h = 0,
			const int w = 0) const
		{
			// 需要判断n c h w 的大小有没有超出范围
			return ((n * channels() + c) * height() + h) * width() + w;
		}

		inline int offset(const vector<int>& indices) const
		{
			int offset = 0;
			for (int i = 0; i < num_axes(); i++)
			{
				offset *= shape(i);
				if (indices.size() > i)
				{
					offset += indices[i]
				}
			}
			return offset;
		}

		void CopyFrom(const Blob<DataType>& source, bool copy_diff = false, bool reshape = false);

		// 通过offset偏移来求具体数据
		inline DataType data_at(const int n, const int c, const int h, const int w) const
		{
			return data()[offset(n, c, h, w)];
		}

		inline DataType diff_at(const int n, const int c, const int h, const int w) const
		{
			return diff()[offset(n, c, h, w)];
		}

		inline DataType data_at(const vector<int>& index) const
		{
			return data()[offset(index)];
		}

		inline DataType diff_at(const vector<int>& index) const
		{
			return diff()[offset(index)];
		}

		inline const shared_ptr<RawData>& blob_data() const
		{
			return data_; 
		}
		inline const shared_ptr<RawData>& blob_diff() const
		{
			return diff_;
		}

		//
		const DataType* data() const;	// 原blob.hpp中的cpu_data() / gpu_data()
		const DataType* diff() const;	// 原blob.hpp中的cpu_diff() / gpu_diff()
		DataType* mutable_data();
		DataType* mutable_diff();

		void setdata(DataType* data);

		void Update();
		// void FromProto(..)
		// void ToProto(..)

		// 分别计算data和diff的绝对值之和以及平方之和
		DataType asum_data() const;
		DataType asum_diff() const;
		DataType sumsq_data() const;
		DataType sumsq_diff() const;

		// 涉及cblas函数运算
		void scale_data(DataType scale_factor);
		void scale_diff(DataType scale_factor);

		//
		void ShareData(const Blob& other);
		void ShareDiff(const Blob& other);
		
		//bool ShapeEquals(const BlobProto& other);

	protected:
		shared_ptr<RawData> data_;
		shared_ptr<RawData> diff_;
		shared_ptr<RawData> shape_data_;
		vector<int> shape_;
		int count_;
		int capacity_;  // 容量  暂时保留
	private:

	};



}