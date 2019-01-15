//daily0724
/************************************************************************/
/* 
>>>PART1:�������
C++���ļ�IO��Ҫ��3����������ݣ�
1.�ļ��򿪷�ʽ
�磺���ļ��򿪣�д�ļ��򿪣������ƴ򿪣�׷�Ӵ򿪣��ضϴ򿪵�.
��Ҫ�����±�־���ƣ�
	in
	out
	app
	ate
	trunc
	binary

���ϱ�־����ϣ�����ʵ�ֳ�nocreate(�ļ��������)��noreplace���ļ����벻���ڣ��������Ҫ��.
�磺
in��in|out��ϣ�����Ҫ���ļ����ڣ�������������б�Ҫʱ�Ŵ����ļ�.

ifstreamĬ��������std::ios::in��־
ofstreamĬ��������std::ios::out��־


2.�ļ��ĸ�ʽ�����ı�����Ǹ�ʽ���������ƣ����������
��ʽ�����������Ҫ������IO��������<<��>>
�Ǹ�ʽ�����������Ҫ������stream�ĳ�Ա������������read��write

3.�ļ�ָ��
ͨ���ļ�ָ�룬ʵ�ֶ�д��������ʣ�
ifstream:
	tellg():	���ص�ǰ�����ľ���λ��. 
	seekg(pos): ���þ��Զ�ȡλ��.
	seekg(offset,pos): ������Զ�ȡλ��.

ofstream:
	tellp():    ���ص�ǰ��д�ľ���λ��.
	seekp(pos): ���þ���д��λ��.
	seekp(offset,pos): �������д��λ��.

tellg��tellp���ص�λ�����ͣ��Լ�seekp/g��ʹ�õ�λ�����ͣ�Ϊstd::ios::pos_type����std::streampos��
������long��unsinged long����������.������Ϊ�ڸ�ʽ���������������£�ĳЩ�ַ��Ķ����������ڲ�ͬ��ƽ̨.

����һ�㣬��ͨ��stream������л��뷴���л�ʱ���ļ�IO�Ѿ����ڳ־û��ˣ������ڻ���������streambuf������
��˲����ֶ������л��ṹ���������ֶ�����ָ����ƶ�.


>>>PART2:�������
1.C++�ļ��������ṩ�ļ�ϵͳ����������ɾ��/�������ļ��ȣ����Խ���cstdio�ĺ���ʵ�֣�http://www.cplusplus.com/reference/cstdio/����
>1.ɾ���ļ���int remove ( const char * filename )ʵ��ɾ���ļ����ԣ����㷨move������ͬ�����ǲ�����ͬ��.
>2.�������ļ���int rename ( const char * oldname, const char * newname )
2.��������ļ����ݣ�ofstream��trunc��ʽ�򿪼���.
3.�޸Ļ���ղ����ļ����ݣ�
>1.������ʱ�ļ�
>2.��ԭʼ�ļ��ж����ݣ�����д����ʱ�ļ�
>3.ɾ��ԭʼ�ļ�������ʱ�ļ�������Ϊԭʼ�ļ���
��https://stackoverflow.com/questions/26177738/remove-parts-of-text-file-c��
4.��ȡ�ļ���С����binary|ate���ļ���ֱ��tellg���ɣ�https://stackoverflow.com/questions/2409504/using-c-filestreams-fstream-how-can-you-determine-the-size-of-a-file��
���Ƕ����ı��ļ���������ƫ��.
*/
/************************************************************************/

#include "common/common.h"
#include <fstream>
#include <cstdio>

