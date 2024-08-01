#pragma once
/*计时模块
*		chrono api模块 计算代码的运行时间  99%
*		自带库
* 
*		endl 与 \n的区别
*/

#include<chrono>
#include<thread>

static void Timing_Func()
{
	using namespace std::literals::chrono_literals;// 利用 sleep_for

	auto start = std::chrono::high_resolution_clock::now(); // 看看他的返回值类型

	std::chrono::steady_clock::time_point starttype=std::chrono::high_resolution_clock::now(); 
	// 看看他的返回值类型,最前面的是返回值的类型

	std::this_thread::sleep_for(1s);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float> duration = end - start;

     // 直接cout 出错了
	std::cout << duration.count() << "s" << std::endl;
}


//==============================
// 使用结构体或者类来计算

struct Timer_S
{
	std::chrono::steady_clock::time_point start, end;
	std::chrono::duration<float> duration;

	Timer_S()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer_S()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		//速度太快了，转换毫秒看看
		float ms = duration.count() * 1000.0f;
		std::cout << "Timer took " << ms << "ms " << std::endl;
		//看一下这俩时间的区别感受一下
		// std::cout << "Timer took " << ms << "ms\n";
	}
};
static void Loop_func()
{
	Timer_S Timer;
	for (int i = 0; i < 10; i++)
		std::cout << "Hello!" << std::endl;
}

static void Struct_Timer()
{
	Loop_func();
}