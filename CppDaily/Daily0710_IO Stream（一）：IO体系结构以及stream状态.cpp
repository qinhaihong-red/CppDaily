//daily0710
/************************************************************************/
/* 
1.IO stream体系结构.
简而言之，用以完成IO的stream对象，由两部分构成：
>1.控制stream格式和状态的basic_stream特化（字符以及字符traits） .
>2.控制stream实际读写的缓冲区basic_streambuf特化（字符以及字符traits）.

前者以后者为成员对象.

>3.体系结构:
         stream结构：                             缓冲区结构：
			 ios_base							  basic_streambuf(streambuf,wstreambuf)
				|
		 basic_ios(ios,wios)
			/		\
	basic_istream   basic_ostream
 (istream,wistream) (ostream,wostream) 
		    \		/
		  basic_iostream
	    (iostream,wiostream)

2.stream状态
>1.状态分类：good,eof,fail,bad . 这些都是iostate类型的常量. iostate类型，依据不同平台的实现，实际上不一样.
>2.状态查询函数:
	good():无错误，返回true.
	eof():遭遇end-of-file，返回true.
	fail():发生错误(包括bad状态)，返回true.
	bad():比fail状态更为严重的bad状态，返回true.

>3.状态修改函数:
	clear():清除所有状态
	clear(state):清除所有状态后，设置state状态
	rdstate():其实是getstate，返回当前所有状态
	setstate(state):加设state状态

>4.通过对stream对象进行条件测试，判断当前状态
stream对象对bool () 以及 !() 进行了重载.

*/
/************************************************************************/


#include "common/common.h"
#include <fstream>
#include <sstream>
void test()
{


	std::fstream inf("..\\Debug\\123.txt", std::ios::in);

	if (inf.good())
	{
		/*while (!inf.eof()) {
			std::cout << inf.get() << "\n";
		}
*/
		while (inf.peek()!= EOF) {
			std::cout << inf.get() << "\n";
		}
		inf.close();
		inf.clear();
	}

	inf.open("..\\Debug\\123.txt", std::ios::in);

	if (inf.good())
	{
		char c;
		while (inf >> c) {
			std::cout << c << "\n";
		}
	}

	inf.close();
	inf.clear();
}


//从文件123.txt中读取3个数，并相加
void func_algor_0710()
{
	std::string strPath("..//debug//123.txt");
	std::ifstream ifs(strPath);
	if (ifs)
	{
		int i = 0, total = 0;
		
		while (ifs >> i)//执行两个步骤:1.先读到i中 2.再判断ifs状态
		{
			total += i;
		}

		std::cout << "the total is:" << total << std::endl;
	}

	std::cout << "now ifs is EOF state:" << std::boolalpha << ifs.eof() << std::endl;
	ifs.close();
	ifs.clear();//手动清除错误状态


	ifs.open(strPath);
	if (ifs)
	{
		int i = 0, total = 0;
		char c = 0;


		while(ifs.get(c))
		{
			if (c==' '|| c=='\n')
			{
				continue;
			}

			std::cout << "c is :" << int(c-'0') << std::endl;
		}
	}

	ifs.close();
	ifs.clear();//手动清除错误状态
}


void read_from_csv()
{
	std::string strPath("..//debug//csv.txt");
	std::ifstream ifs(strPath);

	if (ifs)
	{
		std::string line;
		while (std::getline(ifs,line))
		{
			std::cout << "the line is:" << line << std::endl;
			std::istringstream iss(line);
			//格式：
			//1,james,lakers,999.99
			
			int id = 0;
			double ds = 0;
			std::string strNames, strClub;
			std::string token;
			int index = 0;
			//这里或者用正则，或者用这种方法.
			while (std::getline(iss, token, ','))
			{
				++index;

				if (index==1)
				{
					id = std::stoi(token);
				}
				else if (index==2)
				{
					strNames = token;
				}
				else if (index == 3)
				{
					strClub = token;
				}
				else if (index==4)
				{
					ds = std::stod(token);
				}
				
			}

			std::cout << "The number " << id << " player is:" << strNames << ",from " << strClub << ",with salary:"<<ds<<std::endl;

			std::cout << std::endl;
		}
	}

	
}

int maindaily0710()
{

	read_from_csv();
	//func_algor_0710();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}