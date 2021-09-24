/*
 * BST.h
 *
 *  Created on: 28-Oct-2020
 *      Author: Neil
 */

#ifndef BST_H_
#define BST_H_


struct bst_node{
	int data;
	bst_node *lchild, *rchild;
};

class BST {
private:
	bst_node *root;
public:
	BST();

	// functions to build BST

	bst_node* get_node(int);
	bst_node* get_root();
	void set_root(bst_node*);

	void insert(int n);
	bst_node* recurssive_insert(bst_node*, int);

//	void inorder(bst_node*);
//	void postorder(bst_node*);
//	void preorder(bst_node*);

	// functions for traversals

	void recursive_inorder(bst_node*);
	void recursive_preorder(bst_node*);
	void recursive_postorder(bst_node*);
	void level_order(bst_node*);

	// additional functions

	int height(bst_node*);
	void mirror(bst_node*);
	bst_node* copy(bst_node*);

	// searching

	void recurssive_search(bst_node*, int);

	// deleting a node

	bst_node* recurssive_delete(bst_node*, int);
	bst_node* find_minimum(bst_node*);

	virtual ~BST();
};

#endif /* BST_H_ */
