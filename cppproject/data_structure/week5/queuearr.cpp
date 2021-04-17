//2020112036 김상현
//2021/04/09
//배열 기반 큐(원형 큐)
//queuearr.cpp
#include <iostream>
#include "queuearr.h"

using namespace std;

template <class DT>
Queue<DT>::Queue(int maxNumber):maxSize(maxNumber),front(0),rear(0) {
	element = new DT[maxNumber];
	for (int i = 0; i < maxNumber; i++) {
		element[i] = 0;
	}
}

template <class DT>
Queue<DT>::~Queue(){
	delete[] element;
}

template <class DT>
void Queue<DT>::enqueue(const DT& newData) {
	if (isFull()) {
		cout << "Queue is already full" << endl;
		return;
	}
	element[rear] = newData;
	rear = (rear + 1) % maxSize;
	return;
}

template <class DT>
DT Queue<DT>::dequeue() {
	if (isEmpty()) {
		cout << "Queue is already empty" << endl;
		return NULL;
	}
	DT ret = element[front];
	element[front] = 0;
	front = (front + 1) % maxSize;
	return ret;
}

template <class DT>
void Queue<DT>::clear() {
	front = rear = 0;
	element[front] = 0;
}

template <class DT>
bool Queue<DT>::isEmpty() const {
	return front == rear && element[front] == 0;
}

template <class DT>
bool Queue<DT>::isFull() const {
	return front == rear && element[front] != 0;
}

template <class DT>
void Queue<DT>::showStructure() const {
	if (isEmpty()) {
		cout << "Empty Queue" << endl;
		return;
	}
	cout << "QueueSize:" << maxSize << " front:" << front << " rear:" << rear << endl;
	for (int i = 0; i < maxSize; i++) {
		cout << "[" << i << "]\t";
	}
	cout << endl;
	for (int i = 0; i < maxSize; i++) {
		if (front < rear) {
			if (front <= i && i < rear)	cout << element[i] << "\t";
			else cout << "\t";
		}
		else if(rear < front){
			if (i < rear || i >= front)	cout << element[i] << "\t";
			else cout << "\t";
		}
		else cout << element[i] << "\t";
	}
}


template <class DT>
void Queue<DT>::putFront(const DT& newDataItem) {
	if (isFull()) {
		cout << "Queue is already full" << endl;
		return;
	}
	else if (isEmpty()) {
		element[rear] = newDataItem;
		rear = (rear + 1) % maxSize;
		return;
	}
	front = (front - 1 >= 0 ? front - 1 : maxSize-1);
	element[front] = newDataItem;
	return;
}

template <class DT>
DT Queue<DT>::getRear() {
	if (isEmpty()) {
		cout << "Queue is already empty" << endl;
		return NULL;
	}
	rear = (rear - 1 >= 0 ? rear - 1 : maxSize-1);
	DT ret = element[rear];
	element[rear] = 0;
	return ret;
}

template <class DT>
int Queue<DT>::getLength() const{
	if (isEmpty()) {
		return 0;
	}
	else {
		if (front < rear)	return rear - front;
		else	return rear + maxSize - front;
	}
}