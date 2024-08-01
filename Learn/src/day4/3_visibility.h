#pragma once
/*指的是一个类中的成员或者方法是否可见  private protect public  
class 默认是private ，只有这个类能访问到他（还有友元 friend) 后续会讲
private: 只有类和友元能访问到
protected : 这个类已及所有的派生类都可以访问到这些成员，再派生类中用，main函数也不能用，
			再类的外面，不在子类中。
public：*/

#include<iostream>
#include<string>


class visual {
private:
	int X, Y;
protected:
	void Pro() {};
public:
	visual() {
		X = 0;
		Pro();
	};
};

class En:public visual
{
public :
	En(int& d)
	{
		//X = 2;  同样无法访问
		visual::Pro();
		int c=d;
	}
};

static void vis_t()
{
	visual::visual();
	//En en(3);
	//en.Pro();  子类外边也无法调用
	//en.En()  也不行
	//En::En(2);
}
