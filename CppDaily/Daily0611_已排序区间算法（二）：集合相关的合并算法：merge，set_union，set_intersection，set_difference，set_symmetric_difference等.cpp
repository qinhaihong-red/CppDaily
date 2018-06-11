//daily0611
/************************************************************************/
/* 
合并算法.

主要是容器集合之间的 并， 交， 差， 补 等相关运算.
类似于数学中集合论里面的相关运算，但是不完全相同.需注意差别.

1.merge:
	将两个已排区间逐一按元素顺序合并在一起.
	list和forword_list有同名的成员函数，效率会更高.
	返回目标区间的第一个未被覆盖的元素.

2.set_union:
	将两个已排区间逐一按元素顺序合并在一起，但对于同位置比较的两个元素，如值相等，则只取一个元素.
	返回目标区间的第一个未被覆盖的元素.

3.set_intersection:
	逐一位置比较两个已排区间，只取值相等的元素插入目标区间.
	返回目标区间的第一个未被覆盖的元素.

4.set_difference:
	逐一位置比较两个已排区间，只取值不等的属于第一个区间内的元素插入目标区间.

5.set_symmetric_difference:
	将两个已排区间逐一按元素顺序合并在一起，忽略同位置值相等的元素.


*/
/************************************************************************/




#include "common/common.h"

void func_algor_0611()
{
	std::vector<int> vec = {1,2,2,4,6,7,7,9};
	std::deque<int> deq  = {2,2,2,3,6,6,8,9};

	std::cout << "now vec and deq are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(deq);
	std::cout << std::endl;

	//1.merge
	std::cout << "\n1.merge:\n";
	std::merge(std::begin(vec), std::end(vec),
		std::begin(deq), std::end(deq),
		std::ostream_iterator<int>(std::cout, " "));

	//2.set_union
	std::cout << "\n2.set_union:\n";
	std::set_union(std::begin(vec), std::end(vec),
		std::begin(deq), std::end(deq),
		std::ostream_iterator<int>(std::cout, " "));


	//3.set_intersection
	std::cout << "\n3.set_intersection:\n";
	std::set_intersection(std::begin(vec), std::end(vec),
		std::begin(deq), std::end(deq),
		std::ostream_iterator<int>(std::cout, " "));

	//4.set_difference
	std::cout << "\n4.set_difference:\n";
	std::set_difference(std::begin(vec), std::end(vec),
		std::begin(deq), std::end(deq),
		std::ostream_iterator<int>(std::cout, " "));

	//5.set_symmetric_difference
	std::cout << "\n5.set_symmetric_differenc:\n";
	std::set_symmetric_difference(std::begin(vec), std::end(vec),
		std::begin(deq), std::end(deq),
		std::ostream_iterator<int>(std::cout, " "));
}


int main()
{
	func_algor_0611();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}