//daily0507
/************************************************************************/
/* 
查看无序容器buckets的属性以及方法

*/
/************************************************************************/

#include"./common/common.h"
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <iomanip>

//打印pair<T1,T2>
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream &os, const std::pair<T1, T2> &t)
{
	os << "[" << t.first << "," << t.second << "]";
	return os;
}

template<typename T>
void printHashTableState(const T &t)
{
	std::cout << "size:" << t.size() << std::endl;
	std::cout << "buckets:" << t.bucket_count() << std::endl;
	std::cout << "load factor:" << t.load_factor() << std::endl;
	std::cout << "max load factor:" << t.max_load_factor() << std::endl;

	//迭代器类型
	if (typeid( std::iterator_traits<typename T::iterator::iterator_category>) == typeid(std::bidirectional_iterator_tag))
	{
		std::cout << "chaining style: doubly-linked" << std::endl;
	}
	else
	{
		std::cout << "chaining style: singly-linked" << std::endl;
	}

	std::cout << "data:\n";

	for (auto i=0;i!=t.bucket_count();++i)
	{
		std::cout << " b[" << std::setw(2) << i << "]: ";
		for (auto pos=t.begin(i);pos!=t.end(i);++pos)
		{
			std::cout << *pos << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void func_unordered_set_buckets_test()
{
	std::unordered_set<int> uset = {1,3,5,7,9,12,13,17,19};
	printHashTableState(uset);

	uset.insert({-7,17,33,4,21,22,23,24,25,26,27,28,29,30});
	printHashTableState(uset);
}


void func_unorderd_map_buckets_test()
{
	std::unordered_multimap<std::string, std::string> umap = {
		{"I","俺"},
		{"Strange","奇怪"},
		{"Car","汽车"},
		{"Smart","机灵"},
		{"Strange","奇异"},
		{"Feature","特征"}	
	};

	printHashTableState(umap);

	umap.insert(
	{
		{"Smart","聪明"},
		{"Smart","灵秀"},
		{"Clever","聪明"}	
	}	
	);

	printHashTableState(umap);

	umap.max_load_factor(0.7);
	printHashTableState(umap);

}



int maindaily0507()
{
	func_unordered_set_buckets_test();
	std::cout << "multi-map:"<<std::endl;
	func_unorderd_map_buckets_test();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}