#pragma once
/*auto关键字
*			到处都能用auto吗？
*			类型名很长很长的时候可以用，，或者很复杂的情况下
*/
#include<vector>
#include<unordered_map>

static auto Auto_GetName()-> const char* // C++11之后的用法
{
	return "Cherno";
}

class Device {};

class DeviceManager
{
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices; // 映射
public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const
	{
		return m_Devices;
	}

};


static void Auto_Func()
{
	auto Name = Auto_GetName();
	std::string Name2 = Auto_GetName(); // 进行了隐式转换

	//Name.size(); 就会出错，因为丧失了某些特定类型的属性
	Name2.size();

	//============
	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	for (std::vector<std::string>::iterator it = strings.begin();  // 这里类型就可以 auto
		it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	//============
	DeviceManager dm;
	const std::unordered_map<std::string, std::vector<Device*>>&
		devices = dm.GetDevices();

	using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
	// 或者typedef
	DeviceManager dm2;

	const DeviceMap& devices2 = dm2.GetDevices();

	const auto& device3 = dm.GetDevices();
}

