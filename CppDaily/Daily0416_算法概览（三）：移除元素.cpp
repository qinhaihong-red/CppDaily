//daily0416

/************************************************************************/
/* 
关于算法对容器的操作，需要记住：
算法不会改变容器的大小（不会增加和减少容器的元素），只会改变容器中元素的内容.
欲改变容器的大小，需要通过容器自身的成员函数进行操作.

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <functional>
#include <list>
#include <algorithm>
#include <iterator>
#include "common/common.h"


void func_algor_remove_inside()
{
	std::list<int> li;
	
	for (int i=1;i<=6;i++)
	{
		li.push_back(i);
		li.push_front(i);
	}

	auto b = li.begin(), e = li.end();

	std::cout << "before remove:\n";
	//以copy取代for循环进行元素输出，非常简洁.
	std::copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//进行remove
	std::remove(b, e, 3);
	std::cout << "after remove:\n";
	std::copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;


	//注意！remove并没有改变容器中元素的个数，而是返回一个迭代器，该迭代器
	//是新的“逻辑”终点.
	//由容器的增删成员函数配合该新的终点，来实现容器的实际缩放.

	li.clear();
	for (int i = 1; i <= 6; i++)
	{
		li.push_back(i);
		li.push_front(i);
	}
	auto new_e = std::remove(li.begin(), li.end(), 3);
	std::cout <<"size of li is:"<<li.size() <<".\nwith new end :\n";
	std::copy(li.begin(),new_e,std::ostream_iterator<int>(std::cout," "));
	std::cout << std::endl;

	std::cout << "num of removed elems:" << std::distance(new_e, li.end());
	li.erase(new_e, li.end());
	std::cout << std::endl;
	std::copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " "));

}


int maindaily0416()
{
	//vecWrapper vw;
	//vw.pushback({1,2,3,4,5});

	//vw.print();

	func_algor_remove_inside();
	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}