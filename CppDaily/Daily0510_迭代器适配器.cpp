//daily0510
/************************************************************************/
/* 

迭代器适配器主要有：
-reverse 反向迭代器
-insert  插入迭代器
 -back  inserter 后向插入迭代器，调用push_back(val). 适用于：vector,deque,list和string
 -front inserter 前向迭代器，调用push_front(val).    适用于：deque和list
 -general inserter 通用迭代器,调用insert(pos,value)  适用于关联容器等.

-stream 流式迭代器.适用于输入输出流.


*/
/************************************************************************/



#include"./common/common.h"


//back inserter和front inserter不再多说,
//可参考daily0413的示例

//以下看看通用插入的迭代器
void func_general_inserter_inside()
{
	std::vector<int> vec;

	std::set<int> st;

	//为st创建插入迭代器
	//-不便利的方式：

	std::insert_iterator<std::set<int>> iter(st,st.begin());
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;

	std::cout << "now set is:\n";
	common::print_elems(st);
	std::cout << std::endl;

	//为st创建插入迭代器
	//-便利的方式：

	std::inserter(st, st.end()) = 44;
	std::inserter(st, st.end()) = 55;
	
	std::cout << "\nnow set is:\n";
	common::print_elems(st);
	std::cout << std::endl;

	std::copy(std::begin(st), std::end(st), std::inserter(vec, std::begin(vec)));


	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;

	std::copy(std::begin(st), std::end(st), std::inserter(vec, ++std::begin(vec)));
	
	std::cout << "\nnow vec is:\n";
	common::print_elems(vec);
	std::cout << std::endl;
}


void func_stream_iterator_inside()
{
	//1.ostream iterator
	std::cout << "1.ostream iterator exapmle:\n";
	std::ostream_iterator<int> intWriter(std::cout, "\n");//"\n"作为分隔符

	*intWriter = 42;
	intWriter++;
	*intWriter = 77;
	intWriter++;
	*intWriter = -5;

	std::vector<int> vec = {1,3,5,7,9};
	std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout));

	std::copy(std::begin(vec), std::end(vec), std::ostream_iterator<int>(std::cout," < "));

	//2.istream iterator
	std::cout << "\n\n2.istream iterator example:\n";

	std::istream_iterator<int> intReader(std::cin);
	std::istream_iterator<int> intReaderEOF;//空对象默认初始化为结束符

	while (intReader!=intReaderEOF)
	{
		std::cout << "once: " << *intReader << std::endl;
		std::cout << "once again: " << *intReader << std::endl;
		++intReader;
	}

	//3.istream和ostream iterator同时使用示例
	std::cout << "\n\n3.istream & osteram iterator example:\n";

	std::istream_iterator<std::string> cinPos(std::cin);
	std::ostream_iterator<std::string> coutPos(std::cout," ");

	while (cinPos!=std::istream_iterator<std::string>()/*EOF*/)
	{
		std::advance(cinPos, 2);//略去紧跟的两个输入strings

		if (cinPos != std::istream_iterator<std::string>())
		{
			*coutPos++ = *cinPos++;
		}
	}

	std::cout << std::endl;

}


int maindaily0510()
{
	func_general_inserter_inside();

	std::cout << std::endl;

	func_stream_iterator_inside();

	std::string strInput;
	//std::getline(std::cin, strInput);


	return 0;
}