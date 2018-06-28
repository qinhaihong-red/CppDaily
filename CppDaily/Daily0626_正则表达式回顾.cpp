//daily0629
/************************************************************************/
/* 

һ.1��ƥ������
bool regex_match(data,smatch,regex_pat,[flags])
bool regex_match(beg,end,smatch,regex_pat,[flags])
bool regex_search(data,smatch,regex_pat,[flags])
bool regex_search(beg,end,smatch,regex_pat,[flags])

1.ƥ������ҵ��������ڣ�ƥ��Ҫ���ͷ��β��ȫ��ƥ��ģʽ�����ҽ�Ҫ�󲿷�ƥ�伴��.python��re.match��re.search.
2.����bool��ʾƥ��������Ƿ�ɹ�.ƥ��Ľ���������smatch��.python��ƥ�䵽���򷵻���ƥ���re���󣬷��򷵻�None.
3.regex_patҪ��regex����.����ʹ��R("pat")������ģʽ�е�ת���ַ�.python��r"pat".

��.ƥ������smatch(cmatch,wsmatch,wcmatch)
1.ƥ�������ͽṹ��ʹ�ã����ݲ�ͬ��data���ͣ�const char *str ,std::string,std::wstring,const wchar_t *wstr��
��Ϊ smatch, match, wsmatch, wcmatch. ������smatchΪ��������.

2.smatch��Ϊ�����֣�
--prefix:sub_match����.ƥ�䲿��֮ǰ������.
--sub_match[n]����:ƥ�䵽�Ĳ���. ����������飬�������±�1��ʼ����λ��sub_match[n]��.
  ͨ����smatch�е�sub_match�������ߵ��������Ի��ȫ�����������.������pyton��group,group(n).
--suffix:sub_match����.ƥ�䲿��֮�������.

ÿ��sub_match�̳���һ��pair�������ò��ֵ���ֹλ�ã���first��ֹ��second���������������Ϣ��for��
����data���з���ģʽ��smatch.

��.ͨ��ѭ������ȫ��ƥ�������
��2�з�����
1.ʹ��forѭ������data����regex_search������ÿ�εõ�ƥ�䵽��smatch������regex_search�е���ʼ����λ��.
  �÷����߼�������������΢����.
2.ʹ��regex_iterator��data���е���.ÿ�ε����ɹ��õ�smatch�����н���.

��Ӧ��python�е�findall��finditer.

��.�зֻ�ִ�
regex_token_iterator:ʹ�÷���������regex_iterator.����ָ��ĳЩflags�Զ���ĳЩ����.

������python��re.split

��.�滻
string regex_replace(data,regex,repl,[flags])
iter regex_replace(dstIter,beg,end,regex,repl,[flags])
1.�������汾���ֱ�Ϊstring�汾��������汾.ָ�������룬��������صķ�ʽ�Ĳ�ͬ.
2.replָ�����滻���.������std::string����ָ��.

������python��re.sub��re.subn.


/////
ע�⣺
1.ƥ�������ַ�����������[.\n]*������û����.��C++��ʹ�� (.|\n)* ����.������()�����Ƿ������˼.
���Ҫ��ӷ��飬����������ټ�����.

2.ȥ���ַ���ͷβ��������ʽ����������:(^\s*)((.|\n)*?)(\s*$)����C++��������\s�Ľ����б���python.
����ʹ��(^[ \t\n]*)((.|\n)*?)([ \t\n]*$)����(^[[:blank:]]*)((.|\n)*?)([[:blank:]]*$)�����滻.

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

	//1.һ��ƥ�䣺regex_match
	bool bFind = false;
	std::smatch sm;

	bFind = std::regex_match(data, sm, std::regex("<html>((.|\n)*)</html>"));//[.\n]* �����ã���(.|\n)* ����.
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

	//2.һ�β��ң�regex_search
	std::smatch s2;
	bFind = std::regex_search(data, s2, std::regex(R"(<(.*)>(.*)</\1>)"));//����ת�壬ʹ��raw string:R"()"
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

	//3.ͨ���������ߵ�����������ƥ�������
	//>ͨ����������forѭ���в��ϸ���regex_search�Ĳ���λ��.���̱Ƚ���������΢����.
	std::smatch s3;
	auto pos = data.cbegin();//������������const��
	auto end = data.cend();

	std::cout << "\n3(1).��������ƥ�����ݣ�ͨ��forѭ��regex_search��:\n";
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

	std::cout<< "\n3(2).��������ƥ�����ݣ�ͨ��regex_iterator��:\n";
	std::regex r3("<(.*)>(.*)</\\1>");
	std::sregex_iterator regIter(data.cbegin(),data.cend(),r3);//���ﲻ�ܴ�����ʱ��regex�����iterator,��Ϊ���ܵ���ָ��ʧЧ������.�ο���https://stackoverflow.com/questions/29895747/visual-studio-regex-iterator-bug
	std::sregex_iterator regEnd;//Ĭ�ϳ�ʼ��Ϊ�������.

	//>ͨ��sregex_iterator��������ƥ�����
	for (;regIter!=regEnd;++regIter)
	{
		std::cout << "\nmatch:\n" << regIter->str() << std::endl;
		for (int i=1;i<regIter->size();++i)//ÿ����������һ��sub_match����
		{
			if (!regIter->str(i).empty())
			{
				std::cout << "group[" << i << "]:" << regIter->str(i) << std::endl;
			}
		}
	}

	//4.�ִ�
	//�ִʵ�ʹ�ã�������ʹ�õ�������������ƥ��
	std::string names = "   james; harden.  curry,  durant   ";//ǰ��Ŀ�����Ҫ�ȳ�ȥ

	std::smatch s4;
	if (std::regex_match(names,s4,std::regex("(^[[:blank:]]*)(.*?)([[:blank:]]*$)")))//std::regex("(^\s*)(.*?)(\s*$)")ȴ����
	{
		names = s4.str(2);//�ڶ���������*����ĵ��ʺţ���ʾ��̰��ƥ��.
	}

	//std::regex r4("[[:space:]]*[;.,][[:space:]]*");
	std::regex r4("[ \t\n]*[;.,][ \t\n]*");//\s����ƥ��հ�.python����.
	std::sregex_token_iterator tIter(names.cbegin(),names.cend(),r4,-1);//-1:ȡ�ָ���֮���ֵ
	std::sregex_token_iterator tEnd;

	std::cout << "\n4.ʹ��srgex_token_iteratro���зִʣ�\n";
	std::cout << "original names list:" << names << std::endl;
	std::cout << "separated as follow:\n";

	while (tIter !=tEnd )
	{
		std::cout << *tIter << std::endl;
		++tIter;
	}

	//5.�滻
	//�滻��������ʽ��һ�����ַ������������һ���ǵ������������

	std::string data2 = "   <html>\n\
<player>James1</player>\n\
<player>Durant2</player>\n\
<player>Curry3</player>\n\
</html>   ";

	std::cout << "\n5.regex_replace:\n";
	//5.1 �Ȱ�data2����β�Ŀհ��ַ������滻�ķ�ʽȥ��
	std::string data2_clean = std::regex_replace(data2, std::regex("(^ *)(.*)( *$)"), "$2");//$n��ʾ\\n
	std::cout << "clean data is:" << data2_clean << std::endl;


	//5.2 �����滻
	std::string strRet;
	std::regex_replace(std::back_inserter(strRet),//ʹ�õ������汾��Ŀ�������
		data2_clean.cbegin(), data2_clean.cend(),//ԭʼ���ݵ�����
		std::regex("<(.*)>(.*)</(\\1)>"),//
		"<$1 value=\"$2\">");//ע�������滻���ʽΪstring����.����ʹ�÷���ķ�������regex����ʹ�õ��ֲ�һ������$n�滻\\n.
							 //�������\\n,��Ҫָ��std::regex_constants::format_set��־.
	std::cout << "after replacement:\n" << strRet << std::endl;

	//���ֻ�뷵�ر��滻��Ľ��������Ҫȫ���İ���δ���滻�����ݣ�����ָ��format_no_copy��־
	strRet.clear();
	std::regex_replace(std::back_inserter(strRet),
		data2_clean.cbegin(), data2_clean.cend(),
		std::regex("<(.*)>(.*)</(\\1)>"),
		"<\\1 value=\"\\2\">",//ʹ��sed��ʽ�����滻����
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