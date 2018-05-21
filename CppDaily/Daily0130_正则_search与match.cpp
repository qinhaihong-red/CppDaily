//daily0130
/************************************************************************/
/* 
正则表达式相关
注意regex_search与regex_match的区别：
前者匹配部分，后者全字匹配.

*/
/************************************************************************/


#include <iostream>
#include <regex>
#include <string>


void func_regex_inside()
{
	std::regex reg1("<.*>.*</.*>");//欲匹配的模式 注意 符号 . 表示匹配除\n以外的任意字符
	bool bFind = false;
	bFind = std::regex_match("<tag>values</gat>", reg1);

	std::cout << std::string(bFind ? "Found" : "Not Found") << std::endl;//Found

	std::regex reg2("<(.*).*</\\1>");//使用捕获组，即前后保持一致
	bFind = std::regex_match("<tag>values</gat>", reg2);
	std::cout << std::string(bFind ? "Found" : "Not Found") << std::endl;//Not Found

	bFind = std::regex_match("<tag>values</tag>", reg2);
	std::cout << std::string(bFind ? "Found" : "Not Found") << std::endl;//Found

	std::cout << std::endl;


	//match无法匹配
	bFind = std::regex_match("XML tag: <tag>vaules</tag>", std::regex("<.*>.*</.*>"));
	std::cout << std::string(bFind ? "Found" : "Not Found") << std::endl;//Not Found

	//进行修改：
	//1.对match进行修改
	bFind = std::regex_match("XML tag: <tag>vaules</tag>", std::regex(".*<.*>.*</.*>.*"));
	std::cout << std::string(bFind ? "Found" : "Not Found") << std::endl;//Found

	//2.使用regex_search进行部分匹配
	bFind = std::regex_search("XML tag: <tag>vaules</tag>", std::regex("<.*>.*</.*>"));
	std::cout << std::string(bFind ? "Found" : "Not Found") << std::endl;//Found
}


int maindaily0130()
{
	func_regex_inside();

	std::string strInput;
	std::getline(std::cin,strInput);

	return 1;
}