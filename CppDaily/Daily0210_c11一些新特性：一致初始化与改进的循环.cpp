//daily0210
/************************************************************************/
/* 
C11һЩ�����ԣ�
1.һ�³�ʼ���ͳ�ֵ�б�
2.foreachѭ��
3.��ֵ���ú��ƶ�����(move semantics����������Ҫ�Ŀ�������ʱ����)
*/
/************************************************************************/

#include <iostream>
#include <string>
#include <vector>

void print_with_inilist(std::initializer_list<int> vals)
{
	for (auto &i:vals)
	{
		std::cout << i << std::endl;
	}
}

void func_c11feature_inside()
{
	//һ�³�ʼ��:ʹ��{ }���κα�������һ�³�ʼ��
	int num{5};
	int vas[] = {1,2,3,4,5};
	std::vector<int> vec{ 6,7,8,9,10 };

	std::cout << num << std::endl;
	//���Ƶ�������ѭ��
	for (auto &i:vas)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	for (auto &i:vec)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//�յ�{}��Ĭ�ϳ�ʼ������.
	//����ȽϺ���
	int num2{};
	int *p{};

	std::cout <<"num2==0 :" <<std::boolalpha <<(num2==0)<< std::endl;
	std::cout << "p==nullptr :"<<std::boolalpha << (p == nullptr) << std::endl;

	std::cout << std::endl << "��ֵ�б�" << std::endl;
	print_with_inilist({ 100,99,88,77 });

}



int maindaily0210()
{
	func_c11feature_inside();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 1;
}