#pragma once
/*构造函数初始化列表*/


#include<string>
#include<iostream>
class day4_9
{
private:
	std::string m_Name; int score;
public:
	day4_9() { m_Name = "Unkonwn"; } // 初始化这个类方法1

	day4_9(const std::string& name)
	{
		m_Name = name;
	}

/* day4_9() // 初始化这个类方法2
		:m_Name("Uknown"),score(0);  // 按照顺序 score(-1)表示没有提供

	day4_9(const std::string& name)
		:m_Name(name)	
*/	
	const std::string& GetName() const { return m_Name; }
	// const std::string&  避免对常量进行修改
};


//为什么有区别呢？看下面的例子  风格+功能的区别，避免了性能浪费
class day4_9_example
{
public:
	day4_9_example()
	{
		std::cout << "Create Example" << std::endl;
	}
	day4_9_example(int x)
	{
		std::cout << "Create Example with " << x << std::endl;
	}

};
class day4_9_En1
{
private:
	day4_9_example Example;
public:
	day4_9_En1()
	{
		Example = day4_9_example(6); // 会导致初始化两次，性能浪费
	};

	// 这样的好处是不会实例化两次

};


class day4_9_En2
{
private:
	day4_9_example Example;
public:
	day4_9_En2()
		:Example(day4_9_example(8)) {}

	// 这样的好处是不会实例化两次

};


static void day4_9_f()
{
	const day4_9 d0;
	std::cout << d0.GetName() << std::endl;
	day4_9 d1("Cherno");
	std::cout << d1.GetName() << std::endl;

	std::cout << "\n两种初始化的区别：避免性能浪费" << std::endl;
	day4_9_En1 ex1;
	day4_9_En2 ex2;

}

