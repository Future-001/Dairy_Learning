#pragma once
/*宏定义
	
*/
#define WAIT std::cin.get()

/* \ 后面不要加空格否则就是堆空格的转义*/
#define Main void main_example() \
{\
	std::cin.get();\
}

// 常用来干什么呢，写开发日志

#if 0   // 禁用了
#deine Nine 9
#endif

/*场景如下：开发时debug模式，就要输出日志，在项目属性中更改C/C++预编译器，
加入PR_DEBUG; release模式下PR_RELEASE，那么这样的话切换回来运行模式之后，
给用户的版本就不会输出日志了*/
#define PR_DEBUG 0
#if PR_DEBUG==1   // 比#ifdef PR_DEBUG 好，不然有时候稍微修改一点会变化很多
#define PR_DEBUG LOG(X)
#else 
#define PR_DEBUG
#endif
