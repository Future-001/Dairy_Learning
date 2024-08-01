#pragma once
// 枚举类型   增加程序可读性
//enum Example  // 可以指定类型或者不指定

enum Example :unsigned char
{
	A, B = 6, C  // 默认从0开始，以此增加   想一下3.log.h中的log级别使用
};

inline void enumeration()
{
	Example c_6 = C;
	std::cout << "枚举成功" << std::endl;
}