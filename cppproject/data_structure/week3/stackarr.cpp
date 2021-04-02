//--------------------------------------------------------------------
//김상현
//  Laboratory 5                                        stackarr.cpp
//
//  SOLUTION: Array implementation of the Stack ADT
//2021-03-28
//--------------------------------------------------------------------
#include "stackarr.h"

//--------------------------------------------------------------------

template <class DT>
Stack<DT>::Stack(int maxNumber) : 
	maxSize(maxNumber),
	top(-1)
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
	element[++top] = newElement;
}

//--------------------------------------------------------------------

template <class DT>
DT Stack<DT>::pop()
{
	if (isEmpty()) {
		cout << "Stack is Empty(Fail to pop)" << "\n";
		return NULL;
	}
	return element[top--];
}

//--------------------------------------------------------------------

template <class DT>
void Stack<DT>::clear()
{
	top = -1;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isEmpty() const
{
	return top == -1;
}

//--------------------------------------------------------------------

template <class DT>
bool Stack<DT>::isFull() const
{
	return top == maxSize-1;
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
		if(i <= top)	
			cout << element[i] << "\t";
		else
			cout << "NULL" << "\t";
	}
	cout << "\n";
}