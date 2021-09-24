/*
 * BST.cpp
 *
 *  Created on: 28-Oct-2020
 *      Author: Neil
 */

#include "BST.h"
#include<iostream>
#include<queue>

BST::BST() {
	// TODO Auto-generated constructor stub
	root = NULL;
}

bst_node* BST::get_root(){
	return root;
}

void BST::set_root(bst_node* new_root){
	root = new_root;
}

bst_node* BST::get_node(int n){
	bst_node *temp = new bst_node();
	temp->data = n;
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
}

void BST::insert(int data){
	if(root == NULL)
		root = get_node(data);
	else{
		// x is used for traversal
		// y points to the parent node of x
		bst_node *x = root, *y = NULL;
		while(x != NULL){ // traverse till leaf node
			y = x; // y is set equal to x
			if(data < x->data)
				x = x->lchild;
			else
				x = x->rchild;
		}
		// upon exiting the while loop x will be a NULL node and y will point to the leaf node
		if(data < y->data)
			y->lchild = get_node(data);
		else if(data > y->data)
			y->rchild = get_node(data);
		else if(data == y->data)
			std::cout << "\nDuplicate entries are not allowed.\n";
	}
}

bst_node* BST::recurssive_insert(bst_node* node, int data){
	if(node == NULL) // base condition
		node = get_node(data);
	else if(data < node->data)
		node->lchild = recurssive_insert(node->lchild, data);
	else if(data > node->data)
		node->rchild = recurssive_insert(node->rchild, data);
	else if(data == node->data)
		std::cout << "\nDuplicate entries are not allowed.\n";
	return node;
}

void BST::recursive_inorder(bst_node* node){ // takes root node address as parameter
	if(node != NULL){ // print tree until leaf node is reached

		// inorder is: left -> node -> right

		recursive_inorder(node->lchild);
		std::cout << node->data << " - ";
		recursive_inorder(node->rchild);
	}
}

void BST::recursive_preorder(bst_node* node){ // takes root node address as parameter
	if(node != NULL){ // print tree until leaf node is reached

		// preorder is: node -> left -> right

		std::cout << node->data << " - ";
		recursive_preorder(node->lchild);
		recursive_preorder(node->rchild);
	}
}

void BST::recursive_postorder(bst_node* node){ // takes root node address as parameter
	if(node != NULL){ // print tree until leaf node is reached

		// preorder is: left -> right -> node

		recursive_postorder(node->lchild);
		recursive_postorder(node->rchild);
		std::cout << node->data << " - ";
	}
}

void BST::recurssive_search(bst_node* node, int data){
	if(node == NULL){
		std::cout << "\n\nData not found in the tree\n";
		return;
	}
	else if(data == node->data){ // base condition
		std::cout << node->data << "\n";
		std::cout << "\nData found\n";
		return;
	}
	else if(data < node->data){ // go to left subtree
		std::cout << node->data << " - ";
		recurssive_search(node->lchild, data);
	}
	else if(data > node->data){ // go to right subtree
		std::cout << node->data << " - ";
		recurssive_search(node->rchild, data);
	}
}

void BST::level_order(bst_node *root){
	// base case
	if (root == NULL)
		return;
	// create an empty queue for level order traversal
	std::queue<bst_node*> q;
	// enqueue root
	q.push(root);

	while (q.empty() == false){
		// print front of queue and remove it from queue
		bst_node *node = q.front();
		std::cout << node->data << " - ";
		q.pop();

		// enqueue left child
		if (node->lchild != NULL)
		q.push(node->lchild);

		// enqueue right child
		if (node->rchild != NULL)
		q.push(node->rchild);
	}
}

int BST::height(bst_node *node){
	if (node == NULL)
		return 0;
	else{
		int l_subtree_depth = height(node->lchild);
		int r_subtree_depth = height(node->rchild);
		if (l_subtree_depth > r_subtree_depth)
			return(l_subtree_depth + 1);
		else return(r_subtree_depth + 1);
	}
}

void BST::mirror(bst_node* node){
	if (node == NULL) // base condition
		return;
	else{
		bst_node* temp; // variable for swapping
		mirror(node->lchild);
		mirror(node->rchild);
		// swap the pointers in this node
		temp = node->lchild;
		node->lchild = node->rchild;
		node->rchild = temp;
	}
}

bst_node* BST::find_minimum(bst_node* node){
	if(node->lchild == NULL)
		return node;
	else
		return find_minimum(node->lchild);
}

bst_node* BST::recurssive_delete(bst_node* node, int data){
	// base case
	if (node == NULL)
		return node;

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	else if (data < node->data)
		node->lchild = recurssive_delete(node->lchild, data);

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (data > node->data)
		node->rchild = recurssive_delete(node->rchild, data);

	// if key is same as root's key, then This is the node
	// to be deleted
	else if(data == node->data){
		// node with no child
		if (node->lchild == NULL && node->rchild == NULL) {
			delete node;
			node = NULL;
		}
		// node with one child
		else if (node->lchild == NULL) {
			bst_node *temp = node;
			node = node->rchild;
			delete temp;
		}
		else if (node->rchild == NULL) {
			bst_node *temp = node;
			node = node->lchild;
//			std::cout << "\nDeleting node...\n";
			delete temp;
		}

		else{
			// node with two children: Get the inorder successor (smallest
			// in the right subtree)
			bst_node* temp = find_minimum(node->rchild);

			// Copy the inorder successor's content to this node
			node->data = temp->data;

			// Delete the inorder successor
			node->rchild = recurssive_delete(node->rchild, temp->data);
		}
	}
	return node;
}

bst_node* BST::copy(bst_node* root){
	if(root == NULL)
		return NULL;
	// create a copy of root node
	bst_node* new_node = get_node(root->data);
	// Recursively create clone of left and right sub tree
	new_node->lchild = copy(root->lchild);
	new_node->rchild = copy(root->rchild);
	// Return root of cloned tree
	return new_node;
}

BST::~BST() {
	// TODO Auto-generated destructor stub
}

