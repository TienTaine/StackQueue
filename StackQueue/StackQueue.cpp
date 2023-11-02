//#include "queue.h" 
//
//int main() 
//{
//	cout << "----------------------------TEST 1----------------------------" << endl;
//	// Test 1 với kiểu dữ liệu của Queue là char
//	Queue<char> q;
//	q.enqueue('a');
//	q.enqueue('b');
//	q.dequeue();
//	q.dequeue();	
//	q.enqueue('d');
//	Queue<char> other(q);
//	if (!q.isEmpty())
//	{
//		cout << "Queue isn't empty" << endl;
//	}
//	else cout << "Queue is empty" << endl;
//	cout << "Front Value of q: " << q.peek() << endl;
//	other.dequeue();
//	other.enqueue('f');
//	cout << "Front Value of other: " << other.peek() << endl;
//	Queue<char> other1;
//	other1 = q;
//	cout << "Front Value of other1: " << other1.peek() << endl;
//	
//	cout << "----------------------------TEST 2----------------------------" << endl;
//	// Test 2 với kiểu dữ liệu của Queue là int
//	Queue<int> q1;
//	if (!q1.isEmpty())
//	{
//		cout << "Queue isn't empty" << endl;
//	}
//	else cout << "Queue is empty" << endl;
//	q1.enqueue(1);
//	q1.enqueue(2);
//	q1.dequeue();
//	q1.enqueue(10);
//	q1.dequeue();
//	cout << "Front Value of q1: " << q1.peek() << endl;
//	Queue<int> temp(q1);
//	temp.dequeue();
//	temp.enqueue(1);
//	cout << "Front Value of temp: " << temp.peek() << endl;
//	Queue<int> temp1;
//	temp1 = q1;
//	cout << "Front Value of temp1: " << temp1.peek() << endl;
//	return 0;
//}

#include "stack.h"

int main()
{
	Stack<int> stack;
	if (stack.isEmpty())
		cout << "This stack is empty!!!" << endl;
	stack.push(1);
	cout << "Popped data: " << stack.pop() << endl;

	stack.push(100);
	cout << "Top Value of stack: " << stack.topValue() << endl;

	Stack<int> other(stack);
	if (other.isEmpty())
	{
		cout << "Stack is empty" << endl;
	}
	else cout << "Stack isn't empty" << endl;

	other.pop();
	cout << "Top Value of other: " << other.topValue() << endl; // should be -1

	Stack<int> temp;
	temp = stack;
	cout << "Top Value of temp: " << temp.topValue() << endl;
	cout << "Popped data: " << temp.pop() << endl;
	cout << "Top Value of temp 2: " << temp.topValue() << endl;
}