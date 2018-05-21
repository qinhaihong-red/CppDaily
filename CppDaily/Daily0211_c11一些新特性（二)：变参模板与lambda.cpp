//daily0211
/************************************************************************/
/* 
1.���ģ�壨varadic template��
2.lambda

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <functional>

void func_print_manyargs()
{
	//������Ҫ����һ���պ������أ��Խ��������ݹ鶯��.
}


//֧���������Ͳ�������ĺ���

template<typename T1,typename... T2>
void func_print_manyargs(const T1& t1,const T2&... t2)
{
	std::cout << t1 << std::endl;
	func_print_manyargs(t2...);//�ݹ�������.�ݹ���ֹ��һ��func_print_manyargs�պ�������.
}



void func_c11_featuer2_inside()
{
	//���ģ��
	func_print_manyargs(1, "This is second", 99.99);

	//lambda���ﲻ��˵��ֻ��һ��lambda���Ծ���״̬.
	int n = 99;
	std::cout << "before lambda, n:" << n << std::endl;

	auto f = [n]()mutable //������¼n��ֵ����ʹ������f. ����f�����У������״μ�¼��nΪ��.����һ�������ľ�̬�ֲ�����.
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