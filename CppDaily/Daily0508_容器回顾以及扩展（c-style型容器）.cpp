//daily0508
/************************************************************************/
/* 
һ.Ҫ�������������Ӧ����
��.��չ�Զ���������STL
 1.����ʽ. �Զ��������ṩSTL����ӿڣ���begin��end��.
 2.������ʽ.�ṩ�������������Ϊ�㷨������֮��Ľӿ�.
 3.Wrapper.����Զ������ݽṹ������shared_ptrȻ��ŵ�stl ������.

*/
/************************************************************************/


#include"./common/common.h"
#include <iterator>

void func_container_review_and_expand()
{
	//1.ͨ��������ʽ������c-style array����һ��stl����.
	int vals[] = {33,67,-4,13,5,2};

	std::vector<int> v(std::begin(vals),std::end(vals));

	std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//2.�����ʾ���ֱ�ʹ�ò�ͬ���������ӱ�׼�����ȡ�ַ���������ȥ�أ���ӡ.
	//ʹ��set
	std::cout << "use set:\n";
	std::set<std::string> coll( (std::istream_iterator<std::string>(std::cin)),
		std::istream_iterator<std::string>());

	std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<std::string>(std::cout, "\n"));

	//ʹ��vector
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