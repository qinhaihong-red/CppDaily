//daily0321
/************************************************************************/
/* 
clock和timepoint

一. clock
1.clock由两部分组成:epoch,该时钟的起始点; ratio，该时钟的时间单位（毫秒或者秒等）
2.三种类型的时钟：
	system_clock:关联至现行的系统实时时钟
	steady_clock:稳定时钟，不受时钟调整的影响. 适用于计时器等.
	high_resolution_clock:时间单位最小，即最精确的时钟

二. timepoint
1.时间点与clock类型关联：该clock的epoch+该时钟时间单位的duration
2.时间点的运算：算术运算与逻辑比较

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
	//打印出3种时钟的时间精度
	std::cout << strClock<<" 精度为:";

	typedef typename C::period P;//该时钟的时间单位
	if (std::ratio_less_equal<P,std::milli>::value)//时钟的时间单位小于毫秒
	{
		typedef typename std::ratio_multiply<P, std::kilo>::type TT;//扩大1000倍，即最终以毫秒为单位展示
		std::cout << std::fixed << double(TT::num) / TT::den << " 毫秒." << std::endl;
	}
	else
	{
		std::cout << std::fixed << double(P::num) / P::den << " 秒." << std::endl;
	}

	std::cout << "是否为稳定(steady)时钟:" << std::boolalpha << C::is_steady << std::endl;
}


void func_clock_inside()
{
	print_clock<std::chrono::system_clock>("system_clock");
	print_clock<std::chrono::steady_clock>("steady_clock");
	print_clock<std::chrono::high_resolution_clock>("high_resolution_clock");
}



std::string asString(const std::chrono::system_clock::time_point &tp)
{
	//只有system_clock才提供了对time_t的转换
	std::time_t t = std::chrono::system_clock::to_time_t(tp);
	std::string ts = std::ctime(&t);//转成可读的字符串
	ts.resize(ts.size() - 1);//略去换行符
	return ts;
}

void func_system_clock_inside()
{
	//展示出system_clock的epoch,timepoint,最大时间点（未来），最小时间点（过去）
	
	std::cout << "\nsystem_clock info:" << std::endl;

	std::chrono::system_clock::time_point tp;//默认构造函数给出的时间点就是该时钟的epoch
	//该构造函数等同于：
	std::chrono::time_point<std::chrono::system_clock> tp2;
	std::cout << "tp is:" << asString(tp) << std::endl;
	std::cout << "\ntp2 is:" << asString(tp2) << std::endl;

	auto now = std::chrono::system_clock::now();
	std::cout << "\nnow is:" << asString(now) << std::endl;

	//msvc还不支持时钟的最大和最小时间点.
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