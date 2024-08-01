#pragma once
/*箭头运算符
	（*ptr).方法
	ptr->方法
	
	
	
	*/
struct Vector3
{
	float x, y, z;
};

class Arrow_Operator
{
public:
	int x;
	
	void Print() const { std::cout << "Hello!" << std::endl; }
};
class ScopedPtr_Arrow
{
private:
	Arrow_Operator* m_Obj;
public:
	ScopedPtr_Arrow(Arrow_Operator* obj)
		:m_Obj(obj) {}
	~ScopedPtr_Arrow() { delete m_Obj; }

	// 不加入这个的话不能用 . 调用这个歌方法
	Arrow_Operator* GetOjbect() { return m_Obj; }

	//定义一下 -> 方法
	Arrow_Operator* operator->() { return m_Obj; }
};

static void Arrow()
{
	int offset = (int)&((Vector3*)0)->x;
	int offset2 = (int)&((Vector3*)nullptr)->z;
	std::cout << "x offset is"<<offset <<"; y offset is"<< offset2 << std::endl;


	//======================
	ScopedPtr_Arrow entity = new Arrow_Operator;
	entity.GetOjbect()->Print();

	entity->Print();
}