/*
 * TBT.cpp
 *
 *  Created on: 11-Nov-2020
 *      Author: Neil
 */

#include "TBT.h"
#include<iostream>

TBT::TBT() {
	// TODO Auto-generated constructor stub
	head = get_node(-1);
	head->llink = head->rlink = head;
	head->lthread = head->rthread = true;

}

tbt_node* TBT::get_node(int data){
	tbt_node *temp = new tbt_node;
	temp->llink = temp->rlink = NULL;
	temp->lthread = temp->rthread = false;
	temp->data = data;
	return temp;
}

void TBT::create(){
	tbt_node *temp1,*temp2; //take 2 pointers
	int x,choice; //for value and choice
	do{
		std::cout << "Enter the node value: \n";
		std::cin >> x; //accept the value of node
		if(!std::cin.good()){
			std::cout << "\nPlease enter an integer\n";
			std::cin.clear();
			std::cin.ignore();
		} else
			break;
	} while(true);

	//create root node

	if(head->llink == head){
		std::cout << "\n\nhead->llink == head ---> root node to be created\n\n";
		//root node to be created
		temp1 = get_node(x); //set 1st pointer to the given data node
		std::cout << "Creating root node with entered data...\n\n";
		temp1->llink = temp1->rlink = head; //link it to the head
		temp1->lthread = temp1->rthread = true; //make both left and right pointer as true as no child
		head->llink = temp1; //now link head to temp1
		head->lthread = false; // make the lthread as false as root node gets created
		std::cout << "Root node created!\n\n";
	}
	else{ //if root node is already present
		temp1 = head->llink; //point temp1 to root node
		do{ //keep repeating until insertion takes place
			std::cout << "\nCurrent Node: " << temp1->data; //print current data
			do{
				std::cout << "\n\nWhere to insert new node?\n1. Left\n2. Right" << "\nPlease enter your choice: ";
				std::cin >> choice; //take choice from user where to enter new node
				if(!std::cin.good()){
					std::cout << "\nPlease enter an integer\n";
					std::cin.clear();
					std::cin.ignore();
				} else
					break;
			} while(true);
			if(choice == 1){ //for left link
				if(temp1->lthread){ //check if left subtree is present
					//this will get executed if no subchild and a node is inserted
					std::cout << "\nEnd of subtree reached, inserting new node...\n";
					temp2 = get_node(x); //take 2nd pointer and create node for insertion of new element
					temp2->llink = temp1->llink; //pointing to predecessor
					temp2->rlink = temp1; //points to successor
					temp2->rthread = temp2->lthread = true; //set both threads as true as no subchild
					temp1->llink = temp2; //parent points to the new created node
					temp1->lthread = false; //set thread as false as new node is created
					std::cout << "\nNew node inserted!\n";
					break;
				}
				else
					temp1 = temp1->llink; //if not null go ahead till u find insertion point
			}
			else{ //for right link insertion
				if(temp1->rthread){ //check if right subtree is present
					std::cout << "\nEnd of subtree reached, inserting new node...\n";
					temp2 = get_node(x); //create new node with insertion data with 2nd pointer
					temp2->rlink = temp1->rlink; //points to successor
					temp2->llink = temp1; //points to predecessor
					temp2->lthread = temp2->rthread = true; //set both as true
					temp1->rlink = temp2; //link parent to child
					temp1->rthread = false;
					std::cout << "\nNew node inserted!\n";
					break;
				}
				else
					temp1 = temp1->rlink;//if not null go ahead till you find insertion point
			}
		}while(true);

	}
}

void TBT::inorder(){
	tbt_node *temp = head->llink;//take a pointer and point it to head
	if(temp == head){//if head is null print empty tree
		std::cout<<"\nTree is empty\n";
		return;
	}
	std::cout << "\n\nINORDER TRAVERSAL: \n\n";
	while(!(temp->lthread))//traverse till the last left node with no child
		temp = temp->llink;
	while(temp != head)
	{
		std::cout << " - " << temp->data;//print the data of the node
		if(temp->rthread)//if no rchild to  successor
			temp = temp->rlink;
		else
		{//if rchild present point the temp to it
			temp = temp->rlink;
			while(!(temp->lthread) && (temp != head))//if that right child also has further subtree traverse it
				temp = temp->llink;
		}
	}
}

void TBT::preorder(){
	tbt_node *temp = head->llink;//take a pointer and point it to head
	if(temp == head){//if head is null print empty tree
		std::cout<<"\nTree is empty\n";
		return;
	}
	std::cout << "\n\nPREORDER TRAVERSAL: \n\n";
	while(temp != head){//if head is not null
		std::cout << " - " << temp->data;//print the data
		if(!(temp->lthread)){//if left child is present
			temp = temp->llink;//point temp to left child and itrate the llop again
			continue;

		}
		else{//if no left child go to right subtree
			while(temp->rthread && temp!=head){//if no subchild
				temp = temp->rlink;//point to successor
			}
		}
		if(!(temp->rthread) && (temp != head)){//if right child is present
			temp = temp->rlink;//point to the next node
		}
	}
}

TBT::~TBT() {
	// TODO Auto-generated destructor stub
}
