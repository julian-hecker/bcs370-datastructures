#include "Student.h"

string Student::getName() {
	return *name;
}

double Student::getGpa() {
	return *gpa;
}

void Student::setName(string newName) {
	*name = newName;
}

void Student::setGpa(double newGpa) {
	*gpa = newGpa;
}

Student::Student(string newName, double newGpa) {
	name = new string;
	gpa = new double;
	*name = newName;
	*gpa = newGpa;
}

Student::Student(const Student &rhs) {
	name = new string;
	gpa = new double;
	*name = *rhs.name;
	*gpa = *rhs.gpa;
}

Student::~Student() {
	delete name;
	name = nullptr;
	delete gpa;
	gpa = nullptr;
	cout << "Destructor Called!" << endl;
}

ostream& operator<< (ostream& os, const Student &rhs) {
	os << *rhs.name << ", " << *rhs.gpa << endl;
	return os;
}

void Student::operator=(const Student &rhs) {
	
}
