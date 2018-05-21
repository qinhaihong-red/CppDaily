//daily0409
/************************************************************************/
/* 

容器：
按容器的结构，分为3种：
1.序列式容器：vector,list,array 等，内部以 链表 来实现.
2.关联式容器：set,map,multiset,multimap等，内部以 二叉树 来实现.
3.无序容器：unorderd_set,unordered_map,unordered_multiset,unordered_multimap，内部以 hash table 实现.

关联式容器会对插入的元素进行排序.有时候不关心排序，只关心元素是否在容器中（是否唯一），
这时可以使用无序容器.

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <type_traits>

template<typename T>
void func_print_all_elements(const T &t)
{
	for (const auto &i:t)
	{
		std::cout << i <<std::endl;
	}
}

template<typename T1,typename T2>
void func_print_all_elements(const std::multimap<T1,T2> &t)
{
	for (const auto &i : t)
	{
		std::cout << i.first<<" "<<i.second << std::endl;
	}
}


void func_multiset_multimap_inside()
{
	std::multiset<std::string> s = {"james","jordan","wade","curry"};
	func_print_all_elements(s);
	std::cout << std::endl;


	s.insert("jordan");
	s.insert("james");
	func_print_all_elements(s);
	std::cout << std::endl;
}

//使用 multimap 制作字典
//给出指定key,打印出该键对应的所有值.
//给出指定value，打印出该值对应的所有键.
void func_multimap_as_dict()
{
	std::multimap<std::string, std::string> mm = {
		{"shooter","curry"},
		{"forward","james"/*lbj,of course*/},
		{"guard"  ,"jordan"},
		{"shooter","thompson"},
		{"guard","james"/*jh,of course*/},
		{"shooter","allen"},
		{"center","o'neal"}
	};

	func_print_all_elements(mm);
	std::string str("shooter");
	//检索出字典中的所有 shooter 键对应的值.
	std::cout << "\nshooters are as followed:" << std::endl;

	for (auto pos=mm.lower_bound(str);pos!=mm.upper_bound(str);++pos)
	{
		std::cout << "\t"<<pos->second << std::endl;
	}

	//检索出字典中值为james的键
	str = "james";
	std::cout << "james are as followed:" << std::endl;

	for (auto &i:mm)
	{
		if (i.second == str)
		{
			std::cout << "\t" << i.first << std::endl;
		}
	}
}

int maindaily0409()
{
	func_multiset_multimap_inside();
	func_multimap_as_dict();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}