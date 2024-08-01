#pragma once
/*
Copying:
	有时候过多的copy会造成性能浪费，能不能再想要copy时在copy，
	     且只copy部分内容


	*/

#include<memory>
class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];//要存结束符
		memcpy(m_Buffer, string, m_Size + 1);// m_Buffer[m_Size]=0也是添加了结束符
		//这里就相当于利用 for给字符串每个都赋值
	}

	char& operator[](unsigned int index) { return m_Buffer[index]; }

	/*
	 浅层拷贝做的事情其实如下
	String(const String& other)  //String(const String& other)=delete 那么就不允许 拷贝
									// unique_ptr 的内容
	{memcpy(this, &other, sizeof(String));}
			// 等价于 m_Buffer(other.m_Buffer), m_Size (other.m_Size)
			*/
	
	//深拷贝如下，其实就是给重新分配了内存；
	String(const String& other)  
	:m_Buffer(other.m_Buffer), m_Size (other.m_Size)
	{	
		std::cout << "Copy string!" << std::endl;
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);}
		

	~String() { delete[] m_Buffer; }  // 避免内存泄漏
	friend std::ostream& operator<<(std::ostream& stream, const String& string);

};
std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;// 这是私有变量，必须用友元
	return stream;
}

//详细解释看下面的应用
static void Copy_Print(String string)
{
	//如果在里面还要复制，直接用String copy=string;就可以了
	std::cout << string << std::endl;
}

static void Copy_Example()
{
	String string("Cherno");
	String second = string; // 没定义String(深拷贝之前，这其实是浅拷贝，
	//string second共用了一块内存，但是delete释放的时候，程序以为要释放两块内存
	//所以程序崩溃了

	second[2] = 'a';

	std::cout << string << std::endl;
	std::cout << second << std::endl;
	
	Copy_Print(string);
	Copy_Print(second);
	//看起来上面second 做了一次复制，但是将其传递给Copy_Print时，
	// 我们实际上做了额外两次复制操作，有三个copy string
	//除非定义时使用 const String& string直接引用。
}
