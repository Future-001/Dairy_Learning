#pragma once
/*字符串
C++默认处理子方式就是ASCII字符（很多类型utf-8 unicode等待)
字符串其实就是很多const char*类型字符组成的数组,  asciitable.com
字符串的组合
		name+="string";    const char* name=std::string("Cherno")+",Hello";

*/
#include<string>
void day4_string()
{
	const char* name = "Cherno";  // const   内存视图查看数据,看一下结束符
	char* N_name = new char[10];
	delete[] N_name;
	std::cout << name << std::endl;

	char name2[7] = { 'C','h','e','r','n','o',0};
	// 没有结束符，去内存中看一下是什么样子  0  或者 '\0'
	std::cout << name2 << std::endl;
	//很好奇内存溢出是什么样子

	std::string name3 = "zhang_san";  // const char 的数组不是char的数组
	name3 += ",Hello!";  // 无法直接用 "zhangsan" + ",Hello~"
	//const char* name=std::string("Cherno")+",Hello";

	std::cout << name3 <<std::endl;
	bool contains = name3.find("no") != std::string::npos;  // 就是如果不是非法位置
	//bool contains = name.find("no")!=std::string::npos  表达式类型必须是类类型 class type

	name3.size();
	//strcpy(name3);
	//strlen(name3);;  只适合用charL数组

	//char* HHH="lll" ; 无法将const char 类型赋值 char 
	//std::cout << HHH << std::endl;
}