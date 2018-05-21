//daily0307
/************************************************************************/
/*
unique_ptr����������Դ�Ĺ�����Զ������������Ĺ�������
shared_ptr��̫һ��

*/
/************************************************************************/

#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include <utility>




void func_unique_ptr_inside2()
{
	//һ. ����������Դ�Ĺ���
	//std::unique_ptr<int> p(new int[10]);//���ַ�ʽ���������Ǵ����

	//�������1��u_ptr�����˶Դ���������Դ��ƫ�ػ��汾��ֻ��Ҫ��ģ��������� x[] ��
	//��������Դ������ʱ�򣬵���delete []. ��shared_ptrû������ƫ�ػ��汾֧��.
	std::unique_ptr<int[]> p(new int[10]);
	for (auto i=0;i<10;++i)
	{
		p[i] = i;//��ƫ�ػ��汾�����ṩ*��->��������ֻ�ṩ[]������
	}

	std::cout << "p[0] + p[9] : "<< p[0] + p[9] << std::endl;

	//�������2���Զ���������.
	//���������ֲ�ͬ��shared_ptr��uunique_ptr��Ҫ�ڵڶ���ģ�����ָ�����������ͣ�
	//��shared_ptr����ָ��.
	auto f_deleter = [](int *p)
	{
		delete[] p;
	};
	std::unique_ptr<int, decltype(f_deleter)> p2(new int[10],f_deleter);
	for (auto i = 0; i < 10; ++i)
	{
		p2.get()[i] = i;
		//*(p2+i) = i;//���ṩָ��++����
	}
	std::cout << "p2[0] + p2[9] : " << p2.get()[0] + p2.get()[9] << std::endl;

	//��. ������Դ�Ĺ���
	//���ľ����Զ���������.���峡�����嶨���.
}


int maindaily0307()
{

	func_unique_ptr_inside2();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}