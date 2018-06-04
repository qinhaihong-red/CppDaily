//daily0604
/************************************************************************/
/* 
��ν�����㷨�����Ǹı�������Ԫ�ص�˳��.��˲������ڹ����Լ���������.

reverse: ��תԪ��˳��.

rotate:��ĳԪ��Ϊ�ᣬ������ת����.

pre/next_permutation:�ѽ������������У���һ�����������.


*/
/************************************************************************/


#include "common/common.h"


void func_algor_0604()
{
	//1.reverse,reverse_copy
	//list��ͬ����reverse��Ա��������Ч�ʸ���.���reverse��������vector��deque.
	std::vector<int> vec;
	common::insert_element(vec, 1, 9);
	std::cout << "1.reverse:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::reverse(std::begin(vec), std::end(vec));
	common::print_elems(vec);
	std::cout << std::endl;

	std::reverse(std::begin(vec) + 1, std::end(vec) - 1);
	std::reverse_copy(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;


	//2.rotate
	vec.clear();
	common::insert_element(vec, 1, 9);
	std::cout << "\n2.rotate:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::rotate(std::begin(vec), std::begin(vec) + 1, std::end(vec));
	common::print_elems(vec);
	std::cout << std::endl;

	std::rotate(std::begin(vec), std::end(vec) - 2, std::end(vec));
	common::print_elems(vec);
	std::cout << std::endl;

	std::rotate(std::begin(vec), std::find(std::begin(vec), std::end(vec), 4), std::end(vec));
	common::print_elems(vec);
	std::cout << std::endl;

	//3.next/pre_permutation
	//�ֱ����ͬ����˫���б�ʽ�汾��û��_if�汾��
	//����������е��������У�next_permutation����������е��������У�prev_permutation����������е���������.
	//����ʹ�øú����������򣬵���Ч�ʲ���.
	vec.clear();
	common::insert_element(vec, 1, 3);
	std::cout << "\n3.next/prev_permutation:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::cout << "All the permutation is:\n";
	while (std::next_permutation(std::begin(vec), std::end(vec)))
	{
		common::print_elems(vec);
		std::cout << std::endl;
	}

	std::cout << "\nnow vec is:";
	common::print_elems(vec);
	std::cout << std::endl;

	//�������в��ǽ������prev_permutation�������Ȱ�vec���н���Ȼ�󷵻�false.
	//�����������.
	while (std::prev_permutation(std::begin(vec),std::end(vec)))
	{
		common::print_elems(vec);
		std::cout << std::endl;
	}

	std::cout << "\nnow vec is:";
	common::print_elems(vec);
	std::cout << std::endl;

	//���������Ѿ�������һ�������.
	while (std::prev_permutation(std::begin(vec), std::end(vec)))
	{
		common::print_elems(vec);
		std::cout << std::endl;
	}

	std::cout << "\nnow vec is:";
	common::print_elems(vec);
	std::cout << std::endl;
}


int main()
{
	func_algor_0604();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}