//daily0619
/************************************************************************/
/* 
bitset:�ں�bit����bool�Ĺ̶�����array.

�������ܣ�
1.����bit�Լ�bit֮��ĸ������.����ͨ����int64��������ͨ�� & ,|, ^�Ȳ���ʵ��flag������ж�ĳ�����ͣ�
���ڿ���ͨ��bitsetʵ����ͬ�Ĺ���.

2.������������ַ���֮��Ļ�ת.

*/
/************************************************************************/


#include "common/common.h"
#include <bitset>
#include <limits>


void func_algor_0619()
{
	//1.bitset����flag
	enum class Color:int{black,white,red,green,blue,COLOR_NUM};

	std::bitset<size_t(Color::COLOR_NUM)> color_bs;
	color_bs.set(size_t(Color::red));
	color_bs.set(size_t(Color::blue));

	std::cout << "1.bitset����flags:\nbitfield of used colors:" << color_bs << std::endl;
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

	//2.ʹ��bitset����������������ַ���֮��Ļ�ת
	std::cout << "\n2.use bitset conv i to bs and bs to i:\n";

	std::bitset<std::numeric_limits<unsigned short>::digits> bs_267_short(267);
	std::bitset<std::numeric_limits<unsigned long>::digits> bs_267_long(267);

	//--����ת�������ַ���:�ֱ���short��long���ȱ�ʾ��267
	std::cout << "267 as bin short:" << bs_267_short.to_string() << std::endl;
	std::cout << "267 as bin long:" << bs_267_long.to_string() << std::endl;

	//--����ת�������ַ���:��24λ���ȶ������ַ�����ʾ��1000��
	std::bitset<24> bs_24(1e7);
	std::cout << "10000000 with 24 bits:" << bs_24.to_string() << std::endl;

	//--�������ַ���ת����
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