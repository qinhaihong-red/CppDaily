//daily0315
/************************************************************************/
/* 
1.reference warppter��std::ref�������÷�ʽ����.
	-make_pair��make_tuple���ɴ����õĶ���.
	-std::bind���԰󶨵����������Ͳ����ĺ���.
	-thread������Դ�������õĲ���.
2.function wrapper��  ��std::function<T>����Բ�ͬ�ɵ��ö��󣨺�������ĳ�Ա������lambda�������󣩣�
��ͳһ�ķ�ʽ���а�װ������
3.min��max��ѡ�����ֵ����Сֵ
4.swap�����ٽ��ж����û������Ч��
5.std::rel_ops���ڽ�����ر��ıȽϲ�������==��<��������£�ʹ��std::rel_ops,
�ڲ������������Ƚϲ����������ܿ��ٽ��� !=��> �ȱȽ�

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <functional> //std::cref��std::functional
#include <algorithm>  //min��max
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
	auto func2 = std::bind(func_add<int>, c, std::cref(b));//cû����ref���÷�ʽ���룬��˲��ᱻ�޸�
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
	//1.ע��min�ķ�������
	const int &c = std::min(a, b);//�����ص���ʵ��һ��const �͵�����
	//����ͨ���� int c = std::min(a,b); ������.
	std::cout << c << std::endl;//10
	a = 101;
	std::cout << c << std::endl;//101

	//2.ע��minmax�ķ�������
	//minmax���ص���һ��pair��first��С�ģ�second�Ǵ��
	auto r = std::minmax(a, b);
	std::cout << "the min is: " << r.first << ", the max is: " << r.second << std::endl;

	//3.�Զ���ȽϺ���
	//�����Խ���һ���ȽϺ���
	//����дһ���Ƚ�ƽ���ĺ���,����ƽ����С����
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

	//4.�Ƚϲ�ͬ���͵���ֵ
	long m = 100;
	int n = 99;

	//�����ǲ��е�
	//ret = std::min(m, n);

	//���������ֿ���
	ret = std::min<long>(m,n);

	//5.��ֵ��. min ���� minmax�����Խ��ճ�ֵ�У����Ǹо��Ƚϼ���.
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

//����MyContainer���ͣ�����ȫ������
void swap(MyContainer &mc1, MyContainer &mc2) noexcept(noexcept(mc1.swap(mc2)))
{
	std::cout << "call the special overload for MyContainer." << std::endl;
	mc1.swap(mc2);
}
void func_swap_inside()
{
	std::cout << std::endl << "----swap Test-----" << std::endl;

	//swap�����ڲ�ʹ��std::moveʵ�֣�������֧��move����move������ʹ��copy����assign.
	//��������δ����move,Ҳδ����copy���ͻ����ʧ��.

	//swap���������ǽ���������ڲ���Ա�����Ǹ�ֵ������������Ч��.
	//��ע������������Լ�string����Ӧ���˸ü���.


	//�����Զ�����󣬿����ػ�swap��������Ч��

	int *a = new int[10];
	int *b = new int[20];
	MyContainer mc1(a,10);
	MyContainer mc2(b, 20);

	std::cout << "before swap:" << std::endl;
	mc1.print();
	mc2.print();
	//std::swap(mc1,mc2);//����std::�������ռ䣬������õ��Զ����swap
	swap(mc1, mc2);//ֱ�ӵ���
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

//��ʽ���ӱȽϲ���������������
//���������Զ������ͣ�����бȽϵ��߼���
//ֻ��Ҫ����<��==����������ؼ���.
//�����ıȽϲ���������ʹ��std::rel_ops�Զ���չ.
void func_rel_ops_inside()
{
	using namespace std::rel_ops;

	std::cout << std::endl << "----rel_ops Test-----" << std::endl;


	XSQ x(-10);
	XSQ y(9);

	if (x>y)//����û�ж���>���أ�����ͨ��std::rel_ops������ʽ��չ.
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