//daily0629
/************************************************************************/
/* 

一.1次匹配或查找
bool regex_match(data,smatch,regex_pat,[flags])
bool regex_match(beg,end,smatch,regex_pat,[flags])
bool regex_search(data,smatch,regex_pat,[flags])
bool regex_search(beg,end,smatch,regex_pat,[flags])

1.匹配与查找的区别在于，匹配要求从头到尾，全部匹配模式；查找仅要求部分匹配即可.python是re.match与re.search.
2.返回bool表示匹配与查找是否成功.匹配的结果，存放在smatch中.python如匹配到，则返回已匹配的re对象，否则返回None.
3.regex_pat要求regex类型.可以使用R("pat")来避免模式中的转义字符.python是r"pat".

二.匹配结果：smatch(cmatch,wsmatch,wcmatch)
1.匹配结果类型结构的使用，根据不同的data类型：const char *str ,std::string,std::wstring,const wchar_t *wstr，
分为 smatch, match, wsmatch, wcmatch. 以下以smatch为例子讨论.

2.smatch分为三部分：
--prefix:sub_match对象.匹配部分之前的内容.
--sub_match[n]数组:匹配到的部分. 如果包含分组，则分组从下标1开始依次位于sub_match[n]中.
  通过对smatch中的sub_match遍历或者迭代，可以获得全部分组的内容.类似于pyton的group,group(n).
--suffix:sub_match对象.匹配部分之后的内容.

每个sub_match继承于一个pair，包含该部分的起止位置（起：first，止：second），可利用这个信息在for中
遍历data所有符合模式的smatch.

三.通过循环查找全部匹配的内容
有2中方法：
1.使用for循环，对data进行regex_search遍历，每次得到匹配到的smatch并更新regex_search中的起始查找位置.
  该方法逻辑清晰，但是稍微复杂.
2.使用regex_iterator对data进行迭代.每次迭代成功得到smatch，进行解析.

对应于python中的findall和finditer.

四.切分或分词
regex_token_iterator:使用方法类似于regex_iterator.可以指定某些flags以定制某些需求.

类似于python的re.split

五.替换
string regex_replace(data,regex,repl,[flags])
iter regex_replace(dstIter,beg,end,regex,repl,[flags])
1.有两个版本：分别为string版本与迭代器版本.指的是输入，输出，返回的方式的不同.
2.repl指的是替换规格.必须以std::string类型指定.

类似于python的re.sub与re.subn.


/////
注意：
1.匹配任意字符，理论上是[.\n]*，但是没有用.在C++中使用 (.|\n)* 代替.而括号()并非是分组的意思.
如果要添加分组，必须在外层再加括号.

2.去除字符串头尾的正则表达式，理论上是:(^\s*)((.|\n)*?)(\s*$)，但C++的正则库对\s的解析有别于python.
可以使用(^[ \t\n]*)((.|\n)*?)([ \t\n]*$)或者(^[[:blank:]]*)((.|\n)*?)([[:blank:]]*$)进行替换.

*/
/************************************************************************/


#include "common/common.h"
#include <regex>

