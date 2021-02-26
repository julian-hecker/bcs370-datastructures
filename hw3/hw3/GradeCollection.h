// ****
// File: GradeCollection.h
// Purpose: outline properties of the GradeCollection class but with pointers
// Author: Julian Hecker
// Compiler: MSVS 2017
// Updates:
// 9/30/2020: Convert variables to pointy pointers
// ****

#pragma once
#include <string>
using namespace std;
#include "Grade.h"

class GradeCollection {
private:
	// Private Members
	Grade* grades;
	int size;
public:
	// Setters
	void set(int i, Grade g);
	void resize(int newSize);
	// Getters
	Grade get(int i);
	int getSize();
	// Constructors
	GradeCollection();
	GradeCollection(int length);
	GradeCollection(const GradeCollection& rhs);
	~GradeCollection();
	// Methods
	int gradeCount(int low, int high);
	Grade lowestGrade();
	bool findGrade(string name, Grade &g);
	double gradeAverage();
	void initialize();
	string getAuthor();
	GradeCollection* clone();
	// Operator Overloads
	void operator= (const GradeCollection &rhs);
	friend ostream &operator<< (ostream& os, GradeCollection &rhs);

};
