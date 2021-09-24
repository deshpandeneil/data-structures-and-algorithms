/*
 * Stack.h
 *
 *  Created on: 27-Sep-2020
 *      Author: Neil
 */

#ifndef STACK_H_
#define STACK_H_

#define SIZE 10 // set the size of array
#include <iostream>

class Stack {

	// declare data members of class
private:
	std::string arr[SIZE]; // define an array of strings of length SIZE
	int top;// variable which points to the top of stack

	// declare member functions of class
public:
	Stack();
	bool is_full();
	bool is_empty();
	void push(char);
	void pop();
	std::string peep();
	void display();
	virtual ~Stack();
};

#endif /* STACK_H_ */
