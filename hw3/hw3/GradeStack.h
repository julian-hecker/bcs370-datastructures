// ****
// File: GradeStack
// Author: Julian Hecker
// Date: 11/2/2020
// Compiler: MSVS 2017
// Purpose: An Array-based implementation of a stack of grades.
// ****

#pragma once
#include <iostream>
using namespace std;
#include "Grade.h"

class GradeStack {
private:
	int max;
	int top;
	Grade* grades;
public:
	// Constructors
	GradeStack();
	GradeStack(int newMax);
	GradeStack(const GradeStack& rhs);
	~GradeStack();
	// Transformers
	void clear();
	bool push(Grade g);
	bool pop(Grade& g);
	// Observers
	int size();
	int maxStorage();
	bool isEmpty();
	bool isFull();
	bool getTop(Grade& g);
	// Overloads
	GradeStack& operator=(GradeStack& rhs);
	friend ostream& operator<<(ostream& os, GradeStack& rhs);
};
