//daily0710
/************************************************************************/
/* 
1.IO stream��ϵ�ṹ.
�����֮���������IO��stream�����������ֹ��ɣ�
>1.����stream��ʽ��״̬��basic_stream�ػ����ַ��Լ��ַ�traits�� .
>2.����streamʵ�ʶ�д�Ļ�����basic_streambuf�ػ����ַ��Լ��ַ�traits��.

ǰ���Ժ���Ϊ��Ա����.

>3.��ϵ�ṹ:
         stream�ṹ��                             �������ṹ��
			 ios_base							  basic_streambuf(streambuf,wstreambuf)
				|
		 basic_ios(ios,wios)
			/		\
	basic_istream   basic_ostream
 (istream,wistream) (ostream,wostream) 
		    \		/
		  basic_iostream
	    (iostream,wiostream)

2.stream״̬
>1.״̬���ࣺgood,eof,fail,bad . ��Щ����iostate���͵ĳ���. iostate���ͣ����ݲ�ͬƽ̨��ʵ�֣�ʵ���ϲ�һ��.
>2.״̬��ѯ����:
	good():�޴��󣬷���true.
	eof():����end-of-file������true.
	fail():��������(����bad״̬)������true.
	bad():��fail״̬��Ϊ���ص�bad״̬������true.

>3.״̬�޸ĺ���:
	clear():�������״̬
	clear(state):�������״̬������state״̬
	rdstate():��ʵ��getstate�����ص�ǰ����״̬
	setstate(state):����state״̬

>4.ͨ����stream��������������ԣ��жϵ�ǰ״̬
stream�����bool () �Լ� !() ����������.

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


//���ļ�123.txt�ж�ȡ3�����������
void func_algor_0710()
{
	std::string strPath("..//debug//123.txt");
	std::ifstream ifs(strPath);
	if (ifs)
	{
		int i = 0, total = 0;
		
		while (ifs >> i)//ִ����������:1.�ȶ���i�� 2.���ж�ifs״̬
		{
			total += i;
		}

		std::cout << "the total is:" << total << std::endl;
	}

	std::cout << "now ifs is EOF state:" << std::boolalpha << ifs.eof() << std::endl;
	ifs.close();
	ifs.clear();//�ֶ��������״̬


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
	ifs.clear();//�ֶ��������״̬
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
			//��ʽ��
			//1,james,lakers,999.99
			
			int id = 0;
			double ds = 0;
			std::string strNames, strClub;
			std::string token;
			int index = 0;
			//������������򣬻��������ַ���.
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