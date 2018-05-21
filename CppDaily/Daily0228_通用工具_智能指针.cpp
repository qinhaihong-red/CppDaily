//daily0228
/************************************************************************/
/* 
����ָ�룺shared_ptr
1.��ʼ��.��ʽ����.�Ƽ�ʹ��std::make_shared
2.��������Ԫ�ص�����
3.�Զ����������ͷ���Դ��.

*/
/************************************************************************/


#include <iostream>
#include <string>
#include <memory>
#include <functional>

void func_sharedptr_inside()
{
	//��ʼ��1��
	std::shared_ptr<std::string> pStr(new std::string("hello"));
	//std::shared_ptr<std::string> pStr = new std::string("hello");//������ʽ���캯���������ĳ�ʼ����������

	//��ʼ��2��
	std::shared_ptr<std::string> pStr2 = std::make_shared<std::string>("world!");//���ֳ�ʼ������ȫ��Ҳ����

	//��ʼ��3:
	std::shared_ptr<std::string> pStr3;
	pStr3.reset(new std::string("^_^"));

	std::cout << *pStr << " " << *pStr2 << " " << *pStr3 << std::endl << std::endl;


	//����new Array ���͵�����
	//std::shared_ptr��Ĭ�����������ǵ���delete.��˶���new type[num]�͵�ָ�룬Ҫ�ر�ע�⣺
	//1.std::shared_ptr<int> p(new int[10]); ����ͨ�����룬������ʱ����delete����delete []���Ӷ������Դй¶
	//2.std::shared_ptr<int[]> ����д������ͨ������
	
	//���ְ취���delete []�����⣺
	//1.�Զ���������
	std::shared_ptr<int> p(new int[10], [](int *p) {delete[] p; });
	for (int i=0;i<10;++i)
	{
		p.get()[i] = i;
	}

	std::cout << (p.get()[0] + p.get()[9]) << std::endl;

	//2.ʹ�ø������� std::default_delete<int[]>();
	std::shared_ptr<int> p2(new int[10], std::default_delete<int[]>());
	for (int i = 0; i < 10; ++i)
	{
		p2.get()[i] = i;
	}
	std::cout << (p2.get()[0] + p2.get()[9]) << std::endl;

}


int maindaily0228()
{
	func_sharedptr_inside();


	std::string strInput;
	std::getline(std::cin,strInput);

	return 0;
}