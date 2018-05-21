//daily0124
//写出反转输入单词的函数

#include <iostream>
#include <string>

#define _DILIMTER " \t,."

bool func_reverse_words(const std::string &strInput,std::string &strOutput,const std::string &strDilimter=_DILIMTER)
{
	if (strInput.empty())
	{
		return false;
	}

	strOutput = strInput;
	std::string::size_type nBegin = strInput.find_first_not_of(strDilimter);
	while (nBegin != std::string::npos)
	{
		std::string::size_type szPos = strInput.find_first_of(strDilimter,nBegin);
		if (szPos == std::string::npos)
		{
			szPos = strInput.length();
		}

		std::string strTemp;
		for (int i= szPos-1;i>=static_cast<int>(nBegin);--i)
		{
			strTemp.push_back(strOutput[i]);
		}
		strOutput.replace(nBegin,szPos-nBegin ,strTemp);

		nBegin = strInput.find_first_not_of(strDilimter,szPos);
	}

	return true;
}


void test_func_reverse_words()
{
	std::string strInput1("james wade paul"), strOutput;
	func_reverse_words(strInput1, strOutput);

	std::cout << strOutput.c_str() << std::endl;

	std::string strInput2("james.wade.paul");
	func_reverse_words(strInput2, strOutput);

	std::cout << strOutput.c_str() << std::endl;
}


int mainDaily0124()
{
	test_func_reverse_words();

	std::string strInput;
	std::getline(std::cin, strInput);
	return 1;
}