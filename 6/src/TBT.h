/*
 * TBT.h
 *
 *  Created on: 11-Nov-2020
 *      Author: Neil
 */

#ifndef TBT_H_
#define TBT_H_

struct tbt_node{
	int data;
	tbt_node *llink, *rlink;
	bool lthread, rthread;
};

class TBT {

	tbt_node *head; // root node

public:
	TBT();

	tbt_node* get_node(int); // get a new node for data
	void create(); // create a tbt
	void insert(); // insert data in tbt

	// traversals

	void inorder();
	void preorder();

	virtual ~TBT();
};

#endif /* TBT_H_ */
