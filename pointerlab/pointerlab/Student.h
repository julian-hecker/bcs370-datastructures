#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student {
private:
	string* name;
	double* gpa;
public:
	string getName();
	double getGpa();
	void setName(string newName);
	void setGpa(double newGpa);

	Student(string newName, double newGpa);
	Student(const Student &rhs);
	~Student();

	friend ostream& operator<< (ostream& os, const Student &rhs);
	void operator=(const Student &rhs);
};

