//daily0524
/************************************************************************/
/* 

�����㷨��ı�������Ԫ�����ݣ�ע���Ǹ��ģ�������Ӻ�ɾ��. ����ʹ��back_inserter.��:
1.�ڵ���������ֱ�Ӹı�Ԫ������.
2.��Ԫ�ش�Դ���临�Ƶ�Ŀ������ʱ�Ķ�.

ע�⣬Ŀ�����䲻���� �������� �� ��������. ��Ϊ������������Ԫ�ر���Ϊ����.

*/
/************************************************************************/

#include "common/common.h"



void func_algor_0524()
{
	//1.copy,copy_if,copy_n,copy_backward
	//--4���㷨������Ŀ�����������һ��������Ԫ�ص���һ��λ��.
	//--����copy��destBeg����λ��[sourceBeg,sourceEnd)֮��;��Ҫ��һ�������临�Ƶ�ǰ�ˣ�Ӧʹ��copy����destBegλ��sourceBeg֮ǰ.
	//--����copy_backward,destBeg����λ��(sourceBeg,sourceEnd]֮��;��Ҫ��һ�������临�Ƶ���ˣ�Ӧʹ��copy_backward����destBegλ��sourceEnd֮��.

	std::vector<std::string> vec = {"Hello","This","Is" ,"An","Example"};
	std::list<std::string> li;

	//��vec���ݸ��Ƶ�li
	std::copy(std::begin(vec), std::end(vec), std::back_inserter(li));
	
	//չʾli
	std::cout << "1.copy:\nnow li is:\n";
	std::copy(std::begin(li), std::end(li), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//�ٴδ�vec�и���Ԫ�ص�li��
	//ע��˴ξ��Ǹ�����
	std::copy(std::rbegin(vec), std::rend(vec), std::begin(li));
	std::cout << "\nnow li is:\n";
	std::copy(std::begin(li), std::end(li), std::ostream_iterator<std::string>(std::cout, " "));


	//����չʾ ���Ƶ������� ��ʾ��
	//ע�� copy �� copy_backward ������

	std::vector<char> source(10,'.');
	for (char c='a';c<='f';++c)
	{
		source.push_back(c);
	}

	source.insert(std::end(source), 10, '.');
	std::cout << "\nnow source is:\n";
	common::print_elems(source);
	std::cout << std::endl;

	//�������������ݵ���������֮ǰ
	std::vector<char> s1(source);
	std::copy(std::begin(s1) + 10, std::begin(s1) + 16, std::begin(s1) + 7);
	std::cout << "\nnow s1 is:\n";
	common::print_elems(s1);
	std::cout << std::endl;


	//�������������ݵ���������֮��
	std::vector<char> s2(source);
	std::copy_backward(std::begin(s2) + 10, std::begin(s2) + 16, std::begin(s2) + 19);

	std::cout << "\nnow s2 is:\n";
	common::print_elems(s2);
	std::cout << std::endl;

	//2.move��move_backward
	//Ҳ����copy���ƶ������

	//li.clear();//clear֮��size��Ϊ0����˻��ǲ�Ҫclear��ֱ�Ӹ���.
	std::copy(std::begin(vec), std::end(vec), std::begin(li));
	std::cout << "\n2.move:\nnow move li to cout:\n";
	std::move(std::begin(li), std::end(li), std::ostream_iterator<std::string>(std::cout, " "));

	//�ٴδ�vec�з��򸲸�li
	std::copy(std::rbegin(vec), std::rend(vec), std::begin(li));
	std::cout << "\nnow move li to cout again:\n";
	std::move(std::begin(li), std::end(li), std::ostream_iterator<std::string>(std::cout, " "));

}

int main()
{
	func_algor_0524();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}