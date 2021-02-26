#include "UnsortedList.h"

// Constructors
UnsortedList::UnsortedList() {
	listData = nullptr;
	length = 0;
}

UnsortedList::~UnsortedList() {
	UnsortedList::clear();
}

// Methods
void UnsortedList::add(int item) {
	NodeType* temp;
	temp = new NodeType;
	temp->data = item;
	temp->next = listData;
	listData = temp;
	length++;
}

void UnsortedList::remove(int target) {
	// we didnt do this yet
}

void UnsortedList::clear() {
	// Can't just delete listdata, must iterate through all nodes and delete
	NodeType* tempPtr;
	while (listData != nullptr) {
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}

void UnsortedList::show() {
	if (listData == nullptr) {
		cout << "Empty" << endl;
		return;
	}

	NodeType* temp = listData;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
