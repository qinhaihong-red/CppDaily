//daily0207
/************************************************************************/
/* 
ʹ����������ģʽ�滻

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <regex>
#include <iterator>


void func_regex_replace()
{
	std::string strPlayer = "<player>\n"
		"<first>James</first>\n"
		"<second>Harden</second>\n"
		"</player>\n";

	std::regex rgPattern("<(.*)>(.*)</(\\1)>");
	std::string strReplaceAsSed("<\\1 value=\"\\2\"/>");
	std::string strReplace("<$1 value=\"$2\"/>");

	std::cout << "Regex Replace(normal) :" << std::regex_replace(strPlayer, rgPattern, strReplace) << std::endl;
	std::cout << "Regex Replace (sed style):" << std::regex_replace(strPlayer, rgPattern, strReplaceAsSed, std::regex_constants::format_sed) << std::endl;

	//ʹ�õ������汾���滻
	std::string strOutput;
	std::regex_replace(std::back_inserter(strOutput), strPlayer.cbegin(), strPlayer.cend(), rgPattern, strReplace, std::regex_constants::format_no_copy | std::regex_constants::format_first_only);
	std::cout << "Regex Replace(using iterator):" << strOutput << std::endl;

}


int maindaily0207()
{
	func_regex_replace();

	std::string strInput;
	std::getline(std::cin, strInput);
	return 1;
}