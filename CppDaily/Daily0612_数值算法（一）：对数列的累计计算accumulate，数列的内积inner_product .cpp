//daily0612
/************************************************************************/
/* 
数值计算
1.accumulate(beg,end,init_val,[BF op]):
	不带双参函数的版本对数列进行累加计算：init_val+a1+a2+a3...
	带双参函数的版本依据op进行计算:init_val [op] a1 [op] a2 [op] ...
	返回值为最终的计算结果.

2.inner_product(beg1,end1,beg2,init_val,[BF op1],[BF op2]):
	不带双参函数的版本对数列进行内积运算:init_val+(a1*b1)+(a2*b2)+(a3*b3)+...
	带双参函数的版本对数列依据op1和op2进行计算：init_val [op1] (a1[op2]b1) [op1] (a2[op2]b2)...
	返回值为最终的计算结果.
*/
/************************************************************************/


#include "common/common.h"
#include <numeric> //数值计算


void func_algor_0612()
{
	//1.accumulate
	std::vector<int> vec;
	common::insert_element(vec, 1, 9);
	std::cout << "1.accumulate:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//累加和
	std::cout << "\nsum: " << std::accumulate(std::begin(vec), std::end(vec), 0) << std::endl;
	//累积
	std::cout << "\nproduct: " << std::accumulate(std::begin(vec), std::end(vec), 1,std::multiplies<int>()) << std::endl;


	//2.inner_product
	std::list<int> li;
	common::insert_element(li, 1, 6);
	std::cout << "\n2.inner_product:\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//向量内积
	std::cout << "\ninner product of li:"
		<< std::inner_product(std::begin(li), std::end(li), std::begin(li), 0)
		<< std::endl;

	//更复杂的自定义内积：
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