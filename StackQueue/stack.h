#ifndef stack_h
#define stack_h

//========= NODE

template <class T>
struct Node {
	T _data;
	Node<T>* _pNext;
};

//========= STACK

template <class T>
class Stack {
public:
	Node<T>* _top;

	Stack();				    // constructor
	Stack(const Stack&);		// copy constructor
	~Stack();				    // destructor

	// operations
	bool isEmpty() const;		// check empty
	void push(const T);		// thêm phần tử vào 
	T pop();	// xoá phần tử top
	T topValue() const;			// lấy ra giá trị phần tử top

	// assign operator
	Stack<T>& operator=(const Stack<T>&);  // định nghĩa toán tử = cho 2 stack
};
#include "stack.cpp"

#endif
