// ****
// File: Grade.h
// Purpose: Outline properties of the Grade class
// Author: Julian Hecker
// Compiler: MSVS 2017
// ****

#pragma once
#include <string>
using namespace std;

class Grade {
private:
	// Private Members
	string name;
	double score;
public:
	// Setters
	void setName(string newName);
	void setScore(double newScore);
	// Getters
	string getName();
	double getScore();
	// Constructors
	Grade();
	Grade(string newName, double newScore);
	Grade(const Grade &rhs);
	// Operator Overloads
	void operator = (const Grade& rhs);
	friend ostream& operator<<(ostream& os, Grade& rhs);
};
