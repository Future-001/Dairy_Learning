#pragma once
/*两种用处：
	类中修改const方法下的内容
	lambda表达式中用大
	*/
static void day4_8_mutable()
{
	int x = 6;
	auto f = [=]()  // 简而言之就是将某个函数赋给某个变量  [=/&....] 
		//如果在 auto f=[]() mutable 则可直接用x++
	{
			int y = x; // 如果要进行x++只能如此 
			y++;
			std::cout << x << std::endl;
	};
	f();//再看x还是6因为没有用& 这只是一个简单的值传递
}