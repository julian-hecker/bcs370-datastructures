#pragma once
#include <iostream> 
using namespace std;

struct Node {
	int key;
	int value;
	bool isOccupied;
	bool isDeleted;
};

const int HASH_TABLE_SIZE = 10;

class HashTable {
private:
	Node table[HASH_TABLE_SIZE];
	int h(int key, int tries);
	int f(int tries);
public:
	HashTable();
	void add(int key, int value);
	void show();
	void clear();
};
