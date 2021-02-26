// ****
// File: main.cpp
// Purpose: runs methods defined in hw classes
// Author: Julian Hecker
// Compiler: MSVS 2017
// ****

#include <iostream>
using namespace std;
#include "GradeCollection.h"

int main() {
	// Parameter Constructor
	Grade g1("reee", 90);
	// Copy Constructor
	Grade g2(g1);
	// Assignment Overload
	Grade g3 = g2;
	// Testing
	g1.setScore(80);
	g2.setScore(99);
	g3.setName("nooo");
	g3.setScore(70);
	// Ostream Overload
	cout << g1 << g2 << g3 << endl;


	GradeCollection grades;

	cout << grades.getAuthor() << endl;

	Grade g4 = grades.get(0);
	g4.setName("boolean");
	g4.setScore(100);
	cout << g4 << endl;

	grades.set(0, g1);
	grades.set(1, g2);
	grades.set(2, g3);
	grades.set(3, g4);

	cout << "Count: " << grades.size() << "; Average: " << grades.gradeAverage() << endl;
	cout << "Passing Scores: " << grades.gradeCount(75, 100) << endl;


	Grade g5;
	grades.findGrade("nooo", g5);
	cout << g5;


	return 0;
}