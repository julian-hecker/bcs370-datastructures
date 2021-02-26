// ****
// File: Grade.cpp
// Purpose: Define methods for Grade
// Author: Julian Hecker
// Compiler: MSVS 2017
// Updates:
// 9/30/2020: Turn variables into pointers
// 10/31/2020: Add equality overload

#include "Grade.h"

// Setters
void Grade::setName(string newName) {
	*name = newName;
}

void Grade::setScore(double newScore) {
	*score = newScore;
}

// Getters
string Grade::getName() {
	return *name;
}

double Grade::getScore() {
	return *score;
}

// Constructors
Grade::Grade() {
	name = new string;
	score = new double;
	*name = "_";
	*score = 0;
}

Grade::Grade(string newName, double newScore) {
	name = new string;
	score = new double;
	*name = newName;
	*score = newScore;
}

Grade::Grade(const Grade &rhs) {
	name = new string;
	score = new double;
	*name = *rhs.name;
	*score = *rhs.score;
}

Grade::~Grade() {
	if (name != NULL) {
		delete name;
	}
	if (score != NULL) {
		delete score;
	}
}

// Operator Overloads
Grade& Grade::operator=(Grade const &rhs) {
	*name = *rhs.name;
	*score = *rhs.score;
	return *this;
}

ostream &operator<< (ostream& os, Grade& rhs) {
	os << "Name:\t" << *rhs.name << endl;
	os << "Score:\t" << *rhs.score << endl;
	return os;
}

istream &operator>> (istream& is, Grade &rhs) {
	is >> *rhs.name >> *rhs.score;
	return is;
}

bool operator==(Grade& lhs, Grade& rhs) { 
	// Overload the equality operator. Returns true if both grades' name are equal
	return (*lhs.name == *rhs.name);
}


