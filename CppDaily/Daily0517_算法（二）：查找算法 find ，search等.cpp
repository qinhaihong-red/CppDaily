//daily0517
/************************************************************************/
/* 
�����㷨
һ ���ҵ�һ��Ԫ��
	find
	find_if
	find_if_not
	Ҫ������input iterator�����ұ����䣬������ҵ����׸�����Ҫ�����ĵ�����.������end.
	ע�⣺
	1.������������䣬Ӧ��ʹ��Ч�ʸ��ߵ������㷨���磺lower_bound,upper_bound,equal_range����
	binary_search���㷨
	2.������������������������Ӧ��ʹ�õ�Ч�ĳ�Ա����find

�� ����ǰn������ƥ��ֵ
	search_n.
	search_n�������汾������һ�����书�ܶ��ԣ�Ӧ������Ϊ��search_n_if. ����Ϊ��ʷԭ��
	û���������������Ҳ���������. ʹ�õ�ʱ����ע��.

�� ���ҵ�һ��������
	search(beg,end,sub-beg,sub-end)
	search(beg,end,sub-beg,sub-end,BinaryPredicate bp)//Ӧ����Ϊ search_if
	�������Ҫ�����Ե��������䣬���еڶ������������������ֵ�ǵ�һ�����������ҵ�.
	Ҫ������forward iterator��������������ҵ����׸�����Ҫ�����ĵ�����.������end.
*/
/************************************************************************/

#include"./common/common.h"


void func_find_search_inside0517()
{
	//1.���ҵ�һ��Ԫ��
	std::cout << "test1:\n";
	std::list<int> li;
	common::insert_element(li, 1, 9);
	common::insert_element(li, 1, 9);

	std::cout << "now li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//�ҵ��׸�ֵΪ4��Ԫ�صĵ�����
	auto pos = std::find(std::begin(li), std::end(li), 4);

	//���ҵڶ���Ԫ��
	if (pos != std::end(li))
	{
		auto pos2 = std::find(++pos, std::end(li), 4);

		if (pos2 != std::end(li))
		{
			//��ӡ������4֮�������Ԫ�أ�������β��
			std::cout << "elements between 4s are:\n";
			//ע�����������
			std::copy(--pos, ++pos2, std::ostream_iterator<int>(std::cout, " "));
			std::cout << std::endl;

		}
	}

	//find_ifʹ��
	li.clear();
	common::insert_element(li, 1, 9);
	std::cout << "now li is:\n";
	common::print_elems(li);
	std::cout << std::endl;

	//�ҵ���һ����3���Ԫ��
	pos = std::find_if(std::begin(li), std::end(li), std::bind(std::greater<int>(), std::placeholders::_1, 3));
	std::cout << "the " << std::distance(std::begin(li), pos) + 1 << " element is the first greater than 3." << std::endl;

	//2.����ǰn������ƥ���ֵ
	std::cout << "test2:\n";

	std::deque<int> deq={1,2,7,7,6,3,9,5,7,7,7,3,6};
	auto d_pos = std::search_n(std::begin(deq), std::end(deq),//��Χ
		3,//�ظ�����
		7 //ֵ
	);//�����ظ�3�ε�ֵΪ7��Ԫ���״γ��ֵ�λ��

	if (d_pos!=std::end(deq))
	{
		std::cout << "3 consecutive elements with 7 start with " << std::distance(std::begin(deq), d_pos) + 1 << " . element." << std::endl;

	}

	//�����б�ʽ��search_n������ʾ��.��Ҫע�⣬������ʽ�Ƚ����.

	//3.���ҵ�һ��������
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


	//��˫���б�ʽ��search
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