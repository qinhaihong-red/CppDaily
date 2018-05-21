//daily0329
/************************************************************************/
/* 
函数对象在参与计算的过程中，我们可能会有两种需要：
1.改变函数对象的内部状态
2.获得函数对象在过程结束后的状态

犹如：
std::string str("Abc");

1.
void MakeUpper(std::string &str);

2.
std::string MakeUpper(std::string str)

第一种方式通过引用，参数是传入传出类型的，可获得最终的结果.
第二种方式通过返回值，来获取结果.

对函数对象的处理与上面的类似.

*/
/************************************************************************/


#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
#include <list>
#include <iterator>
#include <vector>


class IntSeq2
{
public:
	IntSeq2(int val = 0);
	~IntSeq2() {}

	int operator() ();

private:
	int m_nInitVal;
};

IntSeq2::IntSeq2(int val) :m_nInitVal(val)
{

}

int IntSeq2::operator()()
{
	return ++m_nInitVal;
}

template<typename T>
void print_T2(const T &t)
{
	for (auto &i : t)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

//以传引用方式改变函数对象的内部状态：
//2种方法，其中std::ref清晰明了.
void func_change_functor_state()
{
	IntSeq2 seq(1);
	std::list<int> li;

	
	std::generate_n(std::back_inserter(li), 9, std::ref(seq));//1.打印出2到10.由于是引用方式传入函数对象，因此seq的状态也同时改变为10
	print_T2(li);

	std::generate_n(std::back_inserter(li), 9, seq);//2.打印除2到19.但是seq非引用传入，状态维系10不变
	print_T2(li);

	//3.加这么多模板参数，其效果等同于1里面的std::ref.
	//可以看出其异常简洁.
	//打印出2到19，11到19，同时改变seq状态到19
	std::generate_n<std::back_insert_iterator<std::list<int>>,int,IntSeq2&>(std::back_inserter(li), 9, seq);
	print_T2(li);

	//4.打印出2到19，11到19,20到28
	std::generate_n(std::back_inserter(li), 9, seq);
	print_T2(li);
}


class MeanVal
{
public:
	MeanVal(int sum=0,int count=0);
	~MeanVal() {};

	void operator() (int val);
	int Value();
private:
	int m_sum;
	int m_count;
};

MeanVal::MeanVal(int sum/* =0 */, int count/* =0 */) :m_sum(sum), m_count(count)
{

}

void MeanVal::operator()(int val)
{
	m_sum += val;
	++m_count;
}

int MeanVal::Value()
{
	//return double(m_sum) / m_count;
	return m_sum;
}


//以返回值方式，返回新的函数对象
void func_get_functor_state_by_return_value()
{
	std::vector<int> vec={1,3,5,7,9};

	int sum = 0;
	std::for_each(vec.begin(), vec.end(), [&sum](int a)
	{
		sum += a;
	});

	MeanVal mv = std::for_each(vec.begin(), vec.end(), MeanVal());

	std::cout << "\nsum is:" << sum << " .the results are equal :" << std::boolalpha << (mv.Value() == sum) << std::endl;
}

int maindaily0329()
{
	func_change_functor_state();
	func_get_functor_state_by_return_value();
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}

