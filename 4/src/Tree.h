/*
 * Tree.h
 *
 *  Created on: 21-Oct-2020
 *      Author: Neil
 */

#ifndef TREE_H_
#define TREE_H_

#include<iostream>

struct tree_node{
	char data;
	struct tree_node *lchild, *rchild;
};

class Tree {

	tree_node *root;

public:
	Tree();

	void create_from_postfix(char []);
	void create_from_prefix(char []);

	void recursive_inorder(tree_node*);
	void recursive_preorder(tree_node*);
	void recursive_postorder(tree_node*);

	void inorder(tree_node*);
	void preorder(tree_node*);
	void postorder(tree_node*);

	tree_node* get_root();

	virtual ~Tree();
};

#endif /* TREE_H_ */
