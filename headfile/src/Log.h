#pragma once  
// 用来只让文件预编译一次，例如common中也含有另一个结构体Player,出现了链接错误
// 出现了同名错误。
/*另一种方法
#ifndef _LOG_H
#define _LOG_H
...
#endif

头文件的引用
<> 与 ""的区别
		主要是告诉头文件的路径  <> 的路径是默认是包含目录bin
		""用来指代相对路径，表示头文件的位置  "../xxx.h"
*/

void InitLog();  
void Log(const char* message);  
// 如果不在头文件中进行声明，那么每次在别的函数中调用Log.cpp中的Log函数
// 需要每次都进行声明，太麻烦了。
struct Player {}; //只能编译一次


