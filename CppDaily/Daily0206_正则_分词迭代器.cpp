//daily0206
/************************************************************************/
/* 
分词迭代器：把长句分解为一个个单词
*/
/************************************************************************/


#include <iostream>
#include <string>
#include <regex>
#include <algorithm>

bool stringtrim(std::string &strIn,std::string &strOut)
{
	std::string token(" \t\n");
	std::string::size_type posBegin = strIn.find_first_not_of(token);
	std::string::size_type posEnd = strIn.find_last_not_of(token);

	if (posBegin!=std::string::npos && posEnd!=std::string::npos)
	{
		strOut = strIn.substr(posBegin, posEnd - posBegin+1);
	}
	else
	{
		//
	}

	return true;
}

void func_regex_token_iterator_inside()
{
	std::string strPlayer = "<player>\n"
		"<first>James</first>"
		"<second>Harden</second>"
		"</player>\n";


	std::regex rgPattern("<(.*)>(.*)</(\\1)>");
	std::sregex_token_iterator rgTkIterPos(strPlayer.cbegin(), strPlayer.cend(), rgPattern, {0,2});
	std::sregex_token_iterator rgTkIterEnd;

	std::cout << "the player is :" << std::endl;
	for (;rgTkIterPos!=rgTkIterEnd;++rgTkIterPos)
	{
		std::cout << rgTkIterPos->str() << std::endl;
	}

	std::cout << std::endl;

	std::string strPlayers = "  curry ,  durant,  thompson. harden;love ";
	std::regex  rgPattern2("[ \t\n]*[,;.][ \t\n]*");
	std::sregex_token_iterator rgTkIterPos2(strPlayers.cbegin(), strPlayers.cend(), rgPattern2, {-1});

	std::cout << "player name:" << std::endl;
	std::for_each(rgTkIterPos2, rgTkIterEnd, [](const std::ssub_match &sm)
	{
		std::cout<< sm.str() << std::endl;
	});


	std::cout << std::endl;
	std::string strOut;
	stringtrim(strPlayers,strOut);
	std::cout << "trim test:" << strOut << std::endl;

}


int maindaily0206()
{
	func_regex_token_iterator_inside();

	

	std::string strInput;
	std::getline(std::cin, strInput);

	return 1;
}