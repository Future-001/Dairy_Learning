//#pragma once

#ifndef _LOG_H
#define _LOG_H

void Log(const char* message);

void debug()
{
	int a = 5;
	const char* c = "Hello";
	for (int i = 0; i < 5; i++)
	{
		std::cout << c[i] << std::endl;
	}
	bool compareresult = a == 5;
	if (compareresult)
	{
		std::cout << "Good,This is a good news" << " a==5 " << std::endl;
	}
	else
	{
		std::cout << "error!" << std::endl;
	}
}
#endif