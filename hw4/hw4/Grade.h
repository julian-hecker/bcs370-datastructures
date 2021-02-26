// ****
// File: Grade.h
// Purpose Outline properties of the Grade class but with pointers
// Author: Julian Hecker
// Compiler: MSVS 2017
// Updates:
// 9/30/2020: Turn variables into pointers
// 10/31/2020: Add equality overload
// 11/26/2020: < and > overloads
// ****

#pragma once
#include <string>
using namespace std;

class Grade {
private:
	// Private Members (Pointers)
	string* name;
	double* score;
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
	~Grade();
	// Operator Overloads
	Grade& operator=(Grade const &rhs);
	friend ostream& operator<<(ostream& os, Grade &rhs);
	friend istream& operator>>(istream& is, Grade &rhs);
	friend bool operator==(Grade& lhs, Grade& rhs);
	friend bool operator<(Grade& lhs, Grade& rhs);
	friend bool operator>(Grade& lhs, Grade& rhs);
};

