//daily0319
/************************************************************************/
/* 
ratio ���Խ��б����ڵķ������㣬������������Ч�ʣ������ܼ������Լ���0������.
ratio ��duration/timepoint�Ļ���.

1.ratio�ı�ʾ������
2.ratio�ıȽ�

*/
/************************************************************************/


#include <ratio>
#include <iostream>
#include <string>
#include <numeric>

void func_ratio_inside()
{
	typedef std::ratio<5, 3> FiveThirds;//ģ�����������������������
	FiveThirds ft;
	std::cout << "5 of 3 is:" << std::endl;
	std::cout << ft.num << "/" << ft.den << std::endl;
	std::cout << "or (because they are static memebers):" << std::endl;
	std::cout << FiveThirds::num << "/" << FiveThirds::den << std::endl;

	typedef std::ratio<25, 15> AlsoFiveThirds;
	std::cout << "\n25 of 15 is:" << std::endl;
	std::cout << AlsoFiveThirds::num << "/" << AlsoFiveThirds::den << std::endl;


	//1.ratio�ļӼ��˳���������
	typedef std::ratio<1, 4> Quater;
	typedef std::ratio<3, 4> TriQuater;

	//�ӷ�
	std::cout << "\nThe result of 1/4 add 3/4 is:" << std::endl;
	std::cout << std::ratio_add<Quater, TriQuater>::num << "/" << std::ratio_add<Quater, TriQuater>::den << std::endl;

	//����
	std::cout << "\nThe result of 1/4 minus 3/4 is:" << std::endl;
	std::ratio_subtract<Quater, TriQuater>::type minus_result;
	std::cout << minus_result.num << "/" << minus_result.den << std::endl;

	//�˷�
	std::cout << "\nThe result of 1/4 multi 3/4 is:" << std::endl;
	std::ratio_multiply<Quater, TriQuater>::type multi_result;
	std::cout << multi_result.num << "/" << multi_result.den << std::endl;

	//����
	std::cout << "\nThe result of 1/4 divide 3/4 is:" << std::endl;
	std::ratio_divide<Quater, TriQuater>::type divide_result;
	std::cout << divide_result.num << "/" << divide_result.den << std::endl;


	//2.���ڣ�����...�߼��Ƚ�����.
	typedef std::ratio<4, 2> Two;
	typedef std::ratio<2> AlsoTwo;//�ڶ�������Ĭ��Ϊ1
	typedef std::ratio<0> Zero;

	Two two;
	AlsoTwo a_two;
	std::cout << "\n4/2 equals 2 is:" << std::boolalpha << std::ratio_equal<Two, AlsoTwo>::value << std::endl;

	std::cout << "\n2 is greater than 0 is:" << std::boolalpha << std::ratio_greater<Two, Zero>::value << std::endl;

	//3.�Ƿ�������

	//--��0���
	//�����޷�ͨ��
	//����	C2338	zero denominator	
	//std::cout << "\n2 divide 0 is:" << std::ratio_divide<Two, Zero>::num << std::endl;

	//--������
	//�����޷�ͨ��
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