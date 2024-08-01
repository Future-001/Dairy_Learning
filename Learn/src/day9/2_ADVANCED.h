#pragma once
/*可视化基准测试
*		基准测试（计时器例子）
*		
//=====================可视化测试
	chrome://tracing/
*			加载一个包含所有数据的json文件

*/

#include<chrono>
#include<algorithm>
#include<fstream>

#include<cmath>
#include<thread> 

struct ProfileResult
{
	std::string Name;
	long long Start, End;
	uint32_t ThreadID;
};

struct InstrumentationSession
{
	std::string Name;
};

class Instrumentor   //格式化一个json文件
{
private:
	InstrumentationSession* m_CurrentSession;
	std::ofstream m_OutputStream;
	int m_ProfileCount;
public:
	Instrumentor()
		:m_CurrentSession(nullptr), m_ProfileCount(0)
	{
	}

	//打开文件
	void BeginSession(const std::string& name, const std::string& filepath = "src/day9/results.json")
	{
		m_OutputStream.open(filepath);
		WriteHeader(); //写文件头，即json文件的开头，chrome tarcing需要的特定格式
		m_CurrentSession = new InstrumentationSession{ name };
	}

	//写一个简单的页脚，关闭文件等
	void EndSession()
	{
		WriteFooter();
		m_OutputStream.close();
		delete m_CurrentSession;
		m_CurrentSession = nullptr;
		m_ProfileCount = 0;
	}

	//核心：用于写时间分析数据
	void WriteProfile(const ProfileResult& result)
	{
		if (m_ProfileCount++ > 0)
			m_OutputStream << ",";

		std::string name = result.Name;
		std::replace(name.begin(), name.end(), '"', '\'');

		m_OutputStream << "{";
		m_OutputStream << "\"cat\":\"function\",";
		m_OutputStream << "\"dur\":" << (result.End - result.Start) << ',';
		m_OutputStream << "\"name\":\"" << name << "\",";
		m_OutputStream << "\"ph\":\"X\",";
		m_OutputStream << "\"pid\":0,";
		m_OutputStream << "\"tid\":" << result.ThreadID<<",";
		m_OutputStream << "\"ts\":" << result.Start;
		m_OutputStream << "}";

		m_OutputStream.flush();
	}

	void WriteHeader()
	{
		m_OutputStream << "{\"otherData\": {},\"traceEvents\":[";
		m_OutputStream.flush();
	}

	void WriteFooter()
	{
		m_OutputStream << "]}";
		m_OutputStream.flush();
	}

	static Instrumentor& Get()
	{
		static Instrumentor* instance = new Instrumentor();
		return *instance;
	}
};
class Instrumentation_VS_BENCHMARKING
{
private:
	std::chrono::time_point<std::chrono::steady_clock> m_StartTimepoint;
	bool m_Stopped;
	const char* m_Name;
public:
	Instrumentation_VS_BENCHMARKING(const char* name)
		:m_Name(name), m_Stopped(false)
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}
	~Instrumentation_VS_BENCHMARKING()
	{
		if(!m_Stopped)
			Stop();
	}
	void Stop()
	{
		auto endTimepoint = std::chrono::high_resolution_clock::now();

		long long start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();
	
		uint32_t threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());
		//

		//std::cout << m_Name << ": " << (end - start) << "ms\n";
		Instrumentor::Get().WriteProfile({ m_Name,start,end,threadID});

		m_Stopped = true;
	}
};


#define PROFILING 1
#if PROFILING	
// 增加关闭计时器的代码
#define PROFILE_SCOPE(name) Instrumentation_VS_BENCHMARKING timer##__LINE__(name);
//这里是用来包装Instrumentation_VS_BENCHMARKING timer 这样就可以为变量去一个唯一的名字
//   __LINE__将timer和行号拼接起来

//能否自动获取函数的名称，不用每次都输入
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__) //如果有重载函数，那么名称会重复的
								// __FUNCSIG__  这是带参数的
#else
#define PROFILE_SCOPE(name)
#endif


namespace Timer_Analysis_Benchmark {  //如果再加入一个时间分析呢，可以得到所有的信息
	//尝试加上和去掉的区别
	static void test_Func1()
	{
		PROFILE_FUNCTION();
		for (int i = 0; i < 1000; i++)
			std::cout << "Hello World #" << i << std::endl;
	}

	static void test_Func2()
	{
		PROFILE_FUNCTION();
		for (int i = 0; i < 1000; i++)
			std::cout << "Hello World #" << i << std::endl;
	}

	static void RunBenchmarks()
	{
		PROFILE_FUNCTION();

		std::cout << "Running Benchmarks...\n";
		std::thread a([]() {test_Func1(); });
		std::thread b([]() {test_Func2(); });

		a.join();
		b.join();
	}
}

static void VS_BENCHMARKING_ADVANCED_Main()
{
	Instrumentor::Get().BeginSession("Profile");
	Timer_Analysis_Benchmark::RunBenchmarks();
	Instrumentor::Get().EndSession();
}

