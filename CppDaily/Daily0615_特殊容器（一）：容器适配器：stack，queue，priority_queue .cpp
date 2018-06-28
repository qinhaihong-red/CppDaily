//daily0615
/************************************************************************/
/* 

容器适配器：
所谓适配器，类似于代理或者转换器，将一种已有容器以另一种形式（通常为限制其某些功能）展现.

1.stack<T,container=deque<T>>:
	LIFO（后入先出）容器.
	默认以deque实现，也可以使用vector（相比于vector，deque移除元素时会释放空间并且不必在重分配时复制全部元素），
	或者list.
	核心接口：
	push(调用内部容器的push_back)
	top(调用内部容器的back)
	pop(调用内部容器的pop_back)

	要移除并同时返回该元素，需要先调用top再调用pop.
	也就是说，移除不返回，返回不移除. queue 和 priority_queue 都有此特性.

2.queue<T,container=deque<T>>:
	FIFO(先入先出)容器.
	默认以deque实现.也可以使用list实现.不能用vector，因为其不支持pop_front.
	核心接口：
	push(调用内部容器的push_back)
	front(调用内部容器的的front)
	back(调用内部容器的back)
	pop(调用内部容器的pop_front)

3.priority_queue<T,container=vector<T>,compare=less<T>>:
	优先队列.
	返回的下一个元素，是在某种规则下"优先级"最高的元素.
	默认的排序规则采用operator<形成降序，也就是下一个返回的元素是最大的.
	默认使用vector作为内部容器.由于排序用到了heap的相关算法，因此内部容器必须使用RA迭代器.
	核心接口：
	push(调用内部容器的push_back)
	top(调用内部容器的back)
	pop(调用内部容器的pop_back)

*/
/************************************************************************/



#include "common/common.h"
#include <stack>
#include <queue>

void func_algor_0615()
{
	//1.stack
	std::cout << "1.stack:\n";
	std::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);

	std::cout << st.top() << std::endl;
	st.pop();
	std::cout << st.top() << std::endl;
	st.pop();

	st.top() = 77;

	st.push(4);
	st.push(5);

	st.pop();

	while (!st.empty())
	{
		std::cout << st.top() << std::endl;
		st.pop();
	}

	//2.queue
	std::cout << "\n2.queue:\n";
	std::queue<std::string> q;
	q.push("These ");
	q.push("are ");
	q.push("more than ");

	std::cout << q.front();
	q.pop();
	std::cout << q.front();
	q.pop();

	q.push("four ");
	q.push("words!");

	q.pop();

	std::cout << q.front();
	q.pop();
	std::cout << q.front();
	q.pop();

	std::cout << "\nnumber of elements left:" << q.size() << std::endl;


	//3.priority_queue
	std::cout << "\n3.priority_queue:\n";
	std::priority_queue<float> pq;
	pq.push(66.6);
	pq.push(22.2);
	pq.push(44.4);

	std::cout << pq.top() << " ";
	pq.pop();
	std::cout << pq.top() << std::endl;
	pq.pop();

	pq.push(11.1);
	pq.push(55.5);
	pq.push(33.3);

	pq.pop();

	while (!pq.empty())
	{
		std::cout << pq.top() << " ";
		pq.pop();
	}


}

int main0615()
{
	func_algor_0615();

	std::string strInput;
	std::getline(std::cin, strInput);


	return 0;
}