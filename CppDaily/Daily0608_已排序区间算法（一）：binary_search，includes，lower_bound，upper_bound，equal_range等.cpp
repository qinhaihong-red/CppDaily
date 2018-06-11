//daily0608
/************************************************************************/
/* 
已排序区间算法.

在已排序区间上，执行查找等算法，会有额外的效率优势.
这些算法与排序算法不同，不再要求RA迭代器.
但是如果是RA迭代器，复杂度会降低到对数复杂度，否则就是线性复杂度.

1.binary_search:
	二分查找指定value值.包含同名的带双参判别式的版本.
	返回值类型bool.
	该函数查找指定数值是否存在，如果需要返回位置迭代器，需要使用lower_bound和upper_bound.

2.includes(InputIterator beg1,II end1,II beg2, II end2,[BP op]):
	判断已排序区间[beg1,end1)是否包含已排序区间[beg2,end2)，也就是判断后者是否为前者子集.
	包含同名的带双参判别式的版本.
	返回值类型bool.

3.lower_bound/upper_bound:
	在不破坏已排序区间的情况下，返回可供插入的元素的位置:
	前者返回第一个可供插入的位置（第一个大于等于指定元素的位置），
	后者返回最后一个可供插入的位置（第一个大于指定元素的位置）.
	返回值是可供插入位置的迭代器.
	均包含带双参判别式的同名版本.

	关联容器具有同名的成员函数，效率更好.

4.equal_range:
	返回可供插入的一个区间.即一个pair.
	等效于make_pair(lower_bound(...),upper_bound(...))

*/
/************************************************************************/


#include "common/common.h"

void func_algor_0608()
{
	//1.binary_search:
	std::list<int> li;
	common::insert_element(li, 1, 9);
	std::cout << "1.binary_search:\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	if (std::binary_search(std::begin(li),std::end(li),5))
	{
		std::cout << "bin_search found 5.\n";
	}
	else
	{
		std::cout << "bin_search not found 5.\n";
	}

	if (std::binary_search(std::begin(li), std::end(li), 10))
	{
		std::cout << "bin_search found 10.\n";
	}
	else
	{
		std::cout << "bin_search not found 10.\n";
	}

	//2.includes
	//查找一个已排序区间是否包含另一个已排序区间
	std::vector<int> vec;
	li.clear();
	common::insert_element(li, 1, 9);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);

	std::cout << "\2.includes:\nnow li and vec are :\n";
	common::print_elems(li);
	std::cout << std::endl;
	common::print_elems(vec);
	std::cout << std::endl;

	if (std::includes(std::begin(li),std::end(li),std::begin(vec),std::end(vec)))
	{
		std::cout << "\nall elements of vec are in li.";
	}
	else
	{
		std::cout << "\nnot all elements of vec are in li.";
	}

	//3.lower_bound/upper_bound
	li.clear();
	common::insert_element(li, 1, 9);
	common::insert_element(li, 1, 9);
	li.sort();
	std::cout << "\n3.lower_bound/upper_bound:\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//查找可插入5的第一个和最后一个位置
	auto pos1 = std::lower_bound(std::begin(li), std::end(li), 5);
	auto pos2 = std::upper_bound(std::begin(li), std::end(li), 5);

	std::cout << "5 可以插入到 " << std::distance(std::begin(li), pos1) + 1 << " 和 " << std::distance(std::begin(li), pos2) + 1 << " 之间，而不破坏序列顺序.\n";

	//插入3到第一个可插入的位置
	li.insert(std::lower_bound(std::begin(li), std::end(li), 3), 3);

	//插入7到最后一个可插入的位置
	li.insert(std::upper_bound(std::begin(li),std::end(li),7),7);

	std::cout << "now li is :\n";
	common::print_elems(li);
	std::cout << std::endl;

	//4.equal_range
	//同时返回第一个和最后一个可插入位置.
	li.clear();
	common::insert_element(li, 1, 9);
	common::insert_element(li, 1, 9);
	li.sort();
	std::cout << "\n4.equal_range:\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	auto pp = std::equal_range(std::begin(li), std::end(li), 5);
	std::cout << "可以在 " << std::distance(std::begin(li), pp.first) + 1 << " 和 " << std::distance(std::begin(li), pp.second) + 1 << " 之间插入5，而不破坏序列顺序.\n";
}


int main0608()
{
	func_algor_0608();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}