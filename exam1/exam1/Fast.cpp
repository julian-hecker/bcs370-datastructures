#include "Fast.h"

void Fast::insert(string data, int priority) {
	if (priority == 1) { // Store in priority linkedList
		LinkedNode* temp;
		temp = new LinkedNode;
		temp->data = data;
		temp->next = linkedList;
		linkedList = temp;
		linkedLength++;

		// Max 5 items in priority list
		if (linkedLength > 5) {
			arrayList[arrayLength] = linkedTail->data;
			arrayLength++;
			linkedLength--;
		}

		// Keeping the tail
		LinkedNode* tempTail = linkedList;
		for (int i = 0; i < linkedLength - 1; i++) {
			tempTail = tempTail->next;
		}
		linkedTail = tempTail;
	}
	else if (priority == 0) { // Store in arrayList
		arrayList[arrayLength] = data;
		arrayLength++;
	}
	else {
		cerr << "Priority is either 0 or 1" << endl;
	}
}

bool Fast::hasItem(string target) {
	// Search in Priority LinkedList
	LinkedNode* temp = linkedList;
	while (temp != nullptr) {
		if (temp->data == target) {
			return true;
		}
		temp = temp->next;
	}
	// Search in Array List
	for (int i = 0; i < arrayLength; i++) {
		if (arrayList[i] == target) {
			return true;
		}
	}
	return false;
}

void Fast::clear() {
	// Clear linkedList
	LinkedNode* temp;
	while (linkedList != nullptr) {
		temp = linkedList;
		linkedList = linkedList->next;
		delete temp;
	}
	linkedLength = 0;
	linkedTail = nullptr;
	// Clear arrayList
	arrayLength = 0;
}

Fast::Fast() {
	linkedList = nullptr;
	linkedLength = 0;
	linkedTail = linkedList;
	arrayList = new string[100];
	arrayLength = 0;
}

Fast::~Fast() {
	clear();
	arrayList = nullptr;
}
