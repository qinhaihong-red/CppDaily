//daily0615
/************************************************************************/
/* 

������������
��ν�������������ڴ������ת��������һ��������������һ����ʽ��ͨ��Ϊ������ĳЩ���ܣ�չ��.

1.stack<T,container=deque<T>>:
	LIFO�������ȳ�������.
	Ĭ����dequeʵ�֣�Ҳ����ʹ��vector�������vector��deque�Ƴ�Ԫ��ʱ���ͷſռ䲢�Ҳ������ط���ʱ����ȫ��Ԫ�أ���
	����list.
	���Ľӿڣ�
	push(�����ڲ�������push_back)
	top(�����ڲ�������back)
	pop(�����ڲ�������pop_back)

	Ҫ�Ƴ���ͬʱ���ظ�Ԫ�أ���Ҫ�ȵ���top�ٵ���pop.
	Ҳ����˵���Ƴ������أ����ز��Ƴ�. queue �� priority_queue ���д�����.

2.queue<T,container=deque<T>>:
	FIFO(�����ȳ�)����.
	Ĭ����dequeʵ��.Ҳ����ʹ��listʵ��.������vector����Ϊ�䲻֧��pop_front.
	���Ľӿڣ�
	push(�����ڲ�������push_back)
	front(�����ڲ������ĵ�front)
	back(�����ڲ�������back)
	pop(�����ڲ�������pop_front)

3.priority_queue<T,container=vector<T>,compare=less<T>>:
	���ȶ���.
	���ص���һ��Ԫ�أ�����ĳ�ֹ�����"���ȼ�"��ߵ�Ԫ��.
	Ĭ�ϵ�����������operator<�γɽ���Ҳ������һ�����ص�Ԫ��������.
	Ĭ��ʹ��vector��Ϊ�ڲ�����.���������õ���heap������㷨������ڲ���������ʹ��RA������.
	���Ľӿڣ�
	push(�����ڲ�������push_back)
	top(�����ڲ�������back)
	pop(�����ڲ�������pop_back)

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