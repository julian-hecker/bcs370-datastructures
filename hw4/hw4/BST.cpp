// ****
// File: BST.cpp
// Purpose: Define methods for the Grade Binary Search Tree class
// Author: Julian Hecker
// Compiler: MSVS 2017
// Date: 11/26/2020
// ****

#include "BST.h"


// Constructors
// Default Constructor
BST::BST() {
	root = nullptr;
}
// Copy Constructor
BST::BST(const BST& rhs) {
	root = copyHelper(rhs.root);
}
Node* BST::copyHelper(const Node* node) {
	// http://www.cplusplus.com/forum/windows/59865/
	if (node == nullptr) {
		return nullptr;
	}
	Node *copy = new Node;
	copy->data = node->data;
	copy->left = copyHelper(node->left);
	copy->right = copyHelper(node->right);
	return copy;
}

// Destructor
BST::~BST() {
	clear();
}


// Methods
// Clear: removes all elements
// Complexity: Best & Worst Case: O(n), visits all nodes
void BST::clear() {
	clear(root);
	root = nullptr;
}
void BST::clear(Node*& tree) {
	if (tree != nullptr) {
		clear(tree->left);
		clear(tree->right);
		delete tree;
	}
}

// Size: returns the number of elements in the tree
// Complexity: Best & Worst Case: O(n), visits all nodes
int BST::size() {
	return size(root);
}
int BST::size(Node* tree) {
	if (tree == nullptr) { // Base Case
		return 0;
	}
	else { // Recursive Case
		return size(tree->left) + size(tree->right) + 1;
	}
}

// Add: Inserts new item into BST
// Complexity: Worst Case: O(n); Best Case: O(log n);
void BST::add(Grade e) {
	add(root, e);
}
void BST::add(Node*& tree, Grade e) {
	if (tree == nullptr) { // Insert here!
		tree = new Node;
		tree->right = nullptr;
		tree->left = nullptr;
		tree->data = e;
	}
	else if (e < tree->data) {
		add(tree->left, e);
	}
	else {
		add(tree->right, e);
	}
}

// Preorder: Traverses BST in preorder fashion
// Complexity: Best & Worst Case: O(n), visits all nodes
void BST::preorder() {
	preorder(root);
	cout << endl;
}
void BST::preorder(Node* tree) {
	if (tree != nullptr) {
		cout << tree->data.getName() << " ";
		preorder(tree->left);
		preorder(tree->right);
	}
}

// Inorder: Traverses BST in inorder fashion
// Complexity: Best & Worst Case: O(n), visits all nodes
void BST::inorder() {
	inorder(root);
	cout << endl;
}
void BST::inorder(Node* tree) {
	if (tree != nullptr) {
		inorder(tree->left);
		cout << tree->data.getName() << " ";
		inorder(tree->right);
	}
}

// Postorder: Traverses BST in postorder fashion
// Complexity: Best & Worst Case: O(n), visits all nodes
void BST::postorder() {
	postorder(root);
	cout << endl;
}
void BST::postorder(Node* tree) {
	if (tree != nullptr) {
		postorder(tree->left);
		postorder(tree->right);
		cout << tree->data.getName() << " ";
	}
}

// Get Score: retrieves an item by name
// Complexity: Worst Case: O(n); Best Case: O(log n);
bool BST::getScore(string name, double& score) {
	return getScore(root, name, score);
}
bool BST::getScore(Node* tree, string name, double& score) {
	if (tree == nullptr) { // No more nodes
		return false;
	}
	Grade temp = Grade(name, 0);
	if (temp < tree->data) { 
		getScore(tree->left, name, score);
	}
	else if (temp > tree->data) {
		getScore(tree->right, name, score);
	}
	else { // Item found!
		score = tree->data.getScore();
		return true;
	}
}


// Overloads
// Assignment Override (Deep Copy) 
BST& BST::operator=(const BST& rhs) {
	root = copyHelper(rhs.root);
	return *this;
}


// Ostream Override 
void ostreamHelper(ostream& os, Node* node) {
	if (node != nullptr) {
		ostreamHelper(os, node->left);
		os << node->data << " ";
		ostreamHelper(os, node->right);
	}
}

ostream& operator<<(ostream& os, const BST& rhs) {
	ostreamHelper(os, rhs.root);
	os << endl;
	return os;
}
