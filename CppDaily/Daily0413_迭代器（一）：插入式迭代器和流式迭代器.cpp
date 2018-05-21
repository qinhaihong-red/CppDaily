//daily0413
/************************************************************************/
/* 
迭代器适配器.
根据作用对象的不同，迭代器适配器分为以下种类：
1.插入式迭代器(作用于容器)
2.流式迭代器（作用于输入输出流）
3.逆向迭代器（作用于容器）
4.移动迭代器（move semantic）


*/
/************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <iterator>


template<typename T>
void print_elems_0413(const T &t)
{
	for (auto &i:t)
	{
		std::cout << i << " ";
	}
}

void func_simple_inserter_test()
{
	std::list<int> li = {1,3,5,7,9};
	auto li_begin = li.begin(), li_end = li.end();


	//1.back insterter
	//适用于序列式容器：vector，list,deque，string
	std::vector<int> vec;
	std::copy(li_begin, li_end, std::back_inserter(vec));
	std::cout << "now vec is:\n";
	print_elems_0413(vec);


	//2.front inserter
	//适用于部分序列容器：foward_list,deque
	std::deque<int> deq;
	std::copy(li_begin, li_end, std::front_inserter(deq));
	std::cout << "\nnow deq is:\n";
	print_elems_0413(deq);

	//3.inserter
	//一般性的插入迭代器.
	//写法比较特殊，主要适用于关联式容器和无序容器
	std::set<int> st;
	std::copy(li_begin,li_end,std::inserter(st,st.begin()));
	
	std::cout << "\nnow set is:\n";
	print_elems_0413(st);
	std::cout << std::endl;
}

void func_simple_stream_iterator_test()
{
	std::vector<std::string> s_input;

	//输入到string中
	auto _b = std::istream_iterator<std::string>(std::cin), _e = std::istream_iterator<std::string>();

	std::copy(_b, _e, std::back_inserter(s_input));

	std::sort(s_input.begin(), s_input.end());

	//去重并输出到std::cout
	std::unique_copy(s_input.cbegin(), s_input.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));


	std::string strInput;
	std::getline(std::cin, strInput);
}





int maindaily0413()
{
	func_simple_inserter_test();
	func_simple_stream_iterator_test();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}