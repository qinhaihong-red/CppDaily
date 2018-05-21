//daily0123
/*
写一个将文件名字符串abc.xzy改为abc.tmp的函数.
锻炼对string的使用
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

#define _SPLITTER "."
#define _TMPNAME "tmp"
#define _SAMPLE 4

bool func_change_suffix(const std::string &strSrcName, std::string &strDstName)
{
	if (strSrcName.empty())
	{
		strDstName = "";
		return false;
	}
	else
	{
		std::string::size_type nPos = strSrcName.find(_SPLITTER);
		if (std::string::npos == nPos)
		{
			strDstName = strSrcName + _SPLITTER+ _TMPNAME;
		}
		else
		{
			strDstName = strSrcName.substr(0, nPos + 1);
			strDstName += _TMPNAME;
		}
	}

	return true;
}

void test_func_change_suffix()
{
	char* str[_SAMPLE] = {"james.txt", "wade.bat", "curry" , "thompson.tmp"};
	std::vector<std::string> strOut(_SAMPLE);

	std::cout << "before change:" << std::endl;
	for (int i=0;i<_SAMPLE;++i)
	{
		std::cout << str[i] << std::endl;
		func_change_suffix(str[i], strOut[i]);
	}


	std::cout << std::endl << "after change:" << std::endl;
	for (auto iter=strOut.begin();iter!=strOut.end();++iter)
	{
		std::cout << *iter << std::endl;
	}

}

int maindaily0123()
{
	
	test_func_change_suffix();
	std::getchar();
	return 1;
}