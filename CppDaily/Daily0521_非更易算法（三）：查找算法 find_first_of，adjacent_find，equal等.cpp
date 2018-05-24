//daily0521
/************************************************************************/
/* 
继续查找算法:

find_first_of/find_first_of[if版本]：
	相当于find和find_if的双区间版本：即接收一个子区间，并与之比较.
	这里的命名并非规范，接收BinaryPredicate的find_first_of相当于重载，并未命名以if结尾.

adacent_find/adacent_find[if版本]：
	查找两个连续相等元素的首个位置.

equal/equal[if版本]：
	比较两个区间的相等性.


*/
/************************************************************************/
#include "common/common.h"


void func_algor_find_inside0521()
{
	//1.find_first_of
	std::vector<int> vec;
	std::list<int> liSearch;

	common::insert_element(vec, 1, 11);
	common::insert_element(liSearch, 3, 5);

	std::cout << "now vec and li are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(liSearch);
	std::cout << std::endl;

	auto pos = std::find_first_of(vec.begin(), vec.end(),
		liSearch.begin(), liSearch.end());

	std::cout << "\nfirst element of liSearch in vec is element " << std::distance(std::begin(vec), pos) + 1 << std::endl;

	//反向查找--vs不支持
	//auto rpos = std::find_first_of(vec.rbegin, vec.rend(), std::begin(liSearch), std::end(liSearch));

	//2.adjacent_find
	vec.clear();
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(0);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;


	pos = std::adjacent_find(std::begin(vec), std::end(vec));
	if (pos != std::end(vec))
	{
		std::cout << "first 2 elements with equal val have pos " << std::distance(std::begin(vec), pos) + 1 << std::endl;
	}


	auto func = [](int elem1, int elem2)
	{
		return elem1 * 2 == elem2;	
	};

	pos = std::adjacent_find(std::begin(vec), std::end(vec), func);

	if (pos != std::end(vec))
	{
		std::cout << "first 2 elements with second val twice the first have pos. " << std::distance(std::begin(vec), pos) + 1 << std::endl;

	}

	//3.equal 区间比较. 返回值是bool，而不再是iterator.
	// 比较两个区间内元素是否相等或者符合 bin-predicate
	//--当序列不相等时，如果想要了解其间的不同，应使用mismatch.
	//--is_permutation用来判断两个序列是否元素值相等但顺序不同.

	vec.clear();
	liSearch.clear();

	common::insert_element(vec, 1, 7);
	common::insert_element(liSearch, 3, 9);

	std::cout << "\nnow vec and li are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(liSearch);
	std::cout << std::endl;


	if (std::equal(std::begin(vec),std::end(vec),std::begin(liSearch)))//子区间要小于主区间，需要自己保证
	{
		std::cout << "li == vec" << std::endl;
	}
	else
	{
		std::cout << "li != vec" << std::endl;
	}

	//使用双参判别式进行自定义比较
	auto func_check_even_odd = [](int e1, int e2)
	{
		return e1 % 2 == e2 % 2;
	};

	if (std::equal(std::begin(vec),std::end(vec),std::begin(liSearch),func_check_even_odd))
	{
		std::cout << "even and odd elements are correspond." << std::endl;
	}
	else
	{
		std::cout << "even and odd elements do not correspond." << std::endl;
	}

}

int maindaily0521()
{
	func_algor_find_inside0521();
	
	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}