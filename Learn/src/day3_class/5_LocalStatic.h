#pragma once
/*生命周期 与 作用域
*/

//             单例模式   这个类只有一个实例存在
class Singleton
{
private:
	static Singleton* s_Instance;
public:
	static Singleton& Get() { return *s_Instance; }

	void Hello() {}
};
// Singleton* Singleton::s_Instance = nullptr;  不注释会重复定义，因为两次func 

#include<iostream>
inline void func()
{
	static int i = 0;  // 每次调用函数i 不一定从0开始了，只能在函数内调用i
	i++;
	std::cout << i << std::endl;

	Singleton::Get().Hello();
}

/*   利用静态变量，我们可以说实现
class Singleton
{
public:
	static Singleton& Get() 
	{ 
	static Singleton Instance;
	return Instance; }

	void Hello(){}
};
*/