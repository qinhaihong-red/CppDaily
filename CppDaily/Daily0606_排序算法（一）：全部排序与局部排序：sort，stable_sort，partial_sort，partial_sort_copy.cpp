//daily0606
/************************************************************************/
/* 
�����㷨Ҫ�������Ϊ random access iterator,��˲�������list,������������������.

1.ȫ������sort,stable_sort
	����ͬ���Ĵ�˫���б�ʽ���ϸ����򣩵İ汾.
	stalbe_sort��֤��ȵ�Ԫ��������󱣳�˳�򲻱�.
	���Ӷȣ�
		sort:ƽ��Ϊnlogn
		stalbe_sort:�ڴ��㹻ʱΪnlogn�������Ϊn(logn)^2

2.�ֲ�����partial_sort
	�ֲ�����.����ͬ���Ĵ�˫���б�ʽ���ϸ����򣩵İ汾.
	���Ӷȣ������Ժ�nlogn֮��.���������ȫ�ţ�ƽ�����ܲ���sort����������������sort.

3.partial_sort_copy:���ƹ���������

*/
/************************************************************************/

#include "common/common.h"

void func_algor_0606()
{
	//1.sort
	std::deque<int> deq;
	common::insert_element(deq, 1, 9);
	common::insert_element(deq, 1, 9);
	std::cout << "1.sort:\nnow deq is:\n";
	common::print_elems(deq);
	std::cout << std::endl;

	//��������
	std::sort(std::begin(deq), std::end(deq));
	common::print_elems(deq);
	std::cout << std::endl;

	//��������
	std::sort(std::begin(deq), std::end(deq), std::greater<int>());
	common::print_elems(deq);
	std::cout << std::endl;

	//�Ƚ�sort��stable_sort
	auto funcLessLen = [](const std::string &s1,const std::string &s2)
	{
		return s1.length() < s2.length();
	};

	std::vector<std::string> vec = {"1xxx","2x","3x","4x","5xx","6xxxx","7xx","8xxx","9xx","10xxx",
	"11","12","13","14xx","15","16","17"};

	std::vector<std::string> vec2(vec);

	//vs stl ����ʵ�ֵ� sort �� stable_sort ����һ��.
	std::sort(std::begin(vec), std::end(vec), funcLessLen);
	std::stable_sort(std::begin(vec2), std::end(vec2), funcLessLen);
	
	std::cout << "\ndifference between sort and stable_sort:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	common::print_elems(vec2);
	std::cout << std::endl;

	//2.partial_sort
	deq.clear();
	common::insert_element(deq, 3, 7);
	common::insert_element(deq, 2, 6);
	common::insert_element(deq, 1, 5);
	std::cout << "\n2.partial_sort:\nnow deq is:\n";
	common::print_elems(deq);
	std::cout << std::endl;

	//ֻ��ǰ5��Ԫ��:����
	std::partial_sort(std::begin(deq), std::begin(deq) + 5, std::end(deq));
	common::print_elems(deq);
	std::cout << std::endl;
	
	//ֻ��ǰ5��Ԫ��:����
	std::partial_sort(std::begin(deq), std::begin(deq) + 5, std::end(deq),std::greater<int>());
	common::print_elems(deq);
	std::cout << std::endl;

	//����partial_sort����ȫ����
	std::partial_sort(std::begin(deq), std::end(deq), std::end(deq));
	common::print_elems(deq);
	std::cout << std::endl;


	//2.partial_sort_copy(inputIter sBeg,inputIter sEnd,RAIter dBeg,RAIter dend,[BP op])
	//��Ԫ�ش�Դ���临�Ƶ�Ŀ�����䣬������.
	//Դ����ֻҪ��intput iterator����Ŀ������Ҫ��random access iterator.
	//���Ʋ������Ԫ�صĸ������Խ�С����Ϊ׼.���Դ����С��Ŀ�����䣬��ô�൱�ڰ�Դ����Ԫ�ظ��Ƶ�Ŀ�����䣬
	//����ȫ����.

	deq.clear();
	std::vector<int> v6(6), v30(30);
	common::insert_element(deq, 3, 7);
	common::insert_element(deq, 2, 6);
	common::insert_element(deq, 1, 5);
	std::cout << "\n3.partial_sort_copy:\nnow deq is:\n";
	common::print_elems(deq);
	std::cout << std::endl;

	//����6��Ԫ�ص�v6������
	auto pos6 = std::partial_sort_copy(std::begin(deq), std::end(deq), std::begin(v6), std::end(v6));
	std::copy(std::begin(v6), pos6, std::ostream_iterator<int>(std::cout, " "));

	//������Ԫ�ظ��Ƶ�v30�в�����v30��������deq��
	auto pos30 = std::partial_sort_copy(std::begin(deq), std::end(deq), std::begin(v30), std::end(v30), std::greater<int>());
	std::copy(std::begin(v30), pos30, std::ostream_iterator<int>(std::cout, " "));

}

int main0606()
{
	func_algor_0606();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}