//daily0410
/************************************************************************/
/* 

无序容器只关心快速在容器中查找元素是否存在，不会排序。
无序容器的构成：
hash函数，bucket+链表. 链表用于冲突避免.

STL提供了对于基本类型以及string的hash函数.
如果对于自定义类型，需要自定义hash函数.通常会代理到基础类型来处理.


*/
/************************************************************************/

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>


void func_unordered_inside()
{
	std::cout << "unordered_multiset:" << std::endl;
	std::unordered_multiset<std::string> umt = {
	"beijing","shanghai","guangzhou","shenzhen",
	"chengdu","hangzhou","wuhan"	
	};

	for (auto &i:umt)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	umt.insert({"zhengzhou","beijing","shenzhen","jiaozuo"});

	for (auto &i : umt)
	{
		std::cout << i << " ";
	}
	std::cout << "\nunordered_map："<<std::endl;
	std::unordered_map<std::string, double> nmp = {
		{"james",100},{"durant",99}	
	};

	for (std::pair<const std::string,double> &i:nmp)
	{
		i.second *= i.second;
	}

	for (auto &i:nmp)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}
	std::cout << std::endl;
}

int maindaily0410()
{

	func_unordered_inside();
	
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}