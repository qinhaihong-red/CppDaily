//daily0423
/************************************************************************/
/* 
����������˵����Ҫע������ʹ�ó���,���ݽṹ���ڴ�ģ�ͣ�������ʧЧ��.

vector:
1.������β��Ƶ����ɾ�ĳ���
2.ע����������capacity�����С(size)�������Լ��������ݵĲ���
3.������ʧЧ�ĳ��������ݿ���ʹ��ȫ��������ʧЧ��ɾ������ʹ�õ�ǰ������ʧЧ��
4.ɾ��������һ��������
5.vector<bool>����bool��ר�ŵ��ػ���ʹ��ռ�ÿռ�С��bool����������ռ�ÿռ�.
�����Ҫ�̶���С��bitfield����ʹ��bitset.

deque:
1.������ͷβƵ����ɾ�ĳ���
2.��֧�ֿ����������ڴ��ط���ʱ���Ļ��ƣ�����vector������reserve()��capacity()��
3.������ʧЧ�ĳ��������ݺ�ɾ��Ԫ�أ�
4.ɾ��������һ��������


*/
/************************************************************************/


#include"./common/common.h"


void func_vec_deq_inside()
{
	//vector
	std::vector<std::string> sts;
	sts.reserve(5);//Ԥ�ȷ���ռ�

	sts.push_back("Hello ,");
	sts.insert(sts.end(), { "how","are","you","?" });

	//���
	std::copy(sts.begin(), sts.end(), std::ostream_iterator<std::string>(std::cout, " "));

	std::cout << std::endl;


	std::cout << "Max size:" << sts.max_size() << std::endl;
	std::cout << "    size:" << sts.size() << std::endl;
	std::cout << "Capacity:" << sts.capacity() << std::endl;

	//����
	std::swap(sts[1], sts[3]);

	//�� �� ֮ǰ���� always
	sts.insert(std::find(sts.begin(), sts.end(), "?"), "always ");

	sts.back() = "!";//��ֵ��back

	//���
	std::copy(sts.begin(), sts.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "    size:" << sts.size() << std::endl;
	std::cout << "Capacity:" << sts.capacity() << std::endl;
	std::cout << std::endl;
	//ɾ���������Ԫ��
	sts.pop_back();
	sts.pop_back();

	sts.shrink_to_fit();

	std::cout << "    size:" << sts.size() << std::endl;
	std::cout << "Capacity:" << sts.capacity() << std::endl;
	std::cout << std::endl;

	//deque
	std::deque<std::string> deq;
	deq.assign(3, std::string("string"));
	deq.push_back("last string");
	deq.push_front("first string");

	std::copy(deq.begin(),deq.end(),std::ostream_iterator<std::string>(std::cout," "));
	std::cout << std::endl;

	deq.pop_back();
	deq.pop_front();

	for (unsigned i = 1; i < deq.size(); i++)
	{
		deq[i] = "another " + deq.at(i);
	}

	deq.resize(4, "resized string");


	std::copy(deq.begin(), deq.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

}

int maindaily0423()
{

	func_vec_deq_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}