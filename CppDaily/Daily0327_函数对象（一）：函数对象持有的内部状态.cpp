//daily0327
/************************************************************************/
/* 

函数对象与函数的区别在于，函数对象可以保持一种内部状态（internal state,于有静态局部变量的函数）.



*/
/************************************************************************/

#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
#include <list>
#include <iterator>

void func_lambda_state_inside()
{
	int a = 10, b = 99;
	std::cout << "a is:" << a << std::endl;
	std::cout << "b is:" << b << std::endl;
	auto func = [a, &b]() //对于传值捕获，a的值始终是距离lambda最近修改的那个值.
	{
		//std::cout << "\nafter ++,a is:" << ++a << std::endl;//对于以传值方式捕获的a,不能对其进行修改
		
		std::cout << "\ninside func,a is:" << a << std::endl;
		std::cout << "inside func after ++,b is:" << ++b << std::endl;
	};
	a = 50;
	b = 200;
	std::cout << "a is:" << a << std::endl;
	std::cout << "b is:" << b << std::endl;

	func();
	func();

	auto func2 = [a, &b]() mutable 
	{
		//由于mutable的修饰，
		//func2具备修改持有状态的能力
		//如这里持有的可修改的a的值是50，尽管下面在func2外部把a改为了80,
		//但是后续迭代仍以a内部状态为准.

		std::cout << "\ninside func2 after ++,a is:" << ++a << std::endl;
		std::cout << "inside func2 after ++,b is:" << ++b << std::endl;
	};
	a = 80;

	std::cout << "\na is:" << a << std::endl;
	std::cout << "b is:" << b << std::endl;

	func2();
	func2();
}

class IntSeq
{
public:
	IntSeq(int val=0);
	~IntSeq() {}

	int operator() ();

private:
	int m_nInitVal;
};

IntSeq::IntSeq(int val) :m_nInitVal(val)
{

}

int IntSeq::operator()()
{
	return ++m_nInitVal;
}

template<typename T>
void print_T(const T &t)
{
	for (auto &i : t)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void func_functor_interalstate_inside()
{
	std::list<int> li;

	std::generate_n(std::back_inserter(li), 9, IntSeq(9));
	print_T(li);

	//这个next犹如python中的next一般
	std::generate(std::next(li.begin())/*start,含*/, std::prev(li.end())/*end,不含*/, IntSeq(90));
	print_T(li);



	IntSeq seq(1);
	std::generate_n(std::back_inserter(li), 5, seq);
	print_T(li);
	//由于是传值的方式传入functor，seq状态不会改变
	//上下两个print增加的内容一样.
	std::generate_n(std::back_inserter(li), 5, seq);
	print_T(li);

}


int maindaily0327()
{
	func_lambda_state_inside();
	std::cout << std::endl;
	func_functor_interalstate_inside();
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}