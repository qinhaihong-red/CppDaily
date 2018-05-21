//daily0314
/************************************************************************/
/* 
type_traits:
1.���ε������б�ʽ
2.���Լ������͹�ϵ��traits
3.�������η�
*/
/************************************************************************/

#include <iostream>
#include <string>
#include <type_traits>


void func_type_traits_inside2()
{

	//1.���������б�ʽ
	//ʾ����is_const<T>�����Լ�鴫��������Ƿ�Ϊconst

	std::cout << "1.���������б�ʽ:" << std::endl;
	typedef int T;
	std::cout << "(Here T means int.)" << std::endl;
	std::cout << "std::is_const<T>::value :" << std::boolalpha << std::is_const<T>::value << std::endl;
	std::cout << "std::is_const<const volatile T>::value :" << std::boolalpha << std::is_const<const volatile T>::value << std::endl;

	std::cout << "std::is_const<T* const>::value :" << std::boolalpha << std::is_const<T* const>::value << std::endl;

	std::cout << "std::is_const<const T*>::value :" << std::boolalpha << std::is_const<const T*>::value << std::endl;

	std::cout << "std::is_const<const T&>::value :" << std::boolalpha << std::is_const<const T&>::value << std::endl;

	std::cout << "std::is_const<T[3]>::value :" << std::boolalpha << std::is_const<T[3]>::value << std::endl;

	std::cout << "std::is_const<const T[3]>::value :" << std::boolalpha << std::is_const<const T[3]>::value << std::endl;

	//2.˫�������͹�ϵ����traits
	//ʾ����is_assignable���Լ������2�Ƿ���Ը�ֵ������1
	//is_constructible���Լ������2�Ƿ���Գ�ʼ������1

	std::cout << "2.˫�������͹�ϵ����:" << std::endl;
	//��ֵ
	//��һ����������none class����Զ���false_type
	std::cout << "std::is_assignable<T,T>::value :" << std::boolalpha << std::is_assignable<T, T>::value << std::endl;

	std::cout << "std::is_assignable<T&,T>::value :" << std::boolalpha << std::is_assignable<T&, T>::value << std::endl;

	std::cout << "std::is_assignable<T&&,T>::value :" << std::boolalpha << std::is_assignable<T&&, T>::value << std::endl;

	std::cout << "std::is_assignable<const T&&,T>::value :" << std::boolalpha << std::is_assignable<const T&&, T>::value << std::endl;

	std::cout << "std::is_assignable<const char *,std::string>::value :" << std::boolalpha << std::is_assignable<const char *, std::string>::value << std::endl;

	std::cout << "std::is_assignable<std::string,const char *>::value :" << std::boolalpha << std::is_assignable<std::string, const char *>::value << std::endl;

	//��ʼ��
	std::cout << " std::is_constructible<long,T> :" << std::boolalpha << std::is_constructible<long, T>::value << std::endl;

	std::cout << " std::is_constructible<void*,T> :" << std::boolalpha << std::is_constructible<void*, T>::value << std::endl;

	std::cout << "std::is_constructible<std::string,const char *>::value :" << std::boolalpha << std::is_constructible<std::string, const char *>::value << std::endl;

	//3.��������
	//���ݴ��������T���������Σ������µ�����
	std::cout << "3.�������Σ�" << std::endl;

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