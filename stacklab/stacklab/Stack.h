#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class Stack {
private:
	Node *top;
public:
	// Constructors
	Stack();
	~Stack();
	Stack(const Stack& rhs);
	// Transformers
	void push(int item);
	int pop();
	void makeEmpty();
	// Observers
	bool isEmpty();
	bool isFull();
	// Overloads
	friend ostream& operator<<(ostream& os, Stack& rhs);
	const Stack& operator=(const Stack& rhs);
}; 
