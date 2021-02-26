// ****
// File: GradeQueue.cpp
// Author: Julian Hecker
// Date: 11/2/2020
// Compiler: MSVS 2017
// Purpose: A link-based implementation of a Grade queue
// ****

#include "GradeQueue.h"

// Constructors
GradeQueue::GradeQueue() {
	front = nullptr;
	rear = nullptr;
	size = 0;
}

GradeQueue::GradeQueue(const GradeQueue& rhs) {
	clear();
	size = rhs.size; 

	Node* temp = rhs.front;
	while (temp != nullptr) {
		if (front == nullptr) {
			front = temp;
		}
		else {
			rear->next = temp;
		}
		rear = temp;
		temp = temp->next;
	}
}

GradeQueue::~GradeQueue() {
	clear();
}

// Transformers
void GradeQueue::clear() {
	Node* temp;

	while (front != nullptr) {
		temp = front;
		front = front->next;
		delete temp;
	}
	rear = nullptr;
	size = 0;
}

void GradeQueue::enqueue(Grade g) {
	Node* temp;
	temp = new Node;

	temp->data = g;
	temp->next = nullptr;
	if (rear == nullptr) {
		front = temp;
	}
	else {
		rear->next = temp;
	}
	rear = temp;
	size++;
}

void GradeQueue::dequeue(Grade& g) {
	if (isEmpty()) { // Can't dequeue if it's already empty
		cout << "Empty Queue!" << endl; 
		return; 
	}

	Node* temp = new Node;
	temp = front;
	
	g = front->data; // sets popped data to g
	front = front->next; // Front becomes next element

	if (isEmpty()) { // If the queue becomes empty,
		rear = nullptr; // Mark it as such
	}

	delete temp; // Destroy the removed node
	size--;
}

// Observers
int GradeQueue::getSize() {
	return size;
}

bool GradeQueue::isEmpty() {
	return (front == nullptr);
}

// Overrides
GradeQueue& GradeQueue::operator=(GradeQueue& rhs) {

	Node* temp = rhs.front;
	while (temp != nullptr) {
		if (front == nullptr) {
			front = temp;
		}
		else {
			rear->next = temp;
		}
		rear = temp;
		temp = temp->next;
	}

	return *this;
}

ostream& operator<<(ostream& os, GradeQueue& rhs) {
	Node* temp = rhs.front;
	if (rhs.isEmpty()) {
		os << "Empty Queue" << endl;
		return os;
	}

	os << "GradeQueue:" << endl;
	while (temp != nullptr) {
		os << temp->data;
		temp = temp->next;
	}
	os << "====" << endl;
	return os;
}

