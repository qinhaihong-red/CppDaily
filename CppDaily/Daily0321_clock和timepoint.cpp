//daily0321
/************************************************************************/
/* 
clock��timepoint

һ. clock
1.clock�����������:epoch,��ʱ�ӵ���ʼ��; ratio����ʱ�ӵ�ʱ�䵥λ�����������ȣ�
2.�������͵�ʱ�ӣ�
	system_clock:���������е�ϵͳʵʱʱ��
	steady_clock:�ȶ�ʱ�ӣ�����ʱ�ӵ�����Ӱ��. �����ڼ�ʱ����.
	high_resolution_clock:ʱ�䵥λ��С�����ȷ��ʱ��

��. timepoint
1.ʱ�����clock���͹�������clock��epoch+��ʱ��ʱ�䵥λ��duration
2.ʱ�������㣺�����������߼��Ƚ�

*/
/************************************************************************/

#include <chrono>
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

template<typename C>
void print_clock(const std::string & strClock)
{
	//��ӡ��3��ʱ�ӵ�ʱ�侫��
	std::cout << strClock<<" ����Ϊ:";

	typedef typename C::period P;//��ʱ�ӵ�ʱ�䵥λ
	if (std::ratio_less_equal<P,std::milli>::value)//ʱ�ӵ�ʱ�䵥λС�ں���
	{
		typedef typename std::ratio_multiply<P, std::kilo>::type TT;//����1000�����������Ժ���Ϊ��λչʾ
		std::cout << std::fixed << double(TT::num) / TT::den << " ����." << std::endl;
	}
	else
	{
		std::cout << std::fixed << double(P::num) / P::den << " ��." << std::endl;
	}

	std::cout << "�Ƿ�Ϊ�ȶ�(steady)ʱ��:" << std::boolalpha << C::is_steady << std::endl;
}


void func_clock_inside()
{
	print_clock<std::chrono::system_clock>("system_clock");
	print_clock<std::chrono::steady_clock>("steady_clock");
	print_clock<std::chrono::high_resolution_clock>("high_resolution_clock");
}



std::string asString(const std::chrono::system_clock::time_point &tp)
{
	//ֻ��system_clock���ṩ�˶�time_t��ת��
	std::time_t t = std::chrono::system_clock::to_time_t(tp);
	std::string ts = std::ctime(&t);//ת�ɿɶ����ַ���
	ts.resize(ts.size() - 1);//��ȥ���з�
	return ts;
}

void func_system_clock_inside()
{
	//չʾ��system_clock��epoch,timepoint,���ʱ��㣨δ��������Сʱ��㣨��ȥ��
	
	std::cout << "\nsystem_clock info:" << std::endl;

	std::chrono::system_clock::time_point tp;//Ĭ�Ϲ��캯��������ʱ�����Ǹ�ʱ�ӵ�epoch
	//�ù��캯����ͬ�ڣ�
	std::chrono::time_point<std::chrono::system_clock> tp2;
	std::cout << "tp is:" << asString(tp) << std::endl;
	std::cout << "\ntp2 is:" << asString(tp2) << std::endl;

	auto now = std::chrono::system_clock::now();
	std::cout << "\nnow is:" << asString(now) << std::endl;

	//msvc����֧��ʱ�ӵ�������Сʱ���.
	//tp = std::chrono::system_clock::min
}


int	maindaily0321()
{
	func_clock_inside();
	func_system_clock_inside();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}