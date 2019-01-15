//daily0726
/************************************************************************/
/* 
stringstream主要完成格式化字符串(istringstream)与反格式化字符串(ostringstream)的功能.
可以认为是字符串版本的二进制序列化与反序列化的实现.

比如可以把自定义的结构体通过stringstream进行格式化与反格式化.

当然，stringstream也可以通过其read和write完成二进制序列化与反序列化.
ibinstream和obinstream重载了stringstream的格式化操作符>>和<<，用其实现序列化与反序列化.
*/
/************************************************************************/

#include "common/common.h"
#include <sstream>

void func_algor_format_and_deformat()
{
	//1.格式化
	std::ostringstream oss;
	oss << "James" << " " << 33 << " " << "Power Forward" << " " << 9.9 << std::endl;
	oss << "Harden" << " " << 29 << " " << "Score Guard" << " " << 9.7 << std::endl;


	std::string csv = oss.str();
	std::cout << "now players csv lists:\n" << csv << std::endl;

	//2.反格式化
	std::istringstream iss(csv);
	std::string s;
	int n = 0;
	std::string name, position;
	int age = 0;
	float rank = 0;
	while (std::getline(iss, s))
	{
		//如下这样的反格式化行不通
		//虽然>>以ws为定界符，但是如果子字符串内部又含有空格，就会对>>的解析形成干扰
		//如果上述的Power Forward改为Power_Forward就可以正常解析了.
		std::istringstream line(s);
		line >> name >> age >> position >> rank;

		std::cout << ++n << "." << name << " " << age << " " << position << " " << rank << std::endl;
	}
}

void func_algor_parse_csv_0726()
{
	//1.格式化
	std::ostringstream oss;
	oss << "James" << "," << 33 << "," << "Power Forward" <<","<< 9.9 << std::endl;
	oss << "Harden" << "," << 29 << "," << "Score Guard" << ","<<9.7 << std::endl;
	oss << "Durant" << "," << 30 << "," << "Small Forward" << ","<<9.8 << std::endl;

	std::string csv = oss.str();
	std::cout << "now players csv lists:\n" << csv<<std::endl;

	//2.反格式化
	std::istringstream iss(csv);
	std::string s;
	int n = 0;
	std::string name, position;
	int age = 0;
	float rank = 0;
	while (std::getline(iss,s))
	{
		//>>如下这样的反格式化行不通，因为line是一整个字符串，stringstream不知道定界符在哪里(默认使用ws).
		//std::istringstream line(s);
		//line >> name >> age >> position >> rank;

		//>>必须通过分割定界符来逐一反格式化
		std::istringstream line(s);
		std::string i;
		int col = 0;
		while (std::getline(line,i,','))
		{
			std::istringstream _temp(i);
			if (col==0)
			{
				_temp >> name;
			}
			else if (col==1)
			{
				_temp >> age;
			}
			else if (col==2)
			{
				_temp >> position;
			}
			else if(col==3)
			{
				_temp >> rank;
			}


			++col;
		}

		std::cout << ++n << "." << name << " " << age << " " << position << " " << rank << std::endl;
	}

}


int main0726()
{
	func_algor_format_and_deformat();
	//func_algor_parse_csv_0726();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}
