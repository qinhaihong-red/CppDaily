//daily0313
/************************************************************************/
/* 
type_traits��type_utility,�ṩ�ˣ�
1.��ѯģ��������Ϣ�Ľӿ�
2.����ģ�����͵Ľӿ�

Ϊģ���̣�������б�ģ��������Ϣ���ṩ�˱���.

*/
/************************************************************************/

#include <iostream>
#include <type_traits>
#include <string>

//1.ϣ�����������ͺ͸��������ͽ��зֱ���.
//���û��type_traits����ô���д�������.

template<typename T>
void foo_impl(T t, std::true_type)
{
	std::cout << "���������� : " << t << std::endl;
}


template<typename T>
void foo_impl(T t,std::false_type)
{
	std::cout << "�����˸����� : " << t << std::endl;
}

template<typename T>
void foo(T t)
{
	foo_impl(t, std::is_integral<T>());
	//���ж�ģ��������Ϣ�жϵ�is_xxx<T>�ӿڣ�������true_type����false_type.
	//�� is_integral<T>::value���򷵻�true �� false.
}

//2.����ͨ����
/************************************************************************/
/* 
�磺
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
	//ʶ�������򸡵���������
	int a = 99;
	short b = 16;

	float c = 99;
	double d = 16;

	foo(a);//int
	foo(c);//float

	foo(b);//short
	foo(d);//double

	std::cout << std::endl;
	
	//����ͨ����
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