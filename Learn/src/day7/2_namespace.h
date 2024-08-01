#pragma once
/*什么是名称空间：
	void apple_print() {};
	void orange_print() {};

	避免名称冲突，使用了相同的符号但是来自不同名称空间
*/
namespace apple {  // namespace start { 多个嵌套
	void print() {};
} 
namespace orange {
	void print() {};
}
//using apple::print;
//
//namespace a = apple;