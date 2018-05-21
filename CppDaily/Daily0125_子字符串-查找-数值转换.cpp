//daily0125
//string的相关函数
/************************************************************************/
/*几点注意 
1.string::size_type类型来定义索引下标.string::npos表示string元素中最后面的下一个.
2.操作string的成员函数，更多的基于索引下标，这与其他容器以迭代器来操作不不太一样.
在string中，区间的表示，通常以某个索引作为开始，再以包含索引在内的顺序n个元素表示区间，如：
substr(0,5):返回包括第一个元素在内的后续5个元素
而其他stl容器通常以左闭右开的迭代器表示区间

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <exception>

struct MyStructPack
{
	int a;
	char sz[10];
};

void func_string_operation()
{
	//1.string作为序列化容器
	MyStructPack mp;
	mp.a = 99;
	strcpy_s(mp.sz, 10, "hello");

	std::string strBytes((char*)&mp,sizeof(mp));
	std::cout << "string作为序列化容器：" << strBytes.size() << std::endl << std::endl;

	//2.字符串比较
	//注意：操作符比较和成员函数compare比较，两者返回的结果不同。
	//前者返回bool类型，后者返回int 类型（0相等，-1小于，1大于）
	std::string strComp("abcd");
	std::cout << "字符串比较："<<std::endl<<strComp.compare("abc") << std::endl;
	std::cout  << strComp.compare("abcde") << std::endl;
	std::cout << strComp.compare("abcd") << std::endl << std::endl;


	//3.子字符串
	//子字符串是典型的以：开始下标+字符个数 为操作区间的操作类型

	std::string strSub("pythoncookbook");
	std::cout << "子字符串：" << std::endl << strSub.substr() << std::endl;
	std::cout << strSub.substr(strSub.find("n")) << std::endl;
	std::cout << strSub.substr(6) << std::endl;
	std::cout << strSub.substr(6, 4) << std::endl <<std::endl;

	//4.查找
	//注意：1.find是全字匹配
	//2.find_first_of(not of)是相当于匹配给定集合中的某个元素

	std::string strTestFind("pythoncookbook");
	std::cout << "查找：" << std::endl;
	std::cout << strTestFind.find("on") << std::endl;
	std::cout << strTestFind.find_first_of("xyzk") << std::endl;
	std::cout << strTestFind.find_first_not_of("python") << std::endl << std::endl;

	//数值转换
	//1.字符串的数值转换函数位于std空间中，全部以s（string）开头（转字符串的以to_开头）
	//2.数值转换可以自动跳过字符串前面的空白字符
	//3.可以指定参数返回“被处理字符串的最后一个字符”的下一个字符的位置
	//4.可以设置基数（对于整数）


	std::cout << "数值转换：" << std::endl;
	try
	{
		std::cout << std::stoi("   77") << std::endl;
		std::cout << std::stod("  99.88") << std::endl;
		std::cout << std::stoi("-0x88") << std::endl;

		std::size_t idx;
		std::cout << std::stoi("  45 is the ...", &idx) << std::endl;
		std::cout << "第一个未被处理的字符位置：" << idx << std::endl;

		std::cout << std::stoi("   42", nullptr, 16) << std::endl;//这个意思是说，string中的42是以16进制表示的
		std::cout << std::stol("789", &idx, 8) << std::endl;
		std::cout << "第一个未被处理的字符位置：" << idx << std::endl;

		std::cout << "数值转字符串：" << std::endl;

		long long ll = std::numeric_limits<long long>::max();
		std::string sll = std::to_string(ll);
		std::cout << sll << std::endl;
		
		std::cout << std::stoi(sll);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}



int maindaily0125()
//int main()
{

	func_string_operation();
	
	std::cout << std::endl<< "****************" << std::endl;
	std::cout << std::to_string(0xff) << std::endl;
	//std::cout << std::stoi("-0x88") << std::endl;//这样不行的，必须指定基数
	std::cout << std::stoi("-0x88", nullptr, 16) << std::endl;



	std::string strInput;
	std::getline(std::cin,strInput);

	return 1;
}