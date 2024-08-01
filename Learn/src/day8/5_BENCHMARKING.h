#pragma once
/*基准测试
*		测试代码的速度
*/

#include<memory>
#include<chrono>

#include<array>

class BenchMarkering_Timer //定时器，计算一下运算的时间
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
public:
	BenchMarkering_Timer() { m_StartTimepoint = std::chrono::high_resolution_clock::now(); }

	~BenchMarkering_Timer() 
	{
		Stop(); //RAII Resource Acquisition is Initialization
	}
	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << ms << "ms(" << duration << "us)" << std::endl;
	}
};

inline void BenchMarking_Func()
{
	struct Vector2
	{
		float x, y;
	};

	// 1,2判断使用指针会不会有开销，也要注意release模式下，少了很多检查，所以Make Shared 更快
	std::cout << "Make Shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		BenchMarkering_Timer Timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_shared<Vector2>();
	}

	std::cout << "Make New Shared\n";
	{
		std::array<std::shared_ptr<Vector2>, 1000> sharedPtrs;
		BenchMarkering_Timer Timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::shared_ptr<Vector2>(new Vector2());
	}

	std::cout << "Make Unique\n";
	{
		std::array<std::unique_ptr<Vector2>, 1000> sharedPtrs;
		BenchMarkering_Timer Timer;
		for (int i = 0; i < sharedPtrs.size(); i++)
			sharedPtrs[i] = std::make_unique<Vector2>();
	}

	// __debugbreak(); 
}