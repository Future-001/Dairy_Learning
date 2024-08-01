#pragma once
/*线程
*		
*/
#include<thread>

static bool s_Finished = false;
static void Dowork()
{
	using namespace std::literals::chrono_literals;  // 为了使用 this_thread::sleep_for

	std::cout << "This Thread id=" << std::this_thread::get_id() << std::endl;
	while (!s_Finished)
	{
		std::cout << "Working...\n" << std::endl;
		std::this_thread::sleep_for(1s);
	}
}
static void Thread_Func()
{
	std::thread work(Dowork); 

	std::cin.get();
	s_Finished = true;

	work.join() ; // 其实就是等待上面的线程结束在进入主线程

	std::cout << "This Thread id=" << std::this_thread::get_id() << std::endl;
}

