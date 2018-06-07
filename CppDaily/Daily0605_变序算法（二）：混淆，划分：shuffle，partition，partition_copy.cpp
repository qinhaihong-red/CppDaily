//daily0605
/************************************************************************/
/* 
变序算法二：

shuffle/random_shuffle:以随机数混淆元素.

partion/stable_partition:划分元素.将元素向前搬移.

partition_copy:在复制的过程中划分.

*/
/************************************************************************/


#include "common/common.h"
#include <cstdlib>
#include <random> //随机数

void func_algor_0605()
{
	//1.shuffle和random_shuffle
	//前者需要随机数引擎支持.
	//后者不带op的版本使用均匀分布随机数产生器来对区间进行混淆.
	//带op的版本则使用op产生随机数来对区间进行混淆.

	std::vector<int> vec;
	common::insert_element(vec, 1, 9);
	std::cout << "1.shuffle:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//random_shuffle默认使用均匀分布产生随机数
	std::random_shuffle(std::begin(vec), std::end(vec));
	common::print_elems(vec);
	std::cout << std::endl;


	//使用default_random_engin产生随机数
	std::default_random_engine dre;
	std::shuffle(std::begin(vec), std::end(vec), dre);
	common::print_elems(vec);
	std::cout << std::endl;

	//自定义op产生随机数
	auto func_randomOp = [](std::ptrdiff_t mx)
	{
		double tmp=0;
		tmp = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
		return static_cast<ptrdiff_t>(tmp*mx);
	};

	std::random_shuffle(std::begin(vec), std::end(vec), func_randomOp);
	common::print_elems(vec);
	std::cout << std::endl;

	//2.partition和stable_partition
	//划分元素.划分准则由单参判别式给出:即符合准则的元素划分到前部，不符合的划分到后部.
	//后者保证划分的过程中，保证被划分在一起的元素保持原序.
	//返回首个不符合准则元素的迭代器.

	vec.clear();
	std::list<int> li;
	common::insert_element(vec, 1, 9);
	common::insert_element(li, 1, 9);
	std::cout << "\n2.partition:\nnow vec and li are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(li);
	std::cout << std::endl;

	//针对同一个准则的划分，比较stalbe_partition和partition的区别.
	auto pos1 = std::partition(std::begin(vec), std::end(vec), [](int i) {return i % 2 == 0; });
	auto pos2 = std::stable_partition(std::begin(li), std::end(li), [](int i) {return i % 2 == 0; });


	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << "\nfirst odd element is:" << *pos1 << std::endl;

	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << "\nfirst odd element is:" << *pos2 << std::endl;


	//3.partition_copy
	//按准则把序列划分为两部分：符合准则的一部分复制到区间1，不符合准则的部分复制到区间2.
	//返回一个pair,内含区间1和区间2复制后的下一个元素.
	vec.clear();
	vec = {1,6,33,7,22,4,11,33,2,7,0,42,5};
	std::cout << "\n3.partition_copy:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::vector<int> vec2;
	li.clear();

	std::partition_copy(std::begin(vec),std::end(vec),
		std::back_inserter(vec2),
		std::back_inserter(li),
		[](int i) {return i % 2 == 0; });

	std::cout << "\nnow vec2 and li are:\n";
	common::print_elems(vec2);
	std::cout << std::endl;
	common::print_elems(li);
	std::cout << std::endl;
}

int main0605()
{
	func_algor_0605();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}