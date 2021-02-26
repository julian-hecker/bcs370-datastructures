// ****
// File: BST.h
// Purpose: Outline members and methods of a Binary Search Tree of Grades
// Author: Julian Hecker
// Compiler: MSVS 2017
// Date: 11/26/2020
// ****

#pragma once
#include <iostream>
using namespace std;
#include "Grade.h"

struct Node {
	Grade data;
	Node* left;
	Node* right;
};

class BST {
private:
	Node* root;
	// Helper Functions
	int size(Node* tree);
	void add(Node*& tree, Grade e);
	void clear(Node*& tree);
	void preorder(Node* tree);
	void inorder(Node* tree);
	void postorder(Node* tree);
	bool getScore(Node* tree, string name, double& score);
	Node* copyHelper(const Node* node);
	friend void ostreamHelper(ostream& os, Node* node);
public:
	// Constructors
	BST();
	BST(const BST& rhs);
	~BST();
	// Methods
	void clear();
	int size();
	void add(Grade e);
	void preorder();
	void inorder();
	void postorder();
	bool getScore(string name, double& score);
	// Overloads
	BST& operator=(const BST& rhs);
	friend ostream& operator<<(ostream& os, const BST& rhs);
};



