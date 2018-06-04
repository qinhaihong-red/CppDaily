//daily0604
/************************************************************************/
/* 
所谓变序算法，就是改变容器内元素的顺序.因此不适用于关联以及无序容器.

reverse: 反转元素顺序.

rotate:以某元素为轴，进行旋转镜像.

pre/next_permutation:把降序或升序的序列，逐一进行排列输出.


*/
/************************************************************************/


#include "common/common.h"


void func_algor_0604()
{
	//1.reverse,reverse_copy
	//list有同名的reverse成员函数，且效率更高.因此reverse仅适用于vector和deque.
	std::vector<int> vec;
	common::insert_element(vec, 1, 9);
	std::cout << "1.reverse:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::reverse(std::begin(vec), std::end(vec));
	common::print_elems(vec);
	std::cout << std::endl;

	std::reverse(std::begin(vec) + 1, std::end(vec) - 1);
	std::reverse_copy(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;


	//2.rotate
	vec.clear();
	common::insert_element(vec, 1, 9);
	std::cout << "\n2.rotate:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::rotate(std::begin(vec), std::begin(vec) + 1, std::end(vec));
	common::print_elems(vec);
	std::cout << std::endl;

	std::rotate(std::begin(vec), std::end(vec) - 2, std::end(vec));
	common::print_elems(vec);
	std::cout << std::endl;

	std::rotate(std::begin(vec), std::find(std::begin(vec), std::end(vec), 4), std::end(vec));
	common::print_elems(vec);
	std::cout << std::endl;

	//3.next/pre_permutation
	//分别包含同名的双参判别式版本（没有_if版本）
	//输出有序序列的所有排列：next_permutation输出升序序列的所有排列，prev_permutation输出降序序列的所有排列.
	//可以使用该函数进行排序，但是效率不佳.
	vec.clear();
	common::insert_element(vec, 1, 3);
	std::cout << "\n3.next/prev_permutation:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::cout << "All the permutation is:\n";
	while (std::next_permutation(std::begin(vec), std::end(vec)))
	{
		common::print_elems(vec);
		std::cout << std::endl;
	}

	std::cout << "\nnow vec is:";
	common::print_elems(vec);
	std::cout << std::endl;

	//这里序列并非降序，因此prev_permutation函数会先把vec进行降序，然后返回false.
	//不会输出排列.
	while (std::prev_permutation(std::begin(vec),std::end(vec)))
	{
		common::print_elems(vec);
		std::cout << std::endl;
	}

	std::cout << "\nnow vec is:";
	common::print_elems(vec);
	std::cout << std::endl;

	//这里序列已经降序，逐一输出排列.
	while (std::prev_permutation(std::begin(vec), std::end(vec)))
	{
		common::print_elems(vec);
		std::cout << std::endl;
	}

	std::cout << "\nnow vec is:";
	common::print_elems(vec);
	std::cout << std::endl;
}


int main()
{
	func_algor_0604();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}