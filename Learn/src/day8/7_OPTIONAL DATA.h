#pragma once
/*如何处理OPTIONAL数据
*				当数据可能存在也可能不存在时会发生什么？
*
* std::optional  C++17
*
*/
#include<fstream> // 操作文件的头文件

std::string ReadFileAsString(const std::string& filepath, bool& ReadStatus)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result; // 这里得到的结果是文件的字符串
		//rea file
		stream.close();
		ReadStatus = true;
		return result;
	}

	ReadStatus = false;
	return std::string();// 打开失败就返回空
};

inline void OPTIONAL_Func()
{
	bool ReadStatus;
	std::string data = ReadFileAsString("data.txt",ReadStatus);
	if (ReadStatus) 
	{
		std::cout << "Open Success!(Func)\n";
	}
	else std::cout << "Failed Open!(Func)\n"; 	
}


//======================================

#include<optional>
std::optional<std::string> ReadFile(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		stream.close();
		return result;
	}

	return std::optional<std::string>();  // 直接返回{}也可以
}

inline void OPTIONAL_Func2()
{
	std::optional<std::string> data = ReadFile("data.txt");

	std::string value = data.value_or("Not Present");  //如果存在返回内容，不存在返回默认值
	std::cout << value << std::endl;

	if (data.has_value())  //if(data) 也可以
	{
		std::cout << "OpenFile Success!(Optional)" << std::endl;
		data.value();
		//data-> 
		std::string& content = *data;
	}
	else
	{
		std::cout << "Failed OpenFile Success!(Optional)" << std::endl;
	}
}