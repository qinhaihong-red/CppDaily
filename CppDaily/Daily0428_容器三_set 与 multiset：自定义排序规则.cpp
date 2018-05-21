//daily0428
/************************************************************************/
/* 

set��multiset:
1.�ڲ��Ժ����ʵ�֣������Զ�����.
2.����������ϸ�����ģ�strict weak order��:
--�ǶԳƵģ�x<yΪtrue����y<xΪfalse
--�ɴ��ݵ�
--���Է��ģ�x<x��ԶΪfalse
--��Ч����
3.Ĭ�����Ͳ���less<T>����������.�Զ������ͱ���ָ���������
  ��������bool operator()(T t1,T t2)�ĺ����������lambda����.
  ���ϸ�����ֻ��Ҫʹ�� < �Ƚϼ��� ������˵��ֻ��Ҫreturn t1.xx < t2.xx ;��

4.����Ĳ��Һ�����lower_bound(val)��upper_bound(val):
--ǰ�߷��� Ԫ��ֵ >= val �ĵ�һ��Ԫ��
--���߷��� Ԫ��֮ >  val �ĵ�һ��Ԫ��

5.��������˫�������. ��˶���Ҫ��ʹ��������������㷨���޷�����.
�����޷�ֱ�Ӹı�Ԫ��ֵ�������ԭ����ȷ�����򣩣�������ɾ�����ٲ���.

6.ɾ������Ա���� erase(val)��erase(pos)��ǰ�߷���ɾ����ֵΪval��Ԫ�صĸ����������޷���.
������е�����ʧЧ�ĳ���������ڵ�����ѭ���У���Ҫ��erase(pos++).




*/
/************************************************************************/
#include"./common/common.h"

class CItem
{
public:
	CItem(const std::string&,int nPrice=0);
	~CItem() {};

	std::string getName() const { return m_strName; };
	int getPrice() const { return m_nPrice; };
private:
	std::string m_strName;
	int m_nPrice;
};


CItem::CItem(const std::string& name, int nPrice/* =0 */) :m_nPrice(nPrice), m_strName(name)
{

}


std::ostream& operator<<(std::ostream &os, const CItem &ci)
{
	os << ci.getName().c_str() << " " << ci.getPrice() << std::endl;

	return os;
}


void func_set_mset_inside()
{
	CItem i1("james",99);//lbj
	CItem i2("james",96);//james harden
	CItem i3("curry", 97);
	CItem i4("durant",98);


	auto f = [](const CItem &x,const CItem &y)
	{
		if (x.getName() == y.getName())
		{
			return x.getPrice() > y.getPrice(); 
		}

		return x.getName() < y.getName();
	};


	std::set<CItem, decltype(f)> s(f);
	s.insert(i1);
	s.insert(i2);
	s.insert(i3);
	s.insert(i4);

	s.insert(i1);


	std::copy(s.begin(), s.end(), std::ostream_iterator<CItem>(std::cout, ""));


}



int maindaily0428()
{
	func_set_mset_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}