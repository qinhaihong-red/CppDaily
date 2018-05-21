//daily0423
/************************************************************************/
/* 
对于容器来说，需要注意它的使用场景,数据结构与内存模型，迭代器失效等.

vector:
1.适用于尾部频繁增删的场景
2.注意其容量（capacity）与大小(size)的区别以及引发扩容的操作
3.迭代器失效的场景（扩容可能使得全部迭代器失效，删除仅仅使得当前迭代器失效）
4.删除返回下一个迭代器
5.vector<bool>对于bool有专门的特化，使得占用空间小于bool真正类型所占用空间.
如果需要固定大小的bitfield，可使用bitset.

deque:
1.适用于头尾频繁增删的场景
2.不支持控制容量和内存重分配时机的机制（不像vector那样有reserve()和capacity()）
3.迭代器失效的场景（扩容和删除元素）
4.删除返回下一个迭代器


*/
/************************************************************************/


#include"./common/common.h"


void func_vec_deq_inside()
{
	//vector
	std::vector<std::string> sts;
	sts.reserve(5);//预先分配空间

	sts.push_back("Hello ,");
	sts.insert(sts.end(), { "how","are","you","?" });

	//输出
	std::copy(sts.begin(), sts.end(), std::ostream_iterator<std::string>(std::cout, " "));

	std::cout << std::endl;


	std::cout << "Max size:" << sts.max_size() << std::endl;
	std::cout << "    size:" << sts.size() << std::endl;
	std::cout << "Capacity:" << sts.capacity() << std::endl;

	//交换
	std::swap(sts[1], sts[3]);

	//在 ？ 之前插入 always
	sts.insert(std::find(sts.begin(), sts.end(), "?"), "always ");

	sts.back() = "!";//赋值给back

	//输出
	std::copy(sts.begin(), sts.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "    size:" << sts.size() << std::endl;
	std::cout << "Capacity:" << sts.capacity() << std::endl;
	std::cout << std::endl;
	//删除最后两个元素
	sts.pop_back();
	sts.pop_back();

	sts.shrink_to_fit();

	std::cout << "    size:" << sts.size() << std::endl;
	std::cout << "Capacity:" << sts.capacity() << std::endl;
	std::cout << std::endl;

	//deque
	std::deque<std::string> deq;
	deq.assign(3, std::string("string"));
	deq.push_back("last string");
	deq.push_front("first string");

	std::copy(deq.begin(),deq.end(),std::ostream_iterator<std::string>(std::cout," "));
	std::cout << std::endl;

	deq.pop_back();
	deq.pop_front();

	for (unsigned i = 1; i < deq.size(); i++)
	{
		deq[i] = "another " + deq.at(i);
	}

	deq.resize(4, "resized string");


	std::copy(deq.begin(), deq.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

}

int maindaily0423()
{

	func_vec_deq_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}