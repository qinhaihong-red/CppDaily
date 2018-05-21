//daily0314
/************************************************************************/
/* 
type_traits:
1.单参的类型判别式
2.用以检验类型关系的traits
3.类型修饰符
*/
/************************************************************************/

#include <iostream>
#include <string>
#include <type_traits>


void func_type_traits_inside2()
{

	//1.单参类型判别式
	//示例：is_const<T>，用以检查传入的类型是否为const

	std::cout << "1.单参类型判别式:" << std::endl;
	typedef int T;
	std::cout << "(Here T means int.)" << std::endl;
	std::cout << "std::is_const<T>::value :" << std::boolalpha << std::is_const<T>::value << std::endl;
	std::cout << "std::is_const<const volatile T>::value :" << std::boolalpha << std::is_const<const volatile T>::value << std::endl;

	std::cout << "std::is_const<T* const>::value :" << std::boolalpha << std::is_const<T* const>::value << std::endl;

	std::cout << "std::is_const<const T*>::value :" << std::boolalpha << std::is_const<const T*>::value << std::endl;

	std::cout << "std::is_const<const T&>::value :" << std::boolalpha << std::is_const<const T&>::value << std::endl;

	std::cout << "std::is_const<T[3]>::value :" << std::boolalpha << std::is_const<T[3]>::value << std::endl;

	std::cout << "std::is_const<const T[3]>::value :" << std::boolalpha << std::is_const<const T[3]>::value << std::endl;

	//2.双参数类型关系检验traits
	//示例：is_assignable用以检查类型2是否可以赋值给类型1
	//is_constructible用以检查类型2是否可以初始化类型1

	std::cout << "2.双参数类型关系检验:" << std::endl;
	//赋值
	//第一个类型若是none class，永远获得false_type
	std::cout << "std::is_assignable<T,T>::value :" << std::boolalpha << std::is_assignable<T, T>::value << std::endl;

	std::cout << "std::is_assignable<T&,T>::value :" << std::boolalpha << std::is_assignable<T&, T>::value << std::endl;

	std::cout << "std::is_assignable<T&&,T>::value :" << std::boolalpha << std::is_assignable<T&&, T>::value << std::endl;

	std::cout << "std::is_assignable<const T&&,T>::value :" << std::boolalpha << std::is_assignable<const T&&, T>::value << std::endl;

	std::cout << "std::is_assignable<const char *,std::string>::value :" << std::boolalpha << std::is_assignable<const char *, std::string>::value << std::endl;

	std::cout << "std::is_assignable<std::string,const char *>::value :" << std::boolalpha << std::is_assignable<std::string, const char *>::value << std::endl;

	//初始化
	std::cout << " std::is_constructible<long,T> :" << std::boolalpha << std::is_constructible<long, T>::value << std::endl;

	std::cout << " std::is_constructible<void*,T> :" << std::boolalpha << std::is_constructible<void*, T>::value << std::endl;

	std::cout << "std::is_constructible<std::string,const char *>::value :" << std::boolalpha << std::is_constructible<std::string, const char *>::value << std::endl;

	//3.类型修饰
	//根据传入的类型T，加以修饰，生成新的类型
	std::cout << "3.类型修饰：" << std::endl;

	T i = 1;
	std::cout << "i is:" << i << std::endl;
	std::add_const<T>::type c_i = 5;
	//++c_i;//you cann't do that. 
	std::add_lvalue_reference < T>::type lr_i = i;
	++lr_i;

	std::cout << "now i is:" << i << std::endl;

	std::add_pointer<T>::type p_i = &i;
	++(*p_i);
	std::cout << "now i is:" << i << std::endl;

	typedef const int c_T;
	c_T c_i2 = 55;

	std::remove_const<c_T>::type i3 = 99;
	std::cout << "now i3 is:" << ++i3 << std::endl;
}


int	maindaily0314()
{
	func_type_traits_inside2();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}