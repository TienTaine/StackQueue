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
	//cout << "Stack was created!!!" << endl;
	this->_top = NULL;
}

template <class T>
Stack<T>::~Stack()
{
	while (this->_top != NULL)
	{
		Node<T>* temp = this->_top;
		this->_top = this->_top->_pNext;
		delete temp;
	}
	//cout << "Stack was deleted!!!" << endl;
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
	if (other._top == NULL)
	{
		this->_top = NULL;
		return;
	}

	// copy từng phần tử từ other sang 
	Node<T>* current = other._top;

	while (current != nullptr)
	{
		push(current->_data);
		current = current->_pNext;
	}

	cout << "Copied !!!" << endl;
}

template <class T>
bool Stack<T>::isEmpty() const
{
	return this->_top == NULL;
}


template <class T>
void Stack<T>::push(const T data)
{
	Node<T>* newNode = new Node<T>;
	newNode->_data = data;

	// Avoid NULL case
	if (this->_top == NULL)
		newNode->_pNext = NULL; // First element added
	else
		newNode->_pNext = this->_top->_pNext; // Link newNode.pNext to seconde Node
	this->_top = newNode;
	//cout << "Push succesfully!!!" << endl;
}

template <class T>
T Stack<T>::pop()
{
	if (this->_top == NULL) {
		cout << "Cannot pop. Stack is empty!!!" << endl;
		return NULL;
	}
	Node<T>* temp = this->_top;
	this->_top = this->_top->_pNext;
	return temp->_data;
}

template <class T>
T Stack<T>::topValue() const
{
	if (this->_top == NULL) {
		cout << "Cannot get top value. Stack is empty!!!" << endl;
		return -10;
	}
	else
	{
		return this->_top->_data;
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
		while (this->_top != NULL)
		{
			Node<T>* temp = this->_top;
			this->_top = this->_top->_pNext;
			delete temp;
		}

		// copy các node từ other sang
		if (other._top == NULL)
		{
			this->_top = NULL;
		}
		else 
		{
			Node<T>* current =other._top;
			while (current != nullptr)
			{
				push(current->_data);
				current = current->_pNext;
			}
		}

		cout << "Copied by operator !!!" << endl;
	}

	return *this;
}

#endif