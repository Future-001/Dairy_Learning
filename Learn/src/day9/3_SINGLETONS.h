#pragma once
/*单例模式
*		一个类的单一实例
*				只是一种组织一堆全局变量和静态函数方式
* 其实就像 名称空间那样工作
* 
*  其实很简单，就是不能 实例化（包括复制），通过返回指针来进行调用类中的功能
*/
class Singleton
{
public:
	Singleton(const Singleton&) = delete; //为了防止复制==>成了多个实例化，就不是单例了
	static Singleton& Get()
	{
		return s_Instance;
	}

	void func() {};
private:
	Singleton() {}; //  如果public有构造函数，会允许实例化

	static Singleton s_Instance;
};

Singleton Singleton::s_Instance;

static void Singleton_Func()
{
	Singleton& Instance = Singleton::Get(); //如果 没有引用，就成了复制，就不是单例模式了
	Instance.func();
}


/*
class Singleton
{
public:
	Singleton(const Singleton&) = delete; //为了防止复制==>成了多个实例化，就不是单例了
	static Singleton& Get()
	{
		static Singleton s_Instance;
		return s_Instance;
	}

	void func() {};
private:
	Singleton() {}; //  如果public有构造函数，会允许实例化
};


*/