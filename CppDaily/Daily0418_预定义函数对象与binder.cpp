//daily0418
/************************************************************************/
/* 

1.����һЩԤ����ĺ�������
2.�㷨��binder+������������

*/
/************************************************************************/

#include"./common/common.h"


void func_functor_and_binder_inside()
{
	//1.ʹ�ø�����������˷���������������ԭ����
	std::deque<int> de = {1,3,5,7,9};
	std::cout << "before negate it :\n";
	std::copy(de.begin(), de.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "after negate it :\n";
	std::transform(de.begin(), de.end(), de.begin(), std::negate<int>());
	std::copy(de.begin(), de.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "after multi it:\n";
	std::transform(de.begin(), de.end(), de.begin(), de.begin(),std::multiplies<int>());
	std::copy(de.begin(), de.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//2.ʹ��Ԥ���庯���������binder
	//Ĭ�����򣬸�Ϊ����
	std::set<int, std::greater<int>> st = {1,2,3,4,5,6,7,8,9};
	std::vector<int> vec;
	std::cout << "st inits as :\n";
	std::copy(st.begin(), st.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//��st��ÿ��Ԫ�س���10д��vec
	std::transform(st.begin(), st.end(), std::back_inserter(vec), std::bind(std::multiplies<int>(), std::placeholders::_1, 10));
	std::cout << "now vec is:\n";
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//��vec�е���70��Ԫ�ػ�Ϊ42
	std::cout << "after replace 70 with 42:\n";
	std::replace_if(vec.begin(), vec.end(), std::bind(std::equal_to<int>(),std::placeholders::_1,70),42);
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	//�Ƴ�vec��[50,80]֮���Ԫ��
	std::cout << "after erase some elems :\n";
	//ע��������ĸ����߼���д��
	vec.erase(std::remove_if(vec.begin(), vec.end(), 
		std::bind(std::logical_and<bool>(), 
			std::bind(std::greater_equal<int>(), std::placeholders::_1, 50), 
			std::bind(std::less_equal<int>(), std::placeholders::_1, 80))),
		vec.end());

	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}


int maindaily0418()
{

	func_functor_and_binder_inside();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}