#pragma once
#include <string>
#include <iostream>
using namespace std;

struct LinkedNode {
	string data;
	LinkedNode* next;
};

class Fast {
private:
	LinkedNode* linkedList; // this is basically the head
	LinkedNode* linkedTail;
	int linkedLength;
	string* arrayList;
	int arrayLength;
public:
	void insert(string data, int priority);
	bool hasItem(string target);
	void clear();
	Fast();
	~Fast();
};