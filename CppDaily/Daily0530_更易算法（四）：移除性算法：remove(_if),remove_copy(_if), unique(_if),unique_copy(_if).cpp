//daily0530
/************************************************************************/
/* 
�Ƴ����㷨
��ν���Ƴ���ֻ���߼��Ե��Ƴ������������ϴ��������Ƴ�Ԫ��.����˵���㷨����Щ��Ӧ���Ƴ���Ԫ�ظ��ǵ�Ӧ�Ƴ���Ԫ��.
�������µ��߼��յ㣬Ҳ�������һ�����Ƴ�Ԫ�ص���һ��λ��.
������Ӧ��֤�Ӵ�ʹ���µ��߼��յ㣬����ʹ��ԭ����end�յ�.

1.remove,remove_if
	���㷨�������ڹ����������������������������ƹ��ܵĳ�Ա����erase.����list��˵���и���Ч��
��Ա����remove(��Ϊ�������¸�ֵ����ֵ������ָ�����).

��ˣ���Ч��������remvoe�㷨������ֻ��vector��deque����.

2.remove_copy,remove_copy_if
	�ڴ�Դ���临�Ƶ���һ������ʱ���Ƴ�ĳЩԪ�أ�Դ���䲻��Ӱ�죩.


3.unique(����ͬ�����ص�˫���б�ʽ�汾��Ҳ������û�д�_if�����İ汾)
	�Ƴ������ظ���Ԫ��.
	���Դ����Ҫ�������򣬲���ʹ�øú���������˵�����ٲ����ڽ�Ԫ����ȣ����㷨����Ч��.
	�������ڹ�������������.
	list��ͬ���ĸ���Ч�ĳ�Ա����.
	��ˣ���Ч��������remvoe�㷨������ֻ��vector��deque����.

4.unique_copy(����ͬ�����ص�˫���б�ʽ��Ҳ������û�д�_if�����İ汾)
	���ƹ������Ƴ��ظ�Ԫ�أ�Դ���䲻��Ӱ�죩.

*/
/************************************************************************/


#include "common/common.h"


void func_algor_0530()
{
	//1.remove,remove_if
	std::vector<int> vec;
	common::insert_element(vec, 2, 6);
	common::insert_element(vec, 4, 9);
	common::insert_element(vec, 1, 7);
	std::cout << "1.remove:\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//�Ƴ�����ֵΪ5��Ԫ��
	auto pos = std::remove(std::begin(vec), std::end(vec), 5);
	std::cout << "\nnow vec is(size not changed):\n";
	common::print_elems(vec);
	std::cout << std::endl;

	vec.erase(pos, std::end(vec));
	std::cout << "\nnow vec is(size changed):\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//�Ƴ�����С��4��Ԫ��
	//erase+remove:�߼���������һ��.
	vec.erase(std::remove_if(std::begin(vec), std::end(vec),
		[](int i){return i < 4;}),std::end(vec));

	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;


	//2.remove_copy,remove_copy_if
	std::list<int> li;
	common::insert_element(li, 1, 6);
	common::insert_element(li, 1, 9);
	std::cout << "\n2.remove_copy:\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//�ѳ�ֵΪ3�������Ԫ�������cout
	std::remove_copy(std::begin(li), std::end(li),
		std::ostream_iterator<int>(std::cout," "),3);
	std::cout << std::endl;

	//�ѳ�ֵ����4�����Ԫ�������cout
	std::remove_copy_if(std::begin(li), std::end(li),
		std::ostream_iterator<int>(std::cout," "),
	[](int i)
	{
		return i > 4;
	});
	std::cout << std::endl;
	
	//��С��4��Ԫ�ظ��Ƶ�m-set
	std::multiset<int> m_set;
	std::remove_copy_if(std::begin(li), std::end(li),
		std::inserter(m_set, m_set.end()),
		std::bind(std::less<int>(), std::placeholders::_1, 4));
	std::cout << "\nnow m_set is:\n";
	common::print_elems(m_set);
	
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//unique. ˫���б�ʽͬ�����أ���_if�����汾.
	std::cout << "\n3.unique:\n";
	int source[] = {1,4,4,6,1,2,2,3,1,6,6,6,5,7,5,4,4};
	vec.clear();
	std::copy(std::begin(source), std::end(source),std::back_inserter(vec));
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	auto pos2 = std::unique(std::begin(vec), std::end(vec));
	std::copy(std::begin(vec), pos2, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//�ٴγ�ʼ��vec
	std::copy(std::begin(source), std::end(source), std::begin(vec));

	vec.erase(std::unique(std::begin(vec), std::end(vec), 
		std::greater<int>()		
		), std::end(vec));

	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	//4.unique_copy.˫���б�ʽͬ������.�����_if�����汾.
	std::cout << "\n4.unique_copy:\n";
	li.clear();
	std::copy(std::begin(source), std::end(source), std::back_inserter(li));
	std::cout << "\nnow li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	std::unique_copy(std::begin(li), std::end(li), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	auto func_differencOne = [](int i, int j)
	{
		return (i + 1 == j) || (i - 1 == j);
	};

	std::unique_copy(std::begin(li), std::end(li), std::ostream_iterator<int>(std::cout, " "), func_differencOne);
	std::cout << std::endl;

}


int maindaily0530()
{
	func_algor_0530();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}