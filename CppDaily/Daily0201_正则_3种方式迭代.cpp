//daily0201
/************************************************************************/
/* 
正则表达式：迭代器相关
以三种方式迭代捕获组：
1.regex_search
2.sregex_iterator循环
3.for_each+sregex_iterator
*/
/************************************************************************/

#include <iostream>
#include <regex>
#include <string>
#include<algorithm>

void func_regex_iter_inside()
{
	//std::string strData = "<player>\n"
	//	"<first>Lebron</first>\n"
	//	"<second>James</second>\n"
	//	"</player>";

	//std::regex rgPattern("<(.*)>(.*)</(\\1)>");

	std::string strData = "<player>"
		"<first>Lebron</first>"
		"<second>James</second>"
		"</player>";

	//std::regex rgPattern("<(.*)>(.*)</(\\1)>");//由于进行最长匹配，因此只把最外层匹配了，里面没有迭代匹配
	std::regex rgPattern("<(.*)>([^<]*)</(\\1)>");//这样可以迭代内层


	std::smatch smt;
	auto iterPos = strData.cbegin();
	auto iterEnd   = strData.cend();

	//使用regex_search循环迭代
	for (;std::regex_search(iterPos,iterEnd,smt,rgPattern);iterPos=smt.suffix().first)
	{
		std::cout << "匹配：" << smt.str() << std::endl;
		std::cout << "tag:" << smt.str(1) << std::endl;
		std::cout << "value:" << smt.str(2) << std::endl;
	}

	std::cout << std::endl;

	//使用sregex_iterator进行迭代. 可以看出整体结构简洁清晰.
	std::cout << "使用sregex_iterator进行迭代:" << std::endl;
	std::sregex_iterator srgIterPos(strData.cbegin(),strData.cend(),rgPattern);
	std::sregex_iterator srgIterEnd;//默认构造函数初始化为end

	for (;srgIterPos!=srgIterEnd;++srgIterPos)
	{
		std::cout << "匹配：" << srgIterPos->str() << std::endl;
		std::cout << "tag:" << srgIterPos->str(1) << std::endl;
		std::cout << "value:" << srgIterPos->str(2) << std::endl;

	}

	std::cout << std::endl;
	std::cout << "使用for_each通用算法+函数对象迭代:" << std::endl;

	//使用for_each通用算法+函数对象迭代
	//更加简洁
	std::sregex_iterator srgIterBegin(strData.cbegin(),strData.cend(),rgPattern);

	std::for_each(srgIterBegin, srgIterEnd, [](const std::smatch & s)
	{
		std::cout << "匹配：" << s.str() << std::endl;
		std::cout << "tag:" << s.str(1) << std::endl;
		std::cout << "value:" << s.str(2) << std::endl;
	
	});


}

int maindaily0201()
{

	func_regex_iter_inside();

	std::string strInput;

	std::getline(std::cin,strInput);

	return 1;
}