#pragma once
/*堆和栈性能方面的差异：
	
	对象如何生存在栈上：
	
	栈：在顶部添加数据的数据结构
		作用域结束，内存释放
	*/
class day5_5
{
public:
	day5_5()
	{
		std::cout << "Create day5_5!" << std::endl;
	}
	~day5_5()
	{
		std::cout << "Destory day5_5!" << std::endl;
	}
};

inline int* example_array()
{
	int a[66];
	return a;
}


// 我们创建一个工作在堆上的指针，当作用域结束解释放   作用域指针
//unique_ptr  工作原理如下 
//自动化new delete 
class ScopedPtr
{
private:
	day5_5* m_Ptr;
public:
	ScopedPtr(day5_5* ptr)
		:m_Ptr(ptr) {}
	~ScopedPtr() { delete m_Ptr; }
};


static void _5()
{
	{day5_5 e;}
	{day5_5* e = new day5_5;}
	example_array();// 肯定得不到返回的数组


	//智能指针
	{ ScopedPtr entity = new day5_5; }
	//这种方式也是在堆上创建指针，但是作用域结束就消失了。
}
