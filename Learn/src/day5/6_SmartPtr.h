#pragma once
/*智能指针
	上一个视频的 unique_ptr
	功能：调用new分配内存时，不用再单独调用delete释放内存
		只能指针会在作用域结束时自动释放内存

	unique_ptr:
		不要copy，否则两个指向了同一块内存，释放时被直接释放了
		查看上一个视频取理解深入的原理

	shared_ptr:
		工作方式：通过引用计数，跟踪你的指针有多少引用的方法，如果为0 那就删除指针
		创建一个shared_ptr,copy它创建另一个shared_ptr,引用计数为2

		在 make_unique时候，不利用new是因为这个方法的异常安全性；
		shared_ptr中，会额外分配一块控制块的内存，存储引用计数
					如果new Entity,在把他传递给shared_ptr的构造函数，会有两次内存分配
					利用 make_shared会将两部分结合起来，效率更高

		weak_ptr
			make_shared 复制会增加引用次数，但是weak_ptr不会增加引用次数
	
unique_ptr开销最低
		但是如果需要在对象之间共享，不能用unique_ptr
		使用shared_ptr,主要是复制时的问题
		*/

#include<memory>

class day5_6
{
public:
	day5_6()
	{
		std::cout << "Created Entity!" << std::endl;
	}
	~day5_6()
	{
		std::cout << "Destory Entity!" << std::endl;
	}
	void Print() {};
};

static void Smart_Ptr()
{
	{ 
		std::unique_ptr<day5_6> entity(new day5_6());  // 不能用 entity = nwe day5_6()  explicit显式调用
		std::unique_ptr<day5_6> entity2 = std::make_unique<day5_6>();
	//方2基于异常更安全
		entity->Print();

	}

	{
		std::shared_ptr<day5_6> e0;
		{
			std::shared_ptr<day5_6> shared_entity = std::make_shared<day5_6>();
			e0 = shared_entity;
		}
	}

	{
		std::weak_ptr<day5_6> e0;
		{
			std::shared_ptr<day5_6> shared_entity = std::make_shared<day5_6>();
			e0 = shared_entity;
		}
	}
	
}