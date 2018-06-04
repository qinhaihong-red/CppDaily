//daily0530
/************************************************************************/
/* 

赋值：
fill, fill_n

生成新值：
generate, generate_n. 与fill相比，generate使用了函数对象.

为容器赋予一系列递增值：
iota

替换元素：
replace:把指定的旧值替换新值.
replace_if:把符合单参判别式的旧值，替换为新值.

replace_copy:把源区间内元素复制到新的区间，并将其中等于旧值的元素替换为新值.
replace_copy_if:把源区间内元素复制到新的区间，并将其中满足单参判别式的旧值元素替换为新值.

*/
/************************************************************************/


#include "common/common.h"
#include <numeric>

void func_algor_0529()
{
	//1.fill,fill_n
	//返回值都是void
	std::cout << "1.fill:\n";
	//向cout输出10个7
	std::fill_n(std::ostream_iterator<int>(std::cout, " "), 10, 7);
	std::cout << std::endl;

	std::list<std::string> li;
	std::fill_n(std::back_inserter(li), 5, "hello");//只需要一个起始迭代器即可.
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//使用fill对li进行覆盖
	std::fill(std::begin(li), std::end(li), "again");
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	std::fill_n(std::begin(li), li.size() - 2,"hi");

	std::fill(++std::begin(li), --std::end(li), "i");
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//2.generate,generate_n
	//返回值都是void
	std::cout << "\n2.generate:\n";
	int nSeed = 100;
	auto func_genVal = [&nSeed]()
	{
		return ++nSeed;
	};

	std::vector<int> vec;
	std::generate_n(std::back_inserter(vec), 5, func_genVal);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::generate(std::begin(vec), std::end(vec), func_genVal);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//3.void iota(beg,end,T startVal):赋予容器一系列递增的值
	std::cout << "\n3.iota(from <numberic.h>):\n";
	std::iota(std::begin(vec),std::end(vec),20);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;


	//4.replace,replace_if 替换元素
	//返回void. _if版本具备单参判别式.
	std::cout << "\n4.replace:\n";
	vec.clear();

	common::insert_element(vec, 2, 7);
	common::insert_element(vec, 4, 9);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::replace(std::begin(vec), std::end(vec), 6, 42);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::replace_if(std::begin(vec), std::end(vec), [](int i) 
	{
		if (i<5)
		{
			return true;
		}

		return false;
	},
		0);

	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;


	//5.replace_copy 把源区间内的元素复制到另一个区间的同时把旧值替换为新值.
	std::cout << "\n5.replace_copy:\n";
	vec.clear();

	common::insert_element(vec, 2, 6);
	common::insert_element(vec, 4, 9);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//输出vec内元素到cout并替换其中等于5的元素为55
	std::replace_copy(std::begin(vec), std::end(vec),
		std::ostream_iterator<int>(std::cout, ""),
		5,
		55);
	std::cout << std::endl;

	//输出vec内元素到cout并替换其中为偶数的元素
	std::replace_copy_if(std::begin(vec), std::end(vec),
		std::ostream_iterator<int>(std::cout, " "),
		[](int i)
	{
		if (i % 2 == 0)
		{
			return true;
		}

		return false;
	},
		0);

	std::cout << "\nat last vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;
}

int maindaily0529()
{
	func_algor_0529();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}