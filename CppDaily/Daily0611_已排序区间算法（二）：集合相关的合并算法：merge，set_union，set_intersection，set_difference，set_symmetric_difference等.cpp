//daily0611
/************************************************************************/
/* 
�ϲ��㷨.

��Ҫ����������֮��� ���� ���� � �� ���������.
��������ѧ�м����������������㣬���ǲ���ȫ��ͬ.��ע����.

1.merge:
	����������������һ��Ԫ��˳��ϲ���һ��.
	list��forword_list��ͬ���ĳ�Ա������Ч�ʻ����.
	����Ŀ������ĵ�һ��δ�����ǵ�Ԫ��.

2.set_union:
	����������������һ��Ԫ��˳��ϲ���һ�𣬵�����ͬλ�ñȽϵ�����Ԫ�أ���ֵ��ȣ���ֻȡһ��Ԫ��.
	����Ŀ������ĵ�һ��δ�����ǵ�Ԫ��.

3.set_intersection:
	��һλ�ñȽ������������䣬ֻȡֵ��ȵ�Ԫ�ز���Ŀ������.
	����Ŀ������ĵ�һ��δ�����ǵ�Ԫ��.

4.set_difference:
	��һλ�ñȽ������������䣬ֻȡֵ���ȵ����ڵ�һ�������ڵ�Ԫ�ز���Ŀ������.

5.set_symmetric_difference:
	����������������һ��Ԫ��˳��ϲ���һ�𣬺���ͬλ��ֵ��ȵ�Ԫ��.


*/
/************************************************************************/




#include "common/common.h"

void func_algor_0611()
{
	std::vector<int> vec = {1,2,2,4,6,7,7,9};
	std::deque<int> deq  = {2,2,2,3,6,6,8,9};

	std::cout << "now vec and deq are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(deq);
	std::cout << std::endl;

	//1.merge
	std::cout << "\n1.merge:\n";
	std::merge(std::begin(vec), std::end(vec),
		std::begin(deq), std::end(deq),
		std::ostream_iterator<int>(std::cout, " "));

	//2.set_union
	std::cout << "\n2.set_union:\n";
	std::set_union(std::begin(vec), std::end(vec),
		std::begin(deq), std::end(deq),
		std::ostream_iterator<int>(std::cout, " "));


	//3.set_intersection
	std::cout << "\n3.set_intersection:\n";
	std::set_intersection(std::begin(vec), std::end(vec),
		std::begin(deq), std::end(deq),
		std::ostream_iterator<int>(std::cout, " "));

	//4.set_difference
	std::cout << "\n4.set_difference:\n";
	std::set_difference(std::begin(vec), std::end(vec),
		std::begin(deq), std::end(deq),
		std::ostream_iterator<int>(std::cout, " "));

	//5.set_symmetric_difference
	std::cout << "\n5.set_symmetric_differenc:\n";
	std::set_symmetric_difference(std::begin(vec), std::end(vec),
		std::begin(deq), std::end(deq),
		std::ostream_iterator<int>(std::cout, " "));
}


int main()
{
	func_algor_0611();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}