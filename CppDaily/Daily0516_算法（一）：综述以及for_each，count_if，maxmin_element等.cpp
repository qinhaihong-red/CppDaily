//daily0516
/************************************************************************/
/* 

STL�㷨�����STL������ʵ��ĳ�ֹ��ܵķ��ͺ���.

����򵥵İ��㷨��Ϊ���������ݵ�����ɾ���ģ���Ļ�����Ҫע�⣺
STL�㷨�����STL�������������ϵ�����ɾ����ֻ�ܽ��иĺͲ�Ĳ���.

������㷨��������ӳ�䣺f:R^n->R^m �� �����ȷ���㷨��3Ҫ�أ�
1.�������ܣ��磺���ң������.
2.ԭ�ռ䣺һ���ɵģ��������ĵ�����ȷ��������ҿ���[ )
3.Ŀ�Ŀռ䣺�����У�Ҳ���ܾ���ԭ�ռ�.

�㷨���ࣺ
һ. �����ܷ���
	--�Ǹ����㷨��non-modifying��:��for_each��.
	--�����㷨��modifying��:��transform��.
	--�Ƴ��㷨����remove��unique_copy��.
	--�����㷨��find,search��
	--�����㷨����reverse,shuffle,partition��.
	--�����㷨����sort,partial_sort,stable_sort��.
	--��ֵ�㷨��accumulate��.

��. ��������������������
	--�����ȡ��������        �����㷨ȫϵ��Ҫ����������.
	--�ǹ��������Լ����������������㷨�Լ��Ƴ��㷨���ܶԴ�����������.

*/
/************************************************************************/
//��ƪ��Ҫʾ��for_each��count,count_if,min/max_element�ȷǸ����㷨.


#include"./common/common.h"
#include <cstdlib>//for abs()

void func_non_modifying_algor_inside_0516()
{
	//1.for_each
	//���lambda��ʹ�ã��ǳ�����

	std::cout << "1.for_each test:\n";

	std::vector<int> vec;
	common::insert_element(vec, 1, 9);

	std::for_each(std::begin(vec), std::end(vec), [](int &i)
	{
		i += 10;
	});
	std::cout << "now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//��ֵ����vec
	std::for_each(std::begin(vec), std::end(vec), [=](int &i)
	{
		i += *vec.begin();
	});

	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//�����ò���vec
	std::for_each(std::begin(vec), std::end(vec), [&](int &i)
	{
		i += *vec.begin();
	});

	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//2.Ԫ�ؼ���:copy �� copy_if
	//���ĳ�㷨����ͬ����_if�㷨�����ǵĲ�������һ��. �������ڣ�
	//ǰ��Ҫ��һ������ֵ(value)������Ҫ��һ�������б�ʽ��unary predicate��.
	
	//--������Ҫ��InputIterator
	//--����ֵ�Ƕ�����iterator_traits�е�difference type��Ҳ����int.
	//--�����������������ṩ��ͬ���ĳ�Ա����.

	std::cout << "\n2.copy and copy_if test:\n";
	vec.clear();

	common::insert_element(vec, 1, 9);
	std::cout << "now vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	auto num = std::count(std::begin(vec),std::end(vec),4);
	std::cout << "number of elems eq to 4 is:" << num << std::endl;

	num = std::count_if(std::begin(vec), std::end(vec), [](int &i)
	{
		return (i % 2 == 0);
	});

	std::cout << "number of elems with even value:" << num << std::endl;

	//3.��Сֵ�����ֵ�Ƚ�
	//min/max_element(b,e,[op,˫�αȽ��б�ʽ bin-predicate]):����forward iterator.
	//minmax_element(b,e,[op,˫�αȽ��б�ʽ bin-predicate]) :����forwar iteratro��pair.

	//����ж����С���ֵ��min_ele��max_elem���ض����ҵ��ĵ�һ��Ŀ��Ԫ��.
	//��minmax_elem���ص��ǵ�һ����С�����һ�����Ԫ��.

	vec.clear();
	std::cout << "\n3.min/max_element test:\n";
	common::insert_element(vec, 2, 6);
	common::insert_element(vec, -3, 6);


	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::cout << "\nminimum ele is:\n" << *std::min_element(std::begin(vec), std::end(vec)) << std::endl;
	std::cout << "\nmaximum ele is:\n" << *std::max_element(std::begin(vec), std::end(vec)) << std::endl;


	auto mm = std::minmax_element(std::begin(vec), std::end(vec));
	std::cout << "min:" << *(mm.first) << std::endl;
	std::cout << "max:" << *(mm.second) << std::endl;
	std::cout << "distance:" << std::distance(mm.first, mm.second) << std::endl;


	auto absLess = [](int i, int j) {return abs(i) < abs(j); };
	std::cout << "\nmininum of abs value is:" << *std::min_element(std::begin(vec), std::end(vec), absLess);
	std::cout << "\nmaxinum of abs value is:" << *std::max_element(std::begin(vec), std::end(vec), absLess);

}


int maindaily0516()
{

	func_non_modifying_algor_inside_0516();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}