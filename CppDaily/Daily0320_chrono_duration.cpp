//daily0320
/************************************************************************/
/* 
chronoģ���е�duration�����Ա�ʾһ��ʱ��.

1.duration�Ĺ���
	duration<V,U>��ʾһ��ʱ�䳤�ȡ�������ȵĵ�λ��U��Ҳ����ration����ʾ�����������Ϊ��λ.
	V��һ����ֵ������λ����Ŀ��tick��

2.���㣺duration�ļӼ��˳����Լ��߼��Ƚ�

3.duration���໥ת��.
	--��λ�����޷�ת��ΪС��λ����Сʱ�����ӣ�
	--С��λת����λ����Ҫ����duration_castǿ��ת��

*/
/************************************************************************/

#include <ratio>
#include <chrono>
#include <iostream>
#include <string>

template<typename V,typename U>
std::ostream& operator << (std::ostream& os, const std::chrono::duration<V, U> &d)
{
	os << "[ " << d.count() << " �� " << U::num << "/" << U::den << "��. ]";

	return os;
}



void func_druation_inside()
{
	//1.duration�ı�ʾ
	typedef std::chrono::duration<int, std::ratio<1, 2>> HalfSecond;
	HalfSecond one_sec(2);
	std::cout << one_sec << std::endl;
	//rep��period�ֱ��ǳ����뵥λ������
	std::cout << "HalfSecond ���������� int :" << std::boolalpha << (typeid(HalfSecond::rep) == typeid(int)) << std::endl;
	std::cout << "HalfSecond ��λ������ std::ration<1,2>" << std::boolalpha << (typeid(HalfSecond::period) == typeid(std::ratio<1, 2>)) << std::endl;



	//2.����
	std::chrono::seconds s1(10);
	std::chrono::microseconds s2(10);
	auto s3 = s1 - s2;
	std::cout << "\ns1-s2 is:"<<s3 << std::endl;
	
	//3.�Ƚ�
	std::chrono::seconds chrono_one_sec(1);
	std::cout << "\none_sec(2) equal chrono_one_sec(1) is: "<<std::boolalpha << (one_sec == chrono_one_sec) << std::endl;

	std::cout << "s1 is greater than s2:" << std::boolalpha << (s1 > s2) << std::endl;


	//4.ת��
	//��תС��������
	std::chrono::seconds s4(1);
	std::chrono::microseconds s5 = s4;
	std::cout << "\ns5 is:"<<s5 << std::endl;

	s4 *= 60;
	std::cout << "now s4 is:" << s4 << std::endl;
	//Сת�󣬲�����
	//std::chrono::minutes m1 = s4;
	//��ͨ��ǿ��ת��
	std::chrono::minutes m1 = std::chrono::duration_cast<std::chrono::minutes>(s4);
	std::cout << "m1 is:" << m1 << std::endl;

	//ͨ��ת������һ�������ʾ������ʾΪСʱ,���ӣ���ͺ���

	std::chrono::milliseconds ms(7255042);
	std::chrono::hours split_h1 = std::chrono::duration_cast<std::chrono::hours>(ms);
	std::chrono::minutes split_m1 = std::chrono::duration_cast<std::chrono::minutes>(ms % std::chrono::hours(1));
	std::chrono::seconds split_s1 = std::chrono::duration_cast<std::chrono::seconds>(ms % std::chrono::minutes(1));
	std::chrono::milliseconds split_milli = std::chrono::duration_cast<std::chrono::milliseconds>(ms % std::chrono::seconds(1));

	std::cout << std::endl;
	std::cout<< "Сʱ:"<<split_h1 << std::endl;
	std::cout<<"����:"<< split_m1 << std::endl;
	std::cout << "��:" << split_s1 << std::endl;
	std::cout << "����:" << split_milli << std::endl;


	std::cout << std::endl;
}


int	maindaily0320()
{
	func_druation_inside();
	
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}