#pragma once
#include <string>
#include <iostream>
using namespace std;

class Wallpost {
private:
	string name;
	string comment;
	string likes[10];
	int likesCount = 0;
public: 
	void addLike(string newLiker);
	void setName(string newName);
	void setComment(string newComment);
	string getName();
	string getComment();
	Wallpost();
	Wallpost(string newName, string newComment);
	Wallpost(const Wallpost &rhs);
	friend ostream& operator<<(ostream& os, Wallpost& rhs);
};