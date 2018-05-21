//daily0517
/************************************************************************/
/* 
查找算法
一 查找第一个元素
	find
	find_if
	find_if_not
	要求输入input iterator的左开右闭区间，输出是找到的首个符合要求结果的迭代器.否则是end.
	注意：
	1.如果是已排区间，应该使用效率更高的排序算法，如：lower_bound,upper_bound,equal_range或者
	binary_search等算法
	2.关联容器或者是无序容器，应该使用等效的成员函数find

二 查找前n个连续匹配值
	search_n.
	search_n有两个版本，其中一个就其功能而言，应该命名为：search_n_if. 但因为历史原因，
	没有这样命名，并且参数有冗余. 使用的时候需注意.

三 查找第一个子区间
	search(beg,end,sub-beg,sub-end)
	search(beg,end,sub-beg,sub-end,BinaryPredicate bp)//应命名为 search_if
	区间查找要求两对迭代器区间，其中第二个迭代器区间包含的值是第一个区间欲查找的.
	要求输入forward iterator迭代器，输出是找到的首个符合要求结果的迭代器.否则是end.
*/
/************************************************************************/

#include"./common/common.h"


void func_find_search_inside0517()
{
	//1.查找第一个元素
	std::cout << "test1:\n";
	std::list<int> li;
	common::insert_element(li, 1, 9);
	common::insert_element(li, 1, 9);

	std::cout << "now li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//找到首个值为4的元素的迭代器
	auto pos = std::find(std::begin(li), std::end(li), 4);

	//再找第二个元素
	if (pos != std::end(li))
	{
		auto pos2 = std::find(++pos, std::end(li), 4);

		if (pos2 != std::end(li))
		{
			//打印出两个4之间的所有元素（包含首尾）
			std::cout << "elements between 4s are:\n";
			//注意迭代器区间
			std::copy(--pos, ++pos2, std::ostream_iterator<int>(std::cout, " "));
			std::cout << std::endl;

		}
	}

	//find_if使用
	li.clear();
	common::insert_element(li, 1, 9);
	std::cout << "now li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//找到第一个比3大的元素
	pos = std::find_if(std::begin(li), std::end(li), std::bind(std::greater<int>(), std::placeholders::_1, 3));
	std::cout << "the " << std::distance(std::begin(li), pos) + 1 << " element is the first greater than 3." << std::endl;

	//2.查找前n个连续匹配的值
	std::cout << "test2:\n";

	std::deque<int> deq={1,2,7,7,6,3,9,5,7,7,7,3,6};
	auto d_pos = std::search_n(std::begin(deq), std::end(deq),//范围
		3,//重复次数
		7 //值
	);//查找重复3次的值为7的元素首次出现的位置

	if (d_pos!=std::end(deq))
	{
		std::cout << "3 consecutive elements with 7 start with " << std::distance(std::begin(deq), d_pos) + 1 << " . element." << std::endl;

	}

	//接收判别式的search_n不再演示了.需要注意，它的形式比较奇怪.

	//3.查找第一个子区间
	std::cout << "test3:\n";
	li.clear();
	deq.clear();

	common::insert_element(deq, 1, 7);
	common::insert_element(deq, 1, 7);
	common::insert_element(li, 3, 6);

	std::cout << "now deq and li are:\n";
	common::print_elems(deq);
	std::cout << std::endl;
	common::print_elems(li);
	std::cout << std::endl;

	d_pos = std::search(std::begin(deq), std::end(deq), std::begin(li), std::end(li));

	while (d_pos!=std::end(deq))
	{
		std::cout << "sub found starting with element " << std::distance(std::begin(deq), d_pos) + 1 << std::endl;

		++d_pos;

		d_pos = std::search(d_pos, std::end(deq), std::begin(li), std::end(li));
	}


	//带双参判别式的search
	std::vector<std::string> vec = {"GE","apple","apple","tesla","amazon"};
	li.clear();
	li = {5,5,5};

	auto func = [](const std::string&str, int i)
	{
		if (str.length()==i)
		{
			return true;
		}

		return false;
	};

	auto v_pos = std::search(std::begin(vec), std::end(vec), std::begin(li), std::end(li), func);
	if (v_pos != std::end(vec))
	{
		std::cout << "the match are:\n" << std::endl;
		for (int i=0;i<li.size();++i)
		{
			std::cout << *v_pos++ << std::endl;
		}
	}

}


int main()
{
	func_find_search_inside0517();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}