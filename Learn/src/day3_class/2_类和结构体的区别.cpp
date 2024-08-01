/*类和结构体基本没有区别，主要是访问控制
类的内部变量一般是私有的

结构体是共有的

主要是为了兼容性，因为C语言中只有结构体

#define struct class

什么时候用，主要就是基于数据的开放性，你想用私有的还是公开的数据

继承的问题：
*/

#include<iostream>

struct Player
{
private:   // 如果不是共有变量，外界无法调用：访问控制
	int x, y;
	int speed = 2;

	void Move(int xa, int ya)  //类内部的叫做method
	{
		x += xa * speed;
		y += ya * speed;
	}
};
void test()
{
	Player player; // 实例化
	//player.Move(1, -1); //报错了，因为x和y私有了
}