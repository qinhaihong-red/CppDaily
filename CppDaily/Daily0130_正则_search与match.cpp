//daily0130
/************************************************************************/
/* 
������ʽ���
ע��regex_search��regex_match������
ǰ��ƥ�䲿�֣�����ȫ��ƥ��.

*/
/************************************************************************/


#include <iostream>
#include <regex>
#include <string>


void func_regex_inside()
{
	std::regex reg1("<.*>.*</.*>");//��ƥ���ģʽ ע�� ���� . ��ʾƥ���\n����������ַ�
	bool bFind = false;
	bFind = std::regex_match("<tag>values</gat>", reg1);

	std::cout << std::string(bFind ? "Found" : "Not Found") << std::endl;//Found

	std::regex reg2("<(.*).*</\\1>");//ʹ�ò����飬��ǰ�󱣳�һ��
	bFind = std::regex_match("<tag>values</gat>", reg2);
	std::cout << std::string(bFind ? "Found" : "Not Found") << std::endl;//Not Found

	bFind = std::regex_match("<tag>values</tag>", reg2);
	std::cout << std::string(bFind ? "Found" : "Not Found") << std::endl;//Found

	std::cout << std::endl;


	//match�޷�ƥ��
	bFind = std::regex_match("XML tag: <tag>vaules</tag>", std::regex("<.*>.*</.*>"));
	std::cout << std::string(bFind ? "Found" : "Not Found") << std::endl;//Not Found

	//�����޸ģ�
	//1.��match�����޸�
	bFind = std::regex_match("XML tag: <tag>vaules</tag>", std::regex(".*<.*>.*</.*>.*"));
	std::cout << std::string(bFind ? "Found" : "Not Found") << std::endl;//Found

	//2.ʹ��regex_search���в���ƥ��
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