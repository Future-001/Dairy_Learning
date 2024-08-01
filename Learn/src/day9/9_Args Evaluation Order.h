#pragma once
/*参数计算顺序
*		
*		
*/

static void PrintSum(int a, int b)
{
	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
}

static void Arg_Order_Func()
{
	int value = 0, i = 0;
	PrintSum(value++, value++);
	PrintSum(++i, ++i);
	//和C++的标准有关，和调试模式以及debug模式有关
	//0+1 1+0 2+2 都不一样
}