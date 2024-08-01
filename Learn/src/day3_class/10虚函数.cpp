/*
虚函数功能：
			在子类中重写方法，例如A,B类，B是A的子类，那么如果在A中将一个方法标记为虚函数，
				那么也可以在B类中重写这个方法，实现其他的功能
虚函数缺点：
	运行时间：  额外内存存储虚表，这样可以分配到正确的函数
				基类中还有一个指针成员指向虚表
				
				每次调用虚函数的时候，必须遍历虚表去找到最终要运行的函数

正确使用虚类的方法
		父类（基类）的方法中加入virtual 
		子类的方法后加入 override   
*/
#include<string>
#include<iostream>
class Entity10
{
public:
	std::string GetName() { return "Entity"; }
	//virtual std::string GetName() { return "Entity"; }
};
class Player10 :public Entity10
{
private:
	std::string m_Name;
public:
	Player10(const std::string& name)
		:m_Name(name) {}

	std::string GetName() { return m_Name; }
	//std::string GetName() override { return m_Name; }
};

void PrintName(Entity10* entity)
{
	std::cout << entity->GetName() << std::endl;
}
void virtual_f()
{
	Entity10* e = new Entity10();
	std::cout << e->GetName() << std::endl;
	
	Player10* p = new Player10("Cherno");
	// std::cout<<p->GetName()<<std::endl;
	PrintName(p);  // 这样的话他连cherno都不输出了
	
	Entity10* entity = p;   // 明明p指针是Player的为什么输出 entity？ 
	// 这是因为我们在类中正常声明函数或者方法，当调用这个方法时，我们总是先去调用这个类中的这个方法
	// 简而言之，这里的entity的类型时 Entity10，所以调用的方法就是entity中的
	// 如果我们需要让函数意识到，我们要调用的方法是另一个类的方法，那么我们就用到了虚函数
	std::cout << entity->GetName() << std::endl;
}


