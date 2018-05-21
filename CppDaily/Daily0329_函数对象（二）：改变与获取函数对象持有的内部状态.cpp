//daily0329
/************************************************************************/
/* 
���������ڲ������Ĺ����У����ǿ��ܻ���������Ҫ��
1.�ı亯��������ڲ�״̬
2.��ú��������ڹ��̽������״̬

���磺
std::string str("Abc");

1.
void MakeUpper(std::string &str);

2.
std::string MakeUpper(std::string str)

��һ�ַ�ʽͨ�����ã������Ǵ��봫�����͵ģ��ɻ�����յĽ��.
�ڶ��ַ�ʽͨ������ֵ������ȡ���.

�Ժ�������Ĵ��������������.

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

//�Դ����÷�ʽ�ı亯��������ڲ�״̬��
//2�ַ���������std::ref��������.
void func_change_functor_state()
{
	IntSeq2 seq(1);
	std::list<int> li;

	
	std::generate_n(std::back_inserter(li), 9, std::ref(seq));//1.��ӡ��2��10.���������÷�ʽ���뺯���������seq��״̬Ҳͬʱ�ı�Ϊ10
	print_T2(li);

	std::generate_n(std::back_inserter(li), 9, seq);//2.��ӡ��2��19.����seq�����ô��룬״̬άϵ10����
	print_T2(li);

	//3.����ô��ģ���������Ч����ͬ��1�����std::ref.
	//���Կ������쳣���.
	//��ӡ��2��19��11��19��ͬʱ�ı�seq״̬��19
	std::generate_n<std::back_insert_iterator<std::list<int>>,int,IntSeq2&>(std::back_inserter(li), 9, seq);
	print_T2(li);

	//4.��ӡ��2��19��11��19,20��28
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


//�Է���ֵ��ʽ�������µĺ�������
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

