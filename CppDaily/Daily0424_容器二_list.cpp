//daily0424
/************************************************************************/
/* 

list:
1.适用于在任何部位进行频繁增删的场景.
2.内部实现为双向链表，因此它的迭代器是双向迭代器.某些算法要求随机迭代器，所以
  不适宜于list. 而list有自己的sort算法.
3.list有自己的remove(value)【返回的是删除所有值为value元素的个数】和erase(iter)【如同vector，返回的是下一个迭代器】成员函数，因此不必像vector和deque那样erase+remove进行删除元素.
4.任意增删都不会导致list迭代器失效.
5.注意list有一系列在同类型对象之间进行移动（move）和链接（splice,relink）等的算法.


*/
/************************************************************************/
#include"./common/common.h"


void print_lists(const std::list<int> &l1, const std::list<int> &l2)
{
	std::cout << "list 1:\n";
	std::copy(l1.begin(), l1.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\nlist 2:\n";
	std::copy(l2.begin(), l2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}


void func_list_inside()
{
	std::list<int> l1, l2;

	for (int i=0;i<6;++i)
	{
		l1.push_back(i);
		l2.push_front(i);
	}
	std::cout << "before splice:\n";
	print_lists(l1, l2);

	//把list1中的所有元素移动到l2中值为3的元素之前
	l2.splice(std::find(l2.begin(),l2.end(),3),l1);
	std::cout << "after splice:\n";
	print_lists(l1, l2);

	//把l2头部的元素移动到尾部
	l2.splice(l2.end(), l2, l2.begin());
	print_lists(l1, l2);

	l2.sort();
	l1 = l2;
	l2.unique();
	print_lists(l1, l2);


	//把l2所有元素合并到l1
	l1.merge(l2);
	print_lists(l1, l2);
}


int maindaily0424()
{
	func_list_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}