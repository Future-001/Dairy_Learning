#pragma once
/*如何让C++运行的更快
* https://www.youtube.com/watch?v=5HWCsmE9DrE&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=79
* https://www.bilibili.com/video/BV1UR4y1j7YL/?spm_id_from=333.788&vd_source=88650c8acf756d4c8b3d97b06eee3587
*		多线程提升性能   std::asnyc future头文件中
*		std::async(job类型，实际异步运行的函数，函数参数)  //返回值类型是std::future
*		异步运行是涉及到一个互斥锁的问题，你不可能几个线程同时修改某个文件
*			肯定是某几个时候某个线程拥有堆该文件的所有权，处理结束后释放该权限
*		static std::mutex s_MeshesMutes;  
*		std::lock_guard<std::mutex> lock<s_MeshesMutes>; //结果该锁
* 
* 
*		for(const auto& file: meshFilepaths)
*			m_Meshes.push_back(Mesh::Load(file));
*		每次进行相同的任务，都是加载网格，在同一个线程上面进行相同的任务19次，速度慢
*		利用并行for循环可以减少操作(C#中)
* 
*		for(const auto& file: meshFilepaths)
*			std::async(std::launch::async,LoadMesh,m_Meshes,file);  
*			//启动类型async ，如果是deferred等，那么可能不会再一个单独的线程上完成，会根据工作负载选择
*			//返回值类型std::future，如果不保留，将被摧毁
					（此时应确保async实际上已经完成，但是这意味着他不是并行的,因为在结束一次for
					  循环后，这个函数实际上将在std::future的析构函数中，等待LoadMesh任务完成)
					所以，头文件中我们创建一个std::vector<std::future<void>> m_Futures;利用future来存储成员变量
								void 是那个函数的返回值类型
			m_Futures.push_back(std::async(std::launch::async,LoadMesh,m_Meshed,file));
*/		
