#pragma once
/*New关键词 返回一个指向那个地址的指针
	找到一个满足我们内存需求的最大内存块（空闲列表管理空闲内存）
	调用了构造函数
	实际上调用了C底层的malloc 函数

	Entity* e = new Entity();  
		==>  Entity* e = (Entity*)malloc(sizeof(Entity)); 但是没有调用初始化函数
	have to remembe delete 如果用了 New [] delete 也加上
		C中的是 free(e)

	placement new 只是决定了你的内存来自哪里，实际上没有调用内存，
				只是在特定地址上进行了初始化
*/