void func_algor_0724()
{

	std::string strPath("..//debug//data0724.txt");

	//1.�ļ��Ĵ򿪱�־
	//>1.�ж��ļ��Ƿ����
	{
		std::ifstream ifs(strPath);//Ĭ��std::in
		if (!ifs)
		{
			std::cout << "1.file not exists.\n";
		}
	}

	//>2.�������ļ�������������ļ����ݣ�
	{
		std::ofstream os(strPath,std::ios::trunc);
		if (os)
		{
			os << "Hi";
			std::cout << "\n2.create file and write ok.tellp:" << os.tellp() << std::endl;
		}
	}

	//>3.��׷�ӷ�ʽ��app����
	{
		std::ofstream os(strPath, std::ios::app);
		{
			os << " there";
			
			std::streampos pos = os.tellp();

			std::cout << "\n3.append file ok.tellp:" << pos << std::endl;

			//��app��ʽ�򿪣�����seek����ִ�У����ļ�ָ�뷢�����ƶ�
			if (!os.seekp(-5,std::ios::cur))
			{
				std::cout << "(can't seek if file opened with app flag)\n";
			}
			else
			{
				std::cout << "after seekp, now tellp:" << os.tellp() << std::endl;
				//���������seekp�������ļ�ָ����ǰ�������ƶ�
				//����ÿ��д�룬�����Ȱ��ļ�ָ��ŵ�����ٽ���д��
				//������������������λ��д����!
				os << "!";
				std::cout << "after write, now tellp:" << os.tellp() << std::endl;

			}
		}
	}

	//>4.��ate��ʽ�򿪲�����there
	{
		std::ifstream ifs(strPath,std::ios::ate);
		if (ifs)
		{
			std::cout << "\n4.read:\ntellg:" << ifs.tellg() << std::endl;
			ifs.seekg(-5,std::ios::cur);//��ate�򿪣���ǰλ���Ѿ�����end�ˣ���ǰ�ƶ�5��λ��
			std::cout<<"after seekg,now tellg:"<< ifs.tellg() << std::endl;
			std::string str;
			ifs >> str;
			std::cout << "text is:" << str << std::endl;
		}
		else
		{
			std::cout << "\n4.read failed.\n";
		}

	}

	//>5.ÿ�ζ������һ�У�������µ�һ��:hello[n]
	{
		std::string strPath2("..//debug//data0724_2.txt");
		
		//��in|out|ate�򿪣�����Ҫ���ļ�����
		std::fstream fs(strPath2,std::ios::in|std::ios::out|std::ios::ate);

		if (!fs)
		{
			std::cout << "\n5.can't open file this way:file not exists while open with in|out|ate.\n";

			fs.close();
			fs.clear();

			//��in|out|app��ʽ�򿪣��ļ����Բ�����
			fs.open(strPath2, std::ios::in | std::ios::out | std::ios::app);
	
			fs << "1hello\n";
			std::cout << "\ncreate and write file(in|out|app mode) ok.\n";
			std::cout << "now tellg:" << fs.tellg() << std::endl;
			std::cout << "now tellp:" << fs.tellp() << std::endl;
			int n = 0;

			//appģʽ�򿪣���δ�ƶ��ļ�ָ�������£�curָ��ľ���end��λ��
			//fs.seekg(-7, std::ios::cur); //��ʱtellg��1
			fs.seekg(-7, std::ios::end);//��ʱtellg��1
			std::cout << "after seekg,now tellg:" << fs.tellg() << std::endl;
			fs >> n;
			std::cout << "the line-no is:" << n << std::endl;

		}
		else 
		{

			std::cout << "\n5.open file(in|out|ate mode) ok.\n";
			std::cout << "now tellg:" << fs.tellg() << std::endl;
			std::cout << "now tellp:" << fs.tellp() << std::endl;

			char c1,c2;
			int nLast = 0;

			fs.seekg(-3, std::ios::cur);
			fs >> c1;//����o
			std::cout << "c1 is:"<<c1<<" .after seek -3 from cur,now tellg:" << fs.tellg() << std::endl;

			fs.seekg(-3, std::ios::end);
			fs >> c2;//����o
			std::cout << "c2 is:" << c2 << " .after seek -3 from cur,now tellg:" << fs.tellg() << std::endl;

			//1hello\n
			fs.seekg(-8, std::ios::end);//����Ҫ��ȥ8���ַ��ſ���
			std::cout << "after seek -8 from end,now tellg:" << fs.tellg() << std::endl;
			fs >> nLast;//����һ����ȡ����fs��״̬���Ͼͱ�Ϊfail.��������getline���޷�����.

			int n = 0;
			fs.seekg(0,std::ios::beg);
			std::cout << "after seek to beg,now tellg:" << fs.tellg() << std::endl;
			std::string line;
			while (std::getline(fs, line))
			{
				std::cout<<"\t" << line << std::endl;
				++n;
			}
			//whileѭ����ϣ�fs��״̬��Ϊeof�Ĵ���״̬.�����Ҫ�������clear���״̬.
		
			std::cout << "the last line-no equals:" << std::boolalpha<< (n==nLast) <<",is:"<<n<< std::endl;
			std::cout << "now tellp:" << fs.tellp() << std::endl;
			fs.clear();//�����������ȡ��϶���ɵĴ���״̬
			fs.seekp(0,std::ios::end);
			std::cout << "after clear and seekp,now tellp:" << fs.tellp() << std::endl;
			fs << ++n << "hello\n";
		}

	}
}


int maindaily0724()
{
	func_algor_0724();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}
