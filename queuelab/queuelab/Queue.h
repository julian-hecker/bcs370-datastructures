#pragma once
#include <iostream>
using namespace std;

// Array Based Queue


struct emptyQueue : public exception {};

struct fullQueue : public exception {};

class Queue {
private:
	int front;
	int rear;
	int max = 100;
	int items[100];
public:
	// Constructors
	Queue();
	Queue(const Queue& rhs);
	// Transformers
	void enqueue(int item);
	void dequeue(int& item);
	void makeEmpty();
	// Observers
	bool isEmpty();
	bool isFull();
	friend ostream& operator<<(ostream& os, Queue& rhs);

};