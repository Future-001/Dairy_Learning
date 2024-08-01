#include<iostream>
// filename is just filename.   .cpp 是我们默认用来编译c++的，
// 可以 .cherno 指定编译器用来编译c++

// 预处理的命令  properity: preprocesser里面设置生成 .obj  还是  .i  文件（预处理后的） advanced
// optimization : release 与 debug的区别
//				debug不作任何优化，有很多额外的东西（
//				release可能O2和代码生成下的basic code generation矛盾）
// #if #endif   的运用。  
// .obj文件转换为可读： properity: c/c++ : outputfile --> .asm格式 汇编语言（寄存器，Mov,eax,imul)
#include "Log.h"

int Multiply(int a, int b);
#if true
int main() 
{
	Log("Hello World!");
	Multiply(3,8);

	std::cout << std::endl;
	debug();

	const char* ptr=nullptr;
	if (ptr != nullptr)
		std::cout << "ptr is not null" << std::endl;
	else if (ptr == "Hello")
		std::cout << "Set successed." << std::endl;
	else
		std::cout << "ptr is null!" << std::endl;
}
#endif