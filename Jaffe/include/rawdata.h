// huangshize 2016.03.28
// === rawdata.h ===
// SyncedMemory.hpp的替代，用来存储原始数据
// 没有实现cpu数据与gpu数据的同步

#include <cstdlib>

// 为指针开辟空间
inline void MallocHost(void** ptr, size_t size)
{
	*ptr = malloc(size);
}
// 回收空间
inline void FreeHost(void* ptr)
{
	free(ptr);
}

class RawData {
public:
	RawData() : data_ptr_(NULL), size_(0), own_data_(false){}
	RawData(size_t size) : data_ptr_(NULL), size_(size), own_data_(false) {}
	~RawData();

	// 返回RawData中数据的大小
	size_t size() { return size_; }
	//
	bool own_data() { return own_data_; }
	// 获取data的指针
	const void* data();  
	void* mutable_data();

	void setdata(void* data);
	

	
private:
	void new_data();

	void* data_ptr_;
	size_t size_;
	bool own_data_;
};