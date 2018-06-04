//daily0528
/************************************************************************/
/* 
1.transform:
	把一个区间的或者两个区间的元素，经过变换（通过单参函数或者双参函数），映射到另一个区间.
	类似于：f:R^n-->R^m.
	返回目标区间内最后一个未被转换的元素（也就是第一个未被覆盖的元素）的迭代器.

2.swap_range:
	交换两个区间内元素.
	返回第二个区间中 最后一个被交换元素 的下一个位置.
	如果是同类型容器交换所有的元素，应该使用其成员函数swap.

*/
/************************************************************************/


#include "common/common.h"

void func_algor_0528()
{
	//1.transform

	std::vector<int> vec;
	std::list<int> li;

	common::insert_element(vec, 1, 9);
	std::cout << "1.transform:\n";
	std::cout << "now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//一. 两个区间之间的变换（使用单参函数）
	//把vec内元素变换为其负数
	std::transform(std::begin(vec), std::end(vec), std::begin(vec), std::negate<int>());
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//把vec内元素乘10后插入li
	std::transform(std::begin(vec), std::end(vec),
		std::back_inserter(li),
		std::bind(std::multiplies<int>(), std::placeholders::_1, 10));

	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//反向输出li内元素的负数
	std::cout << "\nnow -r_li is:\n";
	std::transform(std::rbegin(li),std::rend(li),
		std::ostream_iterator<int>(std::cout," "),
		[](int i) {return -i; }
	);

	//二.两个区间结合之后再变换到另一个区间（使用双参函数）
	vec.clear();
	li.clear();

	common::insert_element(vec, 1, 9);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//通过变换使得vec内每个元素开平方
	std::transform(std::begin(vec), std::end(vec),
		std::begin(vec),
		std::begin(vec),
		std::multiplies<int>());
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//vec首尾相加再插入到li中
	std::transform(std::begin(vec), std::end(vec),
		std::rbegin(vec),
		std::back_inserter(li),
		std::plus<int>());
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//vec减去li再输出到cout中
	std::cout << "\nnow vec-li is:\n";
	std::transform(std::begin(vec),std::end(vec),
		std::begin(li),
		std::ostream_iterator<int>(std::cout," "),
		std::minus<int>());


	//2.swap_range 区间内互换元素
	std::cout << "\n2.swap_range:\n";
	std::deque<int> deq;
	vec.clear();

	common::insert_element(vec, 1, 9);
	common::insert_element(deq, 11, 23);

	std::cout << "\nnow vec and deq are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(deq);
	std::cout << std::endl;

	//使vec和deq互换元素
	auto pos = std::swap_ranges(std::begin(vec), std::end(vec), std::begin(deq));
	std::cout << "\nnow vec and deq are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(deq);
	std::cout << std::endl;

	if (pos!=std::end(deq))
	{
		std::cout << "\nfirst not swapped element is:" << *pos << std::endl;
	}

	//deq互换首尾3个元素
	std::swap_ranges(std::begin(deq), std::begin(deq) + 3, std::rbegin(deq));
	std::cout << "\nnoww deq is:\n";

	common::print_elems(deq);
	std::cout << std::endl;

}


int maindaily0528()
{
	func_algor_0528();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}