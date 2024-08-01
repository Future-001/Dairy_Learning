#pragma once
/*类型转换（C++）
*		 static_cast   reinterpret_cast  dynamic_cast   const_cast 四种主要类型
*				除了可能收到的那些编译时的检查之外，还可以在代码库中搜索他们
*		等价于C语言中的强制转换
*/
class Cast_Example {public:virtual  ~Cast_Example() {}; };
class Cast_Example1 : public Cast_Example{};
class Cast_Example2 :public Cast_Example{};

inline void Cast_Func()
{
	double value = 6.6f;
	int a = value;//隐式转换

	Cast_Example* c = reinterpret_cast<Cast_Example*>(&value);

	Cast_Example1* C = new Cast_Example1();
	Cast_Example* cast = C;
	Cast_Example2* vc = dynamic_cast<Cast_Example2*>(cast);
	// dynamic_cast只能在涉及多态时进行派生类到基类的转换（多态：至少一个虚函数）

	if (vc) {};//可以查看是那种类，如果不能正常转换，会返回NULL
}