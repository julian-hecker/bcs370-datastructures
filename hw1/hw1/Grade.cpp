// ****
// File: Grade.cpp
// Purpose: define methods for Grade.cpp
// Author: Julian Hecker
// Compiler: MSVS 2017
// ****

#include "Grade.h"

// Setters
void Grade::setName(string newName) {
	name = newName;
}

void Grade::setScore(double newScore) {
	score = newScore;
}

// Getters
string Grade::getName() {
	return name;
}

double Grade::getScore() {
	return score;
}

// Constructors
Grade::Grade() {
	name = "";
	score = 0;
}

Grade::Grade(string newName, double newScore) {
	name = newName;
	score = newScore;
}

Grade::Grade(const Grade &rhs) {
	name = rhs.name;
	score = rhs.score;
}

// Operator Overloads
void Grade::operator = (const Grade& rhs) {
	name = rhs.name;
	score = rhs.score;
}

ostream& operator<<(ostream& os, Grade& rhs) {
	os << "Name: " << rhs.name << endl;
	os << "Score: " << rhs.score << endl;
	return os;
}
