#pragma once
/*预编译头文件
*			抓取头文件，并将其转换为编译器可以使用的格式
* 
*			不要经常改变头文件，不然每次都得从头编译头文件
* 依赖：
*		有的头文件可能需要一定的依赖才能使用，在处理预编译头文件是要注意是不是包含了所有的依赖项
*		想想之前的依赖福分。
*/
inline void PreCompiled_Func()
{

}

/*
*		---Main.cpp
*				#include"pch.h"
*				int main() {std:::cout<<"Hello World" <<std::endl;}
*		----pch.cpp
*				#include"pch.h"
*		----pch.h
*				#include<iostream>
*				#include<algorithm>
*				#include<functional>
*				#include<memory>
*				#include<thread>
*				#include<utility>
* 
*				#include<string>
*				#include<stack>
*				#include<deque>
*				#include<vector>
*				#include<set>
*				#include<map>
*				#include<unordered_set>
*				#include<unordered_map>
* 
*				#include<windows.h>
*		
*/

/*
*		-> 项目属性 -->  C/C++  -->    Preprocessor (Preprocess to a file ->Yes)   （记得关闭）
*			得到约37万行代码，main中的预编译头文件版汉晋实际的cpp中，在每个cpp中，每次运行都要
*				检查和处理37w行源代码--> 通过预编译来减少这个时间
* 
*		VS中：
*			有一个头文件，应该创建一个包含头文件的cpp文件， ---> pch.cpp文件的属性
*				--> C/C++ --> (Precompiled Header( Precompiled Header --> Create)
*				--> 项目属性 --> C/C++ -->  Precompiled Heade( Precompiled Header --> Use
								Precompiled Header File --> pch.h		)
			对比一下二者时间：tools 的选项里面再VC++设置李打开build time，禁用pch.h


		g++ 中
				time g++ -std=c++11 Main.cpp  // 没有预编译时的时间

				//先编译头文件
				g++ -std=c++11 pch.h   // pch.h.gch  114M
				time g++ -std=c++11 Main.cpp

		第一次会首次编译头文件，所以可以适当修改main中的代码，看稳定下来之后的运算时间

*/