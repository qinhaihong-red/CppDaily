//daily0503
/************************************************************************/
/* 
unodered_xx�������������ڲ���hash tableʵ�֣�����bucket+hashfunc.

���Գ���ʱ����ʵ�ֲ��ң������ڶԲ����ٶ�Ҫ�󼫸ߵĳ���.

1.����key�޷��޸ģ������ڹ�������. ���޸�key������ɾ�����ٲ���.
2.���ڻ������ͣ��Ѷ�����Ĭ�ϵ�hashfunc����ȵıȽϱ�׼�����ڶ������ͣ���Ҫ����hash��������ȵıȽϱ�׼.
3.����multiset��multimap���������ֵͬ�ĳ��֣����������ʽ�����ͻ.
4.����set��map�����ڲ�ֵͬ���ֵ�hash��ͻ����rehash�����ͻ.
5.ɾ������ʹ�õ�����ʧЧ�����ǲ����п���ʹ�����е�����ʧЧ.
6.������ܵ���Ԫ���� ���� bucket*����ϵ�� �����rehash.

*/
/************************************************************************/

#include"./common/common.h"
#include <unordered_set>

void func_unorderd_set_inside()
{

	auto f_hash = [](const CPlayer &player)->std::size_t
	{
		return std::hash<std::string>()(player.getName()) + std::hash<int>()(player.getRank());
	};

	auto f_equal = [](const CPlayer &p1, const CPlayer &p2)
	{
		return p1.getName() == p2.getName();
	};


	std::unordered_set<CPlayer, decltype(f_hash), decltype(f_equal)> uset(50,f_hash,f_equal);

	std::cout << CPlayer("James Harden", 96) << std::endl;

	uset.insert(CPlayer("James Harden", 96));
	uset.insert(CPlayer("Lebron James",99));
	uset.insert(CPlayer("Curry",97));

	common::print_elems(uset, common::PrintFormat::n);
	std::cout << "insert another curry:" << std::endl;
	uset.insert(CPlayer("Curry", 97));
	common::print_elems(uset, common::PrintFormat::n);


}


int maindaily0503()
{

	func_unorderd_set_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}