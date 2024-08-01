#pragma once
/*移动语义
*		很多时候，如果我们需要复制传递一个参数，很可能我们需要复制
*		如果复制的对象 需要分配内存的话，会影响性能
* 
*		我们只对对象进行移动，但是不复制
*/

class StringDemo1 //演示一下为什么需要移动
{
public:
	StringDemo1() = default;
	StringDemo1(const char* string) //创建一个实际的字符串
	{
		printf("Created!\n");
		m_Size = strlen(string);//没有结束符
		m_Data = new char[m_Size];
		memcpy(m_Data, string, m_Size);
	}
	
	StringDemo1(const StringDemo1& other)// 将右值复制过来
	{
		printf("Copied!\n");
		m_Size = other.m_Size;
		m_Data = new char[m_Size];
		memcpy(m_Data, other.m_Data, m_Size);
	}

	StringDemo1(StringDemo1&& other) noexcept //告诉编译器不应该抛出异常
	{
		printf("Moved!\n");
		m_Size = other.m_Size;
		m_Data = other.m_Data;// 给指针赋值

		other.m_Size = 0;
		other.m_Data = nullptr;
	}

	~StringDemo1()
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

class EntityDemo1
{
public:
	EntityDemo1(const StringDemo1& name) 
		:m_Name(name) {}

	// 避免进行复制，因为右值变为左值会进行分配内存
	EntityDemo1(StringDemo1&& name)
		:m_Name(std::move(name)) {} // 或者显式的转换m_Name(StringDemo1(name));

	void PrintName()
	{
		m_Name.Print();
	}
private:
	StringDemo1 m_Name;
};

static void Move_Func1()
{
	EntityDemo1 entity(StringDemo1("Sungt")); //显式转换
	entity.PrintName();
}

/*详细解释如下：
*	类StringDemo1只是为了演示为什么需要移动
*		其中的StringDemo1(const char* string) 是为了创建一个实际的字符串
*		这发生在实例化一个Entity时候，调用了StringDemo1中的创建方法
* 
*		同时，StringDemo1(const StringDemo1& other) 复制了字符串
*			这样每次都利用了内存分配，影响性能
*		此时运行出现Destory实际上只是临时的右值被删除了		
* 
*	我们在实例化的过程中，Entity里面利用右值引用的方法，不会复制对象
*		调用的方法是StringDemo1(StringDemo1&& other)
*			将m_Data的指针指向other,other的指针指向空，那么相当于将other的指针指向
*			了一个空，这样的话，就不会需要两次复制，两次内存分配了
*/
