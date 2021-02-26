// ****
// File: Grade.cpp
// Purpose: Define methods for Grade
// Author: Julian Hecker
// Compiler: MSVS 2017
// Updates:
// 9/30/2020: Turn variables into pointers

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
	*name = "";
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
	delete name;
	name = nullptr;
	delete score;
	score = nullptr;
}

// Operator Overloads
void Grade::operator= (const Grade& rhs) {
	*name = *rhs.name;
	*score = *rhs.score;
}

ostream &operator<< (ostream& os, Grade& rhs) {
	os << "Name: " << *rhs.name << endl;
	os << "Score: " << *rhs.score << endl;
	return os;
}

istream &operator>> (istream& is, Grade &rhs) {
	is >> *rhs.name >> *rhs.score;
	return is;
}

