//daily0403
/************************************************************************/
/* 
使用std::bind绑定到对象的成员函数

*/
/************************************************************************/
#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <map>
#include <numeric>

class CPlayer0403
{
public:
	CPlayer0403(const std::string &name);
	~CPlayer0403() {};
	void print();
	void print2(const std::string &prefix);
	void changeName(const std::string &name);
private:
	std::string m_strName;
};

CPlayer0403::CPlayer0403(const std::string &name) :m_strName(name)
{

}

void CPlayer0403::print()
{
	std::cout << "the player name is:" << m_strName << std::endl;
}

void CPlayer0403::print2(const std::string &prefix)
{
	std::cout << "the player full name is: " << prefix << " " << m_strName << std::endl;
}

void CPlayer0403::changeName(const std::string &name)
{
	m_strName = name;
}


void func_bind_memfunc_inside()
{
	std::vector<CPlayer0403> vec = {CPlayer0403("James"),CPlayer0403("Wade"),CPlayer0403("Curry")};

	//1.绑定到print()
	//注意如果这里的print进行了重载，则bind无法使用.
	//它无法确定绑定到了哪个函数.
	std::for_each(vec.begin(),vec.end(), std::bind(&CPlayer0403::print, std::placeholders::_1));
	std::cout << std::endl;

	//2.绑定到print2()
	std::for_each(vec.begin(), vec.end(), std::bind(&CPlayer0403::print2,std::placeholders::_1,"NBA Player:"));
	std::cout << std::endl;

	//3.可以修改对象内容
	std::for_each(vec.begin(),vec.end(),std::bind(&CPlayer0403::changeName,std::placeholders::_1,"Jordan23"));
	
	
	//4.使用mem_fn绑定成员函数，可不必使用placeholders::_1占位符
	std::for_each(vec.begin(), vec.end(), std::mem_fn(&CPlayer0403::print));
	std::cout << std::endl;

	//5.甚至可以绑定到数据成员

	std::map<std::string, int> mpPlayer = {std::make_pair("James",33),std::make_pair("Wade",36),std::make_pair("Curry",30)};

	//计算所有球员的年龄来
	int sum = std::accumulate(mpPlayer.begin(),mpPlayer.end(),
		0,/*累加的初始值*/
		std::bind(std::plus<int>(),std::placeholders::_1,/*绑定到上面的初始值0*/
			std::bind(&decltype(mpPlayer)::value_type::second,std::placeholders::_2))/*绑定到map item 的 value*/		
		);

	std::cout << "sum ages of players is: " << sum << std::endl;
}



int maindaily0403()
{
	func_bind_memfunc_inside();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}