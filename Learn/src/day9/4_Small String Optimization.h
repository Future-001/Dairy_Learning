#pragma once
/*小字符串优化sso
*		就是将不太长的字符串分配到一个静态分配的栈缓冲区，不去对堆进行分配
*	
*/
/* 1里面已经定义过了new
void* operator new(size_t size)
{
	std::cout << "Allocate " << size << " bytes";
	return malloc(size);
}*/

static void Sso_Func()
{
	std::string name = "Sink The is A PaPa"; // 去看看源码，就知道最后的结果了
	//看看源码string 现在缓冲区多大字符，然后修改name的字符数量看看有没分配内存
	
}