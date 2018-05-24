//daily0521
/************************************************************************/
/* 
���������㷨:

find_first_of/find_first_of[if�汾]��
	�൱��find��find_if��˫����汾��������һ�������䣬����֮�Ƚ�.
	������������ǹ淶������BinaryPredicate��find_first_of�൱�����أ���δ������if��β.

adacent_find/adacent_find[if�汾]��
	���������������Ԫ�ص��׸�λ��.

equal/equal[if�汾]��
	�Ƚ���������������.


*/
/************************************************************************/
#include "common/common.h"


void func_algor_find_inside0521()
{
	//1.find_first_of
	std::vector<int> vec;
	std::list<int> liSearch;

	common::insert_element(vec, 1, 11);
	common::insert_element(liSearch, 3, 5);

	std::cout << "now vec and li are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(liSearch);
	std::cout << std::endl;

	auto pos = std::find_first_of(vec.begin(), vec.end(),
		liSearch.begin(), liSearch.end());

	std::cout << "\nfirst element of liSearch in vec is element " << std::distance(std::begin(vec), pos) + 1 << std::endl;

	//�������--vs��֧��
	//auto rpos = std::find_first_of(vec.rbegin, vec.rend(), std::begin(liSearch), std::end(liSearch));

	//2.adjacent_find
	vec.clear();
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(0);
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;


	pos = std::adjacent_find(std::begin(vec), std::end(vec));
	if (pos != std::end(vec))
	{
		std::cout << "first 2 elements with equal val have pos " << std::distance(std::begin(vec), pos) + 1 << std::endl;
	}


	auto func = [](int elem1, int elem2)
	{
		return elem1 * 2 == elem2;	
	};

	pos = std::adjacent_find(std::begin(vec), std::end(vec), func);

	if (pos != std::end(vec))
	{
		std::cout << "first 2 elements with second val twice the first have pos. " << std::distance(std::begin(vec), pos) + 1 << std::endl;

	}

	//3.equal ����Ƚ�. ����ֵ��bool����������iterator.
	// �Ƚ�����������Ԫ���Ƿ���Ȼ��߷��� bin-predicate
	//--�����в����ʱ�������Ҫ�˽����Ĳ�ͬ��Ӧʹ��mismatch.
	//--is_permutation�����ж����������Ƿ�Ԫ��ֵ��ȵ�˳��ͬ.

	vec.clear();
	liSearch.clear();

	common::insert_element(vec, 1, 7);
	common::insert_element(liSearch, 3, 9);

	std::cout << "\nnow vec and li are:\n";
	common::print_elems(vec);
	std::cout << std::endl;
	common::print_elems(liSearch);
	std::cout << std::endl;


	if (std::equal(std::begin(vec),std::end(vec),std::begin(liSearch)))//������ҪС�������䣬��Ҫ�Լ���֤
	{
		std::cout << "li == vec" << std::endl;
	}
	else
	{
		std::cout << "li != vec" << std::endl;
	}

	//ʹ��˫���б�ʽ�����Զ���Ƚ�
	auto func_check_even_odd = [](int e1, int e2)
	{
		return e1 % 2 == e2 % 2;
	};

	if (std::equal(std::begin(vec),std::end(vec),std::begin(liSearch),func_check_even_odd))
	{
		std::cout << "even and odd elements are correspond." << std::endl;
	}
	else
	{
		std::cout << "even and odd elements do not correspond." << std::endl;
	}

}

int maindaily0521()
{
	func_algor_find_inside0521();
	
	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}