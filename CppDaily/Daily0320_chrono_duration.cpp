//daily0320
/************************************************************************/
/* 
chrono模块中的duration，用以表示一段时间.

1.duration的构成
	duration<V,U>表示一段时间长度。这个长度的单位由U，也就是ration来表示，相对于秒作为单位.
	V是一个数值，代表单位的数目（tick）

2.计算：duration的加减乘除，以及逻辑比较

3.duration的相互转换.
	--大单位可以无缝转换为小单位（如小时到分钟）
	--小单位转到大单位，需要借助duration_cast强制转换

*/
/************************************************************************/

#include <ratio>
#include <chrono>
#include <iostream>
#include <string>

template<typename V,typename U>
std::ostream& operator << (std::ostream& os, const std::chrono::duration<V, U> &d)
{
	os << "[ " << d.count() << " 个 " << U::num << "/" << U::den << "秒. ]";

	return os;
}



void func_druation_inside()
{
	//1.duration的表示
	typedef std::chrono::duration<int, std::ratio<1, 2>> HalfSecond;
	HalfSecond one_sec(2);
	std::cout << one_sec << std::endl;
	//rep和period分别是长度与单位的类型
	std::cout << "HalfSecond 长度类型是 int :" << std::boolalpha << (typeid(HalfSecond::rep) == typeid(int)) << std::endl;
	std::cout << "HalfSecond 单位类型是 std::ration<1,2>" << std::boolalpha << (typeid(HalfSecond::period) == typeid(std::ratio<1, 2>)) << std::endl;



	//2.计算
	std::chrono::seconds s1(10);
	std::chrono::microseconds s2(10);
	auto s3 = s1 - s2;
	std::cout << "\ns1-s2 is:"<<s3 << std::endl;
	
	//3.比较
	std::chrono::seconds chrono_one_sec(1);
	std::cout << "\none_sec(2) equal chrono_one_sec(1) is: "<<std::boolalpha << (one_sec == chrono_one_sec) << std::endl;

	std::cout << "s1 is greater than s2:" << std::boolalpha << (s1 > s2) << std::endl;


	//4.转换
	//大转小，无问题
	std::chrono::seconds s4(1);
	std::chrono::microseconds s5 = s4;
	std::cout << "\ns5 is:"<<s5 << std::endl;

	s4 *= 60;
	std::cout << "now s4 is:" << s4 << std::endl;
	//小转大，不可以
	//std::chrono::minutes m1 = s4;
	//需通过强制转型
	std::chrono::minutes m1 = std::chrono::duration_cast<std::chrono::minutes>(s4);
	std::cout << "m1 is:" << m1 << std::endl;

	//通过转换，把一个毫秒表示的数表示为小时,分钟，秒和毫秒

	std::chrono::milliseconds ms(7255042);
	std::chrono::hours split_h1 = std::chrono::duration_cast<std::chrono::hours>(ms);
	std::chrono::minutes split_m1 = std::chrono::duration_cast<std::chrono::minutes>(ms % std::chrono::hours(1));
	std::chrono::seconds split_s1 = std::chrono::duration_cast<std::chrono::seconds>(ms % std::chrono::minutes(1));
	std::chrono::milliseconds split_milli = std::chrono::duration_cast<std::chrono::milliseconds>(ms % std::chrono::seconds(1));

	std::cout << std::endl;
	std::cout<< "小时:"<<split_h1 << std::endl;
	std::cout<<"分钟:"<< split_m1 << std::endl;
	std::cout << "秒:" << split_s1 << std::endl;
	std::cout << "毫秒:" << split_milli << std::endl;


	std::cout << std::endl;
}


int	maindaily0320()
{
	func_druation_inside();
	
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}