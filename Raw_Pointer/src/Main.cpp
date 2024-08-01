#include<iostream>
// a pointer is just a address , a number 
// 指针类型没有任何意义，只是代表着那个地址的数据可能是指针的类型；类型是无意义的
// 指针类型不会改变指针，指针一定是整数int.void* 代表我们不关心指针地址中的数据是什么类型

#define LOG(x) std::cout<<x<<std::endl;

void reference(int*, int&);
int main()
{
	int var = 9;
	//void* ptr = 0; 地址是0 代表是无效的状态，不是一个有效地址。  ptr = NULL  nullptr
	void* ptr = &var; 
	double* pointer = (double*)&var;  // 不然的话指针地址中的数据是Int, 不符合

	//*ptr = 8;  这样改变就不对，因为编译器不知道你要写入的数据类型，多大字节，void*不知道
	// 指针类型就是用来指导编译器，告诉他应该怎么存数据。
	
	//---------------------------------------------//


	char* buffer = new char[8]; // 分配了八个字节的内存，并且返回一个指向这个地址的指针
	memset(buffer,8, 8);  //memset函数

	char** pptr = &buffer;  

	// 打个断点，看看 buffer &buffer pptr *pptr **pptr都是什么
	delete[] buffer; // 分配的内存需要释放删除  


	// new 和 delete的机制

	//------------------reference-------------
	int a = 2, b = 9;
	reference(&a, b); // int& ref=a; ref不会被创建 int& 引用类似指针效果
	LOG(a);
	LOG(b);

	std::cin.get();

}