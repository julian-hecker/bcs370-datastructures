// ****
// File: GradeCollectionCollection.h
// Purpose: outline properties of the GradeCollectionCollection class
// Author: Julian Hecker
// Compiler: MSVS 2017
// ****

#pragma once
#include <string>
using namespace std;
#include "Grade.h"

class GradeCollection {
private:
	// Private Members
	Grade grades[20] = { Grade("", -1) }; // array full of -1 grades by default
public:
	// Getter/Setter
	void set(int i, Grade g);
	Grade get(int i);
	// Constructors
	GradeCollection();
	// Methods
	int gradeCount(int low, int high);
	Grade lowestGrade();
	bool findGrade(string name, Grade &g);
	double gradeAverage();
	int size();
	void initialize();
	string getAuthor();
};
