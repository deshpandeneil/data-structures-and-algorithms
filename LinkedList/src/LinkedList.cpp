//============================================================================
// Name        : LinkedList.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "LinkedListADT.h"
using namespace std;

int menu(){
	int option;
	bool flag;
	do{
		cout << "\nMenu\n\n1. Insert at front\n2. Insert at last\n3. Insert after\n4. Delete at front\n5. Delete at last\n6. Delete after\n7. Display forward\n8. Display reverse\n9. Revert the linked list\n10. Search\n11. Sort\n12. Exit\n\nEnter the serial number of the operation you want to perform: ";
		cin >> option;
		if(cin.good()){ // check if there was an error while taking input
			flag = false; // if no set flag to exit do while loop
		}
		else{
			flag = true; // if yes set flag to re iterate do while loop
			cout << "\nPlease enter an integer.\n";
			cin.clear();
			cin.ignore();
		}
	}while(flag == true); // iterate till cin is a success
	return option;
}

int main() {
	LinkedListADT list; // instance of ADT
	LinkedListADT list2; // instance of ADT
	int option; // variable to take user input
	option = menu(); // call menu function
	if(option == 10){
		cout << "\nHope you liked this demo\n";
		return 0;
	}
	do{
		switch(option){ // switch user input and call appropriate function
		case 1:{
			int a;
			bool flag = false; // flag variable for validations
			do{
				cout << "\nEnter the value you would like to enter: ";
				cin >> a;
				if(cin.good()){ // check if cin was successful
					flag = false; // set flag to exit do while loop
				} else { // if cin failed
					flag = true; // set flag to reiterate do while loop
					cout << "\nPlease enter an integer.\n";
					cin.clear();
					cin.ignore();
				}
			}while(flag == true); // repeat while flag is set to true
			list.insert_at_front(a);
			break;
		}
		case 2:{
			int n;
			bool flag = false; // flag variable for validations
			do{
				cout << "\nEnter the value you would like to enter: ";
				cin >> n;
				if(cin.good()){ // check if cin was successful
					flag = false; // set flag to exit do while loo
				} else { // if cin failed
					flag = true; // set flag to reiterate do while loop
					cout << "\nPlease enter an integer.\n";
					cin.clear();
					cin.ignore();
				}
			}while(flag == true); // repeat while flag is set to true
			list.insert_at_last(n);
			break;
		}
		case 3:{
			int previous_data, new_data;
			node* head = list.get_head(); // store head address to pass to function for traversal
			cout << "Enter the value you would like to enter: ";
			cin >> new_data;
			cout << "Enter the value after which you would like to enter the new data: ";
			cin >> previous_data;
			list.insert_after(previous_data, new_data, head); // call function
			break;
		}
		case 4:
			list.delete_at_front();
			break;
		case 5:
			list.delete_at_last();
			break;
		case 6:
			int previous_data;
			cout << "Enter the value after which you would like to delete the node: ";
			cin >> previous_data;
			list.delete_after(previous_data);
			break;
		case 7:
			list.display_forward();
			break;
		case 8:{
			node* head = list.get_head(); // store head address to pass to function for traversal
			cout << "\nList is: ";
			list.display_reverse(head);
			cout << "\n";
			break;
		}
		case 9:
			list.reverse_list();
			break;
		case 10:{
			int n;
			cout << "Enter the digit you want to search: ";
			cin >> n;
			list.search(n);
			break;
		}
		case 11:
			list.sort();
			break;
		case 12:
			break;
		default:
			cout << "\nPlease enter a valid input.\n";
			break;
		}
		option = menu(); // call menu function again to continue loop
	}while(option != 12); // iterate do while loop till user does not exit
	cout << "\nHope you liked this demo\n";
	return 0;
}
