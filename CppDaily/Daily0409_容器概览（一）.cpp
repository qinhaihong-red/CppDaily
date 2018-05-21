//daily0409
/************************************************************************/
/* 

������
�������Ľṹ����Ϊ3�֣�
1.����ʽ������vector,list,array �ȣ��ڲ��� ���� ��ʵ��.
2.����ʽ������set,map,multiset,multimap�ȣ��ڲ��� ������ ��ʵ��.
3.����������unorderd_set,unordered_map,unordered_multiset,unordered_multimap���ڲ��� hash table ʵ��.

����ʽ������Բ����Ԫ�ؽ�������.��ʱ�򲻹�������ֻ����Ԫ���Ƿ��������У��Ƿ�Ψһ����
��ʱ����ʹ����������.

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <type_traits>

template<typename T>
void func_print_all_elements(const T &t)
{
	for (const auto &i:t)
	{
		std::cout << i <<std::endl;
	}
}

template<typename T1,typename T2>
void func_print_all_elements(const std::multimap<T1,T2> &t)
{
	for (const auto &i : t)
	{
		std::cout << i.first<<" "<<i.second << std::endl;
	}
}


void func_multiset_multimap_inside()
{
	std::multiset<std::string> s = {"james","jordan","wade","curry"};
	func_print_all_elements(s);
	std::cout << std::endl;


	s.insert("jordan");
	s.insert("james");
	func_print_all_elements(s);
	std::cout << std::endl;
}

//ʹ�� multimap �����ֵ�
//����ָ��key,��ӡ���ü���Ӧ������ֵ.
//����ָ��value����ӡ����ֵ��Ӧ�����м�.
void func_multimap_as_dict()
{
	std::multimap<std::string, std::string> mm = {
		{"shooter","curry"},
		{"forward","james"/*lbj,of course*/},
		{"guard"  ,"jordan"},
		{"shooter","thompson"},
		{"guard","james"/*jh,of course*/},
		{"shooter","allen"},
		{"center","o'neal"}
	};

	func_print_all_elements(mm);
	std::string str("shooter");
	//�������ֵ��е����� shooter ����Ӧ��ֵ.
	std::cout << "\nshooters are as followed:" << std::endl;

	for (auto pos=mm.lower_bound(str);pos!=mm.upper_bound(str);++pos)
	{
		std::cout << "\t"<<pos->second << std::endl;
	}

	//�������ֵ���ֵΪjames�ļ�
	str = "james";
	std::cout << "james are as followed:" << std::endl;

	for (auto &i:mm)
	{
		if (i.second == str)
		{
			std::cout << "\t" << i.first << std::endl;
		}
	}
}

int maindaily0409()
{
	func_multiset_multimap_inside();
	func_multimap_as_dict();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}