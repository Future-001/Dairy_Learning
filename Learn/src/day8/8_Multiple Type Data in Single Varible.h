#pragma once
/*单变量如何存放多种数据类型
*  std::variant		C++17
*		允许列出一个数据所有可能的数据类型，然后你可以决定它将是什么
*		和结构体不一样，variant将所有可能的数据类型存储为单独的变量，作为单独的成员
*				？最大变量+类型标签？
*/
#include<variant>

//另一种使用场景，
enum class ErrorCode
{
	None = 0, NotFound = 1, NotAccess = 2
};
std::variant<std::string, ErrorCode> ReadFile2() { return {}; };


inline void Multiply_Type_Func()
{
	std::variant<std::string, int> data;
	data = "SunGt";
	std::cout << std::get<std::string>(data) << "\n";
	if (data.index()) {}; // 就是索引当前元素的数据类型，0 ，1

	data = 2;
	if (auto value = std::get_if<std::string>(&data))
	{
		std::string& v = *value;
	}
	else std::cout << std::get<int>(data);
}