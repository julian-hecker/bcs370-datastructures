#include "Queue.h"

// Constructors 
Queue::Queue() {
	front = max - 1;
	rear = max - 1;
}

Queue::Queue(const Queue& rhs) {
	front = rhs.front;
	rear = rhs.rear;
	max = rhs.max;
	items[max];
	for (int i = 0; i < max; i++) {
		items[i] = rhs.items[i];
	}
}

// Transformers
void Queue::enqueue(int item) {
	if (isFull()) {
		throw fullQueue();
	}
	else {
		rear = (rear + 1) % max;
		items[rear] = item;
	}
}

void Queue::dequeue(int& item) {
	if (isEmpty()) {
		throw emptyQueue();
	}
	else {
		front = (front + 1) % max;
		item = items[front];
	}
}

void Queue::makeEmpty() {
	if (isEmpty()) {
		throw emptyQueue();
	}
	else {
		front = rear;
	}
}

// Observers
bool Queue::isEmpty() {
	return (front == rear);
}

bool Queue::isFull() {
	return ((rear + 1) % max == front);
}

ostream& operator<<(ostream& os, Queue& rhs) {
	if (rhs.isEmpty()) {
		os << "Empty Queue" << endl;
	}
	else {
		int i = (rhs.front + 1) % rhs.max;
		while (i != (rhs.rear + 1) % rhs.max) {
			os << rhs.items[i] << " ";
			i = (i + 1) % rhs.max;
		}
		os << endl;
	}

	return os;
}
