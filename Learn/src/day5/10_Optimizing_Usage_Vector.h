#pragma once
/*优化使用 Vector
	使用push_back时，如果内存用完，那么将会重新调整大小，重新分配

*/
#include<vector>
struct Optm_Vectex
{
	float x, y, z;

	Optm_Vectex(float x, float y, float z)
		:x(x),y(y),z(z){}

	Optm_Vectex(const Optm_Vectex& other)
	{
		memcpy(this, &other,sizeof(Optm_Vectex)); // 浅拷贝
		std::cout << "Copy!" << std::endl;
	}
};

static void optm_vector()
{
	std::vector<Optm_Vectex> vertexs;
	vertexs.push_back({ 1,2,3 });
	vertexs.push_back(Optm_Vectex(4,5,6));
	vertexs.push_back(Optm_Vectex(7,8,9));
	// 为什么会出现6个Copy!?
	//打断点看：每一次创建一个vectex对象，都是在main栈上创建它，再复制到vector中
	// 第二次创建也是全部复制再创建，此处vector的内存调整了两次1-2-3
	//将其放到vector中，优化策略1：我们选择合适的内存，将创建的对象放到实际的vector中
	// 放在vector分配的内存中

	std::vector<Optm_Vectex> vertexs2;//vertexs2(3) ; 没有这种定义
	vertexs2.reserve(3);
	std::cout << "优化策略1" << std::endl;
	vertexs2.push_back({ 1,2,3 });
	vertexs2.push_back(Optm_Vectex(4, 5, 6));
	vertexs2.push_back(Optm_Vectex(7, 8, 9));
	// 这样就只有了3个copy了
	

	std::cout << "优化策略2" << std::endl;
	std::vector<Optm_Vectex> vertexs3;
	vertexs3.reserve(3);
	// 不先再main创建，直接再实际的vector中创建
	vertexs3.emplace_back(1,2,3);
	vertexs3.emplace_back(4, 5, 6);
	vertexs3.emplace_back(7, 8, 9);
}