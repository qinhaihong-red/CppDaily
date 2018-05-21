//daily0412
/************************************************************************/
/* 
某些算法会要求输入两个区间（犹如变换：从一个空间到另一个空间的映射）：
1.首个区间需要完全确定（左闭右开）
2.第二个区间只要指定开始，结束的位置依据首个区间的结束位置为准.

因此要注意，需保证第二个区间大于等于第一个区间.


*/
/************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

void func_algor_2_interval()
{
	std::vector<int> vec = {1,3,5,7,9};
	std::list<int>    li = {1,3,5,7,9};

	//1.比较时，需要两个区间
	if (std::equal(vec.begin(),vec.end(),li.begin()))
	{
		std::cout << "vec equals to li." << std::endl;
	}
	else
	{
		std::cout << "vec not equals to li." << std::endl;

	}

	//2.从另一个容器拷贝的另一个空间
	std::list<int> d_li;
	
	//注意！此种写法不可行，导致运行时错误！
	//需自己保证容器长度！
	//std::copy(vec.begin(),vec.end(),d_li.begin());
	
	//改写为：
	//1.先分配足够空间
	d_li.resize(vec.size(), 0);
	std::copy(vec.begin(), vec.end(), d_li.begin());

	//2.使用后向迭代器
	std::copy(vec.begin(),vec.end(),std::back_inserter(d_li));

	for (auto &i:d_li)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}


int maindaily0412()
{
	func_algor_2_interval();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}