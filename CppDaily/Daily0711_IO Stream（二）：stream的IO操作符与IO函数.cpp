//daily0710
/************************************************************************/
/* 

stream��IO��������IO��������

1.IO������
ͨ������ >> �� << ��ɸ�ʽ�����������.
��ʽ�����롢����Ķ���ͨ�����ı�.
ע�ⲻ���� << ���д֮������IO������ɶ���.�������ǲ�ƥ���.

2.IO����
��IO��������Ӧ�����޸�ʽ�����������IO����.
�޸�ʽ����������Ķ����Ƕ��������ݣ�Ҳ������ν�����л���������Ӧ�ĳ��õĺ����ǣ�
--read(char *, size)
--write(char*, size)

��stream����������л��뷴���л�����Ȼ����Ҫ�ֶ�����룬Ψһ�ĺô��ǲ��ؿ��ƻ�����
ָ����ƶ����ò�������Ӧ��streambuf���.

�ٴ�ע�⣬��ͬһ���ݣ�IO����������ʽ�������������IO�������޸�ʽ��������������ܻ���.

*/
/************************************************************************/


#include "common/common.h"
#include <fstream>
#include <sstream>

#pragma pack(1)
struct data0711
{
	int first;
	double second;
	uint32_t len;
	std::string str;
	char cend;

	data0711() :first(0), second(0), len(0), cend(0){};
};
#pragma pack()


#pragma pack(1)
struct dataserial
{
	int first;
	double second;
	uint32_t len;
	char str[100];
};
#pragma pack()

//���ڲ��Դ���
//������Ĵ����func_algor_0711()
void stringstream_rw_bin()
{
	data0711 data;
	data.first = 100;
	data.second = 9.999;

	std::string str("data bin");
	data.len = str.length() + 1;

	std::ostringstream os;
	os.write((const char*)&data,sizeof(data));

	int first = 0,len=0;
	double d = 0;

	std::istringstream ifs(os.str());

	//��������
	//	ifs>>first>>d>>len;
	if (!ifs.read((char*)&first,sizeof(first)))
	{
		std::cout << "failed.\n";
	}


	std::cout << "now:" << first << " " << d << " " << std::endl;
}

//���ڲ��Դ���
//������Ĵ����func_algor_0711()
void stream_rw_bin()
{
	data0711 data;
	data.first = 100;
	data.second = 9.999;

	std::string str("data bin");
	data.len = str.length() + 1;
	//data.str = str;	
	//data.cend = ' ';

	std::string strPath("..//debug//data.bin");

	std::ofstream of(strPath,std::ios_base::binary|std::ios_base::trunc);
	if (of)
	{
		//of << data.first << data.second << data.len << data.str << data.cend;

		of.write((char*)&data, sizeof(data));
		std::cout << "write data succeeded!" << std::endl;
	}
	else
	{
		std::cout << "create file failed.\n";
	}

	of.close();

	std::ifstream ifs(strPath,std::ios_base::binary);
	if (ifs)
	{
		data0711 d;
		if (!ifs.read((char*)&(d.first),sizeof(d.first)))
		{
			std::cout << "read failed.\n";
		}

		if (!ifs.read((char*)&(d.second),sizeof(d.second)))
		{
			std::cout << "read failed.\n";
		}

		uint32_t len=0;
		if (!ifs.read((char*)&(d.len), sizeof(d.len)))
		{
			std::cout << "read failed.\n";
		}

		char *p = new char[len];
		if (!ifs.read(p, len))
		{
			std::cout << "read failed.\n";
		}

		//d.str = std::string(p,len);
		delete[] p;

		if (!ifs.read((char*)&(d.len), sizeof(d.len)))
		{
			std::cout << "read failed.\n";
		}


		//std::cout << "read file as following:\n" << "data is:" << d.first << " " << d.second << " " << d.str << std::endl;

		std::cout << "read file as following:\n" << "data is:" << d.first << " " << d.second  << std::endl;



		

	}
	else
	{
		std::cout << "open file failed.\n";
	}
	
}

