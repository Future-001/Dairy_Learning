#pragma once
/*让字符串更快
*		字符串慢，其实主要来说还是内存的分配上
*/
static uint32_t s_AllocCount = 0;
inline void* operator new(size_t size)
{
	s_AllocCount++;
	std::cout << "Allocating " << size << " bytes\n";

	//5中添加的代码
	//s_AllocationMetrics.TotalAllocated += static_cast<uint32_t>(size);

	return malloc(size);
}

static void PrintName(const std::string& name)
{
	std::cout << "PrintName: " << name << std::endl;
}

//利用std::string_view方法
static void PrintName1(std::string_view name)
{
	std::cout << "PrintName1: " << name << std::endl;
}

static void Sting_Func()
{
	std::string name = "GT Sun"; //分配了一次内存

#if 0
	std::string firstname = name.substr(0, 2); //(开始位置，字符长度) 实际上构造了一个子字符串
	std::string lastname = name.substr(3, 3);
	PrintName(firstname);// 这三行代码其实分配了两次，加上前面的一共是三次

	//每一次都会重新分配内存，那么可不可以直接指向最开始的那个内存呢？
	//std::string_view  指向现有内存的指针，其实就是一个const char* ，
			// 指向其他人幽幽的现有字符串，再加上一个size
#else
	std::string_view firstname1(name.c_str(), 2); // c_str构造字符串
	std::string_view lastname1(name.c_str() + 3, 3);

#endif

	PrintName1(name); // 如果直接用 PrintName('GT Sun") 也分配了内存，因为const std::string& 这块分配的)

	PrintName1(firstname1);
	PrintName1(lastname1); // 还是分配了一次内存，就是定义部分
	std::cout << s_AllocCount << " allocations\n"; 

	
}

//完全零分配内存的方法如下========================


static void Sting_Func2()
{
	std::cout << "\n====================\n";


	PrintName1("zhang san");
	std::cout << s_AllocCount-1 << " allocations\n"; 

	const char* name = "Yan Cherno";
	std::string_view firstname(name, 3);
	std::string_view lastname(name + 3, 6);
	PrintName1(firstname);
	PrintName1(lastname);
	std::cout << s_AllocCount-1 << " allocations\n";

}