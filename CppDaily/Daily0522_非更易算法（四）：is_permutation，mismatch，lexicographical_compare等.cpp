//daily0522
/************************************************************************/
/* 

继续非更易算法：
1.is_permutation: 判断两个不定序集合内所含元素是否相等

2.mismatch:查找两个序列中第一处不同

3.lexicographical_compare:以字典序检查两个序列是否存在小于关系


*/
/************************************************************************/

#include "common/common.h"


void func_algor_0522()
{
	//1.is_permutation
	std::vector<int> vec = {1,1,2,3,4,5,6,7,8,9};
	std::list<int> li = {1,9,8,7,6,5,4,3,2,1};
	std::deque<int> deq = {11,12,13,19,18,17,16,15,14,11};


	std::cout << "1.now vec, li, deq are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(li);
	std::cout << std::endl;
	common::print_elems(deq);
	std::cout << std::endl;

	if (std::is_permutation(std::begin(vec),std::end(vec),std::begin(li)))
	{
		std::cout << "vec and li have equal elements.\n";
	}
	else
	{
		std::cout << "vec and li do not have equal elements.\n";
	}

	auto func_bothEvenOdd = [](int i, int j)
	{
		return i % 2 == j % 2;
	};

	if (std::is_permutation(std::begin(vec),std::end(vec),std::begin(deq),func_bothEvenOdd))
	{
		std::cout << "\nvec and deq have same numbers of even and elements.\n";
	}
	else
	{
		std::cout << "\nvec and deq do not have same numbers of even and elements.\n";
	}

	//2.mismatch
	//返回一个pair，由两个序列内首个不同元素的一对迭代器组成.
	vec.clear();
	li.clear();

	vec = {1,2,3,4,5,6};
	li = {1,2,4,8,16,3};

	std::cout << "\n2.now vec, li are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(li);
	std::cout << std::endl;

	auto vals_pair = std::mismatch(std::begin(vec), std::end(vec), std::begin(li), std::less_equal<int>());
	if (vals_pair.first == std::end(vec))
	{
		std::cout << "vec and li are always equal or less.\n";
	}
	else
	{
		std::cout << "not less-or-equal:" << *vals_pair.first << " and " << *vals_pair.second << std::endl;
	}

	std::cout << "\n3.lexicographical_compare:\n";
	std::list<int> t1, t2, t3, t4;

	common::insert_element(t1, 1, 5);
	t2 = t3 = t4 = t1;

	t1.push_back(7);
	t3.push_back(2);
	t3.push_back(0);
	t4.push_back(2);

	std::vector<std::list<int>> vecLists;
	vecLists.insert(std::begin(vecLists), { t1,t2,t3,t4,t3,t1,t4,t2 });

	std::cout << "now vecLists are:\n";
	
	auto func_printVecList = [](const std::list<int> &j)
	{
		common::print_elems(j);
		std::cout << std::endl;
	};

	std::for_each(std::begin(vecLists), std::end(vecLists), func_printVecList);

	auto func_lessForVecLists = [](const std::list<int> &j, const std::list<int> &k)
	{
		return std::lexicographical_compare(std::begin(j), std::end(j), std::begin(k), std::end(k));
	};

	std::sort(std::begin(vecLists), std::end(vecLists), func_lessForVecLists);

	std::cout << "\nnow vecLists are:\n";
	std::for_each(std::begin(vecLists), std::end(vecLists), func_printVecList);

}

int maindaily0522()
{	
	func_algor_0522();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}