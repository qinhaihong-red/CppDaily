//daily0508
/************************************************************************/
/* 
一.要清楚各容器的适应场景
二.扩展自定义容器到STL
 1.侵入式. 自定义容器提供STL所需接口，如begin和end等.
 2.非侵入式.提供特殊迭代器，作为算法和容器之间的接口.
 3.Wrapper.如把自定义数据结构包裹到shared_ptr然后放到stl 容器中.

*/
/************************************************************************/


#include"./common/common.h"
#include <iterator>

void func_container_review_and_expand()
{
	//1.通过非侵入式方法把c-style array当作一种stl容器.
	int vals[] = {33,67,-4,13,5,2};

	std::vector<int> v(std::begin(vals),std::end(vals));

	std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//2.下面的示例分别使用不同的容器，从标准输入读取字符串，排序，去重，打印.
	//使用set
	std::cout << "use set:\n";
	std::set<std::string> coll( (std::istream_iterator<std::string>(std::cin)),
		std::istream_iterator<std::string>());

	std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));

	//使用vector
	std::vector<std::string> vec((std::istream_iterator<std::string>(std::cin)),std::istream_iterator<std::string>());

	std::sort(vec.begin(),vec.end());

	std::cout << "use vector:\n";
	std::unique_copy(vec.begin(),vec.end(),std::ostream_iterator<std::string>(std::cout,"\n"));


	std::string strInput;
	std::getline(std::cin, strInput);
}


int maindaily0508()
{
	func_container_review_and_expand();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}