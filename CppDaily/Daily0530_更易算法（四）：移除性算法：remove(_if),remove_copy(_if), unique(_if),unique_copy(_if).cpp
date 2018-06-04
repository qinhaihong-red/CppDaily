//daily0530
/************************************************************************/
/* 
移除性算法
所谓的移除，只是逻辑性的移除，不会物理上从容器内移除元素.就是说，算法把那些不应被移除的元素覆盖掉应移除的元素.
并返回新的逻辑终点，也就是最后一个不移除元素的下一个位置.
调用者应保证从此使用新的逻辑终点，不再使用原来的end终点.

1.remove,remove_if
	该算法不适用于关联容器和序列容器，它们有类似功能的成员函数erase.对于list来说，有更高效的
成员函数remove(因为它不重新赋值，而值是连接指针而已).

因此，高效且适用于remvoe算法的容器只有vector和deque而已.

2.remove_copy,remove_copy_if
	在从源区间复制到另一个区间时，移除某些元素（源区间不受影响）.


3.unique(包括同名重载的双参判别式版本，也就是它没有带_if命名的版本)
	移除连续重复的元素.
	因此源区间要经过排序，才能使用该函数（或者说，至少部分邻接元素相等，该算法才有效）.
	不适用于关联和无序容器.
	list有同名的更有效的成员函数.
	因此，高效且适用于remvoe算法的容器只有vector和deque而已.

4.unique_copy(包括同名重载的双参判别式，也就是它没有带_if命名的版本)
	复制过程中移除重复元素（源区间不受影响）.

*/
/************************************************************************/


#include "common/common.h"


void func_algor_0530()
{
	//1.remove,remove_if
	std::vector<int> vec;
	common::insert_element(vec, 2, 6);
	common::insert_element(vec, 4, 9);
	common::insert_element(vec, 1, 7);
	std::cout << "1.remove:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//移除所有值为5的元素
	auto pos = std::remove(std::begin(vec), std::end(vec), 5);
	std::cout << "\nnow vec is(size not changed):\n";
	common::print_elems(vec);
	std::cout << std::endl;

	vec.erase(pos, std::end(vec));
	std::cout << "\nnow vec is(size changed):\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//移除所有小于4的元素
	//erase+remove:逻辑与物理保持一致.
	vec.erase(std::remove_if(std::begin(vec), std::end(vec),
		[](int i){return i < 4;}),std::end(vec));

	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;


	//2.remove_copy,remove_copy_if
	std::list<int> li;
	common::insert_element(li, 1, 6);
	common::insert_element(li, 1, 9);
	std::cout << "\n2.remove_copy:\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//把除值为3的以外的元素输出到cout
	std::remove_copy(std::begin(li), std::end(li),
		std::ostream_iterator<int>(std::cout," "),3);
	std::cout << std::endl;

	//把除值大于4以外的元素输出到cout
	std::remove_copy_if(std::begin(li), std::end(li),
		std::ostream_iterator<int>(std::cout," "),
	[](int i)
	{
		return i > 4;
	});
	std::cout << std::endl;
	
	//把小于4的元素复制到m-set
	std::multiset<int> m_set;
	std::remove_copy_if(std::begin(li), std::end(li),
		std::inserter(m_set, m_set.end()),
		std::bind(std::less<int>(), std::placeholders::_1, 4));
	std::cout << "\nnow m_set is:\n";
	common::print_elems(m_set);
	
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//unique. 双参判别式同名重载，无_if命名版本.
	std::cout << "\n3.unique:\n";
	int source[] = {1,4,4,6,1,2,2,3,1,6,6,6,5,7,5,4,4};
	vec.clear();
	std::copy(std::begin(source), std::end(source),std::back_inserter(vec));
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	auto pos2 = std::unique(std::begin(vec), std::end(vec));
	std::copy(std::begin(vec), pos2, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//再次初始化vec
	std::copy(std::begin(source), std::end(source), std::begin(vec));

	vec.erase(std::unique(std::begin(vec), std::end(vec), 
		std::greater<int>()		
		), std::end(vec));

	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//4.unique_copy.双参判别式同名重载.因此无_if命名版本.
	std::cout << "\n4.unique_copy:\n";
	li.clear();
	std::copy(std::begin(source), std::end(source), std::back_inserter(li));
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	std::unique_copy(std::begin(li), std::end(li), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	auto func_differencOne = [](int i, int j)
	{
		return (i + 1 == j) || (i - 1 == j);
	};

	std::unique_copy(std::begin(li), std::end(li), std::ostream_iterator<int>(std::cout, " "), func_differencOne);
	std::cout << std::endl;

}


int maindaily0530()
{
	func_algor_0530();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}