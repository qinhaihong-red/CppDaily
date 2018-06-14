//daily0612
/************************************************************************/
/* 
��ֵ����
1.accumulate(beg,end,init_val,[BF op]):
	����˫�κ����İ汾�����н����ۼӼ��㣺init_val+a1+a2+a3...
	��˫�κ����İ汾����op���м���:init_val [op] a1 [op] a2 [op] ...
	����ֵΪ���յļ�����.

2.inner_product(beg1,end1,beg2,init_val,[BF op1],[BF op2]):
	����˫�κ����İ汾�����н����ڻ�����:init_val+(a1*b1)+(a2*b2)+(a3*b3)+...
	��˫�κ����İ汾����������op1��op2���м��㣺init_val [op1] (a1[op2]b1) [op1] (a2[op2]b2)...
	����ֵΪ���յļ�����.
*/
/************************************************************************/


#include "common/common.h"
#include <numeric> //��ֵ����


void func_algor_0612()
{
	//1.accumulate
	std::vector<int> vec;
	common::insert_element(vec, 1, 9);
	std::cout << "1.accumulate:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//�ۼӺ�
	std::cout << "\nsum: " << std::accumulate(std::begin(vec), std::end(vec), 0) << std::endl;
	//�ۻ�
	std::cout << "\nproduct: " << std::accumulate(std::begin(vec), std::end(vec), 1,std::multiplies<int>()) << std::endl;


	//2.inner_product
	std::list<int> li;
	common::insert_element(li, 1, 6);
	std::cout << "\n2.inner_product:\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//�����ڻ�
	std::cout << "\ninner product of li:"
		<< std::inner_product(std::begin(li), std::end(li), std::begin(li), 0)
		<< std::endl;

	//�����ӵ��Զ����ڻ���
	//op2:plus
	//op1:multiplies
	std::cout << "\nproduct of sum:"
		<< std::inner_product(std::begin(li), std::end(li), std::begin(li), 1, std::multiplies<int>(), std::plus<int>())
		<< std::endl;
}


int main0612()
{
	func_algor_0612();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}