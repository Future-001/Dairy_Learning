#pragma once
/*如何再VS中创建多个项目&如何创建一个库让所有项目都能使用
*			项目规模大，库可以帮助用代码创建模块或库，并且多次重用，还能混用语言
*	
*		如何创建一个项目，作为库的项目，特别是静态库，然后将其连接到一个可执行文件
*			以及这些再VS中如何工作的
* 
*			具体操作见下
* 
*	新建解决方案Game(没有将解决方案和放在一起） --> 解决方案下再创建一个新项目Engine
* --->   将engine解决方案属性设置为  .lib格式 
*			稍微运行一下，会生成一个 .lib结尾的文件
*				在里面添加各种代码文件  .h 存储声明，  .cpp文件定义
* 
* 在Game解决方案中 
*				  在Game的属性C/C++  -->  General --> Additional Include Directories
*							$(SolutionDir)Engine\src   反正就是找到这个文件的路径就可以了
* 
*				.cpp文件中include声明的头文件
*				在Game这个项目 --> 右键  reference 选择 Engine编译器以及帮助我们设置了Input什么的
*						或者使用之前链接静态库的方法，Input,包含静态库什么的 engine.lib文件
*				engine 右键清理解决方案
* 
* 自己去试试吧
* 
* 具体的代码去看GAME文件下
* 
* Game ---Engine
*				---Engine.h
*							namesapce engine{void PrintMessage();}
*				---Engine.cpp
*							#include<iostream>
							#include"Engine.h"
							namespace engine{
*										void PrintMessage(){std::cou<<"Hello World!"<<std::endl;}}
*			build之后会生成 Engine.lib
*	   ---Game
*				先右键reference一下Engine（实现静态链接中 Input General的功能)
					同时在属性中将Engine目录添加进来，方便找到头文件
*				----Start.cpp
*							#include"Engine.h"
*							int main(){engine::PrintMessage();}
 */