//daily0411
/************************************************************************/
/* 

算法大概分为查找，排序，数值计算，变换等等.
充分体现了 gp 模式的强大功力.
注意输入到算法的区间是半开区间：[ )，即左闭右开区间.

*/
/************************************************************************/


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void func_algor_simple()
{
	std::vector<int> vec = { 25,3,9,44,65,1,7 };
	auto minpos = std::min_element(vec.begin(), vec.end());
	std::cout << "min elem of vec is: " << *minpos << std::endl;

	auto maxpos = std::max_element(vec.begin(), vec.end());
	std::cout << "max elem of vec is: " << *maxpos << std::endl;

	std::cout << "\nbefore sorted,vec is: " << std::endl;
	for (auto &i:vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//排序
	std::sort(vec.begin(),vec.end());

	std::cout << "\nafter sorted,vec is: " << std::endl;
	for (auto &i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//find
	auto pos3 = std::find(vec.begin(), vec.end(), 3);
	std::reverse(pos3, vec.end());
	std::cout << "\nafter reversed,vec is: " << std::endl;
	for (auto &i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

}

int maindaily0411()
{
	func_algor_simple();
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}