/*
 * ConstructBST.h
 *
 *  Created on: 13-Dec-2020
 *      Author: Neil
 */

#ifndef CONSTRUCTBST_H_
#define CONSTRUCTBST_H_

// Data structure to store a Binary Tree node
struct Node{
	Node *left;
	int data;
	Node *right;
};

class ConstructBST {
	Node* root;
	int *preorder, *postorder, size;
private:
	Node* newNode(int);
public:
	ConstructBST();

	Node* getRoot(); // to allocate memory for new node

	// utility functions to take expression and display it
	void input();
	void display();

	// constructing bst and traversing it
	void inorder(Node*);
	void construct();

	virtual ~ConstructBST();
};

#endif /* CONSTRUCTBST_H_ */
