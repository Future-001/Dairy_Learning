#pragma once
/*  //  ERROR 3
void Log(const char* message)
{
	std::cout << message << std::endl;
}
*/

//  -----------解决方法----------------
static void Log(const char* message)
//inline void Log(const char* message)
{
	std::cout << message << std::endl;
}

