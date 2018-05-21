//daily0315
/************************************************************************/
/* 
1.reference warppter，std::ref，以引用方式传参.
	-make_pair和make_tuple生成带引用的对象.
	-std::bind可以绑定到带引用类型参数的函数.
	-thread对象可以传入带引用的参数.
2.function wrapper，  即std::function<T>，针对不同可调用对象（函数，类的成员函数，lambda函数对象），
以统一的方式进行包装并调用
3.min和max，选出最大值和最小值
4.swap，快速进行对象置换，提高效率
5.std::rel_ops，在仅定义必备的比较操作符（==与<）的情况下，使用std::rel_ops,
在不必重载其他比较操作符，就能快速进行 !=，> 等比较

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <functional> //std::cref和std::functional
#include <algorithm>  //min和max
#include <utility>  //std::rel_ops
#include <type_traits>


template<typename T>
T func_add(T &t1, const T &t2)
{
	T r(t1 + t2);
	if (std::is_integral<T>::value)
	{
		t1 = 10;
	}
	//else
	//{
	//	t1 = "hi.";
	//}
	return r;

}



void func_cref_inside()
{
	int a = 1, b = 2,c=1;
	

	std::cout << "before, a is:" << a << std::endl;

	auto func = std::bind(func_add<int>, std::ref(a), std::cref(b));
	int r = func();
	std::cout << "after,result is: " << r << ", a is :" << a << std::endl;

	std::cout << std::endl;
	std::cout << "before, c is:" << c << std::endl;
	auto func2 = std::bind(func_add<int>, c, std::cref(b));//c没有以ref引用方式传入，因此不会被修改
	r = func2();
	std::cout << "after,result is: " << r << ", c is :" << c << std::endl;

	std::string str1 = "hello ", str2 = "world!";
	auto func3 = std::bind(func_add<std::string>, std::ref(str1), std::ref(str2));
	std::string str_r = func3();
	std::cout << std::endl  << str_r << ", " << str1 << std::endl;

}

void func_minmax_inside()
{
	std::cout << std::endl << "----MinMax Test-----" << std::endl;
	int a = 10, b = 99;
	//1.注意min的返回类型
	const int &c = std::min(a, b);//它返回的其实是一个const 型的引用
	//但是通常是 int c = std::min(a,b); 这样用.
	std::cout << c << std::endl;//10
	a = 101;
	std::cout << c << std::endl;//101

	//2.注意minmax的返回类型
	//minmax返回的是一个pair，first是小的，second是大的
	auto r = std::minmax(a, b);
	std::cout << "the min is: " << r.first << ", the max is: " << r.second << std::endl;

	//3.自定义比较函数
	//还可以接收一个比较函数
	//这里写一个比较平方的函数,返回平方较小的数
	int e = -10, f = 5;
	int ret = std::min(e, f, [](int a, int b) 
	{
		if (a*a<b*b)
		{
			return true;
		}
		return false;
	});
	std::cout << "the min is:" << ret << std::endl;

	//4.比较不同类型的数值
	long m = 100;
	int n = 99;

	//这样是不行的
	//ret = std::min(m, n);

	//但是这样又可以
	ret = std::min<long>(m,n);

	//5.初值列. min 或者 minmax还可以接收初值列，但是感觉比较鸡肋.
}


class MyContainer
{
public:
	MyContainer(int *p=nullptr,int nNum=0);
	~MyContainer();

	void swap(MyContainer &mc);
	void print();
private:
	int *m_p;
	int m_nNum;
};

MyContainer::MyContainer(int *p/* =nullptr */, int nNum/* =0 */) :m_p(p), m_nNum(nNum)
{

}

MyContainer::~MyContainer()
{
	if (m_p!=nullptr)
	{
		delete[] m_p;
		m_p = nullptr;
	}

	m_nNum = 0;
}

void MyContainer::swap(MyContainer &mc)
{
	std::swap(m_p, mc.m_p);
	std::swap(m_nNum, mc.m_nNum);
}

void MyContainer::print()
{
	std::cout << "p is:" << m_p << ",num is:" << m_nNum << std::endl;
}

//对于MyContainer类型，进行全局重载
void swap(MyContainer &mc1, MyContainer &mc2) noexcept(noexcept(mc1.swap(mc2)))
{
	std::cout << "call the special overload for MyContainer." << std::endl;
	mc1.swap(mc2);
}
void func_swap_inside()
{
	std::cout << std::endl << "----swap Test-----" << std::endl;

	//swap函数内部使用std::move实现，即对象支持move就用move，否则使用copy或者assign.
	//如果对象既未定义move,也未定义copy，就会调用失败.

	//swap最大的优势是交换对象的内部成员，而非赋值，这样提升了效率.
	//标注库的所有容器以及string，都应用了该技术.


	//对于自定义对象，可以特化swap，以提升效率

	int *a = new int[10];
	int *b = new int[20];
	MyContainer mc1(a,10);
	MyContainer mc2(b, 20);

	std::cout << "before swap:" << std::endl;
	mc1.print();
	mc2.print();
	//std::swap(mc1,mc2);//加上std::的命名空间，不会调用到自定义的swap
	swap(mc1, mc2);//直接调用
	std::cout << std::endl <<"after swap:" << std::endl;
	mc1.print();
	mc2.print();

	std::cout << "end" << std::endl;
}

class XSQ
{
public:
	XSQ(int n = 0);
	~XSQ() {};
	bool operator==(const XSQ& x) const;
	bool operator<(const XSQ& x) const;
private:
	int m_n;
};


XSQ::XSQ(int n /* = 0 */) :m_n(n)
{

}

bool XSQ::operator==(const XSQ& x) const
{
	return m_n*m_n == x.m_n*x.m_n;
}

bool XSQ::operator<(const XSQ& x) const
{
	return m_n*m_n < x.m_n*x.m_n;
}

//隐式增加比较操作符的运算重载
//即，对于自定义类型，如果有比较的逻辑，
//只需要定义<和==的运算符重载即可.
//其他的比较操作，可以使用std::rel_ops自动扩展.
void func_rel_ops_inside()
{
	using namespace std::rel_ops;

	std::cout << std::endl << "----rel_ops Test-----" << std::endl;


	XSQ x(-10);
	XSQ y(9);

	if (x>y)//尽管没有定义>重载，但是通过std::rel_ops可以隐式扩展.
	{
		std::cout << "square of x(-10) bigger than square of y(9)" << std::endl;
	}
}
int	maindaily0315()
{

	func_cref_inside();
	func_minmax_inside();
	func_swap_inside();
	func_rel_ops_inside();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}