//daily0306
/************************************************************************/
/* 
unique_ptr�ṩ�˶�ռʽӵ����Դ������. �ر��ʺ���Դ�Ĺ������ļ�����Ĺرյ�
�����Ա������쳣�����ֵ���Դй¶����.

1.u_ptr��release���壬��s_ptrû��
2.u_ptrͨ�����std::move������Դ���ƶ�
3.ע�⴫�뺯����u_ptr�Լ��Ӻ������ص�u_ptr����Դ�������Լ���Ч�ı����ʽ

*/
/************************************************************************/

#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include <utility>

std::unique_ptr<int> gen_uptr()
{
	std::unique_ptr<int> p(new int(100));

	return p;//���ﲻ��Ҫ��ʽstd::move����Ϊ���ݹ涨�����������Զ����move����
}

void recv_uptr(std::unique_ptr<int> p)//������Ķ���Ҫʹ��std::move
{
	if (p)
	{
		std::cout << "In recv func, now p is:" << *p << std::endl;
	}
}


void func_unique_ptr_inside()
{
	std::unique_ptr<int> p(new int); //������ʽ��ʼ��
	*p = 10;

	std::cout << "Now p is:" << *p << std::endl;


	int *pRaw = p.release();//�����ͷ���Դ,shared_ptr������
	delete pRaw;//���й���

	p.reset(new int(9));

	//���ڶ�ռʽӵ����Դ��ֻ��ͨ��moveת������Ȩ�����ܽ��п�����ʼ�����߸�ֵ
	std::unique_ptr<int> p2 = std::move(p);
	std::cout << "Now p2 is:" << *p2 << std::endl;


	p.reset(new int(11));
	std::cout << "Now p is:" << *p << std::endl;

	p.reset();
	p = gen_uptr();//�Ӻ�������
	std::cout << std::endl << "After get uptr from genfunc:" << std::endl;
	std::cout << "Now p is:" << *p << std::endl;
	*p = 101;
	recv_uptr(std::move(p));//���뺯��. ��move��p�Զ�����ֵΪnullptr.
	std::cout << std::boolalpha << (p == nullptr) << std::endl;


}


int daily0306main()
{

	func_unique_ptr_inside();

	std::string strInput;
	std::getline(std::cin,strInput);

	return 0;
}