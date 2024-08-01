#pragma once
// pure virtual function
/*					讲到了纯虚数
虚函数的功能：提供了某个方法，然后其他子类也能实现相同方法的其他功能
纯虚函数：主要意思是基类提供某个模板，然后再子类中去实现不同的功能

			只包含未实现的方法（直接空着），并将其作为一个模板的类
			由于此接口类不包含实现方法，所以无法实例化这种类
*/


#include<iostream>
#include<string>

//class day4_Entity
//{
//public:
//	virtual std::string GetName() = 0;  // 前面的方法叫做虚函数，后面加上=0成了纯虚函数，
//	// 如果要实例化这个类，那么这个方法必须在子类中实现
//};
//class day4_Player :public day4_Entity
//{
//private :
//	std::string m_Name;
//public:
//	day4_Player(const std::string& name)
//		:m_Name(name) {};
//
//	std::string GetName() override { return m_Name; }
//};
//
//static void day4_PrintName(day4_Entity* entity)
//{
//	std::cout << entity->GetName() << std::endl;
//}
//
//static void interface_pure_virtual()
//{
//	// day4_Entity* e = new day4_Entity();  此时报错，提示已经是一个纯虚函数，无法实例化
//	day4_Player* d4_p = new day4_Player("张三");
//	day4_PrintName(d4_p);
//}


//============================更好的例子===========================

class day4_ClassName
{
public:
	virtual std::string GetClassName() = 0;// 前面的方法叫做虚函数，后面加上=0成了纯虚函数，
	// 如果要实例化这个类，那么这个方法必须在子类中实现
};

class day4_Entity:public day4_ClassName
{
public:
	virtual std::string GetName() {return "day4_Entity";}
	std::string GetClassName() override { return "day4_Entity"; }
};

class day4_Player :public day4_Entity
{
private:
	std::string m_Name;
public:
	day4_Player(const std::string& name)
		:m_Name(name) {};

	std::string GetName() override { return m_Name; }
	std::string GetClassName() override { return "day4_Player"; }
	// 如果没有再play中提供这个函数，那么他会去找entity中的这个方法。
};

static void day4_PrintClassName(day4_ClassName* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}


static void interface_pure_virtual()
{
	// day4_Entity* e = new day4_Entity();  此时报错，提示已经是一个纯虚函数，无法实例化
	day4_Player* d4_p = new day4_Player("张三");
	day4_PrintClassName(d4_p);

	day4_Entity* d4_e = new day4_Entity();
	day4_PrintClassName(d4_e);

	day4_PrintClassName(new day4_Entity()); // 最好不要这么写，可能造成内存泄漏
}