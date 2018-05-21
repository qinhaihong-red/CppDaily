//daily0228
/************************************************************************/
/* 
智能指针：shared_ptr
1.初始化.显式构造.推荐使用std::make_shared
2.对于数组元素的析构
3.自定义析构：释放资源等.

*/
/************************************************************************/


#include <iostream>
#include <string>
#include <memory>
#include <functional>

void func_sharedptr_inside()
{
	//初始化1：
	std::shared_ptr<std::string> pStr(new std::string("hello"));
	//std::shared_ptr<std::string> pStr = new std::string("hello");//由于显式构造函数，这样的初始化不被允许

	//初始化2：
	std::shared_ptr<std::string> pStr2 = std::make_shared<std::string>("world!");//此种初始化更安全，也更快

	//初始化3:
	std::shared_ptr<std::string> pStr3;
	pStr3.reset(new std::string("^_^"));

	std::cout << *pStr << " " << *pStr2 << " " << *pStr3 << std::endl << std::endl;


	//对于new Array 类型的析构
	//std::shared_ptr的默认析构函数是调用delete.因此对于new type[num]型的指针，要特别注意：
	//1.std::shared_ptr<int> p(new int[10]); 可以通过编译，但析构时调用delete而非delete []，从而造成资源泄露
	//2.std::shared_ptr<int[]> 这种写法不能通过编译
	
	//两种办法解决delete []的问题：
	//1.自定义析构器
	std::shared_ptr<int> p(new int[10], [](int *p) {delete[] p; });
	for (int i=0;i<10;++i)
	{
		p.get()[i] = i;
	}

	std::cout << (p.get()[0] + p.get()[9]) << std::endl;

	//2.使用辅助函数 std::default_delete<int[]>();
	std::shared_ptr<int> p2(new int[10], std::default_delete<int[]>());
	for (int i = 0; i < 10; ++i)
	{
		p2.get()[i] = i;
	}
	std::cout << (p2.get()[0] + p2.get()[9]) << std::endl;

}


int maindaily0228()
{
	func_sharedptr_inside();


	std::string strInput;
	std::getline(std::cin,strInput);

	return 0;
}