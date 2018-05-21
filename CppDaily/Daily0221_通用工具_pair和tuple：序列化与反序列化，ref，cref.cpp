//daily0221
/************************************************************************/
/* 
通用工具：
pair和tuple

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <utility>
#include <tuple>


typedef std::pair<int, double> IntFloatPair;

void func_util_pair_tuple_inside()
{
	IntFloatPair p(1,2.3);//浮点型字符串字面量通常为double型
	std::cout << "p.first:" << std::get<0>(p) << std::endl;
	std::cout << "p.second:" << std::get<1>(p) << std::endl;
	std::cout << "sizeof p is :" << std::tuple_size<IntFloatPair>::value << std::endl;
	std::cout << "the second type of IntFloatPair is double:" << std::boolalpha << ( typeid( std::tuple_element<1, IntFloatPair>::type ) == typeid (double ) )<< std::endl;

	std::cout << std::endl;

	 p = std::make_pair(3, 4.5);
	 std::cout << "p.first:" << std::get<0>(p) << std::endl;
	 std::cout << "p.second:" << std::get<1>(p) << std::endl;

	 int i{};//init with 0 .
	 std::cout << std::endl << "i is :" << i << std::endl;
	 auto p2 = std::make_pair(std::ref(i), std::ref(i));
	 ++p2.first;
	 ++p2.second;

	 std::cout << "now i is:" << i << std::endl;

	 auto p3 = std::make_pair('x', 'y');
	 char c{};
	 std::cout << std::endl << "c is :" << c << std::endl;
	 std::tie(std::ignore, c) = p3;
	 std::cout << "now c is:" << c << std::endl;

}


int maindaily0221()
{
	func_util_pair_tuple_inside();

	std::string strInput;
	std::getline(std::cin, strInput);
	return 0;
}