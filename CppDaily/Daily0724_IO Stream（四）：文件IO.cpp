//daily0724
/************************************************************************/
/* 
>>>PART1:常规操作
C++的文件IO主要有3个方面的内容：
1.文件打开方式
如：读文件打开，写文件打开，二进制打开，追加打开，截断打开等.
主要由以下标志控制：
	in
	out
	app
	ate
	trunc
	binary

以上标志的组合，可以实现出nocreate(文件必须存在)和noreplace（文件必须不存在）等特殊的要求.
如：
in和in|out组合，必须要求文件存在；其他组合则在有必要时才创建文件.

ifstream默认设置了std::ios::in标志
ofstream默认设置了std::ios::out标志


2.文件的格式化（文本）与非格式化（二进制）的输入输出
格式化输入输出主要依赖于IO操作符：<<与>>
非格式化输入输出主要依赖于stream的成员函数，尤其是read和write

3.文件指针
通过文件指针，实现读写的随机访问：
ifstream:
	tellg():	返回当前所读的绝对位置. 
	seekg(pos): 设置绝对读取位置.
	seekg(offset,pos): 设置相对读取位置.

ofstream:
	tellp():    返回当前所写的绝对位置.
	seekp(pos): 设置绝对写入位置.
	seekp(offset,pos): 设置相对写入位置.

tellg和tellp返回的位置类型，以及seekp/g所使用的位置类型，为std::ios::pos_type或者std::streampos，
但绝非long和unsinged long等整数类型.这是因为在格式化输入输出的情况下，某些字符的度量，依赖于不同的平台.

补充一点，当通过stream完成序列化与反序列化时（文件IO已经属于持久化了），由于缓冲区依靠streambuf来管理，
因此不必手动像序列化结构体那样，手动进行指针的移动.


>>>PART2:额外操作
1.C++文件操作不提供文件系统操作，比如删除/重命名文件等，可以借助cstdio的函数实现（http://www.cplusplus.com/reference/cstdio/）：
>1.删除文件：int remove ( const char * filename )实现删除文件（对，与算法move命名相同，但是参数不同）.
>2.重命名文件：int rename ( const char * oldname, const char * newname )
2.清空所有文件内容：ofstream以trunc方式打开即可.
3.修改或清空部分文件内容：
>1.创建临时文件
>2.从原始文件中读数据，处理，写入临时文件
>3.删除原始文件，将临时文件重命名为原始文件名
（https://stackoverflow.com/questions/26177738/remove-parts-of-text-file-c）
4.读取文件大小：以binary|ate打开文件，直接tellg即可（https://stackoverflow.com/questions/2409504/using-c-filestreams-fstream-how-can-you-determine-the-size-of-a-file）
但是对于文本文件，可能有偏差.
*/
/************************************************************************/

#include "common/common.h"
#include <fstream>
#include <cstdio>

void func_algor_0724()
{

	std::string strPath("..//debug//data0724.txt");

	//1.文件的打开标志
	//>1.判断文件是否存在
	{
		std::ifstream ifs(strPath);//默认std::in
		if (!ifs)
		{
			std::cout << "1.file not exists.\n";
		}
	}

	//>2.创建新文件（或清除所有文件内容）
	{
		std::ofstream os(strPath,std::ios::trunc);
		if (os)
		{
			os << "Hi";
			std::cout << "\n2.create file and write ok.tellp:" << os.tellp() << std::endl;
		}
	}

	//>3.以追加方式（app）打开
	{
		std::ofstream os(strPath, std::ios::app);
		{
			os << " there";
			
			std::streampos pos = os.tellp();

			std::cout << "\n3.append file ok.tellp:" << pos << std::endl;

			//以app方式打开，这里seek可以执行，即文件指针发生了移动
			if (!os.seekp(-5,std::ios::cur))
			{
				std::cout << "(can't seek if file opened with app flag)\n";
			}
			else
			{
				std::cout << "after seekp, now tellp:" << os.tellp() << std::endl;
				//尽管上面的seekp导致了文件指针向前发生了移动
				//但是每逢写入，总是先把文件指针放到最后再进行写入
				//所以这里仍热在最后的位置写入了!
				os << "!";
				std::cout << "after write, now tellp:" << os.tellp() << std::endl;

			}
		}
	}

	//>4.以ate方式打开并读出there
	{
		std::ifstream ifs(strPath,std::ios::ate);
		if (ifs)
		{
			std::cout << "\n4.read:\ntellg:" << ifs.tellg() << std::endl;
			ifs.seekg(-5,std::ios::cur);//以ate打开，当前位置已经处于end了，向前移动5个位置
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

	//>5.每次读出最后一行，并添加新的一行:hello[n]
	{
		std::string strPath2("..//debug//data0724_2.txt");
		
		//以in|out|ate打开，必须要求文件存在
		std::fstream fs(strPath2,std::ios::in|std::ios::out|std::ios::ate);

		if (!fs)
		{
			std::cout << "\n5.can't open file this way:file not exists while open with in|out|ate.\n";

			fs.close();
			fs.clear();

			//以in|out|app方式打开，文件可以不存在
			fs.open(strPath2, std::ios::in | std::ios::out | std::ios::app);
	
			fs << "1hello\n";
			std::cout << "\ncreate and write file(in|out|app mode) ok.\n";
			std::cout << "now tellg:" << fs.tellg() << std::endl;
			std::cout << "now tellp:" << fs.tellp() << std::endl;
			int n = 0;

			//app模式打开，在未移动文件指针的情况下，cur指向的就是end的位置
			//fs.seekg(-7, std::ios::cur); //此时tellg是1
			fs.seekg(-7, std::ios::end);//此时tellg是1
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
			fs >> c1;//读出o
			std::cout << "c1 is:"<<c1<<" .after seek -3 from cur,now tellg:" << fs.tellg() << std::endl;

			fs.seekg(-3, std::ios::end);
			fs >> c2;//读出o
			std::cout << "c2 is:" << c2 << " .after seek -3 from cur,now tellg:" << fs.tellg() << std::endl;

			//1hello\n
			fs.seekg(-8, std::ios::end);//这里要减去8个字符才可以
			std::cout << "after seek -8 from end,now tellg:" << fs.tellg() << std::endl;
			fs >> nLast;//这里一旦读取出错，fs的状态马上就变为fail.因此下面的getline就无法进行.

			int n = 0;
			fs.seekg(0,std::ios::beg);
			std::cout << "after seek to beg,now tellg:" << fs.tellg() << std::endl;
			std::string line;
			while (std::getline(fs, line))
			{
				std::cout<<"\t" << line << std::endl;
				++n;
			}
			//while循环完毕，fs的状态变为eof的错误状态.因此需要下面进行clear清除状态.
		
			std::cout << "the last line-no equals:" << std::boolalpha<< (n==nLast) <<",is:"<<n<< std::endl;
			std::cout << "now tellp:" << fs.tellp() << std::endl;
			fs.clear();//清除上面的因读取完毕而造成的错误状态
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
