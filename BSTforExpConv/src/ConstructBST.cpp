/*
 * ConstructBST.cpp
 *
 *  Created on: 13-Dec-2020
 *      Author: Neil
 */

#include "ConstructBST.h"
#include<iostream>
#include<stack>

using namespace std;

ConstructBST::ConstructBST() {
	// TODO Auto-generated constructor stub
	// initialize all data members
	root = NULL;
	preorder = NULL;
	postorder = NULL;
	size = 0;
}

void ConstructBST::input(){
	cout << "\nEnter number of nodes in BST: ";
	do{ // loop till correct data type is not entered
		cin >> size;
		if(!cin.good() || size < 0){ // only +ve integers
			cout << "\nPlease enter +ve integer: ";
			cin.clear();
			cin.ignore();
		}
		else
			break;
	} while(true);

	preorder = new int [size]; // allocate memory for expression arrays
	postorder = new int [size];

	cout << "\n\nENTER PREORDER\n\n";
	for(int i = 0; i < size; i++){ // take input for expression
		cout << "Enter preorder node " << i + 1 << ": ";
		do{ // loop till correct data type is not entered
			cin >> preorder[i];
			if(!cin.good() || preorder[i] < 0){ // only +ve integers
				cout << "\nPlease enter +ve integer: ";
				cin.clear();
				cin.ignore();
			}
			else
				break;
		} while(true);
	}

	cout << "\n\nENTER POSTORDER\n\n";
	for(int i = 0; i < size; i++){ // take input for expression
		cout << "Enter postorder node " << i + 1 << ": ";
		do{ // loop till correct data type is not entered
			cin >> postorder[i];
			if(!cin.good() || postorder[i] < 0){ // only +ve integers
				cout << "\nPlease enter +ve integer: ";
				cin.clear();
				cin.ignore();
			}
			else
				break;
		} while(true);
	}
}

void ConstructBST::display(){
	if(preorder == NULL && postorder == NULL){ // check if expressions have been entered
		cout << "\nPlease enter expressions first\n";
		return;
	}
	cout << "\n\nPREORDER\n\n";
	for(int i = 0; i < size; i++){
		cout << preorder[i] << " - "; // display
	}

	cout << "\n\nENTER POSTORDER\n\n";
	for(int i = 0; i < size; i++){
		cout << postorder[i] << " - "; // display
	}
}

Node* ConstructBST::getRoot(){
	return root;
}

Node* ConstructBST::newNode(int data){
	Node *temp = new Node;
	temp->data = data; // assign data to node data
	temp->left = temp->right = NULL; // set left - right children as null
	return temp; // return new node
}

void ConstructBST::construct(){
	if(preorder == NULL && postorder == NULL){ // construct only if expressions have been entered
		cout << "\nPlease enter expressions first\n";
		return;
	}
	stack<Node*> s; // utility stack object
	root = newNode(preorder[0]); // set root
	s.push(root);
	for (int i = 1, j = 0; i < size; ++i){
		// subtree for element present at post[j]
		while (s.top()->data == postorder[j]){
			s.pop();
			++j;
		}
		//subtree of element of top of stack
		Node *temp = newNode(preorder[i]);
		if (s.top()->left == NULL)
			s.top()->left = temp;
		else
			s.top()->right = temp;
		s.push(temp);
	}
	cout << "\nTree has been constructed!\n";
}

void ConstructBST::inorder(Node* root){
	if (root == NULL)
		return;
	else{
		inorder(root->left); // go to left most node
		cout << root->data << " -> "; // display data
		inorder(root->right); // go to right node
	}
}

ConstructBST::~ConstructBST() {
	// TODO Auto-generated destructor stub
}

