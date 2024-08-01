#pragma once
/*
主要讲raw function pointer  C语言中的
	
*/
#include<vector>

static void HelloWorld_Func(int a)
{
	std::cout << "Hello World! Value: " << a << std::endl;
}

//================
static void Print_Vector_Value(int value)
{
	std::cout << "Value: " << value << std::endl;
}
static void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}

static void Function_Pointer()
{
	auto func1 = HelloWorld_Func;
	func1(1);

	void(*func2)(int a); // 没有参数就是()  
	//void(*func2)(int a)=Hello_World;
	func2 = HelloWorld_Func;
	func2(2);

	typedef void(*Type_Name)(int a);
	Type_Name func3 = HelloWorld_Func;
	func3(3);

	//=============
	std::vector<int> values = { 4,5,6 };
	ForEach(values, Print_Vector_Value);
	// 改造为lambda函数 ForEach(values, [](int value) {std::cout<<value<<std::endl;});
	//[] 捕获方式 就是如何传入传出参数
}