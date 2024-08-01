#pragma once
/*跟踪内存分配的方法
*			
*/

#include<memory>

struct Object { int a, b, c; };
struct AllocationMetrics
{
	uint32_t TotalAllocated = 0;
	uint32_t TotalFreed = 0;

	uint32_t CurrentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics  s_AllocationMetrics;

/* 
new 已经定义过了
inline void* operator new(size_t size)
{
	s_AllocationMetrics.TotalAllocated += size;
	std::cout << "Allocating " << size << " bytes\n";
	return malloc(size);
}*/

void operator delete(void* memory, size_t size)
{
	s_AllocationMetrics.TotalFreed += static_cast<uint32_t>(size);
	std::cout << "Free " << size << " bytes\n";
	free(memory);
}

static void PrintUsage()
{
	std::cout << "Memory Usage: " << s_AllocationMetrics.CurrentUsage() << " bytes\n";
}


static void Memory_Func()
{
	PrintUsage();
	std::string string = "zhang san";
	PrintUsage();
	{
		std::unique_ptr<Object> object = std::make_unique<Object>();
		PrintUsage();
	} 
	//出现了一些问题，大概思路是对的，以后再进行尝试吧
	PrintUsage();
}