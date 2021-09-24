/*
 * LinkedListADT.h
 *
 *  Created on: 19-Sep-2020
 *      Author: Neil
 */

#ifndef LINKEDLISTADT_H_
#define LINKEDLISTADT_H_

// structure for a node in linked list
struct node{
	int data; // holds the data
	node* next; // pointer to point to the next node
};

// class definition
class LinkedListADT {
	node* head; // pointer of node data type
public:
	LinkedListADT(); //constructor
	node* get_node(int); // function to get a new node to add to the list
	node* get_head();
	void insert_at_front(int); // function to add a new node at the start of the list
	void insert_at_last(int); // function to add a new node at the end of the list
	void insert_after(int, int, node*);
	void delete_at_front(); // function to delete a node at the start of the list
	void delete_at_last(); // function to delete a node at the end of the list
	void delete_after(int);
	void display_forward(); // function to display the linked list in forward direction i.e. from head to tail
	void display_reverse(node*); // function to display the linked list in forward direction i.e. from head to tail
	void reverse_list();
	void search(int);
	void sort();
	virtual ~LinkedListADT(); // destructor
};

#endif /* LINKEDLISTADT_H_ */
