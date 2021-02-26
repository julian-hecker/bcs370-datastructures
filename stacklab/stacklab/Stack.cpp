#include "Stack.h"

// Constructors
Stack::Stack() {
	top = nullptr;
}

/*Stack::Stack(const Stack& rhs) {
	Node* temp = rhs.top;
	while (temp != nullptr) {
		stack.push(temp->data);
		temp = temp->next;
	}
}*/

Stack::~Stack() {
	makeEmpty();
}

// Transformers
void Stack::push(int item) {
	if (!isFull()) {
		Node* temp;
		temp = new Node;
		temp->data = item;
		temp->next = top;
		top = temp;
	}
	else {
		cout << "It's full! Can't eat any more!" << endl;
	}
}

int Stack::pop() {
	if (!isEmpty()) {
		int item = top->data;
		Node* temp;
		temp = top;
		top = top->next;
		delete temp;
		return item;
	}
	else {
		cout << "Already Empty!" << endl;
	}
}

void Stack::makeEmpty() {
	Node* temp;
	while (top != nullptr) {
		temp = top;
		top = top->next;
		delete temp;
	}
}

// Observers
bool Stack::isEmpty() {
	return (top == nullptr);
}

bool Stack::isFull() {
	Node* temp;
	try {
		temp = new Node;
		delete temp;
		return false;
	} catch (bad_alloc exception) {
		return true;
	}
}

// Overloads
ostream& operator<<(ostream& os, Stack& rhs) {
	Node* temp = rhs.top;
	while (temp != nullptr) {
		os << temp->data << " ";
		temp = temp->next;
	}
	os << endl;
	return os;
}

/*const Stack& Stack::operator=(const Stack& rhs) {
	Stack stack = Stack();
	Node* temp = rhs.top;
	while (temp != nullptr) {
		stack.push(temp->data);
		temp = temp->next;
	}
	return stack;
}*/
