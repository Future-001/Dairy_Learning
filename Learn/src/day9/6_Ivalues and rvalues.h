#pragma once
/*左值和右值
*		临时存储的值是右值，有存储地址的才是左值，或者除非加上
*		左值引用& 只能引用左值，除非加上const    const & 会创建一个左值
*			右值引用 && 这样无法传递左值
*/

int& Getvalue() // 加入了& 同时返回了value是一个左值引用
// 左值引用的也只能是左值，所以下面返回value也只能是value 不能是10
{
	static int value = 10;
	return value;
}
 

static void PrintName_Func(std::string& name)
{
	std::cout << name << std::endl;
}

static void PrintName_Func(std::string&& name)
{
	std::cout << name << std::endl;
}


static void lI_value_Func()
{
	int i = Getvalue();
	Getvalue() = 5; 
	const int& a = 10;

	std::string Firstname = "Sun";
	std::string Lastname = "GT";
	std::string FullName = Firstname + Lastname;
	PrintName_Func(FullName);
	PrintName_Func(Firstname + Lastname);
}