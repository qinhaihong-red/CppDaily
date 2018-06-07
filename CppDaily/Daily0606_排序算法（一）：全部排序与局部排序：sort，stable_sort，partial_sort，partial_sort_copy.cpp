//daily0606
/************************************************************************/
/* 
排序算法要求迭代器为 random access iterator,因此不适用于list,关联容器和无序容器.

1.全部排序：sort,stable_sort
	包含同名的带双参判别式（严格弱序）的版本.
	stalbe_sort保证相等的元素在排序后保持顺序不变.
	复杂度：
		sort:平均为nlogn
		stalbe_sort:内存足够时为nlogn，否则最坏为n(logn)^2

2.局部排序：partial_sort
	局部排序.包含同名的带双参判别式（严格弱序）的版本.
	复杂度：在线性和nlogn之间.如果用其做全排，平均性能不及sort，但是最差情况优于sort.

3.partial_sort_copy:复制过程中排序

*/
/************************************************************************/

#include "common/common.h"

void func_algor_0606()
{
	//1.sort
	std::deque<int> deq;
	common::insert_element(deq, 1, 9);
	common::insert_element(deq, 1, 9);
	std::cout << "1.sort:\nnow deq is:\n";
	common::print_elems(deq);
	std::cout << std::endl;

	//升序排序
	std::sort(std::begin(deq), std::end(deq));
	common::print_elems(deq);
	std::cout << std::endl;

	//降序排序
	std::sort(std::begin(deq), std::end(deq), std::greater<int>());
	common::print_elems(deq);
	std::cout << std::endl;

	//比较sort和stable_sort
	auto funcLessLen = [](const std::string &s1,const std::string &s2)
	{
		return s1.length() < s2.length();
	};

	std::vector<std::string> vec = {"1xxx","2x","3x","4x","5xx","6xxxx","7xx","8xxx","9xx","10xxx",
	"11","12","13","14xx","15","16","17"};

	std::vector<std::string> vec2(vec);

	//vs stl 这里实现的 sort 和 stable_sort 表现一致.
	std::sort(std::begin(vec), std::end(vec), funcLessLen);
	std::stable_sort(std::begin(vec2), std::end(vec2), funcLessLen);
	
	std::cout << "\ndifference between sort and stable_sort:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	common::print_elems(vec2);
	std::cout << std::endl;

	//2.partial_sort
	deq.clear();
	common::insert_element(deq, 3, 7);
	common::insert_element(deq, 2, 6);
	common::insert_element(deq, 1, 5);
	std::cout << "\n2.partial_sort:\nnow deq is:\n";
	common::print_elems(deq);
	std::cout << std::endl;

	//只排前5个元素:升序
	std::partial_sort(std::begin(deq), std::begin(deq) + 5, std::end(deq));
	common::print_elems(deq);
	std::cout << std::endl;
	
	//只排前5个元素:降序
	std::partial_sort(std::begin(deq), std::begin(deq) + 5, std::end(deq),std::greater<int>());
	common::print_elems(deq);
	std::cout << std::endl;

	//利用partial_sort进行全排序
	std::partial_sort(std::begin(deq), std::end(deq), std::end(deq));
	common::print_elems(deq);
	std::cout << std::endl;


	//2.partial_sort_copy(inputIter sBeg,inputIter sEnd,RAIter dBeg,RAIter dend,[BP op])
	//把元素从源区间复制到目标区间，并排序.
	//源区间只要求intput iterator，而目标区间要求random access iterator.
	//复制并排序的元素的个数，以较小区间为准.如果源区间小于目标区间，那么相当于把源区间元素复制到目标区间，
	//并完全排序.

	deq.clear();
	std::vector<int> v6(6), v30(30);
	common::insert_element(deq, 3, 7);
	common::insert_element(deq, 2, 6);
	common::insert_element(deq, 1, 5);
	std::cout << "\n3.partial_sort_copy:\nnow deq is:\n";
	common::print_elems(deq);
	std::cout << std::endl;

	//复制6个元素到v6并排序
	auto pos6 = std::partial_sort_copy(std::begin(deq), std::end(deq), std::begin(v6), std::end(v6));
	std::copy(std::begin(v6), pos6, std::ostream_iterator<int>(std::cout, " "));

	//把所有元素复制到v30中并排序（v30容量大于deq）
	auto pos30 = std::partial_sort_copy(std::begin(deq), std::end(deq), std::begin(v30), std::end(v30), std::greater<int>());
	std::copy(std::begin(v30), pos30, std::ostream_iterator<int>(std::cout, " "));

}

int main0606()
{
	func_algor_0606();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}