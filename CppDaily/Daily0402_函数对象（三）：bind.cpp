//daily0402
/************************************************************************/
/* 

std::bind，将实参或者形参（通过placeholder）绑定到可调用对象，形成新的可调用对象。

*/
/************************************************************************/

#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <locale>

char myToupper(char c)
{
	std::locale loc;
	return std::use_facet<std::ctype<char> >(loc).toupper(c);
}

void changeVal(int &i)
{
	++i;
}

void func_bind_adapter_inside()
{
	//1.std::bind与一些预定义的函数对象的绑定示例
	auto plus10 = std::bind(std::plus<int>(),std::placeholders::_1,10);
	std::cout << "invoke plus10 with param 100 is :" << plus10(100) << std::endl;

	//注意这种链式bind很神奇
	auto plus10times2 = std::bind(std::multiplies<int>(),std::bind(std::plus<int>(),std::placeholders::_1,10),2);
	std::cout << "invoke plus10times2 with param 5 is :" << plus10times2(5) << std::endl;

	auto pow3 = std::bind(std::multiplies<int>(),std::bind(std::multiplies<int>(),std::placeholders::_1,std::placeholders::_1),std::placeholders::_1);
	std::cout << "invoke pow3 with param 9 is : " << pow3(9) << std::endl;

	auto inverseDivide = std::bind(std::divides<double>(),std::placeholders::_2,std::placeholders::_1);
	std::cout << "invoke inverseDivide with param (49,7) is : " << inverseDivide(49, 7) << std::endl;

	//2.绑定到全局函数
	std::string str("International");
	std::string subStr("Nation");

	auto pos = std::search(str.begin(), str.end(),
		subStr.begin(), subStr.end(), 
		std::bind(std::equal_to<char>(), 
			std::bind(myToupper, std::placeholders::_1), 
			std::bind(myToupper, std::placeholders::_2)));

	if (pos != str.end())
	{

		std::cout << subStr << " is part of " << str << std::endl;
	}

	//3.绑定到引用
	int i = 0;
	auto f1 = std::bind(changeVal,i);
	f1();
	std::cout << "\n now i is:" << i << std::endl;

	auto f2 = std::bind(changeVal,std::ref(i));
	f2();
	std::cout << "\n now i is:" << i << std::endl;

	auto f3 = std::bind(changeVal,std::placeholders::_1);
	f3(i);//本身就已经绑定到引用了，不必再使用ref
	std::cout << "\n now i is:" << i << std::endl;

	f3(std::ref(i));//等同于f3(i);
	std::cout << "\n now i is:" << i << std::endl;

}


int maindaily0402()
{
	func_bind_adapter_inside();
	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}
