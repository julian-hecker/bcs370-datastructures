#include "Tree.h"

int main() {
	Tree t = Tree();

	t.addItem(50);
	t.addItem(25);
	t.addItem(100);

	t.inorder();

	t.deleteItem(50);

	t.inorder();

	t.addItem(200);
	t.addItem(10);
	t.addItem(20);
	t.addItem(30);
	t.addItem(60);
	t.addItem(300);


	t.inorder();
	t.preorder();
	t.postorder();


	return 0;
}