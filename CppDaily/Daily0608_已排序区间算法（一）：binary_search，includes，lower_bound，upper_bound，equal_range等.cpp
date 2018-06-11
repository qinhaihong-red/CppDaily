//daily0608
/************************************************************************/
/* 
�����������㷨.

�������������ϣ�ִ�в��ҵ��㷨�����ж����Ч������.
��Щ�㷨�������㷨��ͬ������Ҫ��RA������.
���������RA�����������ӶȻή�͵��������Ӷȣ�����������Ը��Ӷ�.

1.binary_search:
	���ֲ���ָ��valueֵ.����ͬ���Ĵ�˫���б�ʽ�İ汾.
	����ֵ����bool.
	�ú�������ָ����ֵ�Ƿ���ڣ������Ҫ����λ�õ���������Ҫʹ��lower_bound��upper_bound.

2.includes(InputIterator beg1,II end1,II beg2, II end2,[BP op]):
	�ж�����������[beg1,end1)�Ƿ��������������[beg2,end2)��Ҳ�����жϺ����Ƿ�Ϊǰ���Ӽ�.
	����ͬ���Ĵ�˫���б�ʽ�İ汾.
	����ֵ����bool.

3.lower_bound/upper_bound:
	�ڲ��ƻ����������������£����ؿɹ������Ԫ�ص�λ��:
	ǰ�߷��ص�һ���ɹ������λ�ã���һ�����ڵ���ָ��Ԫ�ص�λ�ã���
	���߷������һ���ɹ������λ�ã���һ������ָ��Ԫ�ص�λ�ã�.
	����ֵ�ǿɹ�����λ�õĵ�����.
	��������˫���б�ʽ��ͬ���汾.

	������������ͬ���ĳ�Ա������Ч�ʸ���.

4.equal_range:
	���ؿɹ������һ������.��һ��pair.
	��Ч��make_pair(lower_bound(...),upper_bound(...))

*/
/************************************************************************/


#include "common/common.h"

void func_algor_0608()
{
	//1.binary_search:
	std::list<int> li;
	common::insert_element(li, 1, 9);
	std::cout << "1.binary_search:\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	if (std::binary_search(std::begin(li),std::end(li),5))
	{
		std::cout << "bin_search found 5.\n";
	}
	else
	{
		std::cout << "bin_search not found 5.\n";
	}

	if (std::binary_search(std::begin(li), std::end(li), 10))
	{
		std::cout << "bin_search found 10.\n";
	}
	else
	{
		std::cout << "bin_search not found 10.\n";
	}

	//2.includes
	//����һ�������������Ƿ������һ������������
	std::vector<int> vec;
	li.clear();
	common::insert_element(li, 1, 9);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);

	std::cout << "\2.includes:\nnow li and vec are :\n";
	common::print_elems(li);
	std::cout << std::endl;
	common::print_elems(vec);
	std::cout << std::endl;

	if (std::includes(std::begin(li),std::end(li),std::begin(vec),std::end(vec)))
	{
		std::cout << "\nall elements of vec are in li.";
	}
	else
	{
		std::cout << "\nnot all elements of vec are in li.";
	}

	//3.lower_bound/upper_bound
	li.clear();
	common::insert_element(li, 1, 9);
	common::insert_element(li, 1, 9);
	li.sort();
	std::cout << "\n3.lower_bound/upper_bound:\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//���ҿɲ���5�ĵ�һ�������һ��λ��
	auto pos1 = std::lower_bound(std::begin(li), std::end(li), 5);
	auto pos2 = std::upper_bound(std::begin(li), std::end(li), 5);

	std::cout << "5 ���Բ��뵽 " << std::distance(std::begin(li), pos1) + 1 << " �� " << std::distance(std::begin(li), pos2) + 1 << " ֮�䣬�����ƻ�����˳��.\n";

	//����3����һ���ɲ����λ��
	li.insert(std::lower_bound(std::begin(li), std::end(li), 3), 3);

	//����7�����һ���ɲ����λ��
	li.insert(std::upper_bound(std::begin(li),std::end(li),7),7);

	std::cout << "now li is :\n";
	common::print_elems(li);
	std::cout << std::endl;

	//4.equal_range
	//ͬʱ���ص�һ�������һ���ɲ���λ��.
	li.clear();
	common::insert_element(li, 1, 9);
	common::insert_element(li, 1, 9);
	li.sort();
	std::cout << "\n4.equal_range:\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	auto pp = std::equal_range(std::begin(li), std::end(li), 5);
	std::cout << "������ " << std::distance(std::begin(li), pp.first) + 1 << " �� " << std::distance(std::begin(li), pp.second) + 1 << " ֮�����5�������ƻ�����˳��.\n";
}


int main0608()
{
	func_algor_0608();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}