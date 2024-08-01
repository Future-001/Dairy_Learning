#pragma once
/*这是一个赋值操作对象
*	将一个对象移动到一个已有的对象中时，上节所讲的移动构造函数
*		本节将将一个对象移动到一个已有的对象
*	std::move
*	move assignment operator 移动操作运算符
*/

class StringDemo2 
{
public:
	StringDemo2() = default;
	StringDemo2(const char* string) 
	{
		printf("Created!\n");
		m_Size = strlen(string);
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}

	StringDemo2(const StringDemo2& other)
	{
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	StringDemo2(StringDemo2&& other) noexcept 
	{
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	//本节增加部分
	StringDemo2& operator=(StringDemo2&& other) noexcept
	{
		if (this != &other)
		{
			printf("Move2!\n");
			delete[] m_Data; //需要先将原来指针中的东西删除掉，否则内存泄露了

			m_Size = other.m_Size;
			m_Data = other.m_Data;

			other.m_Size = 0;
			other.m_Data = nullptr;
			//还要确保当前对象不能等与原来的对象，否则数据删了，什么都没了
		}
		return *this;
	}

	~StringDemo2()
	{
		printf("Destoryed!\n");
		delete m_Data;
	}

	void Print()
	{
		for (uint32_t i = 0; i < m_Size; i++)
			printf("%c", m_Data[i]);
		printf("\n");
	}

private:
	char* m_Data;
	uint32_t m_Size;
};


static void StdMove_Func()
{

	StringDemo2 string = "Hello";
	StringDemo2 dest0(std::move(string));
	// 这里其实等价于了 StringDemo1 dest=(StringDemo1&&)string;
	//但是存在一个缺点，就是对与类型不是 StringDemo类型的怎么办呢？所以用std::move
	

	StringDemo2 dest2 = std::move(string); //这样其实有创建了一个对象，调用了构造函数
	//和  dest2=std;:move(string) 的区别，此处 = 其实相当于一个操作函数，只有给变量赋值
	// 时才会调用，相当于   dest2.func(std::move(string))

	StringDemo2 apple = "Apple";
	StringDemo2 dest ;
	std::cout << "Apple: ";
	apple.Print();

	std::cout << "dest: ";
	dest.Print();

	dest = std::move(apple);
	// 这里 = 其实是我们的构造函数 dest.operator=(std;:move(apple))
	//如果没有在类中定义=操作符函数，那么会这里就会出错，因为这里成了赋值操作

	std::cout << "Apple: ";
	apple.Print();

	std::cout << "dest: ";
	dest.Print();
	
}
