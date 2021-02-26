// ****
// File: GradeCollection.cpp
// Purpose: define methods for GradeCollection class
// Author: Julian Hecker
// Compiler: MSVS 2017
// ****


#include "GradeCollection.h"

// Getter/Setter
void GradeCollection::set(int i, Grade g) {
	if (i < 20 && i >= 0) {
		grades[i] = g;
	}
}

Grade GradeCollection::get(int i) {
	return grades[i];
}

// Constructors
GradeCollection::GradeCollection() {
	// resets grades to empty, -1
	GradeCollection::initialize();
}

// Methods
int GradeCollection::gradeCount(int low, int high) {
	int count = 0;
	// iterating over the number of grades
	for (int i = 0; i < GradeCollection::size(); i++) {
		double score = grades[i].getScore();
		if (score >= low && score <= high) {
			count++;
		}
	}
	return count;
}

Grade GradeCollection::lowestGrade() {
	// replaces "lowest score" if it finds a score lower, and returns the grade at that index
	int lowestIndex = -1;
	double lowestScore = 100;
	for (int i = 0; i < GradeCollection::size(); i++) {
		if (grades[i].getScore() < lowestScore) {
			lowestScore = grades[i].getScore();
			lowestIndex = i;
		}
	}
	return grades[lowestIndex];
}

bool GradeCollection::findGrade(string name, Grade &g) {
	// iterate over the number of grades
	for (int i = 0; i < GradeCollection::size(); i++) {
		if (name == grades[i].getName()) {
			// using copy constructor to copy grade into &g
			g = Grade(grades[i]);
			return true;
		}
	}
	return false;
}

double GradeCollection::gradeAverage() {
	double sum = 0;
	// get the sum of grades, then divide by the number of grades
	for (int i = 0; i < GradeCollection::size(); i++) {
		sum += grades[i].getScore();
	}
	return sum / GradeCollection::size();
}

int GradeCollection::size() {
	// detects number of grades by iterating until finding default an unset score of -1
	int count = 0;
	while (grades[count].getScore() != -1) {
		count++;
	}
	return count;
}

void GradeCollection::initialize() {
	// set all grades as default
	for (int i = 0; i < 20; i++) {
		// uses -1 instead of 0 because 0 is a valid grade
		grades[i] = Grade("", -1);
	}
}

string GradeCollection::getAuthor() {
	// thats meeeee
	return "Author: Julian Hecker";
}
