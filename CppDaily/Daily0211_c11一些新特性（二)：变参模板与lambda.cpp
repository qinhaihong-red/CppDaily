//daily0211
/************************************************************************/
/* 
1.变参模板（varadic template）
2.lambda

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <functional>

void func_print_manyargs()
{
	//这里需要定义一个空函数重载，以结束整个递归动作.
}


//支持任意类型参数输出的函数

template<typename T1,typename... T2>
void func_print_manyargs(const T1& t1,const T2&... t2)
{
	std::cout << t1 << std::endl;
	func_print_manyargs(t2...);//递归进行输出.递归终止与一个func_print_manyargs空函数重载.
}



void func_c11_featuer2_inside()
{
	//变参模板
	func_print_manyargs(1, "This is second", 99.99);

	//lambda这里不多说，只提一下lambda可以具有状态.
	int n = 99;
	std::cout << "before lambda, n:" << n << std::endl;

	auto f = [n]()mutable //这里会记录n的值，即使不运行f. 后续f的运行，都以首次记录的n为主.类似一个函数的静态局部变量.
	{
		std::cout << "in lambda,++n is:" << ++n << std::endl;
	};

	//f();
	std::cout << "after lambda,--n is:" << --n << std::endl;

	std::cout << std::endl << "run f() 3 times,see n:" << std::endl;

	f();
	f();
	f();
}


int maindaily0211()
{
	func_c11_featuer2_inside();

	std::string strInput;

	std::getline(std::cin, strInput);
	return 1;
}