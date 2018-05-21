//daily0129
/************************************************************************/
/* 
为string写一个class_traits，支持大小写不敏感的查找与比较

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <cctype> //toupper，tolower

class icase_traits : public std::string::traits_type
{
public:
	static bool eq(const char &psrc, const char &pdst);
	static bool lt(const char &psrc, const char &pdst);
	static int compare(const char* psrc, const char* pdst, std::size_t n);
	static const char* find(const char* psrc,std::size_t n,const char& c);
};

bool icase_traits::eq(const char &psrc, const char &pdst)
{
	return std::toupper(psrc) == std::toupper(pdst);
}


bool icase_traits::lt(const char &psrc, const char &pdst)
{
	return std::toupper(psrc) < std::toupper(pdst);
}

int icase_traits::compare(const char* psrc, const char* pdst, std::size_t n)
{
	for (std::size_t i=0;i<n;++i)
	{
		if (!eq(psrc[i],pdst[i]))
		{
			return lt(psrc[i], pdst[i]) ? -1 : 1;
		}
	}

	return 0;
}

const char* icase_traits::find(const char* psrc, std::size_t n, const char& c)
{
	for (std::size_t i=0;i<n;++i)
	{
		if (eq(psrc[i],c))
		{
			return &psrc[i];
		}
	}

	return 0;
}

typedef std::basic_string<char,icase_traits> icasestring;


//重载
std::ostream& operator << (std::ostream & os, const icasestring &s)
{
	return os << std::string(s.data(), s.length());
}


void func_test_icastring()
{
	icasestring icstring("I'm from JiaoZuo .");
	if (icstring.find("jiaozuo") != std::string::npos)
	{
		std::cout << "Find jiaozuo" << std::endl;
	}
	else
	{
		std::cout << "Not Found ." << std::endl;
	}

	icasestring icstring2("HELLO");
	if (icstring2=="hello")
	{
		std::cout << "HELLO == hello" << std::endl;
	}

}

int maindaily0129()
{
	func_test_icastring();

	std::string strInput;

	std::getline(std::cin, strInput);
	return 1;
}