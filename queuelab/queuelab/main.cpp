#include "Queue.h"

int main() {
	Queue q1 = Queue();
	q1.enqueue(10);
	q1.enqueue(20);
	int x;
	q1.dequeue(x);
	cout << q1;
	Queue q2 = Queue(q1);
	q1.makeEmpty();
	cout << q1;
	q2.enqueue(30);
	cout << q2;
	q2.dequeue(x);
	q2.dequeue(x);
	q2.dequeue(x);

	return 0;
}