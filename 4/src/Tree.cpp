/*
 * Tree.cpp
 *
 *  Created on: 21-Oct-2020
 *      Author: Neil
 */

#include "Tree.h"
#include "Stack.h"
#include "Stack.cpp"
#include<iostream>
#include<cstring>

Tree::Tree() {
	// TODO Auto-generated constructor stub
	root = NULL;
}

void Tree::create_from_postfix(char input_exp[]){
	Stack<tree_node*> s; // stack for storing node addresses
	for(int i = 0; i < strlen(input_exp); i++){ // loop through all char of the array
		if(isalpha(input_exp[i])){ // if char is number -> leaf nodes
			tree_node *temp = new tree_node;
			temp->data = input_exp[i]; // node has data
			temp->lchild = NULL; // no children
			temp->rchild = NULL;
			s.push(temp); // push node on stack
		}
		else{ // if char is operator -> internal nodes
			tree_node *temp = new tree_node;
			temp->data = input_exp[i];
			temp->rchild = s.peep(); // top of stack will be right operand since input exp is postfix
			s.pop();
			temp->lchild = s.peep();
			s.pop();
			s.push(temp); // push address of new 'attached' tree
		}
//		i++;
	}
	// when reached here, only one element remains in stack
	root = s.peep(); // it is the root address
	s.pop();
}

void Tree::recursive_inorder(tree_node* node){ // takes root node address as parameter
	if(node != NULL){ // print tree until leaf node is reached

		// inorder is: left -> node -> right

		recursive_inorder(node->lchild);
		std::cout << node->data;
		recursive_inorder(node->rchild);
	}
}

void Tree::recursive_preorder(tree_node* node){ // takes root node address as parameter
	if(node != NULL){ // print tree until leaf node is reached

		// preorder is: node -> left -> right

		std::cout << node->data;
		recursive_preorder(node->lchild);
		recursive_preorder(node->rchild);
	}
}

void Tree::recursive_postorder(tree_node* node){ // takes root node address as parameter
	if(node != NULL){ // print tree until leaf node is reached

		// preorder is: left -> right -> node

		recursive_postorder(node->lchild);
		recursive_postorder(node->rchild);
		std::cout << node->data;
	}
}

void Tree::inorder(tree_node* node){
	Stack<tree_node*> s;
	if(node == NULL){ // check if empty
		std::cout << "\nTree is empty\n";
		return;
	}

//	       *
//	      / \
//	     +   c
//	    / \
//	   a   b


	// inorder is: left -> subtree root -> right

	while(node != NULL){ // traverse the left children till leaf node
		s.push(node); // push every node
		node = node->lchild;
	}
	while(!s.is_empty()){
		node = s.peep(); // top of stack will be operand
		s.pop();
		std::cout << node->data; // print subtree root data
		node = node->rchild; // go to right child
		while(node != NULL){ // traverse the left children of every right child till leaf node
			s.push(node);
			node = node->lchild;
		}
	}
}

void Tree::preorder(tree_node* node){
	Stack<tree_node*> s;
	if(node == NULL){
		std::cout << "\nTree is empty\n";
		return;
	}

//	       *
//	      / \
//	     +   c
//	    / \
//	   a   b

	// Root -> Left -> Right

	s.push(node); // push root
	while(!s.is_empty()){
		node = s.peep();
		s.pop();
		std::cout << node->data;
		if(node->rchild != NULL)
			s.push(node->rchild);
		if(node->lchild != NULL)
			s.push(node->lchild);
	}
}

void Tree::postorder(tree_node* node){
	Stack<tree_node*> s1;
	Stack<tree_node*> s2;
	if(node == NULL){
		std::cout << "\nTree is empty\n";
		return;
	}

	// Left -> Right -> Root

	s1.push(node);
	while(!s1.is_empty()){
		node = s1.peep(); // exp in reverse order
		s1.pop();
//		std::cout << node->data;
		s2.push(node); // store in another stack
		if(node->lchild != NULL)
			s1.push(node->lchild);
		if(node->rchild != NULL)
			s1.push(node->rchild);
	}
	while(!s2.is_empty()){ // empty second stack to get proper order
		node = s2.peep();
		s2.pop();
		std::cout << node->data;
	}
}

void Tree::create_from_prefix(char input_exp[]){
	Stack<tree_node*> s;
	int i = strlen(input_exp) - 1; // i set to index of last char in char array
	while(i >= 0){ // loop from to last to first index
		if(isalpha(input_exp[i])){ // if char is number -> leaf nodes
			tree_node *temp = new tree_node;
			temp->data = input_exp[i]; // node has data
			temp->lchild = NULL; // no children
			temp->rchild = NULL;
			s.push(temp);
		}
		else{ // if char is operator -> internal nodes
			tree_node *temp = new tree_node;
			temp->data = input_exp[i]; // data is operator
			temp->lchild = s.peep(); // top of stack will be left operand since input exp is prefix and we're scanning from right to left
			s.pop();
			temp->rchild = s.peep();
			s.pop();
			s.push(temp); // push address of new 'attached' tree
		}
		i--;
	}
	// when reached here, only one element remains in stack
	root = s.peep(); // it is the root address
	s.pop();
}

tree_node* Tree::get_root(){
	return root;
}

Tree::~Tree() {
	// TODO Auto-generated destructor stub
}
