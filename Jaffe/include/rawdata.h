// huangshize 2016.03.28
// === rawdata.h ===
// SyncedMemory.hpp的替代，用来存储原始数据
// 没有实现cpu数据与gpu数据的同步

#ifndef JAFFE_RAWDATA_H_
#define JAFFE_RAWDATA_H_

#include <cstdlib>
#include "common.h"


// 为指针开辟空间
inline void mallocHost(void** ptr, size_t size)
{
	*ptr = malloc(size);
}
// 回收空间
inline void freeHost(void* ptr)
{
	free(ptr);
}

class JRawData {
public:
	JRawData() : m_data_ptr(NULL), m_size(0), m_own_data(false){}
	JRawData(size_t size) : m_data_ptr(NULL), m_size(size), m_own_data(false) {}
	~JRawData();

	// 返回RawData中数据的大小
	size_t GetSize() { return m_size; }
	//
	bool GetOwnData() { return m_own_data; }
	// 获取data的指针
	const void* GetData();
	void* GetMutableData();

	void SetData(void* data);



private:
	void NewData();  // to_cpu() / to_gpu ()

	void* m_data_ptr;
	size_t m_size;
	bool m_own_data;
};

#endif