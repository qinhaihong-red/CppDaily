//daily0501
/************************************************************************/
/* 

1.map类似经过自动排序的vector，支持.at()和[]下标操作.
2.内部以红黑树实现.迭代器是双向迭代器.对于要求随机迭代器的算法，并不支持.
3.通过.erase删除节点要注意迭代器失效的问题，必须：erase(pos++)

*/
/************************************************************************/

#include"./common/common.h"


#include <cctype>//toupper tolower
void func_map_inside()
{

	//大小写不敏感的排序准则.
	auto f_compare = [](const std::string& s1, const std::string &s2)
	{
		return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(),
			[](char c1, char c2) {return std::toupper(c1) < std::toupper(c2); });
	
	};

	//默认的排序准则:大小写敏感
	//typedef std::map<std::string, int> PlayerType;

	//自定义排序准则：大小写不敏感
	typedef std::map<std::string, int,decltype(f_compare)> PlayerType;
	PlayerType players(f_compare);

	//1.插入
	//-使用初值列表
	players.insert({ "James",99 });
	players.insert({ "curry",97 });

	//-使用类型的value type
	players.insert(PlayerType::value_type("Durant", 98));

	//-直接使用pair type
	players.insert(std::pair<std::string,int>("harden",97));//这里其实进行了隐式转型
	players.insert(std::pair<const std::string,int>("WB",97));

	//-使用make pair
	players.insert(std::make_pair("Paul",90));

	//-[]
	players["Davis"] = 91;

	//2.循环
	for (auto &i:players)
	{
		i.second += 100;
	}

	std::for_each(players.begin(), players.end(), [](PlayerType::value_type &i)
	{
		std::cout << i.first << " " << i.second << std::endl;
	});
	
}


int maindaily0501()
{

	func_map_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}