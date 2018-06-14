//daily0614
/************************************************************************/
/* 
������к;�������֮���ת��

1.partial_sum(beg,end,dstBeg,[BF op]):
	������������У�   a1, a2,    a3,...
	����һ���µ����У� a1,a1+a2,a1+a2+a3,...
	�������е�Ԫ�ض�Ӧԭ����ÿ��Ԫ����֮ǰԪ�ص��ۼӺ�.
	���ڴ�op��˫�κ����汾�����������㣺a1,a1[op]a2,a1[op]a2[op]a3,...
	
	Դ�����Ŀ�����������ͬ.
	����Ŀ������δ������Ԫ�ص���һ��������.

	�������ν�İ� ���ֵ���� ת��Ϊ ����ֵ����.

2.adjacent_difference(beg,end,stdBeg,[BF op]):
	���������е��ٽ�Ԫ����������µ����У�����
	������������У�   a1, a2,    a3,...
	����һ���µ����У� a1,a2-a1,  a3-a2,...
	���ڴ�op��˫�κ����汾�����������㣺a1,a2[op]a1,a3[op]a2,...

	Դ�����Ŀ�����������ͬ.
	����Ŀ������δ������Ԫ�ص���һ��������.

	�������ν�İ� ����ֵ���� ת��Ϊ ���ֵ����.


Ҳ����˵��partial_sum��adjacent_difference�պû���.

*/
/************************************************************************/

#include "common/common.h"
#include <numeric>

void func_algor_0614()
{
	//1.partial_sum
	std::vector<int> vec;
	common::insert_element(vec, 1, 6);
	std::cout << "1.partial_sum:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::cout << "partial sum of vec is:";
	std::partial_sum(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout, " "));

	std::cout << "\npartial products of vec is:";
	std::partial_sum(std::begin(vec), std::end(vec),
		std::ostream_iterator<int>(std::cout, " "),
		std::multiplies<int>());

	//2.adjacent_difference
	std::cout << "\n2.adjacent_difference:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::cout << "adjacent difference of vec is:";
	std::adjacent_difference(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout, " "));

	std::cout << "\nadjacent sum of vec is:";
	std::adjacent_difference(std::begin(vec), std::end(vec), 
		std::ostream_iterator<int>(std::cout, " "),
		std::plus<int>());

}

int main()
{
	func_algor_0614();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}