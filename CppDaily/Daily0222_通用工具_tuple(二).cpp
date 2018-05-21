//daily0222
/************************************************************************/
/* 
tuple���������ԣ�Ӧ�ÿ����������л��뷴���л�.
����Ҫ����ע�⣺
1.make_tuple
2.ref
3.tie

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <utility>
#include <tuple>
#include <complex>
#include <functional>

void func_tuple_inside2()
{
	std::tuple<int, double, std::string> t{1,9.99,"hello"};
	auto t2 = std::make_tuple(2, 9.99, "hello");

	std::cout << "t is :" << std::endl<< std::get<0>(t) << " " << std::get<1>(t) << " " << std::get<2>(t) << std::endl;
	std::cout << "t2 is :" << std::endl << std::get<0>(t2) << " " << std::get<1>(t2) << " " << std::get<2>(t2) << std::endl;

	std::cout << "t2 > t:"<<std::boolalpha << (t2 > t) << std::endl;


	std::string strText("world hello!");
	int i=100;
	double d{};
	std::cout << std::endl << "here Text is :" << strText << ", i is:" << i << std::endl;
	auto t3 = std::make_tuple(std::ref(strText), std::ref(i));
	std::get<0>(t3) = "hello world!";
	std::get<1>(t3) = 101;
	std::cout << std::endl << "here Text is :" << strText << ", i is:" << i << std::endl;

	//����
	auto t4 = std::make_tuple(std::ref(i), std::ref(d), std::ref(strText)) = t;
	std::cout << std::endl << "here Text is :" << strText<<", d is:"<<d << ", i is:" << i << std::endl;//Ӧ����tһ��

	//���˵make_tuple�����л�����ôtie���Ƿ����л�
	std::tie(i, d, strText) = t2;
	std::cout << std::endl << "here Text is :" << strText << ", d is:" << d << ", i is:" << i << std::endl;//Ӧ����tһ��

	//tuple������һЩ����
	auto t5 = std::tuple_cat(t, t2);
	std::cout << std::endl<<"after cat t & t2, the elements size of t5 is:" << std::tuple_size<decltype(t5)>::value << std::endl;

	std::tuple_element<1, decltype(t)>::type d2 = d;
	std::cout << "d2 = d,is:" << d2 << std::endl;
}


int maindaily0222()
{
	func_tuple_inside2();

	std::string strInput;
	std::getline(std::cin, strInput);
	return 0;
}