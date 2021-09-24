/*
 * Stack.cpp
 *
 *  Created on: 27-Sep-2020
 *      Author: Neil
 */

#include "Stack.h"
#include <iostream>

// constructor
Stack::Stack() {
	// TODO Auto-generated constructor stub
	top = -1; // initializes top to -1 to indicate that array is empty
}

// function to check if array is full or not
// returns true or false
bool Stack::is_full(){
	if(top == SIZE){ // check if top (which acts as a pointer) is equal to SIZE or not
		return true; // if yes then array has been filled
	}
	return false; // if not then the array can be used to store more data
}

// function to check if array is empty or not
// returns true or false
bool Stack::is_empty(){
	if(top == -1){ // check if top (which acts as a pointer) is equal to -1 or not
		return true; // if yes then array is empty
	}
	return false; // if not then there is some data in the array
}

// function to add more data to the array
// it takes the data to be added as parameter
void Stack::push(char x){
	if(is_full()){ // check if array is full
		std::cout << "\nStack overflow\n"; // if yes then display error
		return; // exit the function
	}
	arr[++top] = x; // if not then pre-increment top and add data to the index given by the value of top
	std::cout << "\nPushed\n"; // display success message
}

// function to delete an element from the array
void Stack::pop(){
	if(is_empty()){ // check if array is empty
		std::cout << "\nStack underflow\n"; // if yes then display error
		return; // exit function
	}
	top--; // if not the decrement top by 1
	std::cout << "\nPopped\n"; // display success message
}


// function to peep at the data at the index given by the value of top
// returns the data
std::string Stack::peep(){
	if(is_empty()){ // check if array is empty
		return "\nStack is empty\n"; // if yes then display appropriate message
	}
	return arr[top]; // return data at top
}

// function to display all data in the array
void Stack::display(){
	if(is_empty()){ // check if empty
		std::cout << "\nStack is empty\n"; // if yes then display appropriate message
		return; // exit function
	}
	for(int i = 0; i <= top; i++){ // if not then loop through array till the index given by the value of top
		if(i == top){ // if-else has been added to display values in correct format
			std::cout << arr[i]; // display data at i
		}
		else{
			std::cout << arr[i] << ", "; // display data at i
		}
	}
}

Stack::~Stack() {
	// TODO Auto-generated destructor stub
}

