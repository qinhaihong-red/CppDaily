//daily0710
/************************************************************************/
/* 

stream的IO操作符与IO操作函数

1.IO操作符
通过重载 >> 与 << 完成格式化的输入输出.
格式化输入、输出的对象通常是文本.
注意不能以 << 完成写之后，再以IO函数完成读入.这两者是不匹配的.

2.IO函数
与IO操作符对应的是无格式化输入输出的IO函数.
无格式化输入输出的对象是二进制数据，也就是所谓的序列化操作，对应的常用的函数是：
--read(char *, size)
--write(char*, size)

以stream对象完成序列化与反序列化，自然是需要手动编解码，唯一的好处是不必控制缓冲区
指针的移动，该操作由相应的streambuf完成.

再次注意，对同一数据，IO操作符（格式化输入输出）与IO函数（无格式化输入输出）不能混用.

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

//属于测试代码
//已梳理的代码见func_algor_0711()
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

	//这样不行
	//	ifs>>first>>d>>len;
	if (!ifs.read((char*)&first,sizeof(first)))
	{
		std::cout << "failed.\n";
	}


	std::cout << "now:" << first << " " << d << " " << std::endl;
}

//属于测试代码
//已梳理的代码见func_algor_0711()
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
	//一.文件的格式化与非格式化输入输出
	//>1.文件的格式化输入输出
	std::cout << "1.文件的格式化输入输出:\n";

	std::string strPath("..//debug//data.txt");
	std::ofstream os(strPath,std::ios::trunc);//默认的打开模式为文本方式
	if (os.good())
	{
		data0711 data;
		data.first = 100;
		data.second = 9.999;

		std::string str("data bin");
		data.len = str.length() + 1;
		data.str = str;	

		//这里可以对data进行操作符<<的重载，形式上会更简洁
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
		//注意，这里的>>的操作符读出的数据始终是文本数据.
		//之所以可以输入到数据类型，是因为其对int，double等做了数值处理.
		//这里的str数据，是最后写入并且最后读出的，因此可以进行下列的反序列化操作.
		//如果str数据位于头部或者中部，就无法进行下面的反序列化操作：
		//它不能区分文本类型与数值类型.
		ifs >> data.first >> data.second >> data.len >> data.str;

		std::cout << "read data from data.txt:" << "\nfirst:" << data.first << "\nsecond:" << data.second << "\nstr:" << data.str << std::endl;
	}
	else
	{
		std::cout << "open file failed.\n";
	}
	ifs.close();
	ifs.clear();

	//>2.二进制文件的输入输出
	std::cout << "2.二进制文件的输入输出:\n";

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

		//由于data里面有std::string
		//因此不能直接性一次写入
		//如果未char[]就可以了.
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

		//delete[] p;//debug报错

		delete []p;



		std::cout << "read data from data.bin:" << "\nfirst:" << data.first << "\nsecond:" << data.second << "\nstr:" << data.str << std::endl;

	}
	else
	{
		std::cout << "open file failed.\n";
	}

	ifs.close();
	ifs.clear();

	//二.利用stream对象完成序列化与反序列化
	//有时候，比如对套接字进行读写数据，需要手动控制数据结构内部指针的移动.
	//利用ostringstream 和 istringstream， 可以避免手动控制移动移动.

	std::cout << "3.使用stringstream完成序列化与反序列化：\n";
	{

		dataserial ds;
		ds.first = 100;
		ds.second = 99.999;
		
		std::memset((void*)ds.str, 0, 100);

		std::string str("data serial");
		std::strncpy(ds.str,str.c_str(),str.length());//注意这里不复制0了
		ds.len = str.length();
	
	
		std::ostringstream os;
		//序列化非常简单.
		//这里一次写入.
		os.write((char*)&ds,sizeof(ds)); 
		
		std::memset((void*)&ds,0,sizeof(ds));

		//反序列化
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