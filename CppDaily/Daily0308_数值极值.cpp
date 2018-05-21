//daily0308
/************************************************************************/
/* 数值极值P115.
数值极值主要关注整数和浮点数所占用的位数，极值等等.
上述相关信息传统上包含于<climits>,<cfloat>等头文件中定义的相关常量.

自C++11起，借助统一的模板接口numeric_limits以及各类型的具体特化，可以用统一
的接口，表述不同具体数值类型的极值信息.接口清晰，使用方便.


*/
/************************************************************************/
#include <iostream>
#include <string>
#include <numeric>

void func_numeric_limits_inside()
{
	//由于numeric_limits的所有成员都被声明为static constexpr，所以可以在
	//编译期使用相关函数定义的常量

	long long E_Value = std::numeric_limits<int>::max();
	int a[std::numeric_limits<short>::max()];
	a[0] = 100;
	std::cout << ++ E_Value << std::endl;

	//整数类型的极值
	std::cout << std::endl;

	std::cout << "int max:" << std::numeric_limits<int>::max() << std::endl;
	std::cout << "short max:" << std::numeric_limits<short>::max() << std::endl;
	std::cout << "long max:" << std::numeric_limits<long>::max() << std::endl;

	//浮点类型极值
	std::cout << std::endl;
	std::cout << "float max:" << std::numeric_limits<float>::max() << std::endl;
	std::cout << "double max:" << std::numeric_limits<double>::max() << std::endl;
	std::cout << "long double max:" << std::numeric_limits<long double>::max() << std::endl;

	//查证char是否有符号类型
	std::cout << std::endl;
	std::cout << "is signed_char(char):" << std::numeric_limits<char>::is_signed << std::endl;
	std::cout << std::endl;


	//查证某类型是否特化
	std::cout << "is string specialized:" << std::numeric_limits<std::string>::is_specialized << std::endl;
}


int maindaily0308()
{

	func_numeric_limits_inside();
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}