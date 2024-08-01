#pragma once
/* 标准模板库
	std::vector 其实就是一个动态数组，
			存储时先分配一定内存，如果存储不够，那么重新分配一个删除旧的


*/
#include<vector>

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << "," << vertex.y << "," << vertex.z;
	return stream;
}

static void Dynamic_Array()
{
	Vertex* vertexcases = new Vertex[5];// 分配了五个静态数组
	// 但是一旦超过呢？ Vertex[6]怎么操作？重新调整内存？？

	std::vector<Vertex> vertexs; // 动态分配
	std::vector<Vertex*> verts; // 到底存储什么合适呢？内存上一条直线？还是碎片？
	/*存储的是对象，调整vector大小的时候，就需要重新分配和复制所有东西
			尽量用对象
	存储的是指针，那么指针指向的内容是不变的，实际内存不变，调整大小的时候，只是增加了指针
	*/

	// 添加东西到对象内
	vertexs.push_back({1,2,3});
	vertexs.push_back({4,5,6});

	for (int i = 0; i < vertexs.size(); i++)
		std::cout << vertexs[i] << std::endl;

	//for (Vertex v : vertexs)// 这样写实际上是将每个vertex复制到for循环中，避免复制
	for (const Vertex& v : vertexs)
		std::cout << v << std::endl;

	vertexs.erase(vertexs.begin() + 1);  // 这里的参数需要的是一个Iterator迭代器
	vertexs.clear();
}