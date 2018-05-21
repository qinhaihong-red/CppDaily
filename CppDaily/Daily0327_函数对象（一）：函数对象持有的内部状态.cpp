//daily0327
/************************************************************************/
/* 

���������뺯�����������ڣ�����������Ա���һ���ڲ�״̬��internal state,���о�̬�ֲ������ĺ�����.



*/
/************************************************************************/

#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
#include <list>
#include <iterator>

void func_lambda_state_inside()
{
	int a = 10, b = 99;
	std::cout << "a is:" << a << std::endl;
	std::cout << "b is:" << b << std::endl;
	auto func = [a, &b]() //���ڴ�ֵ����a��ֵʼ���Ǿ���lambda����޸ĵ��Ǹ�ֵ.
	{
		//std::cout << "\nafter ++,a is:" << ++a << std::endl;//�����Դ�ֵ��ʽ�����a,���ܶ�������޸�
		
		std::cout << "\ninside func,a is:" << a << std::endl;
		std::cout << "inside func after ++,b is:" << ++b << std::endl;
	};
	a = 50;
	b = 200;
	std::cout << "a is:" << a << std::endl;
	std::cout << "b is:" << b << std::endl;

	func();
	func();

	auto func2 = [a, &b]() mutable 
	{
		//����mutable�����Σ�
		//func2�߱��޸ĳ���״̬������
		//��������еĿ��޸ĵ�a��ֵ��50������������func2�ⲿ��a��Ϊ��80,
		//���Ǻ�����������a�ڲ�״̬Ϊ׼.

		std::cout << "\ninside func2 after ++,a is:" << ++a << std::endl;
		std::cout << "inside func2 after ++,b is:" << ++b << std::endl;
	};
	a = 80;

	std::cout << "\na is:" << a << std::endl;
	std::cout << "b is:" << b << std::endl;

	func2();
	func2();
}

class IntSeq
{
public:
	IntSeq(int val=0);
	~IntSeq() {}

	int operator() ();

private:
	int m_nInitVal;
};

IntSeq::IntSeq(int val) :m_nInitVal(val)
{

}

int IntSeq::operator()()
{
	return ++m_nInitVal;
}

template<typename T>
void print_T(const T &t)
{
	for (auto &i : t)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void func_functor_interalstate_inside()
{
	std::list<int> li;

	std::generate_n(std::back_inserter(li), 9, IntSeq(9));
	print_T(li);

	//���next����python�е�nextһ��
	std::generate(std::next(li.begin())/*start,��*/, std::prev(li.end())/*end,����*/, IntSeq(90));
	print_T(li);



	IntSeq seq(1);
	std::generate_n(std::back_inserter(li), 5, seq);
	print_T(li);
	//�����Ǵ�ֵ�ķ�ʽ����functor��seq״̬����ı�
	//��������print���ӵ�����һ��.
	std::generate_n(std::back_inserter(li), 5, seq);
	print_T(li);

}


int maindaily0327()
{
	func_lambda_state_inside();
	std::cout << std::endl;
	func_functor_interalstate_inside();
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}