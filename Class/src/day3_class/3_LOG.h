#pragma once
#include<iostream>
/*  怎么用类： 依据你要实现的功能来写类
日志级别：error warning message(trace) */


class Log 
{
public: // static variable  和 variable
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
private:
	int m_LogLevel = LogLevelInfo;
public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	};

	void Error(const char* message)
	{
		if (m_LogLevel >= LogLevelError)
			std::cout << "[Error]:" << message << std::endl;
	}
	void warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[Warning]:" << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[Info]:" << message << std::endl;
	}
};

static void log_f()  // 不用static 或者 inline 就会出现错误，显示引用了很多次
{
	Log log;
	log.SetLevel(log.LogLevelWarning);
	log.warn("Hello!");
	log.Error("Hello!");
	log.Info("Hello!");
}


