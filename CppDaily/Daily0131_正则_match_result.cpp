//daily0131
/************************************************************************/
/* 
������ʽ���
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

	std::cout << "size(sub_match����ĸ���):" << smResult.size() << std::endl;
	std::cout << "str(�ҵ��ķ���ģʽ���ַ�������):" << smResult.str() << std::endl;
	std::cout << "str����:" << smResult.length() << std::endl;
	std::cout << "str����ʼλ��:" << smResult.position() << std::endl;
	std::cout << "ģʽ֮ǰ���ַ���:" << smResult.prefix().str() << std::endl;
	std::cout << "ģʽ֮����ַ���:" << smResult.suffix().str() << std::endl;
	std::cout << std::endl;

	//���±귽ʽ��������ƥ��
	for (int i=0;i<smResult.size();++i)
	{
		std::cout << "�� " << i << " �� �ַ�����" << smResult.str(i) << std::endl;
		std::cout << "��ʼλ��:" << smResult.position(i) << std::endl;
		std::cout << std::endl;
	}

	//�Ե�������ʽ��������ƥ��
	for (auto iter=smResult.begin();iter!=smResult.end();++iter)
	{
		std::cout << *iter << "  ,�����ǣ�" << iter->length() << std::endl;
	}

}


int maindaily0131()
{
	func_regex_matchresult_inside();

	std::string strInput;
	std::getline(std::cin,strInput);
	return 1;
}