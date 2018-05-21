//daily0210
/************************************************************************/
/* 
C11一些新特性：
1.一致初始化和初值列表
2.foreach循环
3.右值引用和移动语义(move semantics，避免无需要的拷贝和临时对象)
*/
/************************************************************************/

#include <iostream>
#include <string>
#include <vector>

void print_with_inilist(std::initializer_list<int> vals)
{
	for (auto &i:vals)
	{
		std::cout << i << std::endl;
	}
}

void func_c11feature_inside()
{
	//一致初始化:使用{ }对任何变量进行一致初始化
	int num{5};
	int vas[] = {1,2,3,4,5};
	std::vector<int> vec{ 6,7,8,9,10 };

	std::cout << num << std::endl;
	//类似迭代器的循环
	for (auto &i:vas)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (auto &i:vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//空的{}有默认初始化功能.
	//这个比较好用
	int num2{};
	int *p{};

	std::cout <<"num2==0 :" <<std::boolalpha <<(num2==0)<< std::endl;
	std::cout << "p==nullptr :"<<std::boolalpha << (p == nullptr) << std::endl;

	std::cout << std::endl << "初值列表：" << std::endl;
	print_with_inilist({ 100,99,88,77 });

}



int maindaily0210()
{
	func_c11feature_inside();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 1;
}