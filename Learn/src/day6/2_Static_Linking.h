#pragma once
/*C++库 以及如何在项目中 使用外部库 
		Cherno习惯在解决方案的实际项目文件夹，保留使用的库版本，
			从一些仓库下载该项目后，就不用再去下载别的库，可直接运行
			到底是用源码编译还是二进制文件编译呢？

		本节用二进制文件编译  GLFW  32位编译还是64位取决于你的目标程序，你要编译为32还是64

		https://www.glfw.org/download.html     
			库由两部分： includes（一堆头文件) ： 用于使用预构建的二进制文件中的函数
						  Library  (函数）： 有预先构建的二进制文件（动态库 静态库）

静态链接： 意味着这个库会被放到你的可执行文件中，它在.exe文件中或者其他执行文件
			速度更快（编译器或链接器实际上可以执行链接时优化之类的）

动态链接：  运行时被链接，可以选择在程序运行时，装载动态链接库 LoadLiabrary函数
			（例如WindowsAPI）它会载入你的动态库，从中拉出函数，然后开始调用
			应用程序启动时启动你的dll文件；

二者的区别： 库文件是否被编译到 .exe可执行文件或者链接到可执行文件
			 还是一个单独的文件，放在.exe周围，当exe启动时被加载

本节使用了头文件以及库文件进行演示
		本节中，将其指向头文件，就可以直到那些函数是可用的，然后就 有了函数声明，
		（实际上是符号声明，因为他们也可以是变量）

		链接器指向库文件，告诉链接器这是库文件，然后将其链接起来才能获取到符号的具体定义

===>  解决方案下，创建一个Dependency目录，在此目录下创建另一个名为GLFW的文件夹
				将头文件以及库文件复制进去

===>  解决方案属性--->  C/C++ --->  General ---> Additional Include Directiories.
				$(SolutionDir)Dependencies\GLFW\include
===>  解决方案属性--->  Linker --->  Input  ---> Additional Dependencies
					---> 添加路径/glfw3.lib    

	如果上述步骤不添加路径，那需要单独设定库文件路径
					Linker --->   General ---> Additional Library Directories
					---> 添加$(SolutionDir)Dependencies\GLFW\lib-vc2022

*/


#include <GLFW/glfw3.h> // <> 一般用来引入外部的头文件  ""一般用来在相对路径下
// 现在只是告诉有这样一些函数及符号在这个头文件（声明） 还没有链接
// 可以去 glfw3.h 里面看看它的内容 

static void DLL_()
{
	int a = glfwInit();  // 尝试调用一下，但是现在只有函数的声明，没有具体的定义
	// 会提示链接错误 
	std::cout << a << std::endl;
}

// 如果没有上面的头文件，那么无法编译，如果我们自己定义声明glfwInit函数，
// 提示混淆了错误(Name-mangling) ，因为GLFW是一个C语言库，这里用C++
// 解决方法
//  extern "C" int glfwInit();   函数声明之前记得加