//daily0326
//���ڸ㶨��С��������.�侲����֣�Ŭ��.

/************************************************************************/
/* 
1.C��POSIX����Ĵ�ͳ��ʹ�õ�date/time����������<ctime>ͷ�ļ��У��ɲο�C++��׼��P158.
2.��ƪ��Ҫ�漰system_clock��timepoint��time_t/tm�Ļ�ת.


*/
/************************************************************************/

#include <iostream>
#include <chrono>
#include <string>
#include <ctime>


std::string sc_tp_2_str(const std::chrono::system_clock::time_point &tp)
{
	std::time_t t = std::chrono::system_clock::to_time_t(tp);
	std::string s = std::ctime(&t);

	s.resize(s.size()-1);
	return s;
}

std::chrono::system_clock::time_point t_2_sc_tp(int year,int mon,int day,int h,int m,int s = 0)
{
	std::tm t;
	t.tm_sec = s;
	t.tm_min = m;
	t.tm_hour = h;

	t.tm_mday = day;//0��31
	t.tm_mon = mon - 1;//0��11
	t.tm_year = year - 1;//since 1900
	t.tm_isdst = -1;//�Ƿ�����ʱ

	std::time_t tm = std::mktime(&t);
	if (-1==tm)
	{
		std::cout<< "no valid system time."<<std::endl;
		return std::chrono::system_clock::time_point();
	}

	auto tp = std::chrono::system_clock::from_time_t(tm);
	return tp;
}

//��ת����
void func_test_tm2sctp2tm()
{
	auto t1 = t_2_sc_tp(2018, 3, 27, 2, 1, 9);
	std::cout << sc_tp_2_str(t1) << std::endl;
}

int maindaily0326()
{
	func_test_tm2sctp2tm();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}