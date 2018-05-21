//daily0424
/************************************************************************/
/* 

list:
1.���������κβ�λ����Ƶ����ɾ�ĳ���.
2.�ڲ�ʵ��Ϊ˫������������ĵ�������˫�������.ĳЩ�㷨Ҫ�����������������
  ��������list. ��list���Լ���sort�㷨.
3.list���Լ���remove(value)�����ص���ɾ������ֵΪvalueԪ�صĸ�������erase(iter)����ͬvector�����ص�����һ������������Ա��������˲�����vector��deque����erase+remove����ɾ��Ԫ��.
4.������ɾ�����ᵼ��list������ʧЧ.
5.ע��list��һϵ����ͬ���Ͷ���֮������ƶ���move�������ӣ�splice,relink���ȵ��㷨.


*/
/************************************************************************/
#include"./common/common.h"


void print_lists(const std::list<int> &l1, const std::list<int> &l2)
{
	std::cout << "list 1:\n";
	std::copy(l1.begin(), l1.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\nlist 2:\n";
	std::copy(l2.begin(), l2.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}


void func_list_inside()
{
	std::list<int> l1, l2;

	for (int i=0;i<6;++i)
	{
		l1.push_back(i);
		l2.push_front(i);
	}
	std::cout << "before splice:\n";
	print_lists(l1, l2);

	//��list1�е�����Ԫ���ƶ���l2��ֵΪ3��Ԫ��֮ǰ
	l2.splice(std::find(l2.begin(),l2.end(),3),l1);
	std::cout << "after splice:\n";
	print_lists(l1, l2);

	//��l2ͷ����Ԫ���ƶ���β��
	l2.splice(l2.end(), l2, l2.begin());
	print_lists(l1, l2);

	l2.sort();
	l1 = l2;
	l2.unique();
	print_lists(l1, l2);


	//��l2����Ԫ�غϲ���l1
	l1.merge(l2);
	print_lists(l1, l2);
}


int maindaily0424()
{
	func_list_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}