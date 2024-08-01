#pragma once
/*操作符：
		其实就是函数
	用于替代函数执行某些事情的符号
	* -> + - / << >>  new delete ....  
操作符重载：
	重载允许在程序中定义或更改一个操作符的行为
	用操作符替代函数


	*/
struct Vector2
{
	float x, y;
	Vector2(float x,float y)
		:x(x),y(y){}

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
		// 另一种方法是  return *this + other // this 关键字后面讲
		//return opeartor+(other); 
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	//定义操作符
	Vector2 operator+(const Vector2& other) const
	{return Add(other);}  //等价于 return Vector2(x + other.x, y + other.y);

	Vector2 operator*(const Vector2& other) const
	{return Multiply(other);}

	bool operator==(const Vector2& other) const
	{
		return x==other.x&&y==other.y;//只涉及比较不涉及递归调用

		//return *this == other;//不能直接用?，因为Operaotr== 之前并没有定义*this???
		// 在 operator== 实现中*this==other，又调用了自身的 operator==，
		// 这会导致无限递归调用，最终导致栈溢出或其他未处理的异常。
		// 正确的方式是在实现中比较成员变量的值，而不是递归调用 operator==。
		
		//return operator==other;
	}
	bool operator!=(const Vector2& other) const
	{
		return !(*this == other);
	}

};

// 对  << 运算符进行重载 将他加入到 cout上   
 // std::ostream& 运算符原始定义
std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{//std::string& stream 存在一个对流的使用，这里是cout 
	stream << other.x << "," << other.y;
	return stream;
}

static void operator_()
{
	Vector2 position(4.0f, 5.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f);

	//如果没有操作符
	Vector2 result1 = position.Add(speed.Multiply(powerup));

	//定义了操作符的情况下
	Vector2 result2 = position + speed * powerup;
	if (result1 == result2);
	if (result1 != result2);

	//另一种重载运算符  std::cout << 左移运算符
	std::cout << result2 << std::endl;
}


