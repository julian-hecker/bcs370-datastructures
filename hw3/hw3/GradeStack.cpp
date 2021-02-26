// ****
// File: GradeStack.cpp
// Author: Julian Hecker
// Compiler: MSVS 2017
// Date: 11/2/2020
// Purpose: An Array-based implementation of a stack of grades.
// ****

#include "GradeStack.h"

// Constructors
GradeStack::GradeStack() {
	max = 5;
	top = -1;
	grades = new Grade[max];
}

GradeStack::GradeStack(int newMax) {
	max = newMax;
	top = -1;
	grades = new Grade[max];
}

GradeStack::GradeStack(const GradeStack& rhs) {
	clear();
	max = rhs.max;
	top = rhs.top;
	grades = new Grade[max];
	for (int i = 0; i < max; i++) {
		grades[i] = rhs.grades[i];
	}
}

GradeStack::~GradeStack() {
	delete[] grades;
}

// Transformers
void GradeStack::clear() {
	top = -1;
}

bool GradeStack::push(Grade g) {
	// Pushes g to stack, returns true if successful
	if (isFull()) { 
		return false;
	}

	top++;
	Grade g1 = g;
	grades[top] = g;
	return true;
}

bool GradeStack::pop(Grade& g) {
	// Pops top into g, returns true if successful
	if (isEmpty()) {
		return false;
	}

	g = grades[top];
	top--;
	return true;
}

// Observers
int GradeStack::size() {
	return (top + 1);
}

int GradeStack::maxStorage() {
	return max;
}

bool GradeStack::isEmpty() {
	return (top == -1);
}

bool GradeStack::isFull() {
	return (top == max - 1);
}

bool GradeStack::getTop(Grade& g) {
	if (isEmpty()) { return false; }
	g = grades[top];
	return true;
}

// Overloads
GradeStack& GradeStack::operator=(GradeStack& rhs) {
	clear();
	max = rhs.max;
	top = rhs.top;
	for (int i = 0; i < top; i++) {
		grades[i] = rhs.grades[i];
	}
	return *this;
	
}

ostream& operator<<(ostream& os, GradeStack& rhs) {
	if (rhs.isEmpty()) {
		os << "GradeStack Empty!" << endl;
		return os;
	}

	os << "GradeStack: " << endl;
	for (int i = 0; i <= rhs.top; i++) {
		os << rhs.grades[i];
	}
	os << "====" << endl;
	return os;
}

