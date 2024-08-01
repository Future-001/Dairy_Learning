#pragma once
#include<iostream>

class Conductors
{
public:
	float X, Y;

	Conductors() {}// X = 0.0f; Y = 0.0f
	// 初始化这个类，不然实例化的时候，其实内存中的东西没有改变
		//，还是原来的内容 除非你对对象的内容进行了改变。否则内存中的内容还没有变化

	Conductors(float x, float y)
	{
		X = x;
		Y = y;
	};
	void print()
	{
		std::cout << X << ',' << Y << std::endl;
	}
};

static void conductor()
{
	Conductors c(10.0f, 2.4f);
	c.print();
}

class Del_Conductor
{
private:
	Del_Conductor() {}; // 这样在外面就不能直接增加成员了，
	//Del_Conductor() = delete;  // 两种方法都可以删除直接创建对象成员的方法
public:
	static void write() {};
};

