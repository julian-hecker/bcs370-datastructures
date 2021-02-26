#pragma once
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

class Tree {
private:
	Node* root;
	void insert(Node*& tree, int item);
	void getPred(Node* tree, int& data);
	void remove(Node*& tree);
	void findDelete(Node*& tree, int target);
	void inorder(Node* tree);
	void preorder(Node* tree);
	void postorder(Node* tree);
	bool hasItem(Node* tree, int target);
	void empty(Node*& tree);
public:
	// Constructors
	Tree();
	~Tree();
	// Transformers
	void addItem(int item);
	void deleteItem(int target);
	void empty();
	// Observers
	bool hasItem(int target);
	int sum();
	// Display
	void inorder();
	void preorder();
	void postorder();
};
