//daily0712
/************************************************************************/
/* 
1.操纵器(manipulator)
操纵器功能有二:
>1.额外修改stream，达到特殊功能.
如endl:输入向缓冲区插入换行符并刷新缓冲区;
ws:读取时忽略空白字符(white space)
>2.用于格式化的快捷操作（见下面的格式化部分）

2.格式化
所谓格式化，即影响输入输出的表现：数值精度、填充字符、进制显示等.
分为三部分：
>1.格式化操作的成员函数：
	setf(flags,[grp])
	unsetf(flags)
	flags()
	flags(flags)
	copyfmt(stream)

	width()
	fill()

	precision([val])

>2.格式的操作对象：flags以及mask常量
如：
	ios::showpos,ios::uppercase

以组呈现的flags:
	mask	   flags
 basefield	  oct/dec/hex
adjustfield   left/right/internal
floatfield	  fixed/scientific

>3.辅助格式操作的操纵器(即可以在同一个输入输出语句中搭配使用，不用显式调用修改格式的成员函数)
如：
setw()
setfill()
left
right
internal
showpos
skipws
等
*/
/************************************************************************/


#include "common/common.h"
#include <iomanip>
#include "common/serialization.h"



struct data0712
{
	int i;
	double d;
	std::string str;
	friend ibinstream& operator>>(ibinstream &ibs, data0712 &data);
	friend obinstream& operator<<(obinstream &obs,const data0712& data);

};

//反序列化
//注意数据类型在序列化与反序列化时，顺序要对齐.
ibinstream& operator>>(ibinstream &ibs, data0712 &data)
{
	ibs >> data.i;
	ibs >> data.d;
	ibs >> data.str;

	return ibs;
}

//序列化
obinstream& operator<<(obinstream &obs, const data0712& data)
{
	obs << data.i;
	obs << data.d;
	obs << data.str;

	return obs;
}


void test0712()
{
	data0712 data;
	data.i = 100;
	data.d = 99.999;
	data.str = "data0712";

	obinstream obs;
	obs << data;



	std::string str = obs.str();
	ibinstream ibs(str);
	
	data0712 d2;
	d2.i = 0;
	d2.d = 0;
	d2.str = "";

	ibs >> d2;

	std::cout << "now d2 is:" << d2.i << " " << d2.d << " "<<d2.str << std::endl;
}

void func_algor_0712()
{

	//1.操纵器
	//不用多说，endl就是最常用的操纵器.
	//有时可能需要自定义操纵器，格式如下：
	//ostream& my_manipulator (ostream &strm){...}

	//2.格式化
	//>1.综述：通过成员函数修改格式
	
	int x = 100;
	std::cout << "x is:" << x << std::endl;
	std::ios::fmtflags oldflgs = std::cout.flags();//保存旧格式.

	std::cout.setf(std::ios::showpos|std::ios::showbase|std::ios::uppercase);
	std::cout.setf(std::ios::internal,std::ios::adjustfield);
	std::cout << std::setw(20)<<std::hex << "now x is:" << x << std::endl;//setw只对一行起作用. hex对后续一直起作用.
	std::cout << "x is:" << x << std::endl;
	std::cout.flags(oldflgs);//复原旧格式
	std::cout << "now x is:" << x << std::endl;

	//>2.bool格式操纵器
	bool b = true;
	std::cout << "\nb is:" << std::boolalpha << b << std::endl;
	std::cout<<"b is:"<< std::boolalpha << b << std::endl;//对后续都起作用.
	auto restore_flgs = [&oldflgs](std::ostream *os)
	{
		os->flags(oldflgs);
	};

	

	//>3.显示宽度，字符填充，位置 等的格式设置
	//这些设置只对一行起作用.
	//本节同时使用成员函数与操纵器来设置格式的显示，后续只使用操纵器.
	//要求：设置20个字符宽度，字符填充为_，位置为右对齐
	{
		//1.使用成员函数完成：
		std::cout << "\n使用成员函数完成:\n";
		std::cout << "-42\n";
		std::cout << "Q" << std::endl;
		
		//析构时自动恢复旧格式
		std::unique_ptr<std::ostream, decltype(restore_flgs)> cout_restore(&std::cout, restore_flgs);
		std::cout.width(20);
		std::cout.fill('_');
		std::cout.setf(std::ios::right, std::ios::adjustfield);
	
		std::cout << "-42\n";
		std::cout << "Q" << std::endl;
		std::cout << "width is:" << std::cout.width() << std::endl;
	}
	{
		//2.使用操纵器完成：
		std::cout << "\n使用操纵器完成:\n";
		std::cout << "-42\n";
		std::cout << "Q" << std::endl;

		//析构时自动恢复旧格式
		std::unique_ptr<std::ostream, decltype(restore_flgs)> cout_restore(&std::cout, restore_flgs);

		std::cout << std::setw(20) << std::setfill('_') << std::right << "-42\nQ"<<std::endl;
		std::cout << "width is:" << std::cout.width() << std::endl;
		
	}
	
	//4.设置数值的正号与大写格式
	{
		std::unique_ptr<std::ostream, decltype(restore_flgs)> cout_restore(&std::cout, restore_flgs);
		int x = 104;
		std::cout << "\nnow x is:" << x << std::endl;
		
		std::cout << std::showpos << x << std::endl;//持续对后续有效
		std::cout << x << std::endl;

		std::cout << std::hex << std::showbase << x << std::endl;//默认0x小写
		std::cout << std::uppercase<< x << std::endl;//0X大写. 上面的设置持续有效.

		
	}

	//5.设置数值基数及进制的显示
	{
		std::unique_ptr<std::ostream, decltype(restore_flgs)> cout_restore(&std::cout, restore_flgs);
		int x = 105;
		std::cout << "\nnow x is:" << x << std::endl;

		//设置基数
		std::cout << std::oct << x << std::endl;
		std::cout << std::hex << x << std::endl;

		//设置进制
		std::cout << std::oct << std::showbase << x << std::endl;
		std::cout << std::hex << x << std::endl;//上一行设置了showbase,本行不必再设置.

	}

	//6.浮点数表示格式的设置
	{
		std::unique_ptr<std::ostream, decltype(restore_flgs)> cout_restore(&std::cout, restore_flgs);
		float x = 106.60;
		std::cout << "\nnow x is:" << x << std::endl;

		std::cout << std::showpoint << x << std::endl;//持续有效
		std::cout <<  x+1 << std::endl;

		std::cout << std::setprecision(5) << x << std::endl;//设置5位精度
		std::cout << x + 1 << std::endl;//持续有效

		double y = 0.01234567;
		std::cout << "\nnow y is:" << y << std::endl;//上面设置的5位精度在这里开始生效.从首个非0位开始计，共显示5位，多余的进行四舍五入截断.
		std::cout << std::scientific << y << std::endl;//科学计数法
		std::cout << y + 1 << std::endl;//持续有效.
		std::cout << std::fixed << y + 1 << std::endl;//小数计数法.
	}

	//7.其他格式设置
	{
		//操纵器：
		//skipws:使用>>时，跳过空白
		//noskipws:功能与上述相反
		//unitbuf:每次写后，刷清output缓冲区
		//nounitbuf:功能与上述相反
	}

	//8.国际化
	{
		//成员函数：
		//getloc():返回当前的locale对象
		//imbue(loc):设置locale对象
		//>>某些特殊字符转换函数：
		//widen(c):把char类型字符c转换为stream字符集内的字符
		//narrow(c,def):把stream字符集内的字符c转换为一个char字符（如果无对应字符，则返回def）
	}


}


int maindaily0712()
{
	//test0712();
	func_algor_0712();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}

