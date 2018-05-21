//daily0128
//关于 string iterator 的相关操作

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

	//使用search进行大小写不敏感的查找
	std::string strDst("jiaozuo");
	std::string::const_iterator cIter = std::search(strZipcode.cbegin(), strZipcode.cend(), strDst.cbegin(), strDst.cend(), [](char c1, char c2)
	{
		return toupper(c1) == toupper(c2);
	});

	if (cIter != strZipcode.cend())
	{
		std::cout << "Find at index of:" << cIter - strZipcode.begin() << std::endl;
	}

	//使用正则库进行查找
	std::regex pattern("jiaozuo",std::regex_constants::icase);
	std::smatch mt;
	if (std::regex_search(strZipcode,mt,pattern))
	{
		std::cout << "Find at index of :" << mt.position() << std::endl;
	}

	std::cout<<std::endl;
	//遍历
	for (char c : strZipcode)
	{
		std::cout << c;
	}
	std::cout << std::endl;

	//反转
	std::reverse(strZipcode.begin(), strZipcode.end());
	std::cout << "Revers :" << strZipcode << std::endl;

	//strZipcode.erase(std::unique(strZipcode.begin(), strZipcode.end()), strZipcode.end());
	//std::cout << "After unique:" << strZipcode << std::endl;

	//排序
	std::sort(strZipcode.begin(),strZipcode.end());
	std::cout << "Odered:" << strZipcode << std::endl;
	//
	//擦除相同元素
	//注意，unique对排过序的元素返回一个新的end，这个end指向重复元素的第一个.
	//然后以这个元素为起始元素，使用strring的成员函数进行删除
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