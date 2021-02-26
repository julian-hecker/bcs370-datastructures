#include "SuperDuperStorage.h"

// Helpers
SN* calculateMax(SN* start) {
	SN* temp = start;
	SN* max = temp;
	while (temp != nullptr) {
		if (temp->data > max->data) {
			max = temp;
		}
		temp = temp->next;
	}
	return max;
}

void clearHelper(SN* node) {
	if (node != nullptr) {
		clearHelper(node->next);
	}
	delete node;
}


// Constructors
SuperDuperStorage::SuperDuperStorage() {
	start = nullptr;
	end = nullptr;
	iter = nullptr;
	high = nullptr;
}

SuperDuperStorage::SuperDuperStorage(const SuperDuperStorage& rhs) {
	SN* temp = rhs.start;
	while (temp != nullptr) {
		insert(temp->data);
		temp = temp->next;
	}
}

SuperDuperStorage::~SuperDuperStorage() {
	clear();
}

// Methods
void SuperDuperStorage::clear() {
	clearHelper(start); // recursion woohoo
	start = nullptr;
	end = nullptr;
	high = nullptr;
	iter = nullptr;
}

void SuperDuperStorage::insert(int data) {
	// Creating new node
	SN* temp = new SN;
	temp->data = data;
	if (end != nullptr) {
		temp->prev = end;
		end->next = temp;
	}
	else { // Inserting first node
		temp->prev = nullptr;
		start = temp;
	}
	temp->next = nullptr;
	end = temp;
	// Calculating highest node
	high = calculateMax(start);
}

int SuperDuperStorage::getMax() {
	return high->data;
}

void SuperDuperStorage::moveIterToStart() {
	iter = start;
}

void SuperDuperStorage::moveIterToEnd() {
	iter = end;
}

void SuperDuperStorage::moveIterForward() {
	iter = iter->next;
}

void SuperDuperStorage::moveIterBackward() {
	iter = iter->prev;
}

bool SuperDuperStorage::isIterValid() {
	return iter != nullptr;
}

int SuperDuperStorage::getIterData() {
	return iter->data;
}
