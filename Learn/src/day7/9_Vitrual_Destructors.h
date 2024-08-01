#pragma once
/*虚析构函数
*			虚函数+析构函数
*			处理多态问题
* 
*		标记为virtual 意味着c++直到可能会有一个方法，在层次结构下的某种重写的方法
*			普通方法前面标记为virtual，那么它就可以被覆写==>虚函数表这样的设置
* 
*		虚析构函数不是覆写析构函数，而是加上一个析构函数
*			意味着这个类（函数）可能被扩展为子类，可能还有一个析构函数也需要被调用
*			
*/

class VD_Base
{
public:
	VD_Base() { std::cout << "VD_Base Constructed" << std::endl; }
	virtual ~VD_Base() { std::cout << "VD_Base Destructed" << std::endl; }
};

class VD_Drived : public VD_Base
{
public:
	VD_Drived() {std::cout << "VD_Drived Constructed" << std::endl; }
	~VD_Drived() { std::cout << "VD_Drived Destructed" << std::endl; }
};

static void Virtual_Destructors()
{
	VD_Base* base = new VD_Base();
	delete base;
	std::cout << "-----------------------\n";
	VD_Drived* drived = new VD_Drived();
	delete drived;
	std::cout << "-----------------------\n";
	VD_Base* ploy = new VD_Drived();
	delete ploy; //不用虚函数，内存泄漏，因为他的父类没有释放内存
	//因为删除的时候不知道调用的这个析构函数可能有另一个析构函数（因为没有被标记为虚函数）


}