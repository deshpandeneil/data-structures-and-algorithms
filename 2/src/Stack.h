/*
 * Stack.h
 *
 *  Created on: 07-Oct-2020
 *      Author: Neil
 */

#ifndef STACK_H_
#define STACK_H_

template <typename T>

struct node{
	T data; // holds the data
	node<T>* next; // pointer to point to the next node
};

template <class T>

class Stack {
private:
	node<T>* top; // pointer of node data type
public:
	Stack();
	node<T>* get_node(T); // function to get a new node to add to the list
	bool is_empty();
	void push(T);
	void pop();
	T peep();
	void display();
	virtual ~Stack();
};

#endif /* STACK_H_ */
