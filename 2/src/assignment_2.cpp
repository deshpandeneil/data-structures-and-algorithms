//============================================================================
// Name        : assignment_2.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>

#include "Convert.h"
#include "Stack.h"
using namespace std;

int menu(){
	// variables to store user choice
	string option_str;
	int option;
	cout << "\nExpression Conversion Menu\n\n1. Infix to Postfix\n2. Infix to Prefix\n3. Evaluate Postfix Expression\n4. Evaluate Prefix Expression\n5. Exit System"; // display menu
	bool flag = false; // flag for input validation
	do{
		cout << "\n\nEnter the option you want to do: "; // prompt user to input choice
		if(flag == true){
			cin.ignore();
		}
//		cin.ignore();
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
	Convert c; // instance of InfixToPostfix class
	char infix_exp[30]; // variables for infix and postfix expressions
	int option = menu(); // call menu function
	if(option == 5){
		cout << "\nExiting...\n";
		return 0;
	}
	do{
		switch(option){ // switch users choice and call appropriate function
		case 1:{
//			int i = 0;
			char* postfix_exp;
			cout << "Enter the infix expression: ";
			cin.ignore();
			cin >> infix_exp; // take input of infix expression from user
			postfix_exp = c.infix_to_postfix(infix_exp);
			if(postfix_exp != NULL)
				cout << "\nTHE POSTFIX EXPRESSION IS: " << postfix_exp << "\n";
			break;
		}
		case 2:{
			char* prefix_exp;
			cout << "Enter the infix expression: ";
			cin.ignore();
			cin >> infix_exp; // take input of infix expression from user
			prefix_exp = c.infix_to_prefix(infix_exp);
			if(prefix_exp != NULL)
				cout << "\nTHE PREFIX EXPRESSION IS: " << prefix_exp << "\n";
			break;
		}
		case 3:{
			char* postfix_exp;
			cout << "Enter the infix expression: ";
			cin.ignore();
			cin >> infix_exp; // take input of infix expression from user
			postfix_exp = c.infix_to_postfix(infix_exp);
			if(postfix_exp != NULL){
				cout << "\nTHE POSTFIX EXPRESSION IS: " << postfix_exp << "\n";
				c.evaluate_postfix(postfix_exp);
			}
			break;
		}
		case 4:{
			char* prefix_exp;
			cout << "Enter the infix expression: ";
			cin.ignore();
			cin >> infix_exp; // take input of infix expression from user
			prefix_exp = c.infix_to_prefix(infix_exp);
			if(prefix_exp != NULL){
				cout << "\nTHE PREFIX EXPRESSION IS: " << prefix_exp;
				c.evaluate_prefix(prefix_exp);
			}
			break;
		}
		case 5:
			break; // do nothing
		default:
			cout << "Enter valid input"; // error message as default value
			break;
		}
//		cin.ignore();
		option = menu(); // prompt user for choice again by calling menu function
	} while(option != 5); // iterate do while loop till user does not enter 4
	cout << "\nExiting...\n";

	return 0;
}
