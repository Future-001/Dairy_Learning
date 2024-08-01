/*		ERROR1: errors.cpp

#include<iostream>
 
 // entry point 主函数一定是Main ? 函数的入口
 // Cerror : compile error       LNKerror : LINKerror
 // compile successed. 但是LNK失败，因为找不到程序的入口。
 // properities: configuration :  find configuration type is .exe must have entry point.
 // if we into the Linker (Advanced) --> Entry Point.
 // 我们可以指定一个程序的入口，不一定是main函数，但是程序必须有一个入口点
	
void Log_1(const char* message)
{
	std::cout << message << std::endl;
	std::cin.get();
}

int Multiply(int a, int b)
{
	Log_1("Multiply");
	return a * b;
}
*/

/*			error2: ERRORS.cpp  Log.cpp

#include<iostream>


	entry point √
	C3861: 'Log_2': identifier not found

 //Linkerror1:
	//unresolved external symbol
	//		1，函数名不匹配，例如我在另一个函数中用了Logr_2(const char*)
	//				链接时连接不到这个函数，就会报这个错
	//		2. 函数类型不匹配  int Log_2(const char*)
	//		3. 函数参数不匹配  void Log_2(const char* message,int level)
	//			传递的参数数目不符
	//		static 参数，如果我在函数中不适用Multipuly 也就用不到Log
	//				但是因为Multipuly中存在Log函数，
	//				如果用到了，无法链接到Log.obj，还是会报错，

//void Log(const char*); 缺少声明报错：C3861: 'Log_2': identifier not found

----------------------------------------------------------------
//    该块代码对应Log中error2的三种情况
//void Log(const char*);
//int Multiply(int a, int b)
//{
//	Log_2("Multiply");
//	return a * b;
//}
//
//void main()
//{
//	std::cout << Multiply(5, 8) << std::endl;
//	std::cin.get();
//}

-------------------------------------------------

//   static 是因为即使在main用不到log,但是万一其他地方用到了，发生了log
//   中 error2 的三种错误，照样还有错。所以声明Multiply函数在该块有用
void Log(const char*);
static int Multiply(int a, int b)
{
	Log("Multiply");
	return a * b;
}

void main()
{
	//std::cout << Multiply(5, 8) << std::endl;
	std::cin.get();
}
*/


/*			error3: errors.cpp  Log.cpp  Log.h
			函数或变量同名且拥有相同参数与返回值链接错误

//-------------------编译错误：具有同名函数-------

//#include<iostream>
//void Log_2(const char* message)
//{
//	std::cout << message << std::endl;
//	std::cin.get();
//}
//void Log_2(const char* message)
//{
//	std::cout << message << std::endl;
//	std::cin.get();
//}

----------------连接错误：具有同名函数名.obj
// error3:  log.cpp-->1  ERRORS.cpp
// 因为log.cpp中也存在着 log函数，所以链接器不知道链接到哪一个log

#include<iostream>
void Log(const char*);
void Log_2(const char* message)
{
	std::cout << message << std::endl;
	std::cin.get();
}

static int Multiply(int a, int b)
{
	Log("Multiply");
	return a * b;
}

void main()
{
	std::cout << Multiply(5, 8) << std::endl;
	std::cin.get();
}

---------------------头文件重复引用，导致多个同名函数------------
// log.h log.cpp-->2  errors.cpp
// 解决方法： 在 Log.h中    
		//  1. 将头文件中的Log函数标记为static
					链接将只发生在函数的内部，在errors.cpp log.cpp中的log是
					不一样的。对其他log.obj不可见
			2.inline  就是将函数体拿过来直接用
#include<iostream>
#include"Log.h"

static int Multiply(int a, int b)
{
	Log("Multiply");
	return a * b;
}

void main()
{
	std::cout << Multiply(5, 8) << std::endl;
	std::cin.get();
}
*/	

#include<iostream>
#include"Log.h"

static int Multiply(int a, int b)
{
	Log("Multiply");
	return a * b;
}

void main()
{
	std::cout << Multiply(5, 8) << std::endl;
	std::cin.get();
}
