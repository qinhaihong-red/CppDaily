//daily0607
/************************************************************************/
/* 

���������㷨:
1.nth_element(beg,nth,end,[BP op]):
	���ݵ�nth��Ԫ�ؽ�������.
	����ͬ���Ĵ�˫���б�ʽ�İ汾.
	ʹ����nthǰ��Ԫ�ض�С�ڣ�������op������nth�����Ԫ�ض�����nth(������op����).
	��partition������ṩ��op���л���.

2.heap����㷨��
	��νheap��������һ����������
	1.���ڵ�Ԫ�����Ǵ���ֱ���ӽڵ�Ԫ��.������һ��Ԫ����������.
	2.���Զ���ʱ�����Ӻ��Ƴ�Ԫ��.
	heap��صĺ����У�
	make_heap
	push_heap
	pop_heap
	sort_heap
	���Ͼ�����ͬ���Ĵ�˫���б�ʽ�İ汾.

*/
/************************************************************************/


#include "common/common.h"

void func_algor_0607()
{
	//1.nth_element
	std::deque<int> deq;
	common::insert_element(deq, 3, 7);
	common::insert_element(deq, 2, 6);
	common::insert_element(deq, 1, 5);
	std::cout << "1.nth_element:\nnow deq is:\n";
	common::print_elems(deq);
	std::cout << std::endl;

	//�Ե��ĸ�Ԫ��Ϊ��������
	//�ڴ�֮ǰ��Ԫ�ؾ�С�ڵ�������֮���Ԫ�ؾ����ڵ�����.
	std::nth_element(std::begin(deq), std::begin(deq) + 3, std::end(deq));
	std::cout << "\nthe 4 lowest elements are:\n";
	std::copy(std::begin(deq), std::begin(deq) + 4, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//ѡ��4������Ԫ�أ�����һ
	std::nth_element(std::begin(deq), std::end(deq) - 4, std::end(deq));
	std::cout << "\nthe 4 highest elements are:\n";
	std::copy(std::end(deq)-4, std::end(deq), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//ѡ��4������Ԫ�أ�������
	//��Ȼͬ��ѡ������4��Ԫ�أ��������ַ�����Ԫ��˳��һ��.
	//����˵��nth_element�Ի��������򣬲���������.
	std::nth_element(std::begin(deq), std::begin(deq) + 3, std::end(deq), std::greater<int>());
	std::cout << "\nthe 4 highest elements are:\n";
	std::copy(std::begin(deq), std::begin(deq) + 4, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//2.heap����㷨
	std::vector<int> vec;
	common::insert_element(vec, 3, 7);
	common::insert_element(vec, 5, 9);
	common::insert_element(vec, 1, 4);
	std::cout << "\n2.heap:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//make_heap
	//��vec����make_heap
	//���Կ���vec���׸�Ԫ�أ���������Ԫ����.
	std::make_heap(std::begin(vec), std::end(vec));
	std::cout << "\nafter make_heap, now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//pop_heap
	//�����γ�heap�����У�����pop������������Ԫ���ƶ�������β��.
	//�����㷨�����������ϲ��������������Ҫ�������ó�Ա����pop_back�����pop����.
	std::pop_heap(std::begin(vec),std::end(vec));
	vec.pop_back();
	std::cout << "\nafter pop_heap, now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//push_heap
	//�����γ�heap�����У����һ����Ԫ�أ�ʹ֮�����������ٴ��γ�heap
	//���Ҫ�ȵ���������push_back��Ա�������ٶ�����ʹ��push_heap
	vec.push_back(17);
	std::push_heap(std::begin(vec), std::end(vec));
	std::cout << "\nafter push_heap, now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//sort_heap
	//�����γ�heap�����У���������.
	//��������о��Ѳ�����heap�ṹ��.
	std::sort_heap(std::begin(vec), std::end(vec));
	std::cout << "\nafter sort_heap, now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;
}

int main0607()
{
	func_algor_0607();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}