void func_algor_0711()
{
	//һ.�ļ��ĸ�ʽ����Ǹ�ʽ���������
	//>1.�ļ��ĸ�ʽ���������
	std::cout << "1.�ļ��ĸ�ʽ���������:\n";

	std::string strPath("..//debug//data.txt");
	std::ofstream os(strPath,std::ios::trunc);//Ĭ�ϵĴ�ģʽΪ�ı���ʽ
	if (os.good())
	{
		data0711 data;
		data.first = 100;
		data.second = 9.999;

		std::string str("data bin");
		data.len = str.length() + 1;
		data.str = str;	

		//������Զ�data���в�����<<�����أ���ʽ�ϻ�����
		os << data.first << data.second << data.len << data.str;
		std::cout << "write file OK.\n";

	}
	else
	{
		std::cout << "open file failed.\n";
	}

	os.close();
	os.clear();

	std::ifstream ifs(strPath);
	if (ifs.good())
	{
		data0711 data;
		//ע�⣬�����>>�Ĳ���������������ʼ�����ı�����.
		//֮���Կ������뵽�������ͣ�����Ϊ���int��double��������ֵ����.
		//�����str���ݣ������д�벢���������ģ���˿��Խ������еķ����л�����.
		//���str����λ��ͷ�������в������޷���������ķ����л�������
		//�����������ı���������ֵ����.
		ifs >> data.first >> data.second >> data.len >> data.str;

		std::cout << "read data from data.txt:" << "\nfirst:" << data.first << "\nsecond:" << data.second << "\nstr:" << data.str << std::endl;
	}
	else
	{
		std::cout << "open file failed.\n";
	}
	ifs.close();
	ifs.clear();

	//>2.�������ļ����������
	std::cout << "2.�������ļ����������:\n";

	strPath="..//debug//data.bin";
	os.open(strPath, std::ios::trunc|std::ios::binary);
	if (os.good())
	{
		data0711 data;
		data.first = 100;
		data.second = 9.999;

		std::string str("data bin");
		data.len = str.length();
		data.str = str;

		//����data������std::string
		//��˲���ֱ����һ��д��
		//���δchar[]�Ϳ�����.
		if (!os.write((char*)&data.first, sizeof(data.first)))
		{
			std::cout << "write failed.\n";
		}

		if (!os.write((char*)&data.second, sizeof(data.second)))
		{
			std::cout << "write failed.\n";
		}

		if (!os.write((char*)&data.len, sizeof(data.len)))
		{
			std::cout << "write failed.\n";
		}


		if (!os.write(data.str.c_str(), data.len))
		{
			std::cout << "write failed.\n";
		}

		std::cout << "write bin file OK.\n";
	}
	else
	{
		std::cout << "open file failed.\n";
	}

	os.close();
	os.clear();


	ifs.open(strPath, std::ios::binary);
	if (ifs.good())
	{
		data0711 data;

		if (!ifs.read((char*)&data.first,sizeof(data.first)))
		{
			std::cout << "read failed.\n";
		}

		if (!ifs.read((char*)&data.second, sizeof(data.second)))
		{
			std::cout << "read failed.\n";
		}

		if (!ifs.read((char*)&data.len, sizeof(data.len)))
		{
			std::cout << "read failed.\n";
		}

		char *p = new char[data.len+1];
		p[data.len + 1] = '\0';
		if (!ifs.read(p, data.len))
		{
			std::cout << "read failed.\n";
		}
		data.str = std::string(p);

		//delete[] p;//debug����

		delete []p;



		std::cout << "read data from data.bin:" << "\nfirst:" << data.first << "\nsecond:" << data.second << "\nstr:" << data.str << std::endl;

	}
	else
	{
		std::cout << "open file failed.\n";
	}

	ifs.close();
	ifs.clear();

	//��.����stream����������л��뷴���л�
	//��ʱ�򣬱�����׽��ֽ��ж�д���ݣ���Ҫ�ֶ��������ݽṹ�ڲ�ָ����ƶ�.
	//����ostringstream �� istringstream�� ���Ա����ֶ������ƶ��ƶ�.

	std::cout << "3.ʹ��stringstream������л��뷴���л���\n";
	{

		dataserial ds;
		ds.first = 100;
		ds.second = 99.999;
		
		std::memset((void*)ds.str, 0, 100);

		std::string str("data serial");
		std::strncpy(ds.str,str.c_str(),str.length());//ע�����ﲻ����0��
		ds.len = str.length();
	
	
		std::ostringstream os;
		//���л��ǳ���.
		//����һ��д��.
		os.write((char*)&ds,sizeof(ds)); 
		
		std::memset((void*)&ds,0,sizeof(ds));

		//�����л�
		std::istringstream ifs(os.str());
		if (!ifs.read((char*)&ds.first,sizeof(ds.first)))
		{
			std::cout << "read failed.\n";
		}

		if (!ifs.read((char*)&ds.second, sizeof(ds.second)))
		{
			std::cout << "read failed.\n";
		}

		if (!ifs.read((char*)&ds.len, sizeof(ds.len)))
		{
			std::cout << "read failed.\n";
		}

		char *p = new char[ds.len + 1];
		p[ds.len + 1] = '\0';

		if (!ifs.read(p,ds.len))
		{
			std::cout << "read failed.\n";
		}

		std::strcpy(ds.str,p);
		delete []p;



		std::cout << "read data from stringstream:" << "\nfirst:" << ds.first << "\nsecond:" << ds.second << "\nstr:" << ds.str << std::endl;

	
	}
}

int maindaily0711()
{
	//stringstream_rw_bin();
	//stream_rw_bin();
	
	func_algor_0711();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}