#pragma once
/*可视化基准测试
*		基准测试（计时器例子）
*/

#include<chrono>

class VS_BENCHMARKING
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
	bool m_Stopped;
	const char* m_Name;
public:
	VS_BENCHMARKING(const char* name)
		:m_Name(name), m_Stopped(false)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}
	~VS_BENCHMARKING()
	{
		Stop();
	}
	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimepoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::milliseconds>(m_StartTimepoint).time_since_epoch().count();
	
		std::cout << m_Name << ": " << (end - start) << "ms\n";

		m_Stopped = true;
	}
};

static void test_Func3()
{
	VS_BENCHMARKING("test_Func3");
	for (int i = 0; i < 1000; i++)
		std::cout << "Hello World #" << i << std::endl;
}

static void test_Func4()
{
	VS_BENCHMARKING("test_Func4");
	for (int i = 0; i < 1000; i++)
		std::cout << "Hello World #" << i << std::endl;
}

static void VS_BENCHMARKING_Main()
{
	test_Func3();

	test_Func4();
}