//daily0607
/************************************************************************/
/* 

继续排序算法:
1.nth_element(beg,nth,end,[BP op]):
	根据第nth个元素进行排序.
	包含同名的带双参判别式的版本.
	使得在nth前的元素都小于（或满足op条件）nth，其后元素都大于nth(或满足op条件).
	而partition则根据提供的op进行划分.

2.heap相关算法：
	所谓heap，是这样一个二叉树：
	1.父节点元素总是大于直接子节点元素.这样第一个元素总是最大的.
	2.能以对数时间增加和移除元素.
	heap相关的函数有：
	make_heap
	push_heap
	pop_heap
	sort_heap
	以上均包含同名的带双参判别式的版本.

*/
/************************************************************************/


#include "common/common.h"

void func_algor_0607()
{
	//1.nth_element
	std::deque<int> deq;
	common::insert_element(deq, 3, 7);
	common::insert_element(deq, 2, 6);
	common::insert_element(deq, 1, 5);
	std::cout << "1.nth_element:\nnow deq is:\n";
	common::print_elems(deq);
	std::cout << std::endl;

	//以第四个元素为界限排序：
	//在此之前的元素均小于等于它，之后的元素均大于等于它.
	std::nth_element(std::begin(deq), std::begin(deq) + 3, std::end(deq));
	std::cout << "\nthe 4 lowest elements are:\n";
	std::copy(std::begin(deq), std::begin(deq) + 4, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//选定4个最大的元素：方法一
	std::nth_element(std::begin(deq), std::end(deq) - 4, std::end(deq));
	std::cout << "\nthe 4 highest elements are:\n";
	std::copy(std::end(deq)-4, std::end(deq), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//选定4个最大的元素：方法二
	//虽然同是选中最大的4个元素，但是两种方法的元素顺序不一样.
	//就是说，nth_element对划定的区域，不会再排序.
	std::nth_element(std::begin(deq), std::begin(deq) + 3, std::end(deq), std::greater<int>());
	std::cout << "\nthe 4 highest elements are:\n";
	std::copy(std::begin(deq), std::begin(deq) + 4, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//2.heap相关算法
	std::vector<int> vec;
	common::insert_element(vec, 3, 7);
	common::insert_element(vec, 5, 9);
	common::insert_element(vec, 1, 4);
	std::cout << "\n2.heap:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//make_heap
	//对vec进行make_heap
	//可以看到vec的首个元素，就是最大的元素了.
	std::make_heap(std::begin(vec), std::end(vec));
	std::cout << "\nafter make_heap, now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//pop_heap
	//对已形成heap的序列，进行pop操作：把最大的元素移动到序列尾部.
	//由于算法不能在物理上操作容器，因此需要容器调用成员函数pop_back来完成pop操作.
	std::pop_heap(std::begin(vec),std::end(vec));
	vec.pop_back();
	std::cout << "\nafter pop_heap, now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//push_heap
	//对已形成heap的序列，添加一个新元素，使之经过调整，再次形成heap
	//因此要先调用容器的push_back成员函数，再对容器使用push_heap
	vec.push_back(17);
	std::push_heap(std::begin(vec), std::end(vec));
	std::cout << "\nafter push_heap, now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//sort_heap
	//对已形成heap的序列，进行排序.
	//排序后，序列就已不再是heap结构了.
	std::sort_heap(std::begin(vec), std::end(vec));
	std::cout << "\nafter sort_heap, now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;
}

int main0607()
{
	func_algor_0607();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}