// ****
// Project: HW3
// Author: Julian Hecker
// Purpose: Updates to Grade hw to use queues and stacks.
// Date: 11/2/2020
// Compiler: MSVS 2017
// Update Information
// ==================
// 9/16/2020
// Update member variables to use pointers and fix methods to work.
// 10/31/2020
// Write a Stack and a Queue of Grade objects, use instead of GradeCollection
// ****

#include <iostream>
using namespace std;
#include "GradeStack.h"
#include "GradeQueue.h"

int main() {	
	// Look nice grades
	Grade g1 = Grade("first", 100);
	Grade g2 = Grade("next", 99);
	Grade g3 = Grade(g1);
	Grade g4;
	
	// Showcasing the Stack
	GradeStack gs = GradeStack();
	GradeStack gs1 = GradeStack(2);
	gs1.push(g1);
	gs1.push(g2);
	cout << gs1;
	GradeStack gs2 = GradeStack(gs1);
	gs2.pop(g4);
	cout << "GS2 Popped: " << g4;
	cout << "GS1 Storage: " << gs1.maxStorage() << "; GS1 Size: " << gs1.size() << "; GS1 Full: " << gs1.isFull() << endl;
	gs1.getTop(g4);
	cout << "GS1 Top: " << g4;
	gs1.clear();
	cout << "GS1 Emptied: " << gs1;
	gs2 = gs1;
	cout << "GS2: " << gs2;
	
	// Showcasing the Queue
	GradeQueue gq = GradeQueue();
	GradeQueue gq1 = GradeQueue();
	// doo allll the enqueueueueueueues
	gq.dequeue(g3);
	gq.enqueue(g3);
	gq.enqueue(g3);
	gq.enqueue(g3);
	gq.enqueue(g3);
	gq.enqueue(g3);
	cout << gq;
	cout << "GQ Size: " << gq.getSize() << endl;
	gq1 = gq;
	cout << gq1;
	GradeQueue gq2 = GradeQueue(gq);
	cout << gq2;

	gq.clear();
	cout << "GQ Cleared! Size: " << gq.getSize() << "; Empty: " << gq.isEmpty() << endl;


	return 0;
	// I just don't understand the error I'm getting down here. The program works flawlessly, but after it's done it gives the oddest error!
}
