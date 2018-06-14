//daily0614
/************************************************************************/
/* 
相对数列和绝对数列之间的转换

1.partial_sum(beg,end,dstBeg,[BF op]):
	根据输入的数列：   a1, a2,    a3,...
	生成一个新的数列： a1,a1+a2,a1+a2+a3,...
	即新数列的元素对应原数列每个元素与之前元素的累加和.
	对于带op的双参函数版本，新数列满足：a1,a1[op]a2,a1[op]a2[op]a3,...
	
	源区间和目标区间可以相同.
	返回目标区间未被覆盖元素的下一个迭代器.

	这就是所谓的把 相对值数列 转换为 绝对值数列.

2.adjacent_difference(beg,end,stdBeg,[BF op]):
	把输入数列的临近元素相减生成新的序列，即：
	根据输入的数列：   a1, a2,    a3,...
	生成一个新的数列： a1,a2-a1,  a3-a2,...
	对于带op的双参函数版本，新数列满足：a1,a2[op]a1,a3[op]a2,...

	源区间和目标区间可以相同.
	返回目标区间未被覆盖元素的下一个迭代器.

	这就是所谓的把 绝对值数列 转换为 相对值数列.


也就是说，partial_sum和adjacent_difference刚好互补.

*/
/************************************************************************/

#include "common/common.h"
#include <numeric>

void func_algor_0614()
{
	//1.partial_sum
	std::vector<int> vec;
	common::insert_element(vec, 1, 6);
	std::cout << "1.partial_sum:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::cout << "partial sum of vec is:";
	std::partial_sum(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout, " "));

	std::cout << "\npartial products of vec is:";
	std::partial_sum(std::begin(vec), std::end(vec),
		std::ostream_iterator<int>(std::cout, " "),
		std::multiplies<int>());

	//2.adjacent_difference
	std::cout << "\n2.adjacent_difference:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::cout << "adjacent difference of vec is:";
	std::adjacent_difference(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout, " "));

	std::cout << "\nadjacent sum of vec is:";
	std::adjacent_difference(std::begin(vec), std::end(vec), 
		std::ostream_iterator<int>(std::cout, " "),
		std::plus<int>());

}

int main()
{
	func_algor_0614();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}