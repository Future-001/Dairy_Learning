#pragma once
/*静态数组
		数组大小固定
		有边界检查，debug模式下不能超出去
		.size()  std::sort() .begin()  ...
		*/
#include<array>

		//static void PrintStaticArray(const std::array<int,5>& array)
		// 思考这里不直接传5 该怎么传数组的大小
template<std::size_t N>
static void PrintStaticArray(const std::array<int, N>& array)
{
	//pass;
}

static void Static_Array_Func()
{
	std::array<int, 5> DataOld;
	DataOld[0] = 0;
	DataOld[1] = 1;
	DataOld[2] = 2;

	PrintStaticArray<DataOld.size()>(DataOld);
}

