//============================================================================
// FileName         : MockTest.cpp
// Batch            : F - 9
// Name             : Neil Deshpande
// Roll Number      : 23121

	/*
	Problem Statement 5:

	Consider a Ticket counter line where people who come first will get
	ticket first, implement Ticket counter line as a Circular queue using
	Array and perform following operations on it for the Ticket Counter
	line:
	a. Add, b. Delete c. Checking Empty/Underflow ,
	d. Checking Overflow/Full
	e. Display of ticket Counter Queue

	*/

// Version          :
// Copyright        : Your copyright notice
// Description      : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"Queue.h"

using namespace std;

int menu(){
	// variables to store user choice
	string option_str;
	int option;
	cout << "\n\nTicket Counter Menu\n\n1. Add customer to queue (enqueue)\n2. Hand out tickets to customer (dequeue)\n3. Display customer queue\n4. Exit System"; // display menu
	bool flag = false; // flag for input validation
	do{
		cout << "\n\nEnter the option you want to do: "; // prompt user to input choice
		if(flag == true){
			cin.ignore();
		}
		cin >> option_str;
		for(int i = 0; i < option_str.length(); i++){ // loop through all indexes of string
			if(isdigit((int)option_str[i]) == false){ // check if data at current index is not a digit
				flag = true; // set flag if not a digit for next iteration of do while loop
				cout << "\nPlease enter correct serial number."; // display error
				break; // exit for loop
			} else{
				flag = false; // else set flag to exit do while loop
				continue; // continue next iteration of for loop
			}
		}
	}while(flag == true); // iterate do while loop till flag is false
	option = atoi(option_str.c_str()); // convert string to integer
	return option;
}

int main() {
	Queue q;
	int option = menu(); // call menu function
	do{
		switch(option){ // switch users choice and call appropriate function
		case 1:
			cin.ignore();
			q.enqueue(); // insert element in queue
			break;
		case 2:
			q.dequeue(); // delete element from queue
			break;
		case 3:
			q.display(); // display queue
			break;
		case 4:
			break; // do nothing
		default:
			cout << "\nEnter valid input\n"; // error message as default value
			break;
		}
		option = menu(); // prompt user for choice again by calling menu function
	} while(option != 4); // iterate do while loop till user does not enter 4
	cout << "\nThank you for using our system\n";
	return 0;
}
