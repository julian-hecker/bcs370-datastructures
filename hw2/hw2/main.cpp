// ****
// Project: HW2
// Author: Julian Hecker
// Purpose: Updates to Grade and GradeCollection classes so they use pointers.
// Date: 10/5/2020
// Compiler: MSVS 2017
// Update Information
// ==================
// 9/16/2020
// Update member variables to use pointers and fix methods to work.
// ****

#include <iostream>
using namespace std;
#include "Grade.h"
#include "GradeCollection.h"

int main() {
	// Showing that all the Grade methods work
	Grade g1 = Grade(); // Default Constructor
	Grade g2 = Grade("reee", 98); // Constructor
	Grade g3 = Grade(g2); // Copy Constructor
	g3.setName("REEE"); // Name Setter
	g3.setScore(100); // Score Setter
	Grade g4 = g2; // Assignment overload
	cout << "Enter name and score" << endl;
	// cin >> g1; // Cin overload
	cout << g1 << g2 << g3 << g4; // Cout Overload
	
	// Showing that all GradeCollection methods work
	GradeCollection gc1 = GradeCollection(3); // Parameter Constructor
	GradeCollection gc2 = GradeCollection(); // Default Constructor 
	gc1.set(0, g3); // Setter
	gc1.set(1, g2);
	gc1.set(2, g4);
	GradeCollection gc3 = GradeCollection(gc1); // Copy Constructor
	cout << gc1 << endl; // ostream overload

	cout << gc1.gradeCount(30, 100) << endl;
	cout << gc1.lowestGrade().getScore() << endl;
	cout << gc1.findGrade("reee", g1) << endl;
	cout << g1 << endl;
	cout << gc1.gradeAverage() << endl;
	cout << gc1.getAuthor() << endl;
	cout << gc1.clone();


	return 0;
}





