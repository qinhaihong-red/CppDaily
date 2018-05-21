//daily0509
/************************************************************************/
/* 

һ ����������
	1.Output	   �������������ǰд��.     �ṩ��: Ostream, inserter.
	2.Input		   �������������ǰ��ȡһ��. �ṩ�ߣ�Istream.
	3.Foward	   ǰ�����������ǰ��ȡ.     �ṩ�ߣ�ǰ���б�forwad list����������.
	4.Bidrectional ˫���������ǰ���ȡ.	 �ṩ�ߣ�list,set,m-set,map,m-map
	5.RandomAccess �����ȡ������.			 �ṩ�ߣ�array,vector,deque,string,c-style array

�� ��������������
	�����ȡ�������Ĺ�����Ϊǿ��. ���������������ṩ��һЩ����������ʹ���������͵�����
	���Ի����ͬ�����ȡ������һ��������:
	--advance()
	--prev()
	--next()
	--distance()
	�Լ�iter_swap(),���Խ���������������ֵ.
	���begin()��end()����������������.

*/
/************************************************************************/

#include"./common/common.h"
#include <iterator>


void func_interator_helpler_inside()
{
	//1. void advance(InputIterator &pos,Dist n)
	//ʹ�÷� random-access �������߱�ǰ�����ߺ���n��Ԫ�ص�����.
	//�ú��������أ��Ҳ����������Ƿ񳬹����е�end().�����Ҫ�Լ�ע��.

	std::list<int> li = {1,3,4,5,7,9};

	auto pos = std::begin(li);

	std::cout << *pos << std::endl;

	std::advance(pos, 3);

	std::cout << *pos << std::endl;

	std::advance(pos, -1);

	std::cout << *pos << std::endl;

	//2.next()��prev():�����ǰ�ƶ���������λ��
	// ForwardIterator next(FI pos)
	// ForwardIterator next(FI pos,Dist n)

	//BidirectionalIterator prev(BI pos)
	//BidirectionalIterator prev(BI pos, Dist n)

	//3.distance() : ��������������֮��ľ���.
	pos = std::find(std::begin(li), std::end(li), 5);
	if (pos != std::end(li))
	{
		std::cout << "\ndistance from beginning and 5 is:" << std::distance(std::begin(li), pos) << std::endl;
	}
	else
	{
		std::cout << "5 not found.\n";
	}

	//4.iter_swap() �� ����������������ֵ.
	//���������Ͳ�����ͬ��������ָ���ͱ�����໥��ֵ.

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