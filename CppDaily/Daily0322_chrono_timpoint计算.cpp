//daily0322
//开始两个月了!!!
/************************************************************************/
/* 
timpoint的算术计算与逻辑比较

需要注意：
chrono是个duration/timepoint库，不是一个完备的datetime库.

*/
/************************************************************************/

#include <chrono>
#include <string>
#include <iostream>
#include <ctime>


std::string print_sysclock_timepoint(const std::chrono::system_clock::time_point &tp)
{
	std::time_t t = std::chrono::system_clock::to_time_t(tp);
	
	std::string strTime = "Null";
	if (std::ctime(&t))
	{
		strTime = std::ctime(&t);
		if (!strTime.empty())
		{
			strTime.resize(strTime.size() - 1);
		}
	}
	//转成可读的字符串



	return strTime;
}


void func_timepoint_operation_inside()
{
	typedef std::chrono::duration<int, std::ratio<60*60*24>> OneDay;
	std::chrono::system_clock::time_point tp{};

	std::cout << "epoch of system clock is:" << print_sysclock_timepoint(tp) << std::endl;

	tp += OneDay(1) + std::chrono::hours(23) + std::chrono::minutes(55);
	std::cout << "\nafter that is:" << print_sysclock_timepoint(tp);

	auto diff = tp - std::chrono::system_clock::time_point();
	std::cout << "\tdiff minutes:" << std::chrono::duration_cast<std::chrono::minutes>(diff).count() << std::endl;

	OneDay days = std::chrono::duration_cast<OneDay>(diff);
	std::cout << "\tdiff days:" << days.count() << std::endl;

	tp -= OneDay(3);
	std::cout << "sub one year is:" << print_sysclock_timepoint(tp) << std::endl;

	tp -= OneDay(365 * 50);
	std::cout << "sub 50 years is:" << print_sysclock_timepoint(tp) << std::endl;
}

void ratio_test()
{
	typedef std::ratio<1, 100> A;
	typedef std::ratio<1, 50>  B;
	A a;
	B b;
	//这里的比较，只能用类型作为参数
	std::cout << "\ntest:\n"<<std::boolalpha << std::ratio_greater<decltype(b), decltype(a)>::value << std::endl;


	std::chrono::seconds twseconds(20);
	std::chrono::hours aday(24);

	std::chrono::milliseconds ms{86399999};
	
	

	std::chrono::milliseconds ms2{ 0 };
	std::cout << ms2.count() << std::endl;
	ms2 += twseconds + aday;
	std::cout << ms2.count() << std::endl;
	--ms2;
	std::cout<<"ms2 is:" << ms2.count() << std::endl;
	std::cout <<"ms is:"<< ms.count() << std::endl;
	
	ms *= 2;
	ms2 *= 2;
	std::cout << "ms2 is:" << ms2.count() << std::endl;
	std::cout << "ms is:" << ms.count() << std::endl;
}

int maindaily0322()
{
	func_timepoint_operation_inside();
	ratio_test();
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}