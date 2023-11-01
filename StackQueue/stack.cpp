#ifndef stack_cpp
#define stack_cpp

#include "stack.h"
#include <iostream>
using namespace std;

template class Stack<int>;
template class Stack<float>;
template class Stack<char>;
template class Stack<double>;

template <class T>
Stack<T>::Stack()
{
	top = NULL;
}

template <class T>
Stack<T>::~Stack()
{
	while (top != NULL)
	{
		Node<T>* temp = top;
		top = top->next;
		delete temp;
	}
}

/*
Ý tưởng chính:
Khởi tạo node đầu tiên copy giá trị từ node đầu tiên của stack other
Duyệt qua các node còn lại của stack other và khởi tạo các node tương ứng cho stack hiện tại
Như vậy, mỗi khi khởi tạo một đối tượng Stack từ một đối tượng Stack khác thì toàn bộ các phần tử sẽ được sao chép sang đối tượng mới.
*/
template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
	if (other.top == NULL)
	{
		return;
	}

	// copy từng phần tử từ other sang 
	Node<T>* current = new Node<T>(other.top->data);
	while (current != nullptr)
	{
		push(current->data);
		current = current->next;
	}
}

template <class T>
bool Stack<T>::isEmpty() const
{
	return top == NULL;
}


template <class T>
void Stack<T>::push(const T& data)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = data;
	newNode->next = NULL;
	top = newNode;
}

template <class T>
void Stack<T>::pop()
{
	if (top == NULL) {
		cout << "Stack is empty!!!" << endl;
		return;
	}
	Node<T>* temp = top;
	top = top->next;
	delete temp;
}

template <class T>
T Stack<T>::topValue() const
{
	if (top == NULL) {
		cout << "Stack is empty" << endl;
		return -1;
	}
	else
	{
		return top->data;
	}
}


/*
Ý tưởng chính:

Kiểm tra xem đối tượng gán có phải chính nó hay không, nếu phải thì trả về luôn đối tượng hiện tại
Xóa các node của stack hiện tại
Copy từng node từ stack other sang stack hiện tại
Trả về đối tượng hiện tại
Như vậy là đã hỗ trợ gán giá trị từ một đối tượng Stack sang một đối tượng Stack khác.
*/
template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		// xóa các node của stack hiện tại
		while (this.top != NULL)
		{
			Node<T>* temp = this.top;
			this.top = this.top->next;
			delete temp;
		}

		// copy các node từ other sang
		if (other.top == NULL)
		{
			this.top = NULL;
		}
		else {
			Node<T>* current = new Node<T>(other.top->data);
			while (current != nullptr)
			{
				push(current->data);
				current = current->next;
			}
		}
	}

	return *this;
}

#endif