#pragma once
/* 实例化对象
	1.内存来自哪里，对象实际上就会创建在哪里
	2.堆上和栈上，优先栈上

堆上还是栈上创建对象；
	栈比较小，一般来说取决于编译器，1~2M,作用域结束的话，栈上空间释放
	不要一直占用栈，
	但是也要注意释放堆内存，不然容易造成内存泄漏

static void S_1()
{
	Entity* e
	{
	Entity entity("Cherno");
	e=&entity;
	std::cout<<e.GetName()<<std::endl;
	} // 运行结束，Cherno就终结了，因为作用域结束了，

	// 如果将上面的初始化改一下：
		Entity* e
	{
	Entity* entity=new Entity("Cherno")  // 这就是在堆上初始化对象，需要调用delete 删除
	e=entity;
	std::cout<<e.GetName()<<std::endl;
	}
*/