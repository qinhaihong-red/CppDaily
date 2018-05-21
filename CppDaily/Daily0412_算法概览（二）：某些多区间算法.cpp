//daily0412
/************************************************************************/
/* 
ĳЩ�㷨��Ҫ�������������䣨����任����һ���ռ䵽��һ���ռ��ӳ�䣩��
1.�׸�������Ҫ��ȫȷ��������ҿ���
2.�ڶ�������ֻҪָ����ʼ��������λ�������׸�����Ľ���λ��Ϊ׼.

���Ҫע�⣬�豣֤�ڶ���������ڵ��ڵ�һ������.


*/
/************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>

void func_algor_2_interval()
{
	std::vector<int> vec = {1,3,5,7,9};
	std::list<int>    li = {1,3,5,7,9};

	//1.�Ƚ�ʱ����Ҫ��������
	if (std::equal(vec.begin(),vec.end(),li.begin()))
	{
		std::cout << "vec equals to li." << std::endl;
	}
	else
	{
		std::cout << "vec not equals to li." << std::endl;

	}

	//2.����һ��������������һ���ռ�
	std::list<int> d_li;
	
	//ע�⣡����д�������У���������ʱ����
	//���Լ���֤�������ȣ�
	//std::copy(vec.begin(),vec.end(),d_li.begin());
	
	//��дΪ��
	//1.�ȷ����㹻�ռ�
	d_li.resize(vec.size(), 0);
	std::copy(vec.begin(), vec.end(), d_li.begin());

	//2.ʹ�ú��������
	std::copy(vec.begin(),vec.end(),std::back_inserter(d_li));

	for (auto &i:d_li)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}


int maindaily0412()
{
	func_algor_2_interval();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}