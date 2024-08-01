#pragma once
/*结构化绑定 --只针对C+=17
*		更好的处理多返回值
*			以前可以利用struct , tuple pari对组等
*		
*/

#include<tuple>

std::tuple<std::string, int> CreatPerson()
{
	return { "SunGt",24 };
}

inline void Structured_Bings_Func()
{
	auto person = CreatPerson();
	std::string& name = std::get<0>(person);

	std::string name2;
	int age2;
	std::tie(name2, age2);// 这也时元组的一种属性方法

	//C++17的最新属性
	auto [name3, age3] = CreatPerson();
	std::cout << "name: " << name3 << "   age:" << age3 << std::endl;
}