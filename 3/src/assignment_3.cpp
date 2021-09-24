//============================================================================
// Name        : assignment_3.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "QueueADT.h"
using namespace std;

int menu(){
	// variables to store user choice
	string option_str;
	int option;
	cout << "\n\nPrinter Menu\n\n1. Queue new page for printing\n2. Print a page from queue\n3. Display printer queue\n4. Exit System"; // display menu
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
	QueueADT q; // create instance of class
	int option = menu(); // call menu function
	do{
		switch(option){ // switch users choice and call appropriate function
		case 1:
			q.insert(); // insert element in queue
			break;
		case 2:
			cout << "\nPrinting...\n";
			q.delete_entry(); // delete element from queue
			break;
		case 3:
			q.display(); // display queue
			break;
		case 4:
			break; // do nothing
		default:
			cout << "Enter valid input"; // error message as default value
			break;
		}
		option = menu(); // prompt user for choice again by calling menu function
	} while(option != 4); // iterate do while loop till user does not enter 4
	cout << "\nThank you for using our system\n";
	return 0;
}
