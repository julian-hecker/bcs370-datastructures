#include "Fast.h"


int main() {
	Fast fast = Fast();

	fast.insert("reee", 0);
	fast.insert("raaa", 1);
	fast.insert("heee", 1);
	fast.insert("eree", 1);
	fast.insert("uwu", 1);
	fast.insert("raca", 1);
	fast.insert("wooohooo", 1);
	fast.insert("rooo", 0);

	// Expected results: 1 1 0
	cout << fast.hasItem("rooo") << endl;
	cout << fast.hasItem("reee") << endl;
	cout << fast.hasItem("rehh") << endl;

	fast.clear();

	// Expected result: 0
	cout << fast.hasItem("rooo") << endl;

	return 0;
}