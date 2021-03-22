//--------------------------------------------------------------------
//	written by : 2020112036 김상현
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//	2021-03-19
//--------------------------------------------------------------------

#include "listarr.h"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).

	: maxSize(maxNumber),
	size(0),
	cursor(-1)
{
	// pre-lab
	dataItems = new DataType[maxNumber];
	for (int i = 0; i < maxNumber; i++) {
		dataItems[i] = '\0'; //init
	}
}

//--------------------------------------------------------------------

List:: ~List()
// Frees the memory used by a list.

{
	// pre-lab
	delete[] dataItems;
}

//--------------------------------------------------------------------

void List::insert(const DataType& newDataItem)
throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	// pre-lab
	if (isFull()) {
		cout << "Full list" << endl;
		return;
	}
	else if (cursor == maxSize - 1) {
		cout << "cursor is at the end of list(insert fail)" << endl;
		return;
	}
	else {
		for (int i = size - 1; i > cursor; i--) {
			dataItems[i + 1] = dataItems[i];
		}
		dataItems[++cursor] = newDataItem;
		size++;
	}

}

//--------------------------------------------------------------------

void List::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.
{
	// pre-lab
	
	if (cursor == -1 || isEmpty()) {
		cout << "Failed -- either at the begin of the list "
			<< "or the list is empty" << endl;
		return;
	}
	if (cursor == size - 1) {
		cursor = (size == 1 ? -1 : 0);
	}
	else {
		for (int i = cursor; i < size - 1; i++) {
			dataItems[i] = dataItems[i + 1];
		}
	}
	dataItems[--size] = '\0';
}

//--------------------------------------------------------------------

void List::replace(const DataType& newDataItem)
throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.
{
	// Requires that the list is not empty
	// pre-lab
	if (isEmpty()) {
		cout << "Empty List" << endl;
		return;
	}
	dataItems[cursor] = newDataItem;
}
//--------------------------------------------------------------------

void List::clear()
// Removes all the data items from a list.
{
	// pre-lab
	for (int i = 0; i < size; i++) {
		dataItems[i] = '\0';
	}
	size = 0;
	cursor = -1;
}

//--------------------------------------------------------------------

bool List::isEmpty() const
// Returns 1 if a list is empty. Otherwise, returns 0.
{
	// pre-lab
	return size ? false : true;
}

//--------------------------------------------------------------------

bool List::isFull() const
// Returns 1 if a list is full. Otherwise, returns 0.
{
	// pre-lab
	return size == maxSize ? true : false;
}

//--------------------------------------------------------------------

bool List::gotoBeginning() throw (logic_error)
// Moves the cursor to the beginning of the list.
{
	// pre-lab
	if (!size)	return false;
	cursor = 0; //출력 예시를 참고하였습니다.
	return true;
}

//--------------------------------------------------------------------

bool List::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
	// pre-lab
	if (!size || cursor == size - 1)	return false;
	cursor = size - 1;
	return true;
}

//--------------------------------------------------------------------

bool List::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.
{
	// pre-lab
	if (!size || cursor == size - 1) {
		return false;
	}
	cursor++;
	return true;
}

//--------------------------------------------------------------------

bool List::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	// pre-lab
	if (!size || cursor == -1) {
		//cursor가 0이 아니라 -1일 경우에만 false를 return하도록 설정했습니다.
		//왜냐하면 모든 원소가 지워지는 경우가 아닌 이상 cursor가 -1이 될 수 없으면 리스트의 가장 왼쪽에 원소를 삽입할 수 없기 때문입니다.
		//ex) 2 6 8 에서 가장 왼쪽에 1을 삽입하고 싶을 때, 1 2 6 8
		return false;
	}
	cursor--;
	return true;

}

//--------------------------------------------------------------------

DataType List::getCursor() const throw (logic_error)
// Returns the item marked by the cursor.

{
	// pre-lab
	return dataItems[cursor];
}

//--------------------------------------------------------------------

void List::showStructure() const
// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	// pre-lab
	if (isEmpty()) {
		cout << "Empty List" << endl;
		return;
	}
	cout << "size:" << size << " cursor:" << cursor << endl;
	for (int i = 0; i < maxSize; i++) {
		cout << "List[" << i << "] ";
	}
	cout << "\n";
	for (int i = 0; i < maxSize; i++) {
		cout << dataItems[i] << "\t";
	}
	cout << "\n";
}

//--------------------------------------------------------------------

//in-lab
void List::moveToNth(int n) throw (logic_error)
{
	// in-lab 2
	if (n >= size) cout << "Impossible (N is larger than the iterator of the element at the end of the list.)" << endl;
	else cursor = n;
}

bool List::find(const DataType& searchDataItem) throw(logic_error)
{
	// in-lab 3
	for (int i = cursor; i < size; i++) {
		if (dataItems[i] == searchDataItem) {
			cursor = i;
			return true;
		}
	}
	cursor = size - 1;
	return false;
}