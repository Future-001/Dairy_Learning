
/*
两种意思：
	1.class 或者 static 外使用 static
		类外的static 使用的是局部的，只对定义它的编译单元(.obj)可见
	2.class 或者 static 内部使用
		表示这部分内存是这个类的所有实例共享的
		如果在一个类中改变了这个静态变量，其他实例化的对象中该变量也会被改变

extern  表示在外部的编译单元去找。

就像3.h一样： 我们Include了3.h，同时两1和3都有了 log_f的定义，那么你调用这相当于链接的时候就会出错了。
		*/

// class 或者 static 内部使用

/*
#include<iostream>

struct Entity
{
	int x, y;
	void print()
	{
		std::cout << "x:" << x << " y:" << y << std::endl;
	}
};

inline void static_class()
{
	Entity e;
	e.x = 4;
	e.y = 5;

	Entity e1 = { 6,8 };
	e.print();
	e1.print();
}

*/

#include<iostream>

struct Entity
{
	static int x, y;
	void print()
	{
		std::cout << "x:" << x << " y:" << y << std::endl;
	}

	// 使用对象来调用类的静态变量没有意义，   类名::静态变量
	// 静态方法不通过类的实例化对象就可以调用，  (类名::静态方法)
};

int Entity::x;
int Entity::y;   // static int x,y 等价于这段代码  ==》定义这些静态变量

void static_class()
{
	Entity e;
	e.x = 4;  // 等价于 Entity::x=4;Entity::y=5;
	e.y = 5;

	// Entity e1 = { 6,8 }; //这样就会报错，因为x,y不再是对象的成员（自我理解）
	//Entity e1;
	/*e1.x = 6;   因为是类的成员，对象进行引用没有什么意义了
	e1.y = 8;
	*/
	Entity::x = 6; Entity::y = 8;
	e.print();
	
}

/*
静态的方法无法调用共用变量
例如
#include<iostream>

struct Entity
{
	int x, y;
	static void print()
	{
		std::cout << "x:" << x << " y:" << y << std::endl;  
	}  //会报错，因为print方法是静态的方法，无法调用x y变量 //改发  Entity::x   Entity::y

};

上面的方法相当于 
static void print()
{
	std::cout << "x:" << x << " y:" << y << std::endl;  
	}   x,y都没有被传输进来，那怎么可能使用得到   static void print(Entity e) 

void static_class()
{
	Entity e;
	e.x = 4; 
	e.y = 5;

	 Entity e1 = { 6,8 }; 

	e.print();

}

*/
