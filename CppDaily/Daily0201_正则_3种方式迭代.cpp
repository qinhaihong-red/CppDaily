//daily0201
/************************************************************************/
/* 
������ʽ�����������
�����ַ�ʽ���������飺
1.regex_search
2.sregex_iteratorѭ��
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

	//std::regex rgPattern("<(.*)>(.*)</(\\1)>");//���ڽ����ƥ�䣬���ֻ�������ƥ���ˣ�����û�е���ƥ��
	std::regex rgPattern("<(.*)>([^<]*)</(\\1)>");//�������Ե����ڲ�


	std::smatch smt;
	auto iterPos = strData.cbegin();
	auto iterEnd   = strData.cend();

	//ʹ��regex_searchѭ������
	for (;std::regex_search(iterPos,iterEnd,smt,rgPattern);iterPos=smt.suffix().first)
	{
		std::cout << "ƥ�䣺" << smt.str() << std::endl;
		std::cout << "tag:" << smt.str(1) << std::endl;
		std::cout << "value:" << smt.str(2) << std::endl;
	}

	std::cout << std::endl;

	//ʹ��sregex_iterator���е���. ���Կ�������ṹ�������.
	std::cout << "ʹ��sregex_iterator���е���:" << std::endl;
	std::sregex_iterator srgIterPos(strData.cbegin(),strData.cend(),rgPattern);
	std::sregex_iterator srgIterEnd;//Ĭ�Ϲ��캯����ʼ��Ϊend

	for (;srgIterPos!=srgIterEnd;++srgIterPos)
	{
		std::cout << "ƥ�䣺" << srgIterPos->str() << std::endl;
		std::cout << "tag:" << srgIterPos->str(1) << std::endl;
		std::cout << "value:" << srgIterPos->str(2) << std::endl;

	}

	std::cout << std::endl;
	std::cout << "ʹ��for_eachͨ���㷨+�����������:" << std::endl;

	//ʹ��for_eachͨ���㷨+�����������
	//���Ӽ��
	std::sregex_iterator srgIterBegin(strData.cbegin(),strData.cend(),rgPattern);

	std::for_each(srgIterBegin, srgIterEnd, [](const std::smatch & s)
	{
		std::cout << "ƥ�䣺" << s.str() << std::endl;
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