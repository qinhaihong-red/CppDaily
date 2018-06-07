//daily0605
/************************************************************************/
/* 
�����㷨����

shuffle/random_shuffle:�����������Ԫ��.

partion/stable_partition:����Ԫ��.��Ԫ����ǰ����.

partition_copy:�ڸ��ƵĹ����л���.

*/
/************************************************************************/


#include "common/common.h"
#include <cstdlib>
#include <random> //�����

void func_algor_0605()
{
	//1.shuffle��random_shuffle
	//ǰ����Ҫ���������֧��.
	//���߲���op�İ汾ʹ�þ��ȷֲ����������������������л���.
	//��op�İ汾��ʹ��op�������������������л���.

	std::vector<int> vec;
	common::insert_element(vec, 1, 9);
	std::cout << "1.shuffle:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//random_shuffleĬ��ʹ�þ��ȷֲ����������
	std::random_shuffle(std::begin(vec), std::end(vec));
	common::print_elems(vec);
	std::cout << std::endl;


	//ʹ��default_random_engin���������
	std::default_random_engine dre;
	std::shuffle(std::begin(vec), std::end(vec), dre);
	common::print_elems(vec);
	std::cout << std::endl;

	//�Զ���op���������
	auto func_randomOp = [](std::ptrdiff_t mx)
	{
		double tmp=0;
		tmp = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
		return static_cast<ptrdiff_t>(tmp*mx);
	};

	std::random_shuffle(std::begin(vec), std::end(vec), func_randomOp);
	common::print_elems(vec);
	std::cout << std::endl;

	//2.partition��stable_partition
	//����Ԫ��.����׼���ɵ����б�ʽ����:������׼���Ԫ�ػ��ֵ�ǰ���������ϵĻ��ֵ���.
	//���߱�֤���ֵĹ����У���֤��������һ���Ԫ�ر���ԭ��.
	//�����׸�������׼��Ԫ�صĵ�����.

	vec.clear();
	std::list<int> li;
	common::insert_element(vec, 1, 9);
	common::insert_element(li, 1, 9);
	std::cout << "\n2.partition:\nnow vec and li are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(li);
	std::cout << std::endl;

	//���ͬһ��׼��Ļ��֣��Ƚ�stalbe_partition��partition������.
	auto pos1 = std::partition(std::begin(vec), std::end(vec), [](int i) {return i % 2 == 0; });
	auto pos2 = std::stable_partition(std::begin(li), std::end(li), [](int i) {return i % 2 == 0; });


	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << "\nfirst odd element is:" << *pos1 << std::endl;

	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << "\nfirst odd element is:" << *pos2 << std::endl;


	//3.partition_copy
	//��׼������л���Ϊ�����֣�����׼���һ���ָ��Ƶ�����1��������׼��Ĳ��ָ��Ƶ�����2.
	//����һ��pair,�ں�����1������2���ƺ����һ��Ԫ��.
	vec.clear();
	vec = {1,6,33,7,22,4,11,33,2,7,0,42,5};
	std::cout << "\n3.partition_copy:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::vector<int> vec2;
	li.clear();

	std::partition_copy(std::begin(vec),std::end(vec),
		std::back_inserter(vec2),
		std::back_inserter(li),
		[](int i) {return i % 2 == 0; });

	std::cout << "\nnow vec2 and li are:\n";
	common::print_elems(vec2);
	std::cout << std::endl;
	common::print_elems(li);
	std::cout << std::endl;
}

int main0605()
{
	func_algor_0605();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}