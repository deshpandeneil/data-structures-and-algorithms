//============================================================================
// Name        : parenthesesCheck.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// include required header files
#include <iostream>
#include "Stack.h"
using namespace std;

int main() {

	// declare required variables
	string parentheses; // holds user input string
	bool string_flag; // flag variable for input validations
	bool balanced_so_far; // flag variable to check if parentheses is balanced or not

	Stack s; // create an instance of the class

	do{
		cout << "\nEnter parentheses string: "; // prompt user to enter string of parentheses
		getline(cin, parentheses);
		if(parentheses.length() == 0){ // check if user has entered something
			cout << "\nPlease enter some string\n"; // if not then display error message
			string_flag = true; // set flag to re-iterate the do-while loop
			continue; // re-iterate from start
		}
		if(parentheses.length() > SIZE){ // check if size of input string exceeds the size of array
			cout << "\nMax length of string can be " << SIZE << " only.\n"; // if yes then display error message
			string_flag = true; // set flag to re-iterate the do-while loop
			continue; // re-iterate from start
		}
		for(int i = 0; i < parentheses.length(); i++){ // loop through the string entered by user

			// check if string contains any characters other than parentheses
			if(isalpha(parentheses[i]) || isdigit(parentheses[i])){

				// if yes then display error message
				cout << "\nPlease enter a valid input. Input can only have different types of parentheses in it i.e. (){}[]<>\n";
				string_flag = true; // set flag to re-iterate the do-while loop
				break; // break out of the for loop at first occurrence of other characters than parentheses
			}
			else{
				string_flag = false; // set flag to exit do-while loop
				continue; // continue for loop to check the next character in the string
			}
		}
	}while(string_flag == true); // repeat the above process until user enters a valid string

	// check if length of entered string is 1
	if(parentheses.length() == 1)
		cout << "\nParentheses are unbalanced\n"; // if yes then obviously the parentheses are unbalanced

	for(int i = 0; i < parentheses.length(); i++){ // loop through all characters of input string
		if(parentheses[i] == '(' || parentheses[i] == '{' || parentheses[i] == '[' || parentheses[i] == '<'){ // check if character is an opening parentheses
			s.push(parentheses[i]); // if yes then push it in the stack
			continue; // continue next iteration of for loop
		}

		// when this point is reached, it means than the character was not an opening parentheses
		// therefore there must be at least one element in the stack
		if(s.is_empty() == true){ // check if stack is empty or not
			balanced_so_far = false; // if yes then set the flag and display appropriate message
			cout << "\nParentheses are unbalanced\n"; // display error
			break; // exit for loop
		}

		// if current character is not an opening parentheses and stack is not empty then we can proceed to pop elements
		switch(parentheses[i]){
		case ')': // check if current character is ) i.e. closing parentheses
			if(s.peep() == "("){ // if yes then top of stack must be ( i.e. its opening parentheses
				balanced_so_far = true; // if it is ( then set flag for displaying appropriate message
				s.pop(); // pop from stack
			}
			else
				balanced_so_far = false; // if not ( i.e. its opening parentheses then set flag for displaying appropriate message
			break;
		case '}': // check if current character is } i.e. closing parentheses
			if(s.peep() == "{"){ // if yes then top of stack must be { i.e. its opening parentheses
				balanced_so_far = true; // if it is { then set flag for displaying appropriate message
				s.pop(); // pop from stack
			}
			else
				balanced_so_far = false; // if not { i.e. its opening parentheses then set flag for displaying appropriate message
			break;
		case ']': // check if current character is ] i.e. closing parentheses
			if(s.peep() == "["){ // if yes then top of stack must be [ i.e. its opening parentheses
				balanced_so_far = true; // if it is [ then set flag for displaying appropriate message
				s.pop(); // pop from stack
			}
			else
				balanced_so_far = false; // if not [ i.e. its opening parentheses then set flag for displaying appropriate message
			break;
		case '>':
			if(s.peep() == "<"){
				balanced_so_far = true;
				s.pop(); // pop from stack
			}
			else
				balanced_so_far = false; // if not < i.e. its opening parentheses then set flag for displaying appropriate message
			break;
		default:
			// do nothing since validations are already done previously
			break;
		}
	}
	if(s.is_empty() == false){ // check if stack is empty or not
		balanced_so_far = false; // if yes then set the flag and display appropriate message
		cout << "\nParentheses are unbalanced\n"; // display error
	}
	if(balanced_so_far == true)
		cout << "\nParentheses are balanced\n";

	return 0;
}
