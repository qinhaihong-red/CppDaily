//daily0131
/************************************************************************/
/* 
正则表达式相关
match_result

*/
/************************************************************************/

#include <iostream>
#include <regex>
#include <string>
#include <iomanip>


void func_regex_matchresult_inside()
{
	std::string strData = "XML tag: <tag_name>value</tag_name>.";
	std::regex rgPattern("<(.*)>(.*)</(\\1)>");

	std::smatch smResult;//std::match_results<string> for string regex

	bool bFound = std::regex_search(strData, smResult, rgPattern);

	if (!bFound)
	{
		std::cout << "Not Found Any Pattern in Data ." << std::endl;
		return;
	}

	std::cout << "size(sub_match对象的个数):" << smResult.size() << std::endl;
	std::cout << "str(找到的符合模式的字符串总体):" << smResult.str() << std::endl;
	std::cout << "str长度:" << smResult.length() << std::endl;
	std::cout << "str的起始位置:" << smResult.position() << std::endl;
	std::cout << "模式之前的字符串:" << smResult.prefix().str() << std::endl;
	std::cout << "模式之后的字符串:" << smResult.suffix().str() << std::endl;
	std::cout << std::endl;

	//以下标方式遍历所有匹配
	for (int i=0;i<smResult.size();++i)
	{
		std::cout << "第 " << i << " 个 字符串：" << smResult.str(i) << std::endl;
		std::cout << "起始位置:" << smResult.position(i) << std::endl;
		std::cout << std::endl;
	}

	//以迭代器方式遍历所有匹配
	for (auto iter=smResult.begin();iter!=smResult.end();++iter)
	{
		std::cout << *iter << "  ,长度是：" << iter->length() << std::endl;
	}

}


int maindaily0131()
{
	func_regex_matchresult_inside();

	std::string strInput;
	std::getline(std::cin,strInput);
	return 1;
}