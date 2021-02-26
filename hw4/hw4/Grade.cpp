// ****
// File: Grade.cpp
// Purpose: Define methods for Grade
// Author: Julian Hecker
// Compiler: MSVS 2017
// Updates:
// 9/30/2020: Turn variables into pointers
// 10/31/2020: Add equality overload
// 11/26/2020: Add < and > overloads
// ****


#include "Grade.h"

// Setters
// Sets instance's name member
void Grade::setName(string newName) {
	*name = newName;
}
// Sets instance's score member
void Grade::setScore(double newScore) {
	*score = newScore;
}

// Getters
// Gets instance's name member
string Grade::getName() {
	return *name;
}
// Gets instance's score member
double Grade::getScore() {
	return *score;
}

// Constructors
// Default Constructor
Grade::Grade() {
	name = new string;
	score = new double;
	*name = "_";
	*score = 0;
}
// Parametered Constructor
Grade::Grade(string newName, double newScore) {
	name = new string;
	score = new double;
	*name = newName;
	*score = newScore;
}
// Copy Constructor
Grade::Grade(const Grade &rhs) {
	name = new string;
	score = new double;
	*name = *rhs.name;
	*score = *rhs.score;
}
// Destructor
Grade::~Grade() {
	if (name != NULL) {
		delete name;
	}
	if (score != NULL) {
		delete score;
	}
}

// Operator Overloads
// Assignment Overload (Deep Copy)
Grade& Grade::operator=(Grade const &rhs) {
	*name = *rhs.name;
	*score = *rhs.score;
	return *this;
}
// Ostream Overload
ostream &operator<< (ostream& os, Grade& rhs) {
	os << "Name:\t" << *rhs.name << endl;
	os << "Score:\t" << *rhs.score << endl;
	return os;
}
// Istream Overload
istream &operator>> (istream& is, Grade &rhs) {
	is >> *rhs.name >> *rhs.score;
	return is;
}
// Equality Overload
bool operator==(Grade& lhs, Grade& rhs) {
	// Overload the equality operator. Returns true if both grades' name are equal
	return *lhs.name == *rhs.name;
}
// Less than Overload
bool operator<(Grade& lhs, Grade& rhs) {
	return *lhs.name < *rhs.name;
}
// Greater than overload
bool operator>(Grade& lhs, Grade& rhs) {
	return *lhs.name > *rhs.name;
}



