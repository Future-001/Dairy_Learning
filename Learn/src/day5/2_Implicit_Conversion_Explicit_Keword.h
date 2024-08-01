#pragma once
/*隐式构造函数&&转换&&explicit关键字


class Entity
{
private:
	std::string m_Name; int score;
public:
	Entity { m_Name = "Unkonwn"; } 
	Entity
		:m_Name("Uknown"),score(-1); 
	Entity(int x)
		{score=x}
}
const std::string& GetName() const { return m_Name; }
};

隐式构造函数：
	以之前的Entity为例，进行实例化时，
	Entity e="Cherno"  ==  Entity e('Cherno")  == Entity e=Entity("Cherno") 
			这些都是显示转换，不是隐式

void Print(const Entity& entity)
{}

隐式转换：
	Entity e=22;Entity e="Cherno";
	在主函数中利用Print(22) 就会创建一个entity,
		实际上实例化了，c++ 认为可以实例化出一个对象，因为entity初始化需要一个整数
	Print(std::string("Cherno") 
		Cherno是 const cahr 类型，但是我们要用到std::string 类型的名字，
		在上面的例子中，类型就被转换了。


explicit：
	如果想用一个字符串构造一个Entity对象，那么就必须显式的调用这个构造函数
	explicit会禁用隐式转换，explicit放在构造函数前面（即初始化函数之前作为关键字）
	这样的话只能显式转换
	Print(Entity("Cherno")); Entity e="Cherno"  ==  Entity e('Cherno")  == Entity e=Entity("Cherno") 

*/