// ****
// File: GradeQueue.h
// Author: Julian Hecker
// Date: 11/2/2020
// Compiler: MSVS 2017
// Purpose: A link-based implementation of a Grade queue
// ****

#pragma once
#include <iostream>
using namespace std;
#include "Grade.h"

struct Node {
	Grade data;
	Node* next;
};

class GradeQueue {
private:
	Node* front;
	Node* rear;
	int size;
public:
	// Constructors
	GradeQueue();
	GradeQueue(const GradeQueue& rhs);
	~GradeQueue();
	// Transformers
	void clear();
	void enqueue(Grade g);
	void dequeue(Grade& g);
	// Observers
	int getSize();
	bool isEmpty();
	// Overrides
	GradeQueue& operator=(GradeQueue& rhs);
	friend ostream& operator<<(ostream& os, GradeQueue& gq);
};
