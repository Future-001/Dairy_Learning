#pragma once
/*排序
		冒泡排序；其他的函数
		std::sort
*/

#include<vector>
#include<algorithm>  //sort 
#include<functional>

static void Sorting_Func()
{
	std::vector<int> values = { 3,5,1,4,2 };
	std::sort(values.begin(), values.end()); // 默认按照升序排序，最后一个参数可以更改
	//std::sort(values.begin(), values.end(),排序方式);
	//排序方式可以是结构体内的函数，lambda 还可以是内置函数(functional头文件中)

	for (int value : values)
		std::cout << value << std::endl;

	std::sort(values.begin(), values.end(),std::greater<int>()); // 内置函数，也是从大到小

	std::sort(values.begin(), values.end(), [](int a, int b)
		{
			if (a == 1) return false;
			if (b == 1) return true; // 将1放在最后面去
			return a < b; // 可以去查一下具体的文档怎么用的 cppreference.com那个
		});


}