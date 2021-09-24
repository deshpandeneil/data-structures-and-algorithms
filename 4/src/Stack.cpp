/*
 * Stack.cpp
 *
 *  Created on: 23-Sep-2020
 *      Author: Neil
 */

#include "Stack.h"
#include <iostream>

template <class T>
Stack<T>::Stack() {
	// TODO Auto-generated constructor stub
	top = NULL; // set head to point at ' ' on creation of new list
}

template <class T>
bool Stack<T>::is_empty(){
	if(top == NULL)
		return true;
	return false;
}

// function to get a new node to ad to the list
// takes element to be added as parameter
template <class T>
node<T>* Stack<T>::get_node(T n){
	node<T>* temp; // create a temporary element to store the new node
	temp = new(node<T>); // get a new address for the node
	temp->data = n; // set the data for the new node
	temp->next = NULL; // point to ' ' by default
	return temp; // return the new node
}

template <class T>
void Stack<T>::push(T a){
	node<T>* temp = get_node(a); // create a temporary element of node type to store node received form function
	temp->next = top; // new node points to current start of node
	top = temp; // head points to address of new node
//	std::cout << "\nPush successful.\n"; // success message
//	display();
}

template <class T>
void Stack<T>::pop(){
	node<T>* temp;
//	char popped;
	temp = top; // set temp to point at start of list
//	popped = top->data;
	top = top->next; // change the head address to point at the second node
	delete(temp); // delete node with temp as address i.e. first element of the list
//		std::cout << "\nPop successful.\n";
}

template <class T>
T Stack<T>::peep(){
	if(top == NULL) // check if list is empty
//		std::cout << "\nStack is empty\n";
		return NULL;
	else{
//		std::cout << "\n(" << top->data << " | " << top->next << ")\n"; // display data and next address of top element
		return top->data;
	}
}

template <class T>
void Stack<T>::display(){
	node<T>* temp;
	temp = top;
	if(top == NULL){ // check if stack is empty
		std::cout << "\nStack is empty.\n";
	}else{
		std::cout << "\nStack is:\n\n";
		while(temp != NULL){ // traverse through list till the end
			std::cout << " | " << temp->data << " | " << std::endl; // display details
			temp = temp->next; // set pointer to next node
		}
		std::cout << "\n";
	}
}

template <class T>
Stack<T>::~Stack() {
	// TODO Auto-generated destructor stub
}

