/*		error2: LNK unresolved external symbojl

//---------------------函数名称不符------------
#include<iostream>

void Log_2(const char* message)
{
	std::cout << message << std::endl;
	std::cin.get();
}

//-------------------返回值不符------------------
//int Log(const char* message)
//{
//	std::cout<<message<<std::endl;
//	return 0;


// -------------传入参数个数不符--------------------
//void Log(const char* message,int level)
//{
//	std::cout << message << std::endl;
//	
//}
*/

/*			error3: 链接器链接错误，不知道链接到哪一个
#include<iostream>

void Log_2(const char* message)
{
	std::cout << message << std::endl;
	std::cin.get();
}

--------------------------2   多个头文件重复引用导致的连接错误---------
//   log.cpp  log.h   ERRORS.cpp
#include<iostream>
#include"Log.h"
void InitLog()
{
	Log("Initialized Lod");
}

*/

#include<iostream>
#include"Log.h"
void InitLog()
{
	Log("Initialized Lod");
}