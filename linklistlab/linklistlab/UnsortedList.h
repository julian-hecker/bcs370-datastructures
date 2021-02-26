#pragma once

#include <iostream>
using namespace std;

struct NodeType {
	int data;
	NodeType* next;
};


class UnsortedList {
private:
	NodeType* listData; // head
	int length;
public:
	// Constructors
	UnsortedList();
	~UnsortedList();
	// Methods
	void add(int item);
	void remove(int target);
	void clear();
	void show();
};
