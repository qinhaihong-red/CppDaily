//daily0417
/************************************************************************/
/* 

1.算法与成员函数配合进行元素的删除与增加
2.以函数（对象）做为算法的参数
	--变换容器内元素
	--单参判别式与双参判别式


*/
/************************************************************************/

#include<iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <functional>
#include <string>
#include <vector>
#include <deque>

class CPerson0417
{
public:
	CPerson0417(const std::string &strFirstName, const std::string &strSecondName);
	~CPerson0417() {};
	void print();
	std::string get1Name() const{ return m_str1Name; };
	std::string get2Name() const{ return m_str2Name; };

private:
	std::string m_str1Name, m_str2Name;
};

bool sort_cr(const CPerson0417 &cp1, const CPerson0417 &cp2)
{
	return cp1.get2Name() < cp2.get2Name() || (cp1.get2Name() == cp2.get2Name() && cp1.get1Name() < cp2.get1Name());
}

CPerson0417::CPerson0417(const std::string &strFirstName, const std::string &strSecondName) :m_str1Name(strFirstName), m_str2Name(strSecondName)
{

}

void CPerson0417::print()
{
	std::cout << "This is:" << m_str1Name << " " << m_str2Name << std::endl;
}

void func_algor0417_inside()
{
	//1.算法配合成员函数进行删除
	std::list<int> li;
	for (int i=1;i<=6;++i)
	{
		li.push_back(i);
		li.push_front(i);
	}

	std::cout << "before erase 3:\n";
	std::copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	li.erase(std::remove(li.begin(), li.end(), 3), li.end());

	std::cout << "after erase 3:\n";
	std::copy(li.begin(), li.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;


	//2.使用for_each进行打印
	std::cout << "print with for_each:\n";
	std::for_each(li.begin(), li.end(), [](int n) 
	{
		std::cout << n << " ";
	});
	std::cout << std::endl;

	//3.使用transform进行变换
	std::vector<int> vec;
	std::transform(li.begin(), li.end(), std::back_inserter(vec), [](int n) 
	{
		return n*n;
	});
	std::cout << "transform li 2 vec with f:x->x^2 .\n";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//4.单参判别式
	//查找vec中是否有16
	auto pos = std::find_if(vec.begin(), vec.end(), [](int n) 
	{
		if (n == 16)
		{
			return true;
		}

		return false;
	});

	if (pos !=vec.end())
	{
		std::cout << "find 16 in vec.\n";
	}

	//5.双参判别
	//双参判别常用于排序等比较算法中.
	
	//这里使用deque容器，就可以配合下面的sort进行排序
	//而list却不行！！
	std::deque<CPerson0417> lip;
	lip.push_back(CPerson0417("Lebron","James"));
	lip.push_back(CPerson0417("James", "Harden"));
	lip.push_back(CPerson0417("Stephen", "Curry"));
	lip.push_back(CPerson0417("Dwyane", "Wade"));
	lip.push_back(CPerson0417("Antony", "Davis"));
	lip.push_back(CPerson0417("Carmelo", "Antony"));


	std::cout << "before sorted ,the players list is:\n";
	std::for_each(lip.begin(), lip.end(), [](CPerson0417& cp) 
	{
		cp.print();
	});
	std::cout << std::endl;

	//进行排序
	std::sort(lip.begin(), lip.end(), [](CPerson0417 &cp1, CPerson0417 &cp2)->bool
	{
		return cp1.get2Name() < cp2.get2Name() || (cp1.get2Name() == cp2.get2Name() && cp1.get1Name() < cp2.get1Name());
	});

	//std::sort(lip.begin(), lip.end(), sort_cr);

	std::cout << "after sorted ,the players list is:\n";
	std::for_each(lip.begin(), lip.end(), [](CPerson0417& cp)
	{
		cp.print();
	});
	std::cout << std::endl;

}

int maindaily0417()
{
	func_algor0417_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}