//daily0125
//string����غ���
/************************************************************************/
/*����ע�� 
1.string::size_type���������������±�.string::npos��ʾstringԪ������������һ��.
2.����string�ĳ�Ա����������Ļ��������±꣬�������������Ե���������������̫һ��.
��string�У�����ı�ʾ��ͨ����ĳ��������Ϊ��ʼ�����԰����������ڵ�˳��n��Ԫ�ر�ʾ���䣬�磺
substr(0,5):���ذ�����һ��Ԫ�����ڵĺ���5��Ԫ��
������stl����ͨ��������ҿ��ĵ�������ʾ����

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <exception>

struct MyStructPack
{
	int a;
	char sz[10];
};

void func_string_operation()
{
	//1.string��Ϊ���л�����
	MyStructPack mp;
	mp.a = 99;
	strcpy_s(mp.sz, 10, "hello");

	std::string strBytes((char*)&mp,sizeof(mp));
	std::cout << "string��Ϊ���л�������" << strBytes.size() << std::endl << std::endl;

	//2.�ַ����Ƚ�
	//ע�⣺�������ȽϺͳ�Ա����compare�Ƚϣ����߷��صĽ����ͬ��
	//ǰ�߷���bool���ͣ����߷���int ���ͣ�0��ȣ�-1С�ڣ�1���ڣ�
	std::string strComp("abcd");
	std::cout << "�ַ����Ƚϣ�"<<std::endl<<strComp.compare("abc") << std::endl;
	std::cout  << strComp.compare("abcde") << std::endl;
	std::cout << strComp.compare("abcd") << std::endl << std::endl;


	//3.���ַ���
	//���ַ����ǵ��͵��ԣ���ʼ�±�+�ַ����� Ϊ��������Ĳ�������

	std::string strSub("pythoncookbook");
	std::cout << "���ַ�����" << std::endl << strSub.substr() << std::endl;
	std::cout << strSub.substr(strSub.find("n")) << std::endl;
	std::cout << strSub.substr(6) << std::endl;
	std::cout << strSub.substr(6, 4) << std::endl <<std::endl;

	//4.����
	//ע�⣺1.find��ȫ��ƥ��
	//2.find_first_of(not of)���൱��ƥ����������е�ĳ��Ԫ��

	std::string strTestFind("pythoncookbook");
	std::cout << "���ң�" << std::endl;
	std::cout << strTestFind.find("on") << std::endl;
	std::cout << strTestFind.find_first_of("xyzk") << std::endl;
	std::cout << strTestFind.find_first_not_of("python") << std::endl << std::endl;

	//��ֵת��
	//1.�ַ�������ֵת������λ��std�ռ��У�ȫ����s��string����ͷ��ת�ַ�������to_��ͷ��
	//2.��ֵת�������Զ������ַ���ǰ��Ŀհ��ַ�
	//3.����ָ���������ء��������ַ��������һ���ַ�������һ���ַ���λ��
	//4.�������û���������������


	std::cout << "��ֵת����" << std::endl;
	try
	{
		std::cout << std::stoi("   77") << std::endl;
		std::cout << std::stod("  99.88") << std::endl;
		std::cout << std::stoi("-0x88") << std::endl;

		std::size_t idx;
		std::cout << std::stoi("  45 is the ...", &idx) << std::endl;
		std::cout << "��һ��δ��������ַ�λ�ã�" << idx << std::endl;

		std::cout << std::stoi("   42", nullptr, 16) << std::endl;//�����˼��˵��string�е�42����16���Ʊ�ʾ��
		std::cout << std::stol("789", &idx, 8) << std::endl;
		std::cout << "��һ��δ��������ַ�λ�ã�" << idx << std::endl;

		std::cout << "��ֵת�ַ�����" << std::endl;

		long long ll = std::numeric_limits<long long>::max();
		std::string sll = std::to_string(ll);
		std::cout << sll << std::endl;
		
		std::cout << std::stoi(sll);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}



int maindaily0125()
//int main()
{

	func_string_operation();
	
	std::cout << std::endl<< "****************" << std::endl;
	std::cout << std::to_string(0xff) << std::endl;
	//std::cout << std::stoi("-0x88") << std::endl;//�������еģ�����ָ������
	std::cout << std::stoi("-0x88", nullptr, 16) << std::endl;



	std::string strInput;
	std::getline(std::cin,strInput);

	return 1;
}