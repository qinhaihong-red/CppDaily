//daily0411
/************************************************************************/
/* 

�㷨��ŷ�Ϊ���ң�������ֵ���㣬�任�ȵ�.
��������� gp ģʽ��ǿ����.
ע�����뵽�㷨�������ǰ뿪���䣺[ )��������ҿ�����.

*/
/************************************************************************/


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

void func_algor_simple()
{
	std::vector<int> vec = { 25,3,9,44,65,1,7 };
	auto minpos = std::min_element(vec.begin(), vec.end());
	std::cout << "min elem of vec is: " << *minpos << std::endl;

	auto maxpos = std::max_element(vec.begin(), vec.end());
	std::cout << "max elem of vec is: " << *maxpos << std::endl;

	std::cout << "\nbefore sorted,vec is: " << std::endl;
	for (auto &i:vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//����
	std::sort(vec.begin(),vec.end());

	std::cout << "\nafter sorted,vec is: " << std::endl;
	for (auto &i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//find
	auto pos3 = std::find(vec.begin(), vec.end(), 3);
	std::reverse(pos3, vec.end());
	std::cout << "\nafter reversed,vec is: " << std::endl;
	for (auto &i : vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

}

int maindaily0411()
{
	func_algor_simple();
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}