//daily0220
/************************************************************************/
/* 
1.明晰异常类的层次结构（system_error,ios_base::failure,future_error）
2.异常类的处理方式：what()和code()
3.常用错误码的枚举领域(std::errc,std::io_errc,std::future_errc)
*/
//写一个处理不同异常的模板函数
/************************************************************************/

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <future>
#include<system_error>



template<typename T>
void func_process_exception_base(const T &e)
{
	auto c = e.code();
	std::cerr << "category:" << c.category().name() << std::endl;
	std::cerr << "value:" << c.value() << std::endl;
	std::cerr << "message:" << c.message() << std::endl;
	std::cerr << "default category:" << c.default_error_condition().category().name() << std::endl;
	std::cerr << "default value:" << c.default_error_condition().value() << std::endl;
	std::cerr << "default mesage:" << c.default_error_condition().message() << std::endl;

}


enum CExceptionAssit : int {logic_error,sys_error,io_error,future_error};

void func_throw_logic_error()
{
	throw std::out_of_range("here out of range.(test)");
}

void func_throw_system_error()
{
	throw std::system_error(std::make_error_code(std::errc::address_not_available),"system error.(test)");
}

void func_throw_io_error()
{
	//const char str[16] = "io error test12";
	//throw std::ios_base::failure(std::make_error_code(std::io_errc::stream), str);


	throw std::ios_base::failure("io error test");
}

void func_throw_future_error()
{
	throw std::future_error(std::make_error_code(std::future_errc::broken_promise));
}

void func_pocess_exception(CExceptionAssit ea)
{
	try
	{
		if (ea == CExceptionAssit::logic_error)
		{
			func_throw_logic_error();
		}
		else if (ea == CExceptionAssit::io_error)
		{
			func_throw_io_error();
		}
		else if (ea == CExceptionAssit::sys_error)
		{
			func_throw_system_error();
		}
		else if (ea == CExceptionAssit::future_error)
		{
			func_throw_future_error();
		}

	}
	catch (const std::ios_base::failure &e)
	{
		std::cerr << "I/O Exception:" << e.what() << std::endl;
		func_process_exception_base(e);
	}
	catch (const std::system_error &e)
	{
		std::cerr << "System Exception:" << e.what() << std::endl;

		if (e.code() == std::errc::address_not_available)
		{
			std::cerr << "The errc is:" << "address_not_available" << std::endl;
		}

		func_process_exception_base(e);
	}
	catch (const std::future_error &e)
	{
		std::cerr << "Future Exception:" << e.what() << std::endl;
		func_process_exception_base(e);
	}
	catch (const std::bad_alloc &e)
	{
		std::cerr << "BadAlloc Exception:" << e.what() << std::endl;
		//func_process_exception_base(e);//bad_alloc无code成员
	}
	catch (const std::exception &e)
	{
		std::cerr <<e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr <<"Exception Unknown." << std::endl;
	}
}

int maindaily0220()
{
	std::cout << "future_error:" << std::endl;
	func_pocess_exception(CExceptionAssit::future_error);
	std::cout << std::endl << "logic_error:" << std::endl;
	func_pocess_exception(CExceptionAssit::logic_error);
	std::cout << std::endl << "sys_error" << std::endl;
	func_pocess_exception(CExceptionAssit::sys_error);
	std::cout << std::endl << "io_error" << std::endl;
	func_pocess_exception(CExceptionAssit::io_error);


	std::string strInput;
	std::getline(std::cin, strInput);

	return 0;
}