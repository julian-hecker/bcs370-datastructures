// ****
// File: GradeCollection.cpp
// Purpose: define methods for GradeCollection class
// Author: Julian Hecker
// Compiler: MSVS 2017
// Updates:
// 9/30/2020: Replace variables with pointers
// ****

#include "GradeCollection.h"

// Setters
void GradeCollection::set(int i, Grade g) {
	// Sets grade at index
	if (i >= 0 && i < size) {
		grades[i] = g;
	}
}

void GradeCollection::resize(int newSize) {
	// This is basically resize method
	Grade* newGrades;
	newGrades = new Grade[newSize];

	for (int i = 0; i < newSize; i++) {
		newGrades[i] = grades[i];
	}
	grades = newGrades;
	delete[] newGrades;
}

// Getters
Grade GradeCollection::get(int i) {
	// Gets grade at index i
	return grades[i];
}

int GradeCollection::getSize() {
	// Gets Size
	return size;
}

// Constructors
GradeCollection::GradeCollection() {
	// Default Constructor
	size = 20;
	grades = new Grade[size];
	GradeCollection::initialize(); // Reset grades to empty -1
}

GradeCollection::GradeCollection(int length) {
	// Parameterized Constructor
	size = length;
	grades = new Grade[size];
}

GradeCollection::GradeCollection(const GradeCollection& rhs) {
	// Copy Constructor
	size = rhs.size;
	grades = new Grade[size];
	for (int i = 0; i < size; i++) {
		grades[i] = rhs.grades[i]; // Calls Grade's Operator=
	}
}

GradeCollection::~GradeCollection() {
	// Deletes the dynamic array
	delete[] grades;
	grades = nullptr;
}

// Methods
int GradeCollection::gradeCount(int low, int high) {
	// Returns the number of grades within bounds (inclusive)
	int count = 0;
	// iterating over the number of grades
	for (int i = 0; i < size; i++) {
		double score = grades[i].getScore();
		if (score >= low && score <= high) {
			count++;
		}
	}
	return count;
}

Grade GradeCollection::lowestGrade() { // ERRORS HERE
	// Returns the grade with the lowest score
	// replaces "lowest score" if it finds a score lower, and returns the grade at that index
	int lowestIndex = -1;
	double lowestScore = grades[0].getScore();
	for (int i = 1; i < size; i++) {
		if (grades[i].getScore() < lowestScore) {
			lowestScore = grades[i].getScore();
			lowestIndex = i;
		}
	}
	return grades[lowestIndex];
}

bool GradeCollection::findGrade(string name, Grade &g) {
	// Returns true if grade is in collection
	// iterate over the number of grades
	for (int i = 0; i < size; i++) {
		if (name == grades[i].getName()) {
			// using copy constructor to copy grade into &g
			g = Grade(grades[i]);
			return true;
		}
	}
	return false;
}

double GradeCollection::gradeAverage() {
	// Gets the average of grades (fails if size != number of grades)
	double sum = 0;
	// get the sum of grades, then divide by the number of grades
	for (int i = 0; i < size; i++) {
		sum += grades[i].getScore();
	}
	return sum / size;
}

void GradeCollection::initialize() {
	// set all grades as default
	for (int i = 0; i < size; i++) {
		// uses -1 instead of 0 because 0 is a valid grade
		grades[i] = Grade("", -1);
	}
}

string GradeCollection::getAuthor() {
	// thats meeeee
	return "Author: Julian Hecker";
}

GradeCollection* GradeCollection::clone() {
	// Returns a pointer to a GradeCollection deep copy
	GradeCollection* newGrades = new GradeCollection(size);
	for (int i = 0; i < newGrades->size; i++) {
		newGrades->set(i, grades[i]); // use -> cuz pointer
	}
	return newGrades;
}

// Operator Overloads
void GradeCollection::operator= (const GradeCollection &rhs) {
	// Overloads assignment operator
	GradeCollection::resize(rhs.size);
	grades = new Grade[size];
	for (int i = 0; i < size; i++) {
		grades[i] = rhs.grades[i];
	}
}

ostream &operator<< (ostream& os, GradeCollection &rhs) {
	// Overloads ostream operator
	for (int i = 0; i < rhs.size; i++) {
		os << rhs.grades[i].getName()
			<< ": " << rhs.grades[i].getScore()
			<< endl;
	}
	return os;
}
