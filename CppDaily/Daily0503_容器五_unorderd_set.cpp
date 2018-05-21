//daily0503
/************************************************************************/
/* 
unodered_xx，无序容器，内部以hash table实现，即：bucket+hashfunc.

可以常数时间量实现查找，适用于对查找速度要求极高的场景.

1.对于key无法修改，类似于关联容器. 欲修改key，需先删除，再插入.
2.对于基本类型，已定义了默认的hashfunc和相等的比较标准；对于定义类型，需要定义hash函数和相等的比较标准.
3.对于multiset和multimap，即允许多同值的出现，以链表的形式处理冲突.
4.对于set和map，对于不同值出现的hash冲突，以rehash处理冲突.
5.删除不会使得迭代器失效，但是插入有可能使得所有迭代器失效.
6.插入可能导致元素数 大于 bucket*负载系数 而造成rehash.

*/
/************************************************************************/

#include"./common/common.h"
#include <unordered_set>

void func_unorderd_set_inside()
{

	auto f_hash = [](const CPlayer &player)->std::size_t
	{
		return std::hash<std::string>()(player.getName()) + std::hash<int>()(player.getRank());
	};

	auto f_equal = [](const CPlayer &p1, const CPlayer &p2)
	{
		return p1.getName() == p2.getName();
	};


	std::unordered_set<CPlayer, decltype(f_hash), decltype(f_equal)> uset(50,f_hash,f_equal);

	std::cout << CPlayer("James Harden", 96) << std::endl;

	uset.insert(CPlayer("James Harden", 96));
	uset.insert(CPlayer("Lebron James",99));
	uset.insert(CPlayer("Curry",97));

	common::print_elems(uset, common::PrintFormat::n);
	std::cout << "insert another curry:" << std::endl;
	uset.insert(CPlayer("Curry", 97));
	common::print_elems(uset, common::PrintFormat::n);


}


int maindaily0503()
{

	func_unorderd_set_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}