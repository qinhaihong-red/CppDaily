//daily0524
/************************************************************************/
/* 

更易算法会改变区间内元素内容（注意是更改，不是添加和删除. 除非使用back_inserter.）:
1.在迭代过程中直接改变元素内容.
2.将元素从源区间复制到目标区间时改动.

注意，目标区间不能是 关联容器 和 无序容器. 因为此类型容器内元素被视为常量.

*/
/************************************************************************/

#include "common/common.h"



void func_algor_0524()
{
	//1.copy,copy_if,copy_n,copy_backward
	//--4个算法都返回目标区间内最后一个被复制元素的下一个位置.
	//--对于copy，destBeg不可位于[sourceBeg,sourceEnd)之间;如要把一个子区间复制到前端，应使用copy，且destBeg位于sourceBeg之前.
	//--对于copy_backward,destBeg不可位于(sourceBeg,sourceEnd]之间;如要把一个子区间复制到后端，应使用copy_backward，且destBeg位于sourceEnd之后.

	std::vector<std::string> vec = {"Hello","This","Is" ,"An","Example"};
	std::list<std::string> li;

	//把vec内容复制到li
	std::copy(std::begin(vec), std::end(vec), std::back_inserter(li));
	
	//展示li
	std::cout << "1.copy:\nnow li is:\n";
	std::copy(std::begin(li), std::end(li), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	//再次从vec中复制元素到li中
	//注意此次就是覆盖了
	std::copy(std::rbegin(vec), std::rend(vec), std::begin(li));
	std::cout << "\nnow li is:\n";
	std::copy(std::begin(li), std::end(li), std::ostream_iterator<std::string>(std::cout, " "));


	//下面展示 复制到子区间 的示例
	//注意 copy 和 copy_backward 的区别

	std::vector<char> source(10,'.');
	for (char c='a';c<='f';++c)
	{
		source.push_back(c);
	}

	source.insert(std::end(source), 10, '.');
	std::cout << "\nnow source is:\n";
	common::print_elems(source);
	std::cout << std::endl;

	//复制子区间内容到该子区间之前
	std::vector<char> s1(source);
	std::copy(std::begin(s1) + 10, std::begin(s1) + 16, std::begin(s1) + 7);
	std::cout << "\nnow s1 is:\n";
	common::print_elems(s1);
	std::cout << std::endl;


	//复制子区间内容到该子区间之后
	std::vector<char> s2(source);
	std::copy_backward(std::begin(s2) + 10, std::begin(s2) + 16, std::begin(s2) + 19);

	std::cout << "\nnow s2 is:\n";
	common::print_elems(s2);
	std::cout << std::endl;

	//2.move和move_backward
	//也就是copy的移动语义版

	//li.clear();//clear之后size变为0，因此还是不要clear，直接覆盖.
	std::copy(std::begin(vec), std::end(vec), std::begin(li));
	std::cout << "\n2.move:\nnow move li to cout:\n";
	std::move(std::begin(li), std::end(li), std::ostream_iterator<std::string>(std::cout, " "));

	//再次从vec中反向覆盖li
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