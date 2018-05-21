//daily0307
/************************************************************************/
/*
unique_ptr对于数组资源的管理和自定义析构函数的管理，都与
shared_ptr不太一样

*/
/************************************************************************/

#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include <utility>




void func_unique_ptr_inside2()
{
	//一. 对于数组资源的管理
	//std::unique_ptr<int> p(new int[10]);//这种方式毫无疑问是错误的

	//解决方法1：u_ptr定义了对处理数组资源的偏特化版本，只需要在模板参数中填 x[] ，
	//即会在资源析构的时候，调用delete []. 而shared_ptr没有这种偏特化版本支持.
	std::unique_ptr<int[]> p(new int[10]);
	for (auto i=0;i<10;++i)
	{
		p[i] = i;//此偏特化版本不再提供*和->操作符，只提供[]操作符
	}

	std::cout << "p[0] + p[9] : "<< p[0] + p[9] << std::endl;

	//解决方法2：自定义析构器.
	//但是这里又不同于shared_ptr，uunique_ptr需要在第二个模板参数指定析构器类型，
	//而shared_ptr不必指定.
	auto f_deleter = [](int *p)
	{
		delete[] p;
	};
	std::unique_ptr<int, decltype(f_deleter)> p2(new int[10],f_deleter);
	for (auto i = 0; i < 10; ++i)
	{
		p2.get()[i] = i;
		//*(p2+i) = i;//不提供指针++操作
	}
	std::cout << "p2[0] + p2[9] : " << p2.get()[0] + p2.get()[9] << std::endl;

	//二. 其他资源的管理
	//核心就是自定义析构器.具体场景具体定义吧.
}


int maindaily0307()
{

	func_unique_ptr_inside2();

	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}