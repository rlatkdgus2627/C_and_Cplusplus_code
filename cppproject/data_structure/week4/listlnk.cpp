//--------------------------------------------------------------------
//	2020112036 김상현
//  Laboratory 7                                           listlnk.cpp
//
//  Class declarations for the linked list implementation of the
//  List ADT
//	작성일 : 2021-04-03
//	연결 리스트 클래스 메소드를 구현한 파일입니다.
//--------------------------------------------------------------------
#include <iostream>
#include "listlnk.h"

using namespace std;

template<class DT>
ListNode<DT>::ListNode(const DT& nodeData, ListNode* nextPtr):dataItem(nodeData), next(nextPtr){}

template<class DT>
List<DT>::List(int ignored):head(nullptr), cursor(nullptr){}

//------------------------------------------------

template<class DT>
List<DT>::~List()
{
	cursor = head;
	ListNode<DT> *temp;
	while (cursor != nullptr) {
		temp = cursor;
		cursor = cursor->next;
		delete temp;
	}
}

//------------------------------------------------


template<class DT>
void List<DT>::insert(const DT& newData)
{
	if (isFull()) {
		cout << "List is full" << "\n";
		return;
	}
	if (isEmpty()) {
		head = new ListNode<DT>(newData, nullptr);
		cursor = head;
		return;
	}
	ListNode<DT> *temp = new ListNode<DT>(newData, cursor->next);
	cursor->next = temp;
	cursor = cursor->next;
	return;
}

//------------------------------------------------


template<class DT>
void List<DT>::remove()
{
	if (isEmpty()) {
		cout << "List is already empty(fail to remove)" << "\n";
		return;
	}
	if (cursor == head) {
		ListNode<DT>* temp = head;
		head = head->next;
		delete temp;
		cursor = head;
		return;
	}

	ListNode<DT>* temp = head;
	while (temp->next != cursor) {
		temp = temp->next;
	}
	temp->next = cursor->next;
	delete cursor;
	cursor = temp->next;
	if (cursor == nullptr) {
		cursor = head;
	}
	return;
}


//------------------------------------------------


template<class DT>
void List<DT>::replace(const DT& newData)
{
	if (isEmpty()) {
		cout << "List is already empty(fail to replace)" << "\n";
		return;
	}
	cursor->dataItem = newData;
	return;
}

//------------------------------------------------


template<class DT>
void List<DT>::clear()
{
	if (isEmpty()) {
		cout << "List is already empty" << "\n";
		return;
	}
	ListNode<DT> *temp;
	cursor = head;
	while (cursor != nullptr) {
		temp = cursor;
		cursor = cursor->next;
		delete temp;
	}
	head = nullptr;
	return;
}

//------------------------------------------------


template<class DT>
bool List<DT>::isEmpty() const
{
	return head == nullptr;
}

//------------------------------------------------


template<class DT>
bool List<DT>::isFull() const
{
	ListNode<DT>* temp;
	try {
		temp = new ListNode<DT>(NULL, nullptr);
		delete temp;
		return false;
	}
	catch (bad_alloc exception) {
		return true;
	}
}

//------------------------------------------------


template<class DT>
void List<DT>::gotoBeginning()
{
	if (isEmpty()) {
		cout << "List is already empty(fail to go to first node)" << "\n";
		return;
	}
	else if (cursor == head) {
		cout << "cursor is already at first node(fail to go to first node)" << "\n";
		return;
	}
	cursor = head;
	return;
}

//------------------------------------------------


template<class DT>
void List<DT>::gotoEnd()
{
	if (isEmpty()) {
		cout << "List is already empty(fail to go to end node)" << "\n";
		return;
	}
	else if (cursor->next == nullptr) {
		cout << "cursor is already at last node(fail to go to end node)" << "\n";
		return;
	}
	while (cursor->next != nullptr) {
		cursor = cursor->next;
	}
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoNext()
{
	if (isEmpty() || cursor->next == nullptr) {
		return false;
	}
	cursor = cursor->next;
	return true;
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoPrior()
{
	if (isEmpty() || cursor == head) {
		return false;
	}
	ListNode<DT> *temp = head;
	while (temp->next != cursor) {
		temp = temp->next;
	}
	cursor = temp;
	return true;
}

//------------------------------------------------


template<class DT>
DT List<DT>::getCursor() const
{
	if (isEmpty()) {
		cout << "List is already empty(fail to return element)" << "\n";
		return NULL;
	}
	return cursor->dataItem;
}

template<class DT>
void List<DT>::showStructure() const
{
	if (isEmpty()) {
		cout << "Empty List" << "\n";
	}
	ListNode<DT>* temp = head;
	while (temp != nullptr) {
		if (temp == cursor) {
			cout << "[" << temp->dataItem << "] ";
		}
		else {
			cout << temp->dataItem << " ";
		}
		temp = temp->next;
	}
	cout << "\n";
}

//------------------------------------------------

//in-lab
template<class DT>
void List<DT>::moveToBeginning()
{
	// in-lab 2
	if (isEmpty()) {
		cout << "List is already empty(fail to move to beginning)" << "\n";
		return;
	}
	else if (cursor == head) {
		cout << "cursor is already at first node(fail to move to beginning)" << "\n";
		return;
	}
	ListNode<DT> *temp = head;
	head = new ListNode<DT>(cursor->dataItem, temp);
	head->next = temp;

	temp = head;
	while (temp->next != cursor) {
		temp = temp->next;
	}
	temp->next = cursor->next;
	delete cursor;
	cursor = head;
	return;
}

template<class DT>
void List<DT>::insertBefore(const DT& newElement)
{
	// in-lab 3
	if (isFull()) {
		cout << "List is full" << "\n";
		return;
	}
	else if (isEmpty()) {
		head = new ListNode<DT>(newElement, nullptr);
		cursor = head;
		return;
	}
	else if (cursor == head) {
		ListNode<DT>* temp = new ListNode<DT>(newElement, head);
		head = temp;
		cursor = head;
		return;
	}
	ListNode<DT>* temp = head;
	while (temp->next != cursor) {
		temp = temp->next;
	}
	temp->next = new ListNode<DT>(newElement, cursor);
	cursor = temp->next;
	return;
}