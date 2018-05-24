//daily0523
/************************************************************************/
/* 
以下算法用于检查指定区间，是否符合某种条件：
1. is_sorted ,is_sorted_until
	前者用于判断指定区间是否有序（包含指定判别式的版本），后者返回区间内第一个破坏有序
	元素的迭代器.

2. is_partitioned, partition_point
	前者用于判断指定区间是否被单参判别式所划分.
	如有划分，可用后者返回被划分的首个元素的迭代器.

3. is_heap, is_heap_until
	前者判断指定区间是否形成一个heap，意味着begin迭代器是最大的元素之一了.
	后者返回首个破坏形成heap的元素的迭代器.

4. all_of, any_of, none_of
	判断区间内元素是否满足单参判别式的条件.

*/
/************************************************************************/
#include "common/common.h"

void func_algor_0523()
{
	//1.is_sorted 和 is_sorted_until

	std::vector<int> vec = {1,1,2,3,4,5,6,7,8,9};
	std::cout << "1.is_sorted:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	if (std::is_sorted(std::begin(vec),std::end(vec)))
	{
		std::cout << "vec is sorted.\n";
	}
	else
	{
		std::cout << "vec is not sorted.\n";
	}

	std::map<int, std::string> mp = { {1,"Bill"},{2,"Jim"},{3,"Nico"},{4,"Liu"},{5,"Ai"} };

	std::cout << "\nnow mp is:\n";
	common::print_elems(mp);
	std::cout << std::endl;

	auto funComName = [](const decltype(mp)::value_type &v1, const decltype(mp)::value_type &v2)
	{
		return v1.second < v2.second;
	};

	if (std::is_sorted(std::begin(mp),std::end(mp),funComName))
	{
		std::cout << "mp is sorted.\n";
	}
	else
	{
		std::cout << "mp is not sorted.\n";
		std::cout << "find first unsorted element as below:\n";

		auto pos = std::is_sorted_until(std::begin(mp), std::end(mp), funComName);
		std::cout << "first unsorted element is :" << pos->second << std::endl;
	}

	//2.is_partitioned和partition_point
	vec.clear();
	vec = {5,3,9,1,3,4,8,2,6};
	std::cout << "\n2.is_partitioned:\n";
	std::cout << "now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	auto funEvenOdd = [](int i)
	{
		return i % 2 == 0;
	};

	if (std::is_partitioned(std::begin(vec),std::end(vec),funEvenOdd))
	{
		
		std::cout << "vec is partitioned by even and odd.\n";
		
		auto pos = std::partition_point(std::begin(vec), std::end(vec), funEvenOdd);
		std::cout << "the first partition point is: "<<*pos<<std::endl;
		
	}
	else
	{
		std::cout << "vec is not partitioned by even and odd.\n";

	}

	//3.is_heap 和 is_heap_until
	vec.clear();
	vec = {9,8,7,7,7,5,4,3,1};
	std::vector<int> vec2 = {5,3,2,1,4,7,9,8,6};

	std::cout << "\n3.is_heap:\n";
	std::cout << "now vec and vec2 are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(vec2);
	std::cout << std::endl;

	std::cout << "vec is heap:" << std::boolalpha << std::is_heap(std::begin(vec), std::end(vec)) << std::endl;
	std::cout << "vec2 is heap:" << std::boolalpha << std::is_heap(std::begin(vec2), std::end(vec2)) << std::endl;

	auto pos2 = std::is_heap_until(std::begin(vec2), std::end(vec2));
	if (pos2!=std::end(vec2))
	{
		std::cout << "firs non-heap element of vec2 is:" << *pos2 << std::endl;
	}

	//4.all_of,any_of,none_of
	std::cout << "\n4.all_of:\n";
	vec.clear();
	common::insert_element(vec, 1, 9);
	std::cout << "now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::cout << "all even?: " << std::boolalpha << std::all_of(std::begin(vec), std::end(vec), funEvenOdd) << std::endl;
	std::cout<<"any even?: "<< std::boolalpha << std::any_of(std::begin(vec), std::end(vec), funEvenOdd) << std::endl;
	std::cout <<"none even?: " << std::boolalpha << std::none_of(std::begin(vec), std::end(vec), funEvenOdd) << std::endl;

}

int maindaily0523()
{
	func_algor_0523();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}