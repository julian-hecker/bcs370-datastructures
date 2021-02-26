// ****
// File: Main.cpp
// Purpose: Driver code
// Author: Julian Hecker
// Compiler: MSVS 2017
// Date: 11/26/2020
// ****

#include "BST.h"

int main() {
	Grade g1 = Grade("reee", 100);
	Grade g2 = Grade("aaack", 20);
	Grade g3 = Grade("nooo", 80);
	Grade g4 = Grade("zeee", 50);

	BST b1 = BST();
	b1.add(g1);
	b1.add(g2);
	b1.add(g3);
	b1.add(g4);

	cout << "size:\t" << b1.size() << endl;
	cout << "preorder:\t";
	b1.preorder();
	cout << "inorder:\t";
	b1.inorder();
	cout << "postorder:\t";
	b1.postorder();

	double found;
	b1.getScore("reee", found);
	cout << "found reee:\t" << found << endl;

	BST b2 = BST(b1);
	cout << "b2, copied b1:\t";
	b2.inorder();
	b2.clear();
	cout << "b2 after clear:\t" << b2.size() << endl;
	b2.add(g3);

	BST b3 = b1;
	cout << "b3, copied b1:\t";
	b3.inorder();

	cout << b1 << b2 << b3 << endl;


	return 0;
}