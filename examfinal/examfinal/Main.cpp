#include "SuperDuperStorage.h"

#include <iostream>
using namespace std;


int main() {
	SuperDuperStorage sds = SuperDuperStorage();
	sds.insert(10);
	sds.insert(20);
	sds.insert(30);
	sds.insert(5);
	sds.insert(40);
	sds.insert(50);
	cout << "Max: " << sds.getMax() << endl;


	sds.moveIterToStart();
	while (sds.isIterValid()) {
		cout << sds.getIterData() << " ";
		sds.moveIterForward();
	}
	cout << endl;


	SuperDuperStorage sds1 = SuperDuperStorage(sds);

	sds.clear();
	
	sds1.moveIterToStart();
	while (sds1.isIterValid()) {
		cout << sds1.getIterData() << " ";
		sds1.moveIterForward();
	}
	cout << endl;


	return 0;
}