#include<iostream>
#include"3_LOG.h"
#include"4_static.h"
#include"5_LocalStatic.h"
#include"6_enum.h"
#include"7_Conductor.h"

Singleton* Singleton::s_Instance = nullptr;
void virtual_f();

class Player
{
public:   // 如果不是共有变量，外界无法调用：访问控制
	int x, y;
	int speed = 2;

	void Move(int xa, int ya)  //类内部的叫做method
	{
		x += xa * speed;
		y += ya * speed;
	}
};

//int main()
//{
//	Player player; // 实例化
//	player.Move(1, -1);
//
//
//	std::cout << "\n=====================第三课======================" << std::endl;
//	log_f();  // 别忘记  static 或者 Inline的功能
//
//	std::cout << "\n=====================第四课======================" << std::endl;
//	static_class();
//
//	std::cout << "\n=====================第五课======================" << std::endl;
//	func();
//	func();
//
//	std::cout << "\n=====================第六课======================" << std::endl;
//	enumeration();
//
//	std::cout << "\n=====================第七课======================" << std::endl;
//	conductor();
//
//	std::cout << "\n=====================第十课======================" << std::endl;
//	virtual_f();
//
//
//
//
//
//
//	std::cin.get();
//}