//daily0319
/************************************************************************/
/* 
ratio 可以进行编译期的分数运算，这样不仅提升效率，而且能检查溢出以及除0的问题.
ratio 是duration/timepoint的基础.

1.ratio的表示与运算
2.ratio的比较

*/
/************************************************************************/


#include <ratio>
#include <iostream>
#include <string>
#include <numeric>

void func_ratio_inside()
{
	typedef std::ratio<5, 3> FiveThirds;//模板参数接受正负号整数类型
	FiveThirds ft;
	std::cout << "5 of 3 is:" << std::endl;
	std::cout << ft.num << "/" << ft.den << std::endl;
	std::cout << "or (because they are static memebers):" << std::endl;
	std::cout << FiveThirds::num << "/" << FiveThirds::den << std::endl;

	typedef std::ratio<25, 15> AlsoFiveThirds;
	std::cout << "\n25 of 15 is:" << std::endl;
	std::cout << AlsoFiveThirds::num << "/" << AlsoFiveThirds::den << std::endl;


	//1.ratio的加减乘除算术运算
	typedef std::ratio<1, 4> Quater;
	typedef std::ratio<3, 4> TriQuater;

	//加法
	std::cout << "\nThe result of 1/4 add 3/4 is:" << std::endl;
	std::cout << std::ratio_add<Quater, TriQuater>::num << "/" << std::ratio_add<Quater, TriQuater>::den << std::endl;

	//减法
	std::cout << "\nThe result of 1/4 minus 3/4 is:" << std::endl;
	std::ratio_subtract<Quater, TriQuater>::type minus_result;
	std::cout << minus_result.num << "/" << minus_result.den << std::endl;

	//乘法
	std::cout << "\nThe result of 1/4 multi 3/4 is:" << std::endl;
	std::ratio_multiply<Quater, TriQuater>::type multi_result;
	std::cout << multi_result.num << "/" << multi_result.den << std::endl;

	//除法
	std::cout << "\nThe result of 1/4 divide 3/4 is:" << std::endl;
	std::ratio_divide<Quater, TriQuater>::type divide_result;
	std::cout << divide_result.num << "/" << divide_result.den << std::endl;


	//2.等于，大于...逻辑比较运算.
	typedef std::ratio<4, 2> Two;
	typedef std::ratio<2> AlsoTwo;//第二个参数默认为1
	typedef std::ratio<0> Zero;

	Two two;
	AlsoTwo a_two;
	std::cout << "\n4/2 equals 2 is:" << std::boolalpha << std::ratio_equal<Two, AlsoTwo>::value << std::endl;

	std::cout << "\n2 is greater than 0 is:" << std::boolalpha << std::ratio_greater<Two, Zero>::value << std::endl;

	//3.非法运算检测

	//--除0检查
	//编译无法通过
	//错误	C2338	zero denominator	
	//std::cout << "\n2 divide 0 is:" << std::ratio_divide<Two, Zero>::num << std::endl;

	//--溢出检查
	//编译无法通过
	//C2338	integer arithmetic overflow
	//std::cout << "\n2 multiply long long max is:" << std::ratio_multiply< std::ratio<1,std::numeric_limits<long long>::max()>, std::ratio<1, 2> >::den<< std::endl;
}


int	maindaily0319()
{
	func_ratio_inside();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}