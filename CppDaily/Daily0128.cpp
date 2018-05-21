//daily0128
//���� string iterator ����ز���

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <regex>


void func_stringiter_operation()
{
	std::string strZipcode("The zipcode of Jiaozuo is 0391 .");
	std::cout << "Original ZipCode is :" << strZipcode << std::endl;

	std::transform(strZipcode.begin(), strZipcode.end(), strZipcode.begin(), [](char c)
	{
		return tolower(c);
	});

	std::cout << "Tolower is :" << strZipcode << std::endl;

	std::transform(strZipcode.begin(), strZipcode.end(), strZipcode.begin(), [](char c)
	{
		return toupper(c);
	});

	std::cout << "Toupper is :" << strZipcode << std::endl;

	//ʹ��search���д�Сд�����еĲ���
	std::string strDst("jiaozuo");
	std::string::const_iterator cIter = std::search(strZipcode.cbegin(), strZipcode.cend(), strDst.cbegin(), strDst.cend(), [](char c1, char c2)
	{
		return toupper(c1) == toupper(c2);
	});

	if (cIter != strZipcode.cend())
	{
		std::cout << "Find at index of:" << cIter - strZipcode.begin() << std::endl;
	}

	//ʹ���������в���
	std::regex pattern("jiaozuo",std::regex_constants::icase);
	std::smatch mt;
	if (std::regex_search(strZipcode,mt,pattern))
	{
		std::cout << "Find at index of :" << mt.position() << std::endl;
	}

	std::cout<<std::endl;
	//����
	for (char c : strZipcode)
	{
		std::cout << c;
	}
	std::cout << std::endl;

	//��ת
	std::reverse(strZipcode.begin(), strZipcode.end());
	std::cout << "Revers :" << strZipcode << std::endl;

	//strZipcode.erase(std::unique(strZipcode.begin(), strZipcode.end()), strZipcode.end());
	//std::cout << "After unique:" << strZipcode << std::endl;

	//����
	std::sort(strZipcode.begin(),strZipcode.end());
	std::cout << "Odered:" << strZipcode << std::endl;
	//
	//������ͬԪ��
	//ע�⣬unique���Ź����Ԫ�ط���һ���µ�end�����endָ���ظ�Ԫ�صĵ�һ��.
	//Ȼ�������Ԫ��Ϊ��ʼԪ�أ�ʹ��strring�ĳ�Ա��������ɾ��
	strZipcode.erase(std::unique(strZipcode.begin(), strZipcode.end()), strZipcode.end());
	std::cout << "After unique:" << strZipcode << std::endl;
}



int maindaily0128()
{
	func_stringiter_operation();

	std::string strInput;	
	std::getline(std::cin, strInput);
	return 1;
}