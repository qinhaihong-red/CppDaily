//daily0501
/************************************************************************/
/* 

1.map���ƾ����Զ������vector��֧��.at()��[]�±����.
2.�ڲ��Ժ����ʵ��.��������˫�������.����Ҫ��������������㷨������֧��.
3.ͨ��.eraseɾ���ڵ�Ҫע�������ʧЧ�����⣬���룺erase(pos++)

*/
/************************************************************************/

#include"./common/common.h"


#include <cctype>//toupper tolower
void func_map_inside()
{

	//��Сд�����е�����׼��.
	auto f_compare = [](const std::string& s1, const std::string &s2)
	{
		return std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end(),
			[](char c1, char c2) {return std::toupper(c1) < std::toupper(c2); });
	
	};

	//Ĭ�ϵ�����׼��:��Сд����
	//typedef std::map<std::string, int> PlayerType;

	//�Զ�������׼�򣺴�Сд������
	typedef std::map<std::string, int,decltype(f_compare)> PlayerType;
	PlayerType players(f_compare);

	//1.����
	//-ʹ�ó�ֵ�б�
	players.insert({ "James",99 });
	players.insert({ "curry",97 });

	//-ʹ�����͵�value type
	players.insert(PlayerType::value_type("Durant", 98));

	//-ֱ��ʹ��pair type
	players.insert(std::pair<std::string,int>("harden",97));//������ʵ��������ʽת��
	players.insert(std::pair<const std::string,int>("WB",97));

	//-ʹ��make pair
	players.insert(std::make_pair("Paul",90));

	//-[]
	players["Davis"] = 91;

	//2.ѭ��
	for (auto &i:players)
	{
		i.second += 100;
	}

	std::for_each(players.begin(), players.end(), [](PlayerType::value_type &i)
	{
		std::cout << i.first << " " << i.second << std::endl;
	});
	
}


int maindaily0501()
{

	func_map_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}