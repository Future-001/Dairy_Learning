#pragma once
/*联合体，共用体
*		类似于结构体，不过一次只能占用一个成员的内存
*		联合体共用体的内存是一样的，公用的
* 通常是匿名使用的，但是匿名的union不能含有成员函数
*/

struct union_Vector2
{
	float x, y;
};

struct union_Vector4  
{
	float x, y, z, w; // 是不是可以将其看作是两个union_Vector2呢？
	// 这样的话一次需要返回两个元素
	union_Vector2& GetA()  // 利用A代表第一部分
	{
		return *(union_Vector2*)&x;  //这里就是类型双关的运用
		//这里看数据的大小
	}
};

struct union_Vector4_2//
{
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			union_Vector2 a, b; // 因为结构体是共用内存的，所以这里就会发现，a和x,y内存
			// b和 z,w内存一致
			/*为甚恶魔a,b没有共用一个内存，因为从外面来看，struct在union当中，所以其大小是16字节*/
		};
	};
};

static void union_Print(const union_Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

static void union_Func()
{
	struct Union
	{
		//匿名union
		union
		{
			float a;
			int b;
		};
	};

	Union u;
	u.a = 2.0f;
	std::cout << u.a << ", " << u.b << std::endl; // 后面的b用来存储整型，想想类型双冠怎么存储的


	union_Vector4_2 vector = { 1.0f,2.0f,3.0f,4.0f };
	union_Print(vector.a);
	union_Print(vector.b);

	vector.z = 500.f;
	std::cout << "=====================\n联合体的内存大小" <<sizeof(vector)<< "\n=====================" << std::endl;
	union_Print(vector.a);
	union_Print(vector.b);
	
}
