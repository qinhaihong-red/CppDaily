//daily0313
/************************************************************************/
/* 
type_traits和type_utility,提供了：
1.查询模板类型信息的接口
2.修饰模板类型的接口

为模板编程，尤其对判别模板类型信息，提供了便利.

*/
/************************************************************************/

#include <iostream>
#include <type_traits>
#include <string>

//1.希望对整数类型和浮点数类型进行分别处理.
//如果没有type_traits，那么需编写多个重载.

template<typename T>
void foo_impl(T t, std::true_type)
{
	std::cout << "输入了整数 : " << t << std::endl;
}


template<typename T>
void foo_impl(T t,std::false_type)
{
	std::cout << "输入了浮点数 : " << t << std::endl;
}

template<typename T>
void foo(T t)
{
	foo_impl(t, std::is_integral<T>());
	//所有对模板类型信息判断的is_xxx<T>接口，均返回true_type或者false_type.
	//而 is_integral<T>::value，则返回true 或 false.
}

//2.处理共通类型
/************************************************************************/
/* 
如：
template<typename T1,typename T2>
??? min(const T1& t1,const T2& t2)
*/
/************************************************************************/
template<typename T1,typename T2>
typename std::common_type<T1, T2>::type min(const T1& t1, const T2& t2)
{
	return t1 < t2 ? t1 : t2;
}


template<typename T>
void print_type(T t)
{
	if (std::is_integral<T>::value)
	{
		std::cout << "(intergral type.)" << std::endl;
	}
	else if(std::is_floating_point<T>::value)
	{
		std::cout << "(floating type.)" << std::endl;
	}
}


void func_type_traits_inside()
{
	//识别整数或浮点数的输入
	int a = 99;
	short b = 16;

	float c = 99;
	double d = 16;

	foo(a);//int
	foo(c);//float

	foo(b);//short
	foo(d);//double

	std::cout << std::endl;
	
	//处理共通类型
	auto r = min(a, d);

	std::cout << "int a = 99;double d = 16; the min of a,d is:" << r  << std::endl;
	print_type(r);

	auto r2 = min(a, b);
	std::cout << "int a = 99;short b = 16; the min of a,b is:" << r2 << std::endl;
	print_type(r2);
}




int maindaily0313()
{

	func_type_traits_inside();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}