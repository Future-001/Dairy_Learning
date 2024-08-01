#pragma once
/*模板
	
	*/
template<typename T>   // template<class T> also is OK
static void Print_Template(T value)
{
	std::cout << value << std::endl;
} // 如果没有调用，模板实际上是不存在的，只有基于模板的使用情况
// 发送到编译器进行编译，才会转换为具体的代码，将类型T转换为具体的类型

template<typename T, int N>
class Template_Class
{
private:
	T Array[N];
public:
	Template_Class(T Name)
	{
		std::cout << "Array Size:" << N << "\t" << Name << std::endl;
	}
};


static void Template()
{
	Print_Template(6.6f);
	Print_Template("Hello World!");
	Print_Template<int>(88);

	Template_Class<std::string, 20> Name_("Cherno");

}