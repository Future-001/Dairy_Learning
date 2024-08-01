#pragma once
/*lambda 匿名函数
	非实际意义上在单独创建函数--> 一次性函数
	不需要函数定义就能定义一个函数

	https://en.cppreference.com/w/可以查看具体的定义
	*/

#include<vector>
#include<algorithm>  // std::find_if函数
#include<functional>

static void ForEach_Lambda(const std::vector<int>& values, const std::function<void(int)>& func)
{  // 上面的lambda 的数据类型已经改变了，所以必须修改
	for (int value : values)
		func(value);
}

static void Lambda_Func()
{

	std::vector<int> values = { 4,5,6 };
	int a = 5;
	auto lambda = [=](int value)  // = 引用全部  
		mutable {  a = 6; std::cout << "a: " << a << " Value: " << value << std::endl; };
	// 要修改其中的变量，使用Mutable
	ForEach_Lambda(values, lambda);

	//=================在std::find_if函数用来在某种迭代器中找到值
	std::vector<int> values_ = { 1,5,4,2,3 };
	auto it = std::find_if(values_.begin(), values_.end(), [](int value)
		{return value > 3; });
	// 返回满足条件的第一个元素
	std::cout << "The num is: " << * it << std::endl;
}