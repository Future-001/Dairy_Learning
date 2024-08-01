#pragma once
/*This 是指向这个函数所属的当前对象实例的指针


*/
class day5_4;
static void day5_4_Print(day5_4* entity);
//2：如果采用   static void day5_4_Print(cosnt day5_4& e) ;

class day5_4
{
public:
	int x, y;

	day5_4(int x, int y)
	{
		//day5_4* entity = this;  // tihs 关键字就相当于这样

		// VS2017之前这样写的this是 类型* cosnt 类型的指针 但是后一个const 不允许改变指针得指向
		// day5_4*& cosnt eneity=this ; 也是错的，不允许更改；
		//day5_4* const & entity=this;  // 才是正确的格式

		this->x = x;
		this->y = y;

		day5_4_Print(this);
		// 如果是对一个常量进行引用
		//如果上面采用了2，那么day5_4_Print(*this) ; 解引用 类似于 day5_4& entity=*this;

		//delete this 小心，正在从成员函数释放内存
	}
	int Get() const
	{
		const day5_4& entity = *this; // const 中对常量进行解引用
	}
};

static void day5_4_Print(day5_4* e)
{
	//Print
};

