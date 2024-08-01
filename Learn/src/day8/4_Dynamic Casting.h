#pragma once
/*dynamic_cast
*		做了额外的工作，确保进行的类型转化时有效的类型转换
*				存储了运行时类型信息RTTI(项目属性下可以关闭)，所以可以知道原来的数据是什么类型
*				还有dynamic_cast也会增加开销
*		专门用于沿继承层次结构进行的强制类型转换  多态（虚函数）
*		可以用来验证某个类型是否为某类型
*/

class Dynamic_Cast_Entity
{
public:virtual void PrintName() {}; // dynamic_cast 一定是用于多态的
};
class  Dynamic_Cast_Player :public  Dynamic_Cast_Entity {};
class  Dynamic_Cast_Enemy :public  Dynamic_Cast_Entity {};

inline void  Dynamic_Cast_Func()
{
	Dynamic_Cast_Player* player = new  Dynamic_Cast_Player();
	Dynamic_Cast_Entity* actuallyEnemy = new  Dynamic_Cast_Enemy();

	Dynamic_Cast_Entity* actuallyplayer = player;  // 这里不能直接转为 Dynamic_Cast_Player了
	// 因为这个父类下面有两个子类，你不确定是哪一个子类，转换错了，可能程序崩溃

	Dynamic_Cast_Player* p0 = dynamic_cast<Dynamic_Cast_Player*>(actuallyEnemy);
	Dynamic_Cast_Player* p1 = dynamic_cast<Dynamic_Cast_Player*>(actuallyplayer);

}