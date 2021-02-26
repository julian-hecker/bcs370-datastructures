#include "Stack.h"

int main() {

	Stack s = Stack();

	s.push(32);
	s.push(12);
	s.push(13);
	cout << s;

	int x = s.pop();

	cout << s;
	cout << x << endl;


	s.makeEmpty();
	cout << "Empty: " << s.isEmpty() << endl;
	cout << "Full: " << s.isFull() << endl;


	return 0;
}