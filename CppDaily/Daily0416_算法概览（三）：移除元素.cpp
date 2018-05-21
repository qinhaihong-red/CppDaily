//daily0416

/************************************************************************/
/* 
�����㷨�������Ĳ�������Ҫ��ס��
�㷨����ı������Ĵ�С���������Ӻͼ���������Ԫ�أ���ֻ��ı�������Ԫ�ص�����.
���ı������Ĵ�С����Ҫͨ����������ĳ�Ա�������в���.

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <functional>
#include <list>
#include <algorithm>
#include <iterator>
#include "common/common.h"


void func_algor_remove_inside()
{
	std::list<int> li;
	
	for (int i=1;i<=6;i++)
	{
		li.push_back(i);
		li.push_front(i);
	}

	auto b = li.begin(), e = li.end();

	std::cout << "before remove:\n";
	//��copyȡ��forѭ������Ԫ��������ǳ����.
	std::copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//����remove
	std::remove(b, e, 3);
	std::cout << "after remove:\n";
	std::copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;


	//ע�⣡remove��û�иı�������Ԫ�صĸ��������Ƿ���һ�����������õ�����
	//���µġ��߼����յ�.
	//����������ɾ��Ա������ϸ��µ��յ㣬��ʵ��������ʵ������.

	li.clear();
	for (int i = 1; i <= 6; i++)
	{
		li.push_back(i);
		li.push_front(i);
	}
	auto new_e = std::remove(li.begin(), li.end(), 3);
	std::cout <<"size of li is:"<<li.size() <<".\nwith new end :\n";
	std::copy(li.begin(),new_e,std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl;

	std::cout << "num of removed elems:" << std::distance(new_e, li.end());
	li.erase(new_e, li.end());
	std::cout << std::endl;
	std::copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " "));

}


int maindaily0416()
{
	//vecWrapper vw;
	//vw.pushback({1,2,3,4,5});

	//vw.print();

	func_algor_remove_inside();
	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}