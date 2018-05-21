//daily0509
/************************************************************************/
/* 

一 迭代器分类
	1.Output	   输出迭代器：向前写入.     提供者: Ostream, inserter.
	2.Input		   输入迭代器：向前读取一次. 提供者：Istream.
	3.Foward	   前向迭代器：向前读取.     提供者：前向列表forwad list，无序容器.
	4.Bidrectional 双向迭代器：前后读取.	 提供者：list,set,m-set,map,m-map
	5.RandomAccess 随机存取迭代器.			 提供者：array,vector,deque,string,c-style array

二 迭代器辅助工具
	随机读取迭代器的功能最为强大. 迭代器辅助工具提供了一些辅助函数，使得其他类型迭代器
	可以获得如同随机存取迭代器一样的能力:
	--advance()
	--prev()
	--next()
	--distance()
	以及iter_swap(),可以交换两个迭代器的值.
	配合begin()和end()辅助函数，更方便.

*/
/************************************************************************/

#include"./common/common.h"
#include <iterator>


void func_interator_helpler_inside()
{
	//1. void advance(InputIterator &pos,Dist n)
	//使得非 random-access 迭代器具备前进或者后天n个元素的能力.
	//该函数不返回，且不检查迭代器是否超过序列的end().因此需要自己注意.

	std::list<int> li = {1,3,4,5,7,9};

	auto pos = std::begin(li);

	std::cout << *pos << std::endl;

	std::advance(pos, 3);

	std::cout << *pos << std::endl;

	std::advance(pos, -1);

	std::cout << *pos << std::endl;

	//2.next()和prev():向后，向前移动迭代器的位置
	// ForwardIterator next(FI pos)
	// ForwardIterator next(FI pos,Dist n)

	//BidirectionalIterator prev(BI pos)
	//BidirectionalIterator prev(BI pos, Dist n)

	//3.distance() : 处理两个迭代器之间的距离.
	pos = std::find(std::begin(li), std::end(li), 5);
	if (pos != std::end(li))
	{
		std::cout << "\ndistance from beginning and 5 is:" << std::distance(std::begin(li), pos) << std::endl;
	}
	else
	{
		std::cout << "5 not found.\n";
	}

	//4.iter_swap() ： 交换两个迭代器的值.
	//迭代器类型不必相同，但是所指类型必须可相互赋值.

	std::cout << "\nnow li is:" << std::endl;
	std::copy(std::begin(li), std::end(li), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "swap first and second value:\n";
	std::iter_swap(std::begin(li), std::next(std::begin(li)));
	std::copy(std::begin(li), std::end(li), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "swap first and last value:\n";
	std::iter_swap(std::begin(li), std::prev(std::end(li)));
	std::copy(std::begin(li), std::end(li), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;


}


int maindaily0509()
{
	func_interator_helpler_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}