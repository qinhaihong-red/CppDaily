//daily0428
/************************************************************************/
/* 

set和multiset:
1.内部以红黑树实现，可以自动排序.
2.排序规则是严格若序的（strict weak order）:
--非对称的：x<y为true，则y<x为false
--可传递的
--非自反的：x<x永远为false
--等效传递
3.默认类型采用less<T>即升序排序.自定义类型必须指定排序规则：
  即重载了bool operator()(T t1,T t2)的函数对象或者lambda函数.
  按严格弱序，只需要使用 < 比较即可 （简单来说，只需要return t1.xx < t2.xx ;）

4.特殊的查找函数：lower_bound(val)与upper_bound(val):
--前者返回 元素值 >= val 的第一个元素
--后者返回 元素之 >  val 的第一个元素

5.迭代器：双向迭代器. 因此对于要求使用随机迭代器的算法则无法适用.
由于无法直接改变元素值（会打乱原本正确的排序），必须先删除，再插入.

6.删除：成员函数 erase(val)与erase(pos)，前者返回删除的值为val的元素的个数，后者无返回.
这里会有迭代器失效的场景，因此在迭代器循环中，需要：erase(pos++).




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