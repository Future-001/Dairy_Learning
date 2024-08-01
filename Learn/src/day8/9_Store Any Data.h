#pragma once
/*存储多种类型的数据
*    C++17  std::any  没有模板参数
*		会动态分配内存-->影响性能
* 
* 看一看源码，对于小类型的数据，any 其实和 variant一样，不过是列举了全部的类型
* 大的类型数据，进入void* 动态分配内存  8min
*/
#include<any>

inline void* operator new(size_t size){
	return malloc(size);}  //打断点测试一下是否分配内存，注意在stack上的详细代码来看

struct CustomClass { std::string s0, s1; };//大数据类型，动态分配

inline void Any_Func()
{
	std::any data; // std::make_any
	data = 2;
	data = "SunGT"; //const char* 类型的 这样的类型可能会带来内存的动态分配，影响性能
	data = std::string("Cherno");
	 
	// 这是复制，影响性能 std::string string = std::any_cast<std::string>(data);
	std::string& string = std::any_cast<std::string&>(data);

	std::any dataClass = CustomClass();
	//std::any data1 = std::make_any< std::initializer_list<int>>({ 1,2,3,4,5,6 });
}