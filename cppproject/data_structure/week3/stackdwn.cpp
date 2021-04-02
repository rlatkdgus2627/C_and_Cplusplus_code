//--------------------------------------------------------------------
//김상현
//  Laboratory 5                                        stackdwn.cpp
//
//  SOLUTION: Array implementation of the Stack ADT (reverse version)
//2021-03-28
//--------------------------------------------------------------------
#include "stackarr.h"

//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int maxNumber) :
	maxSize(maxNumber),
	top(maxNumber)
{
	element = new DT[maxNumber];
}

//--------------------------------------------------------------------

template <class DT>
Stack<DT>:: ~Stack()
{
	delete[] element;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::push(const DT& newElement)
{
	if (isFull()) {
		cout << "Stack is Full(Fail to push)" << "\n";
		return;
	}
	element[--top] = newElement;
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{
	if (isEmpty()) {
		cout << "Stack is Empty(Fail to pop)" << "\n";
		return NULL;
	}
	return element[top++];
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
	top = maxSize;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
	return top == maxSize;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
	return top == 0;
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::showStructure() const
{
	if (isEmpty()) {
		cout << "Empty Stack" << "\n";
		return;
	}
	cout << "top:" << top << "\n";
	for (int i = 0; i < maxSize; i++) {
		cout << "st[" << i << "] " << "\t";
	}
	cout << "\n";
	for (int i = 0; i < maxSize; i++) {
		if (i < top)
			cout << "NULL" << "\t";
		else
			cout << element[i] << "\t";
	}
	cout << "\n";
}