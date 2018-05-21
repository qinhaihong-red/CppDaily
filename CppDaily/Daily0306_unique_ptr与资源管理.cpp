//daily0306
/************************************************************************/
/* 
unique_ptr提供了独占式拥有资源的语义. 特别适合资源的管理，如文件句柄的关闭等
还可以避免因异常而出现的资源泄露问题.

1.u_ptr有release语义，而s_ptr没有
2.u_ptr通常配合std::move进行资源的移动
3.注意传入函数的u_ptr以及从函数返回的u_ptr的资源归属，以及有效的表达形式

*/
/************************************************************************/

#include <iostream>
#include <memory>
#include <functional>
#include <string>
#include <utility>

std::unique_ptr<int> gen_uptr()
{
	std::unique_ptr<int> p(new int(100));

	return p;//这里不需要显式std::move，因为根据规定，编译器会自动添加move操作
}

void recv_uptr(std::unique_ptr<int> p)//被传入的对象，要使用std::move
{
	if (p)
	{
		std::cout << "In recv func, now p is:" << *p << std::endl;
	}
}


void func_unique_ptr_inside()
{
	std::unique_ptr<int> p(new int); //必须显式初始化
	*p = 10;

	std::cout << "Now p is:" << *p << std::endl;


	int *pRaw = p.release();//可以释放资源,shared_ptr不可以
	delete pRaw;//自行管理

	p.reset(new int(9));

	//由于独占式拥有资源，只能通过move转移所有权，不能进行拷贝初始化或者赋值
	std::unique_ptr<int> p2 = std::move(p);
	std::cout << "Now p2 is:" << *p2 << std::endl;


	p.reset(new int(11));
	std::cout << "Now p is:" << *p << std::endl;

	p.reset();
	p = gen_uptr();//从函数传出
	std::cout << std::endl << "After get uptr from genfunc:" << std::endl;
	std::cout << "Now p is:" << *p << std::endl;
	*p = 101;
	recv_uptr(std::move(p));//传入函数. 经move后，p自动被赋值为nullptr.
	std::cout << std::boolalpha << (p == nullptr) << std::endl;


}


int daily0306main()
{

	func_unique_ptr_inside();

	std::string strInput;
	std::getline(std::cin,strInput);

	return 0;
}