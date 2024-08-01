#pragma once
/*数组：存放相同类型数据的集合
运用new关键字创建类的实例化: new关键字实例化时创建在堆上的，一直存活到销毁或程序结束
			delete 关键字删除
	为什么要用new关键字动态分配内存，而不是在栈创建呢？
			生存期；new分配的内存会一直存在，直到删除；
					如果函数需要返回新创建某个数组，除非你传递的参数是地址，否则尽量用new
					
内存间接寻址：指针，指向我们保存实际数组的内存块   p->   p->array 
				会产生一些内存碎片和缓存丢失  */

#include<array>

class Array_ {
public:
	static constexpr int exampleSize = 6;

	int example[exampleSize];  // 创建在栈，作用域结束就销毁
	// int* example = new int[exampleSize];  这样实例化的对象里面存储的就是一个地址。
	//同时计算数组内存大小较难，该方法名字只是地址(指针)
	Array_() {
		for (int i = 0; i < exampleSize; i++)
			example[i] = 2;

		int* ptr = example;
		*(ptr + 2) = 6;// 为什么是+2--> 会根据数据类型计算实际的值，2*4字节
		*((int*)((char*)ptr + 12)) = 8;

		std::cout << example[2] << std::endl;
	}

};
void inline day4_array()
{
	Array_ a; //这个得到的直接是数组，如果new方法，得到的是地址。在堆

	std::array<int, 6> c11;
	// =============================
	int* another = new int[6]; // 创建再堆商，数组类型，删除也要 []
	for (int i = 0; i < 5; i++)
		another[i] = 2;
	delete[] another;
	
}
