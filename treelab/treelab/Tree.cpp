#include "Tree.h"

// Private Methods, Helpers
void Tree::insert(Node*& tree, int item) {
	if (tree == nullptr) {
		tree = new Node;
		tree->right = nullptr;
		tree->left = nullptr;
		tree->data = item;
	}
	else if (item < tree->data) {
		insert(tree->left, item);
	}
	else {
		insert(tree->right, item);
	}
}

void Tree::getPred(Node* tree, int& data) {
	while (tree->right != nullptr) {
		tree = tree->right;
	}
	data = tree->data;
}

void Tree::remove(Node*& tree) {
	int data;
	Node* temp;
	temp = tree;
	if (tree->left == nullptr) {
		tree = tree->right;
		delete temp;
	}
	else if (tree->right == nullptr) {
		tree = tree->left;
		delete temp;
	}
	else {
		getPred(tree->left, data);
		tree->data = data;
		findDelete(tree->left, data);
	}
}

void Tree::findDelete(Node*& tree, int target) {
	if (target < tree->data) {
		findDelete(tree->left, target);
	}
	else if (target > tree->data) {
		findDelete(tree->right, target);
	}
	else {
		remove(tree);
	}
}

void Tree::inorder(Node* tree) {
	if (tree != nullptr) {
		inorder(tree->left);
		cout << tree->data << " ";
		inorder(tree->right);
	}
}

void Tree::preorder(Node* tree) {
	if (tree != nullptr) {
		cout << tree->data << " ";
		preorder(tree->left);
		preorder(tree->right);
	}
}


void Tree::postorder(Node* tree) {
	if (tree != nullptr) {
		postorder(tree->left);
		postorder(tree->right);
		cout << tree->data << " ";
	}
}

bool Tree::hasItem(Node* tree, int target) {
	// Base Cases
	if (tree == nullptr) {
		return false;
	}
	if (tree->data == target) {
		return true;
	}
	// Recursive Cases
	if (target < tree->data) {
		return hasItem(tree->left, target);
	}
	else {
		return hasItem(tree->right, target);
	}
}

void Tree::empty(Node*& tree) {
	if (tree != nullptr) {
		empty(tree->left);
		empty(tree->right);
		delete tree;
	}
}

// Constructors
Tree::Tree() {
	root = nullptr;
}

Tree::~Tree() {
	empty();
}

// Transformers
void Tree::addItem(int item) {
	insert(root, item);
}

void Tree::deleteItem(int target) {
	findDelete(root, target);
}

void Tree::empty() {
	empty(root);
	root = nullptr;
}

// Observers
bool Tree::hasItem(int target) {
	return hasItem(root, target);
}

int Tree::sum() {
	return 0;
}

void Tree::inorder() {
	inorder(root);
	cout << endl;
}

void Tree::preorder() {
	preorder(root);
	cout << endl;
}

void Tree::postorder() {
	postorder(root);
	cout << endl;
}

