//daily0410
/************************************************************************/
/* 

��������ֻ���Ŀ����������в���Ԫ���Ƿ���ڣ���������
���������Ĺ��ɣ�
hash������bucket+����. �������ڳ�ͻ����.

STL�ṩ�˶��ڻ��������Լ�string��hash����.
��������Զ������ͣ���Ҫ�Զ���hash����.ͨ���������������������.


*/
/************************************************************************/

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>


void func_unordered_inside()
{
	std::cout << "unordered_multiset:" << std::endl;
	std::unordered_multiset<std::string> umt = {
	"beijing","shanghai","guangzhou","shenzhen",
	"chengdu","hangzhou","wuhan"	
	};

	for (auto &i:umt)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	umt.insert({"zhengzhou","beijing","shenzhen","jiaozuo"});

	for (auto &i : umt)
	{
		std::cout << i << " ";
	}
	std::cout << "\nunordered_map��"<<std::endl;
	std::unordered_map<std::string, double> nmp = {
		{"james",100},{"durant",99}	
	};

	for (std::pair<const std::string,double> &i:nmp)
	{
		i.second *= i.second;
	}

	for (auto &i:nmp)
	{
		std::cout << i.first << " " << i.second << std::endl;
	}
	std::cout << std::endl;
}

int maindaily0410()
{

	func_unordered_inside();
	
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}