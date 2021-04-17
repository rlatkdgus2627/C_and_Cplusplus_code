//2020112036 김상현
//2021/4/9
//연결리스트 기반 큐 구현
//queueLnk.cpp
#include "queueLnk.h"
#include <iostream>

using namespace std;

template < class DT >
QueueNode<DT>::QueueNode(const DT& nodeData, QueueNode* nextPtr) : dataItem(nodeData), next(nextPtr){}

template < class DT >
Queue<DT>::Queue(int ignored) : front(nullptr), rear(nullptr){}

template < class DT >
Queue<DT>::~Queue() {
	QueueNode<DT>* temp;
	while (front != nullptr) {
		temp = front;
		front = front->next;
		delete temp;
	}
}

template < class DT >
void Queue<DT>::enqueue(const DT& newData) {

	if (isFull()) {
		cout << "Queue is already full" << endl;
		return;
	}
	else if (isEmpty()) {
		front = rear = new QueueNode<DT>(newData, nullptr);
		return;
	}
	QueueNode<DT>* newNode = new QueueNode<DT>(newData, nullptr);
	rear->next = newNode;
	rear = newNode;
	return;
}

template < class DT >
DT Queue<DT>::dequeue() {
	if (isEmpty()) {
		cout << "Queue is already empty" << endl;
		return NULL;
	}
	QueueNode<DT>* temp = front;
	DT ret = temp->dataItem;
	front = front->next;
	if (front == nullptr)	rear = nullptr;
	delete temp;
	return ret;
}

template < class DT >
bool Queue<DT>::isEmpty() const{
	return front == nullptr && rear == nullptr;
}

template < class DT >
bool Queue<DT>::isFull() const{
	try {
		QueueNode<DT>* temp = new QueueNode<DT>(NULL, nullptr);
		delete temp;
		return false;
	}
	catch (bad_alloc exception) {
		return true;
	}
}

template < class DT >
void Queue<DT>::clear(){
	if (isEmpty()) {
		cout << "Queue is already empty" << endl;
		return;
	}
	QueueNode<DT>* temp;
	while (front != nullptr) {
		temp = front;
		front = front->next;
		delete temp;
	}
	front = rear = nullptr;
	return;
}

template < class DT >
void Queue<DT>::showStructure() const{
	if (isEmpty()) {
		cout << "Empty queue" << endl;
		return;
	}
	QueueNode<DT>* temp = front;
	while (temp != nullptr) {
		if (temp == front || temp == rear) {
			cout << "[" << temp->dataItem << "] ";
		}
		else {
			cout << temp->dataItem << " ";
		}
		temp = temp->next;
	}
	cout << endl;
	return;
}

template < class DT >
void Queue<DT>::putFront(const DT& newDataItem) {
	if (isFull()) {
		cout << "Queue is already full" << endl;
		return;
	}
	if (isEmpty()) {
		front = rear = new QueueNode<DT>(newDataItem, nullptr);
		return;
	}
	QueueNode<DT>* temp = new QueueNode<DT>(newDataItem, front);
	front = temp;
	return;
}

template < class DT >
DT Queue<DT>::getRear() {
	if (isEmpty()) {
		cout << "Queue is already empty" << endl;
		return NULL;
	}
	DT ret = rear->dataItem;
	if (front == rear) {
		delete rear;
		front = rear = nullptr;
	}
	else {
		QueueNode<DT>* temp = front;
		while (temp->next != rear) {
			temp = temp->next;
		}
		delete rear;
		temp->next = nullptr;
		rear = temp;
	}
	return ret;
}

template < class DT >
int Queue<DT>::getLength() const{
	if (isEmpty())	return 0;
	int ret = 0;
	QueueNode<DT>* temp = front;
	while (temp != nullptr) {
		ret++;
		temp = temp->next;
	}
	return ret;
}