//daily0528
/************************************************************************/
/* 
1.transform:
	��һ������Ļ������������Ԫ�أ������任��ͨ�����κ�������˫�κ�������ӳ�䵽��һ������.
	�����ڣ�f:R^n-->R^m.
	����Ŀ�����������һ��δ��ת����Ԫ�أ�Ҳ���ǵ�һ��δ�����ǵ�Ԫ�أ��ĵ�����.

2.swap_range:
	��������������Ԫ��.
	���صڶ��������� ���һ��������Ԫ�� ����һ��λ��.
	�����ͬ���������������е�Ԫ�أ�Ӧ��ʹ�����Ա����swap.

*/
/************************************************************************/


#include "common/common.h"

void func_algor_0528()
{
	//1.transform

	std::vector<int> vec;
	std::list<int> li;

	common::insert_element(vec, 1, 9);
	std::cout << "1.transform:\n";
	std::cout << "now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//һ. ��������֮��ı任��ʹ�õ��κ�����
	//��vec��Ԫ�ر任Ϊ�为��
	std::transform(std::begin(vec), std::end(vec), std::begin(vec), std::negate<int>());
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//��vec��Ԫ�س�10�����li
	std::transform(std::begin(vec), std::end(vec),
		std::back_inserter(li),
		std::bind(std::multiplies<int>(), std::placeholders::_1, 10));

	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//�������li��Ԫ�صĸ���
	std::cout << "\nnow -r_li is:\n";
	std::transform(std::rbegin(li),std::rend(li),
		std::ostream_iterator<int>(std::cout," "),
		[](int i) {return -i; }
	);

	//��.����������֮���ٱ任����һ�����䣨ʹ��˫�κ�����
	vec.clear();
	li.clear();

	common::insert_element(vec, 1, 9);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//ͨ���任ʹ��vec��ÿ��Ԫ�ؿ�ƽ��
	std::transform(std::begin(vec), std::end(vec),
		std::begin(vec),
		std::begin(vec),
		std::multiplies<int>());
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//vec��β����ٲ��뵽li��
	std::transform(std::begin(vec), std::end(vec),
		std::rbegin(vec),
		std::back_inserter(li),
		std::plus<int>());
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//vec��ȥli�������cout��
	std::cout << "\nnow vec-li is:\n";
	std::transform(std::begin(vec),std::end(vec),
		std::begin(li),
		std::ostream_iterator<int>(std::cout," "),
		std::minus<int>());


	//2.swap_range �����ڻ���Ԫ��
	std::cout << "\n2.swap_range:\n";
	std::deque<int> deq;
	vec.clear();

	common::insert_element(vec, 1, 9);
	common::insert_element(deq, 11, 23);

	std::cout << "\nnow vec and deq are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(deq);
	std::cout << std::endl;

	//ʹvec��deq����Ԫ��
	auto pos = std::swap_ranges(std::begin(vec), std::end(vec), std::begin(deq));
	std::cout << "\nnow vec and deq are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(deq);
	std::cout << std::endl;

	if (pos!=std::end(deq))
	{
		std::cout << "\nfirst not swapped element is:" << *pos << std::endl;
	}

	//deq������β3��Ԫ��
	std::swap_ranges(std::begin(deq), std::begin(deq) + 3, std::rbegin(deq));
	std::cout << "\nnoww deq is:\n";

	common::print_elems(deq);
	std::cout << std::endl;

}


int maindaily0528()
{
	func_algor_0528();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}