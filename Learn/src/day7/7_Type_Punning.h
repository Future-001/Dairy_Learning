#pragma once
/*类型双关
*		用来绕过类型系统（c++是强类型系统）
*		例如：一段内存，用来存储整型数据，但现在将该内存当作double，或者class类型，可以轻易绕过系统类型
* 
*		例如，一个类，我们想要把它写成一个字节流，假设他是一个基本类型的结构，并且没有
*				指向内存中其他地方的指针，那么我们就可以重新解释整个结构或者类等,
*				将它作为一个字节数组，然后将它写出来或者流出来（字节流），不关心里面的类型
*				只要直到大小，然后对其进行操作
*/

static void Type_Punning_Func()
{
	int a = 50;
	double value1 = a;// 隐式转换，去看看a value1的内存 后面的 49 40是某种转换的结果

	double value2 = *(double*)&a;  // a的地址(int *)指针，转换为double* 在解引用
	// 再去看看value2内存中的内存，
	// 实际上是  a 地址中的内容将其定位为double类型，但是该类型大小是8个字节，
	//所以利用a地址后面的四个字节补充上了；读取了不属于自己的内存，不安全

	/*如果不想拷贝新的变量，只想要引用，剂的使用 & */
	std::cout << "value1: " << value1 << "\nvalue2: " << value2 << std::endl;
}



//========================


struct Entity
{
	int x, y;
}; // 空结构体至少一个字节存储寻址，非空那他的大小就是数据大小，这里是8字节

static void Type_Punning_Func2()
{
	Entity e = { 5,8 };
	
	int* position = (int*)&e;
	std::cout << position[0] << ", " << position[1] << std::endl;

	int y = *(int*)((char*)&e + 4);
	std::cout << y << std::endl;
}