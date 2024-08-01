#pragma once
/*字符串字面量：就是在双引号之间的字符（总是存储在只读内存中)
		所以无法修改（部分编译器可能可以)
字符串字面值是存储在程序的静态内存中的，输出时会自动解引用（在栈上)*/
#include<stdlib.h>

static void string_literal()
{
	char* name = (char*)"Hello"; //  = "Cherno"; const char name[8]  或者 const char* name 一致
	// 初始化方法如上        cosnt 承诺我们不改变数据   
	// char* name="Cherno"  错误，无法给其赋值给const char* 类型数据

	/* VS2017  char* name="Hello"；正确，但是  
			name[2]='a'； 一般来说是错误的，未定义行为，有的编译器无法使用
						因为你再用一个指针指向那个字符串字面量德内存位置（只读)
	深入解析	解决方案属性-> c/c++ ->outputfile assembly(/FAs)   界面上release
	去看看.exe的十六进制，hxd文件，当我们引用name的时候，实际上指向了一个不许编辑的常量数据块
	release模式下修改不会生效,如果确实想要修改， char name[]=...	
	 */
	

	const char name2[8] = "Che\0rno"; // 看看内存以及长度
	std::cout << name2 << strlen(name2) << std::endl;
	// 此时去看地址内存，发现 name2 和  &name2是一样的，都代表数组的地址
	// 到\0 就结束了

	const char* name3 = "Che\0rno";
	std::cout << name3 << strlen(name3) << std::endl;
	// 为什么利用 name3就能直接输出了呢？是因为自动解引用
	//本来指针name3应该是地址，但对于数组，指针名其实就已经解引用了
	// &name3 里面是地址，存储了Che，对name3里面直接就是内容  
	//&name3和name3内容不一样

	const char* a_p = u8"1字节";
	const wchar_t* a = L"aaa";  // 长度由编译器决定
	const char16_t* b = u"bbb";
	const char32_t* c = U"ccc";

	using namespace std::string_literals;
	std::u32string name0 = U"Cherno"s + U",Hello!";
	//其他字符串组合方法   std::string()+   

	const char* example = R"(line1
line2
line3)";  // 利用R避免了转义字符

	std::cout << std::cin.get();

	
}