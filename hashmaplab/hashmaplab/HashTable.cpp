#include "HashTable.h"

// Private Functions
int HashTable::h(int key, int tries) {
	return (key % HASH_TABLE_SIZE + f(tries)) % HASH_TABLE_SIZE;
}

int HashTable::f(int tries) {
	return tries;
}

// Constructor
HashTable::HashTable() {
	clear();
}


// Methods
void HashTable::add(int key, int value) {
	int tries = 0;
	int insert;
	do {
		insert = h(key, tries);
		tries++;
	} while (table[insert].isOccupied);
	table[insert].key = key;
	table[insert].value = value;
	table[insert].isOccupied = true;
}

void HashTable::show() {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		if (table[i].isOccupied) {
			cout << table[i].key << "->" << table[i].value << endl;
		}
	}
	cout << endl;
}

void HashTable::clear() {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		table[i].key = 0;
		table[i].value = 0;
		table[i].isOccupied = false;
		table[i].isDeleted = false;
	}
}