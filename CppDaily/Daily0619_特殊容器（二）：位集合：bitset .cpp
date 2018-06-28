//daily0619
/************************************************************************/
/* 
bitset:内含bit或者bool的固定长度array.

两个功能：
1.管理bit以及bit之间的各种组合.比如通过把int64的整数，通过 & ,|, ^等操作实现flag组合来判断某种类型，
现在可以通过bitset实现相同的功能.

2.整数与二进制字符串之间的互转.

*/
/************************************************************************/


#include "common/common.h"
#include <bitset>
#include <limits>


void func_algor_0619()
{
	//1.bitset管理flag
	enum class Color:int{black,white,red,green,blue,COLOR_NUM};

	std::bitset<size_t(Color::COLOR_NUM)> color_bs;
	color_bs.set(size_t(Color::red));
	color_bs.set(size_t(Color::blue));

	std::cout << "1.bitset管理flags:\nbitfield of used colors:" << color_bs << std::endl;
	std::cout << "number of used colors:" << color_bs.count() << std::endl;
	std::cout << "bitfield of unused colors:" << ~color_bs << std::endl;

	if (color_bs.any())
	{
		for (size_t i = 0; i < size_t(Color::COLOR_NUM); ++i)
		{
			if (color_bs[size_t((Color)i)])
			{
				if( ((Color)i) == Color::red)
				{
					std::cout << "red color used.\n";
				}
				else if (((Color)i) == Color::blue)
				{
					std::cout << "blue color used.\n";

				}
			}
		}
	}

	//2.使用bitset进行整数与二进制字符串之间的互转
	std::cout << "\n2.use bitset conv i to bs and bs to i:\n";

	std::bitset<std::numeric_limits<unsigned short>::digits> bs_267_short(267);
	std::bitset<std::numeric_limits<unsigned long>::digits> bs_267_long(267);

	//--整数转二进制字符串:分别以short和long长度表示的267
	std::cout << "267 as bin short:" << bs_267_short.to_string() << std::endl;
	std::cout << "267 as bin long:" << bs_267_long.to_string() << std::endl;

	//--整数转二进制字符串:以24位长度二进制字符串表示的1000万
	std::bitset<24> bs_24(1e7);
	std::cout << "10000000 with 24 bits:" << bs_24.to_string() << std::endl;

	//--二进制字符串转整数
	std::bitset<100> bs_100("01010101010101");
	std::cout << "\"01010101010101\" as number is:" << bs_100.to_ullong() << std::endl;

}

int maindaily0619()
{
	func_algor_0619();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}