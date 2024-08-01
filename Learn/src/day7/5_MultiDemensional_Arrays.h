#pragma once
/*多维数组
*		数组的集合，数组的数组的数组的数组(四维数组)
*		内存块，存储一堆指向数组的指针
*		
*利用指针处理数组
*		指针指向数组在内存中的起始位置
*			一个指针的数组，最后得到一个内存块，里面是连续的指针，每个指针都指向内存中的某个数组
*/

static void MultiDemensionalArray()
{
	// 数组背后的逻辑

	int* array1d = new int[50];

	int** array2d = new int* [50]; // int* 存储的是一个指针对象的缓冲区
	//指向整型指针的指针
	for (int i = 0; i < 50; i++)
		array2d[i] = new int[50];

	int*** array3d = new int** [50]; // 只是在进行内存分配
	for (int i = 0; i < 50; i++)
	{
		array3d[i] = new int* [50];
		for (int j = 0; j < 50; j++)
		{
			int** ptr = array3d[i];
			ptr[j] = new int[50];
			//等价于   array[i][j]=new int[50] 
		}	
	}

	delete[] array1d;
	  // 没有这样的操作符   delete[][] array2d; 只有 delete[]
	for (int i = 0; i < 50; i++) 
	{
		delete[] array2d[i]; 
		/*不用for循环，直接delete[] array2d，释放的只是200个字节的内存，释放了保存整型
		数组指针的数组的内存；但是这个二维数组总共是 200 + 50 *200 ，所以会造成内存泄漏*/

		for (int j = 0; j < 50; j++)
			delete[] array3d[i][j];
	//
	}
	for (int i = 0; i < 50; i++) delete[] array3d[i];
	delete[] array2d;
	delete[] array3d;

	//====================上述分配可能会造成内存碎片 
	/* 二维数组为例：
		遍历了50个数之后，跳到的其他维度；必须跳转到内存的另一个位置来读写数据
		可能会导致 cache miss 内存不命中，需要浪费时间从ram中获取数据
		如果内存是连在一起分配的，可能没有cache miss

		优化方法：
			我们是否可以采用一维数组的方法，尽量避免cache miss，加快运算的速度
	*/
	int* array = new int[5 * 5];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			array[i + j * 5] = 2;
	delete[] array;
}