void func_algor_0626()
{
	std::string data = "<html>\n\
<player>James1</player>\n\
<player>Durant2</player>\n\
<player>Curry3</player>\n\
</html>";

	std::cout << "data is:\n" << data << std::endl;

	//1.一次匹配：regex_match
	bool bFind = false;
	std::smatch sm;

	bFind = std::regex_match(data, sm, std::regex("<html>((.|\n)*)</html>"));//[.\n]* 不可用，以(.|\n)* 代替.
	if (bFind)
	{
		std::cout << "\n1.regex_match:\n";
		std::cout << "\nmatch:\n" << sm.str() << std::endl;
		for (int i=1;i<sm.size();++i)
		{
			if (!sm.str(i).empty())
			{
				std::cout << "group[" << i << "]:" << sm.str(i) << std::endl;
			}			
		}
	}
	else
	{
		std::cout << "Not Match.\n";
	}

	//2.一次查找：regex_search
	std::smatch s2;
	bFind = std::regex_search(data, s2, std::regex(R"(<(.*)>(.*)</\1>)"));//避免转义，使用raw string:R"()"
	if (bFind)
	{
		std::cout << "\n2.regex_search(once):\n";
		std::cout << "\nmatch:\n" << s2.str() << std::endl;
		for (int i = 1; i < s2.size(); ++i)
		{
			if (!s2.str(i).empty())
			{
				std::cout << "group[" << i << "]:" << s2.str(i) << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Not Match.\n";
	}

	//3.通过遍历或者迭代查找所有匹配的内容
	//>通过遍历：在for循环中不断更新regex_search的查找位置.过程比较清晰，略微繁琐.
	std::smatch s3;
	auto pos = data.cbegin();//迭代器必须是const型
	auto end = data.cend();

	std::cout << "\n3(1).遍历所有匹配内容（通过for循环regex_search）:\n";
	for (;std::regex_search(pos,end,s3,std::regex(R"(<(.*)>(.*)</\1>)"));pos=s3.suffix().first)
	{
		std::cout << "\nmatch:\n" << s3.str() << std::endl;
		for (int i = 1; i < s3.size(); ++i)
		{
			if (!s3.str(i).empty())
			{
				std::cout << "group[" << i << "]:" << s3.str(i) << std::endl;
			}
		}
	}

	std::cout<< "\n3(2).迭代所有匹配内容（通过regex_iterator）:\n";
	std::regex r3("<(.*)>(.*)</\\1>");
	std::sregex_iterator regIter(data.cbegin(),data.cend(),r3);//这里不能传入临时的regex对象给iterator,因为可能导致指针失效的问题.参考：https://stackoverflow.com/questions/29895747/visual-studio-regex-iterator-bug
	std::sregex_iterator regEnd;//默认初始化为结束标记.

	//>通过sregex_iterator迭代所有匹配对象
	for (;regIter!=regEnd;++regIter)
	{
		std::cout << "\nmatch:\n" << regIter->str() << std::endl;
		for (int i=1;i<regIter->size();++i)//每个迭代器是一个sub_match对象
		{
			if (!regIter->str(i).empty())
			{
				std::cout << "group[" << i << "]:" << regIter->str(i) << std::endl;
			}
		}
	}

	//4.分词
	//分词的使用，类似于使用迭代器迭代所有匹配
	std::string names = "   james; harden.  curry,  durant   ";//前后的空行需要先除去

	std::smatch s4;
	if (std::regex_match(names,s4,std::regex("(^[[:blank:]]*)(.*?)([[:blank:]]*$)")))//std::regex("(^\s*)(.*?)(\s*$)")却不行
	{
		names = s4.str(2);//第二个分组中*后面的的问号，表示非贪婪匹配.
	}

	//std::regex r4("[[:space:]]*[;.,][[:space:]]*");
	std::regex r4("[ \t\n]*[;.,][ \t\n]*");//\s不能匹配空白.python可以.
	std::sregex_token_iterator tIter(names.cbegin(),names.cend(),r4,-1);//-1:取分隔符之间的值
	std::sregex_token_iterator tEnd;

	std::cout << "\n4.使用srgex_token_iteratro进行分词：\n";
	std::cout << "original names list:" << names << std::endl;
	std::cout << "separated as follow:\n";

	while (tIter !=tEnd )
	{
		std::cout << *tIter << std::endl;
		++tIter;
	}

	//5.替换
	//替换有两种形式，一种是字符串输入输出，一种是迭代器输入输出

	std::string data2 = "   <html>\n\
<player>James1</player>\n\
<player>Durant2</player>\n\
<player>Curry3</player>\n\
</html>   ";

	std::cout << "\n5.regex_replace:\n";
	//5.1 先把data2中首尾的空白字符，以替换的方式去除
	std::string data2_clean = std::regex_replace(data2, std::regex("(^ *)(.*)( *$)"), "$2");//$n表示\\n
	std::cout << "clean data is:" << data2_clean << std::endl;


	//5.2 进行替换
	std::string strRet;
	std::regex_replace(std::back_inserter(strRet),//使用迭代器版本：目标迭代器
		data2_clean.cbegin(), data2_clean.cend(),//原始数据迭代器
		std::regex("<(.*)>(.*)</(\\1)>"),//
		"<$1 value=\"$2\">");//注意这里替换表达式为string类型.但是使用分组的方法，与regex里面使用的又不一样：用$n替换\\n.
							 //如果想用\\n,需要指定std::regex_constants::format_set标志.
	std::cout << "after replacement:\n" << strRet << std::endl;

	//如果只想返回被替换后的结果而不需要全部的包含未被替换的内容，可以指定format_no_copy标志
	strRet.clear();
	std::regex_replace(std::back_inserter(strRet),
		data2_clean.cbegin(), data2_clean.cend(),
		std::regex("<(.*)>(.*)</(\\1)>"),
		"<\\1 value=\"\\2\">",//使用sed格式描述替换内容
		std::regex_constants::format_no_copy | std::regex_constants::format_sed);

	std::cout << "after replacement(with format_no_copy and format_sed):\n" << strRet << std::endl;
}


int main()
{
	func_algor_0626();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}