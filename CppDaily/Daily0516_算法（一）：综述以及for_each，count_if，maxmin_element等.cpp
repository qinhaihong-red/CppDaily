//daily0516
/************************************************************************/
/* 

STL算法是配合STL容器以实现某种功能的泛型函数.

如果简单的把算法视为对容器数据的增，删，改，查的话，需要注意：
STL算法不会对STL容器进行物理上的增和删，而只能进行改和查的操作.

如果把算法当作函数映射：f:R^n->R^m ， 则可以确定算法的3要素：
1.操作功能，如：查找，排序等.
2.原空间：一定由的，由容器的迭代器确定，左闭右开：[ )
3.目的空间：可能有，也可能就是原空间.

算法分类：
一. 按功能分类
	--非更易算法（non-modifying）:如for_each等.
	--更易算法（modifying）:如transform等.
	--移除算法：如remove，unique_copy等.
	--查找算法：find,search等
	--变序算法：如reverse,shuffle,partition等.
	--排序算法：如sort,partial_sort,stable_sort等.
	--数值算法：accumulate等.

二. 按所需容器迭代器分类
	--随机存取迭代器：        排序算法全系皆要求此类迭代器.
	--非关联容器以及无序容器：更易算法以及移除算法不能对此类容器操作.

*/
/************************************************************************/
//本篇主要示例for_each，count,count_if,min/max_element等非更易算法.


#include"./common/common.h"
#include <cstdlib>//for abs()

void func_non_modifying_algor_inside_0516()
{
	//1.for_each
	//配合lambda来使用，非常方便

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

	//按值捕获vec
	std::for_each(std::begin(vec), std::end(vec), [=](int &i)
	{
		i += *vec.begin();
	});

	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//按引用捕获vec
	std::for_each(std::begin(vec), std::end(vec), [&](int &i)
	{
		i += *vec.begin();
	});

	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//2.元素计数:copy 和 copy_if
	//如果某算法存在同名的_if算法，它们的参数个数一样. 区别在于：
	//前者要求一个参数值(value)，后者要求一个单参判别式（unary predicate）.
	
	//--迭代器要求InputIterator
	//--返回值是定义在iterator_traits中的difference type，也就是int.
	//--关联和无序容器，提供了同名的成员函数.

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

	//3.最小值和最大值比较
	//min/max_element(b,e,[op,双参比较判别式 bin-predicate]):返回forward iterator.
	//minmax_element(b,e,[op,双参比较判别式 bin-predicate]) :返回forwar iteratro的pair.

	//如果有多个最小最大值，min_ele和max_elem返回都是找到的第一个目标元素.
	//而minmax_elem返回的是第一个最小和最后一个最大元素.

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