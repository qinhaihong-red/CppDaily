//daily0122

#include<iostream>
#include<stdio.h>
#include <map>
#include <vector>
#include <initializer_list>

//函数模板可以设置默认参数类型
template<typename R = int, typename T >
R fun_add(T t1, T t2)
{
	return t1 + t2;
}

void test_fun_add()
{
	std::cout << fun_add(1, 2) << std::endl;
	std::cout << fun_add<double>(2.4, 5.7) << std::endl;
}

//auto+decltype判断返回值类型
template<typename T1,typename T2>
auto fun_add_ex(T1 t1, T2 t2) ->decltype(t1 + t2)
{
	return t1 + t2;
}
void test_fun_add_ex()
{
	std::cout << fun_add_ex(1 , 2) << std::endl;
	std::cout << fun_add_ex(1 ,1.2) << std::endl;
}


//接收任意长度参数初始化的示例类

class CSampleInitlist
{
private:
	std::vector<int> vec;
public:
	CSampleInitlist(std::initializer_list<int> &&il)
	{
		for (auto iter=il.begin();iter!=il.end();++iter)
		{
			vec.push_back(*iter);
		}
	}

	uint32_t GetSize()
	{
		return vec.size();
	}
};

//初始化列表
void test_func_init_list()
{
	std::map<int, std::string> m = { {1,"hi"},{2,"today"} };
	std::vector<int > v = {1,2,3,4,5};
	CSampleInitlist sil = {1,2,3,4,5,6};
	std::cout << m.size() << " " << v.size() << " " << sil.GetSize() << std::endl;
}

int main_daily0122()
{
	//test_fun_add();

	//test_fun_add_ex();

	test_func_init_list();

	std::getchar();
	return 0;
}