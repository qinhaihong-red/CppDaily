//daily0510
/************************************************************************/
/* 

��������������Ҫ�У�
-reverse ���������
-insert  ���������
 -back  inserter ������������������push_back(val). �����ڣ�vector,deque,list��string
 -front inserter ǰ�������������push_front(val).    �����ڣ�deque��list
 -general inserter ͨ�õ�����,����insert(pos,value)  �����ڹ���������.

-stream ��ʽ������.���������������.


*/
/************************************************************************/



#include"./common/common.h"


//back inserter��front inserter���ٶ�˵,
//�ɲο�daily0413��ʾ��

//���¿���ͨ�ò���ĵ�����
void func_general_inserter_inside()
{
	std::vector<int> vec;

	std::set<int> st;

	//Ϊst�������������
	//-�������ķ�ʽ��

	std::insert_iterator<std::set<int>> iter(st,st.begin());
	*iter = 1;
	iter++;
	*iter = 2;
	iter++;
	*iter = 3;

	std::cout << "now set is:\n";
	common::print_elems(st);
	std::cout << std::endl;

	//Ϊst�������������
	//-�����ķ�ʽ��

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
	std::ostream_iterator<int> intWriter(std::cout, "\n");//"\n"��Ϊ�ָ���

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
	std::istream_iterator<int> intReaderEOF;//�ն���Ĭ�ϳ�ʼ��Ϊ������

	while (intReader!=intReaderEOF)
	{
		std::cout << "once: " << *intReader << std::endl;
		std::cout << "once again: " << *intReader << std::endl;
		++intReader;
	}

	//3.istream��ostream iteratorͬʱʹ��ʾ��
	std::cout << "\n\n3.istream & osteram iterator example:\n";

	std::istream_iterator<std::string> cinPos(std::cin);
	std::ostream_iterator<std::string> coutPos(std::cout," ");

	while (cinPos!=std::istream_iterator<std::string>()/*EOF*/)
	{
		std::advance(cinPos, 2);//��ȥ��������������strings

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