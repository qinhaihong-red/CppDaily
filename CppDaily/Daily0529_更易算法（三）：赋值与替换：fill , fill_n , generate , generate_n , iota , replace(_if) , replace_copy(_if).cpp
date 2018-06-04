//daily0530
/************************************************************************/
/* 

��ֵ��
fill, fill_n

������ֵ��
generate, generate_n. ��fill��ȣ�generateʹ���˺�������.

Ϊ��������һϵ�е���ֵ��
iota

�滻Ԫ�أ�
replace:��ָ���ľ�ֵ�滻��ֵ.
replace_if:�ѷ��ϵ����б�ʽ�ľ�ֵ���滻Ϊ��ֵ.

replace_copy:��Դ������Ԫ�ظ��Ƶ��µ����䣬�������е��ھ�ֵ��Ԫ���滻Ϊ��ֵ.
replace_copy_if:��Դ������Ԫ�ظ��Ƶ��µ����䣬�����������㵥���б�ʽ�ľ�ֵԪ���滻Ϊ��ֵ.

*/
/************************************************************************/


#include "common/common.h"
#include <numeric>

void func_algor_0529()
{
	//1.fill,fill_n
	//����ֵ����void
	std::cout << "1.fill:\n";
	//��cout���10��7
	std::fill_n(std::ostream_iterator<int>(std::cout, " "), 10, 7);
	std::cout << std::endl;

	std::list<std::string> li;
	std::fill_n(std::back_inserter(li), 5, "hello");//ֻ��Ҫһ����ʼ����������.
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//ʹ��fill��li���и���
	std::fill(std::begin(li), std::end(li), "again");
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	std::fill_n(std::begin(li), li.size() - 2,"hi");

	std::fill(++std::begin(li), --std::end(li), "i");
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//2.generate,generate_n
	//����ֵ����void
	std::cout << "\n2.generate:\n";
	int nSeed = 100;
	auto func_genVal = [&nSeed]()
	{
		return ++nSeed;
	};

	std::vector<int> vec;
	std::generate_n(std::back_inserter(vec), 5, func_genVal);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::generate(std::begin(vec), std::end(vec), func_genVal);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//3.void iota(beg,end,T startVal):��������һϵ�е�����ֵ
	std::cout << "\n3.iota(from <numberic.h>):\n";
	std::iota(std::begin(vec),std::end(vec),20);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;


	//4.replace,replace_if �滻Ԫ��
	//����void. _if�汾�߱������б�ʽ.
	std::cout << "\n4.replace:\n";
	vec.clear();

	common::insert_element(vec, 2, 7);
	common::insert_element(vec, 4, 9);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::replace(std::begin(vec), std::end(vec), 6, 42);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::replace_if(std::begin(vec), std::end(vec), [](int i) 
	{
		if (i<5)
		{
			return true;
		}

		return false;
	},
		0);

	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;


	//5.replace_copy ��Դ�����ڵ�Ԫ�ظ��Ƶ���һ�������ͬʱ�Ѿ�ֵ�滻Ϊ��ֵ.
	std::cout << "\n5.replace_copy:\n";
	vec.clear();

	common::insert_element(vec, 2, 6);
	common::insert_element(vec, 4, 9);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//���vec��Ԫ�ص�cout���滻���е���5��Ԫ��Ϊ55
	std::replace_copy(std::begin(vec), std::end(vec),
		std::ostream_iterator<int>(std::cout, ""),
		5,
		55);
	std::cout << std::endl;

	//���vec��Ԫ�ص�cout���滻����Ϊż����Ԫ��
	std::replace_copy_if(std::begin(vec), std::end(vec),
		std::ostream_iterator<int>(std::cout, " "),
		[](int i)
	{
		if (i % 2 == 0)
		{
			return true;
		}

		return false;
	},
		0);

	std::cout << "\nat last vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;
}

int maindaily0529()
{
	func_algor_0529();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}