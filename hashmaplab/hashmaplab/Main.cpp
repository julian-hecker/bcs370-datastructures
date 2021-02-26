#include "HashTable.h"

int main() {
	HashTable ht;
	ht.add(12, 130);
	ht.add(1, 20);
	ht.add(30, 100);

	ht.show();

	return 0;
}