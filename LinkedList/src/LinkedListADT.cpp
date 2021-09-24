/*
 * LinkedListADT.cpp
 *
 *  Created on: 19-Sep-2020
 *      Author: Neil
 */

#include <iostream>
#include "LinkedListADT.h"

// constructor
LinkedListADT::LinkedListADT() {
	// TODO Auto-generated constructor stub
	head = NULL; // set head to point at NULL on creation of new list

}

// function to get a new node to ad to the list
// takes element to be added as parameter
node* LinkedListADT::get_node(int n){
	node* temp; // create a temporary element to store the new node
	temp = new(node); // get a new address for the node
	temp->data = n; // set the data for the new node
	temp->next = NULL; // point to NULL by default
	return temp; // return the new node
}

node* LinkedListADT::get_head(){
	return head;
}

void LinkedListADT::insert_at_front(int n){
	node* temp = get_node(n); // pass the input value to the get node function and receive new node address in variable
	temp->next = head; // let the new node point towards start of list
	head = temp; // set head to point at the new node
}

void LinkedListADT::insert_at_last(int n){
	node* temp;
	temp = head; // set address of variable to the address of head
	if(head == NULL){ // if the list is empty just call the get_node() function
		head = get_node(n);
		return; // exit function
	}
	while(temp->next != NULL){ // traverse through the list until last node is reached
		temp = temp->next;
	}
	temp->next = get_node(n); // get a new node and change address pointer of previous node (append new node)
}

void LinkedListADT::insert_after(int previous_data, int new_data, node* x){

	// we will traverse the list till the previous and then insert the new node

	if(x->data == previous_data){ // base condition
		node* temp;
		temp = get_node(new_data); // getting the new node
		temp->next = x->next; // new node points to the next node of previous node
		x->next = temp; // previous node points to the new node
		return; // deallocate stack
	}
	insert_after(previous_data, new_data, x->next); // recursive call to the same function for traversing
}

void LinkedListADT::display_forward(){
	node* temp;
	temp = head; // set variable to starting point
	if(head == NULL){
		std::cout << "\nList is empty.\n";
	}else{
		std::cout << "\nList is: ";
		while(temp != NULL){ // traverse through all nodes
			std::cout << "(" << temp->data << " | " << temp->next << "), "; // display data and address of each node
			temp = temp->next; // go to next node
		}
		std::cout << "\n";
	}
}

void LinkedListADT::display_reverse(node* x){ // takes a node pointer as parameter
	if(head == NULL)
		std::cout << "\nThe list is empty\n";
	else{
		if(x == NULL){ // base condition
			return; //exit
		}
		display_reverse(x->next); // call recursively
		std::cout << "(" << x->data << " | " << x->next << "), ";
	}
}

void LinkedListADT::delete_at_front(){
	node* temp;
	if(head == NULL) // check if list is empty
		std::cout << "\nList is already empty";
	else{
		temp = head; // set temp to point at head
		head = head->next; // set head to point at second node in the list
		delete(temp); // delete first node (free memory)
		std::cout << "\nDeletion successful";
	}

}

void LinkedListADT::delete_at_last(){
	if(head == NULL) // check if list is empty
			std::cout << "\nList is already empty";
	else{
		node* temp;
		temp = head; // set temp to point at head
		while(temp->next->next != NULL){ // traverse through all nodes till the second last node
			temp = temp->next;
		}
		delete(temp->next); // delete the last node
		temp->next = NULL; // set the new last node to point at NULL to indicate end of list
		std::cout << "\nDeletion successful\n";
	}

}

void LinkedListADT::delete_after(int data){
	if(head == NULL) // check if list is empty
		std::cout << "\nList is already empty"; // if yes display message
	else{

		// to delete a node after a certain node, we will traverse the list till the previous node

		node* previous_node = head, *temp; // variables for traversing and deleting the node
		while(previous_node->data != data){ // traverse till previous node
			previous_node = previous_node->next;
		}
		temp = previous_node->next; // temp points to the node to be deleted
		previous_node->next = previous_node->next->next; // previous node points to the node after the node to be deleted
		delete(temp); // delete the node
		std::cout << "\nDeletion successful\n"; // display success message
	}

}

void LinkedListADT::reverse_list(){
	if(head->next == NULL)
		return;
	node* current_node = head, *previous_node = NULL, *next_node = NULL;
	while (current_node != NULL) { // loop till end of list is reached
		next_node = current_node->next; // go to the next node of the current node and store as next_node
		current_node->next = previous_node; // reverse the direction of next node pointer
		previous_node = current_node; // the node whose node pointer was just reversed now becomes the previous node
		current_node = next_node; // current node now becomes the next node
	}
	head = previous_node; // the last node of the list now becomes the head of the list
}

void LinkedListADT::search(int x){
	int count = 0;
	while(head != NULL){ // traverse till end of list
		if(x == head->data){ // compare data of each node
			std::cout << "\nElement " << x << " found at index: " << count << "\n";
			return; // exit function when element found
		}
		head = head->next; // move to next node
		count++;
	}
	std::cout << "\nElement not found\n"; // if reached here, element not found
}

void LinkedListADT::sort(){
	if(head==NULL){
		std::cout << "\nList is already empty\n";
		return;
	}
	node* ptr; //for passes
	node* temp; //for comparing elements
	ptr = head;
	while(ptr != NULL) { //loop for pass
		temp = ptr->next;
		while(temp != NULL){
			if(ptr->data > temp->data) { //comparing the values
				int data = ptr->data; //swapping the both values
				ptr->data = temp->data;
				temp->data = data;
			}
			temp = temp->next; //moving to next node to compare
		}
		ptr = ptr->next; //moving to next pass
	}
	std::cout << "\nList has been sorted\n";
}

LinkedListADT::~LinkedListADT() {
	// TODO Auto-generated destructor stub
}
