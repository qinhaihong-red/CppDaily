//daily0308
/************************************************************************/
/* ��ֵ��ֵP115.
��ֵ��ֵ��Ҫ��ע�����͸�������ռ�õ�λ������ֵ�ȵ�.
���������Ϣ��ͳ�ϰ�����<climits>,<cfloat>��ͷ�ļ��ж������س���.

��C++11�𣬽���ͳһ��ģ��ӿ�numeric_limits�Լ������͵ľ����ػ���������ͳһ
�Ľӿڣ�������ͬ������ֵ���͵ļ�ֵ��Ϣ.�ӿ�������ʹ�÷���.


*/
/************************************************************************/
#include <iostream>
#include <string>
#include <numeric>

void func_numeric_limits_inside()
{
	//����numeric_limits�����г�Ա��������Ϊstatic constexpr�����Կ�����
	//������ʹ����غ�������ĳ���

	long long E_Value = std::numeric_limits<int>::max();
	int a[std::numeric_limits<short>::max()];
	a[0] = 100;
	std::cout << ++ E_Value << std::endl;

	//�������͵ļ�ֵ
	std::cout << std::endl;

	std::cout << "int max:" << std::numeric_limits<int>::max() << std::endl;
	std::cout << "short max:" << std::numeric_limits<short>::max() << std::endl;
	std::cout << "long max:" << std::numeric_limits<long>::max() << std::endl;

	//�������ͼ�ֵ
	std::cout << std::endl;
	std::cout << "float max:" << std::numeric_limits<float>::max() << std::endl;
	std::cout << "double max:" << std::numeric_limits<double>::max() << std::endl;
	std::cout << "long double max:" << std::numeric_limits<long double>::max() << std::endl;

	//��֤char�Ƿ��з�������
	std::cout << std::endl;
	std::cout << "is signed_char(char):" << std::numeric_limits<char>::is_signed << std::endl;
	std::cout << std::endl;


	//��֤ĳ�����Ƿ��ػ�
	std::cout << "is string specialized:" << std::numeric_limits<std::string>::is_specialized << std::endl;
}


int maindaily0308()
{

	func_numeric_limits_inside();
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}