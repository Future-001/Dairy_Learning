#pragma once
/*const关键字

const int a=90 ; 表明这是一个常量，无法修改了

int* b= new int;
*b=2;
b=(int*)&a;  这样也可以赋值，只是改了指向的地址而已

const int* c= new int; // 表面我们不改变修改指针指向的地址中的内容
//此时  *c=2; 会报错，因为我们改了指针指向的内容

c =(int*)&a;   // 重点::::这样正确，因为我们没有改变指针指向的地址中的内容
				//我们改了什么呢？改了&c这个里面的内容c
				//原来&c存储的地址变了,也就是指针指向变了

int* const d=new int; // 作用正好相反，可以改变指针指向的内容，不能重新赋值指针
					// 指针的方向定了  
					//c=(int*)&a;就错了


// const int*  <==>  int const* ;
// const int const* 既不也不



=======================类中的const =========

class Entity
{
private:
	int* m_X, m_Y;  // 这种m_Y的类型只是 int
	mutable int X;  //mutable 表示允许在常量中进行改变
public:
	const int const* Get() const  // 最后面的const 代表了该方法内我们不会更改类
	// 如果在主程序中  const Entity e; 如果没有最后一个const 那么这个方法无法使用了
	{
		X = 6; return m_X;
	}
	 int* Get2() const  // 最后面的const 代表了该方法内我们不会更改类
	{
		return m_X;
	}
	int* Get3() { return m_X; }  // 这样的可以修改
};

static void Day4_7_Print(const Entity& e)  // (Entity e) 会复制类中所有的内容，占用内存
{				// const 表示只引用常量 ,表示无法修改e,如果重新分配e,实际上在改变这个对象
				// 引用其实就是内容，引用就是entity 无法修改Entity
				// const & 代表了不会修改引用来的内容
				// const Entity* e 表示只能修改指向，不能修改*e的内容  可以 e=nullptr;
	std::cout << e.Get2() << std::endl;
}

*/

class Entity
{
private:
	int* m_X, m_Y;  // 这种m_Y的类型只是 int 
	mutable int X;  //mutable 表示允许在常量中进行改变
public:
	const int const* Get() const  // 最后面的const 代表了该方法内我们不会更改类
	{
		X = 6; return m_X;
	}
	 int* Get2() const  // 最后面的const 代表了该方法内我们不会更改类
	{
		return m_X;
	}
	int* Get3() { return m_X; }  // 这样的可以修改
};

static void Day4_7_Print(const Entity& e)  // (Entity e) 会复制类中所有的内容，占用内存
{				// const 表示只引用常量 ,表示无法修改e,如果重新分配e,实际上在改变这个对象
				// 引用其实就是内容，引用就是entity 无法修改Entity
				// const Entity* e 表示只能修改指向，不能修改*e的内容  可以 e=nullptr;
	std::cout << e.Get2() << std::endl;
}