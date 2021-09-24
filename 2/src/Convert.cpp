/*
 * Convert.cpp
 *
 *  Created on: 30-Sep-2020
 *      Author: Neil
 */

#include "Convert.h"
#include "Stack.h"
#include "Stack.cpp"
#include <string.h>
#include<iostream>
#include<cmath>


Convert::Convert() {
	// TODO Auto-generated constructor stub

}

bool Convert::associativity(char o){ // function to check associativity of operators
	if(o == '^')
		return false; // right to left
	return true; // left to right by default
}

int Convert::precedence(char o){ // function to check precedence of operators
	if(o == '^')
		return 3; // '^' operator has the highest priority
	else if(o == '*' || o == '/' || o == '%')
		return 2; // '*', '/', '%' operator have the second highest priority
	else if(o == '+' || o == '-')
		return 1; // '+', '-' operator have the third highest priority
	return -1;
}

char* Convert::infix_to_postfix(char* infix){
	std::cout << "\nCONVERTING INFIX TO POSTFIX...\n";
	Stack<char> s;
	static char postfix_exp[30]; // declare empty string, keep on appending it (this is the output stream)
	bool flag = false; // flag for validation
	int j = 0;
	while(*infix != '\0'){ // loop through all characters from the end
		if(*infix == ' ')
			continue;
		if(isalnum(*infix)){ // check if infix character is alpha-numeric
			postfix_exp[j] = *infix; // if yes append to output string
			j++;
		}
		else if(*infix == '(' || *infix == '{' || *infix == '['){ // check if character is any closing parenthesis
			s.push(*infix); // push
			postfix_exp[j] = ' '; // add a space in output string to differentiate between 2 digit numbers
			j++;
		}
		else if(*infix == ')' || *infix == '}' || *infix == ']'){ // check if character is any opening parenthesis
			while(true){ // go on popping
				if(s.peep() == '(' || s.peep() == '{' || s.peep() == '[') // if closing parenthesis found, stop
					break;
				else{
					postfix_exp[j] = ' '; // add space
					j++;
					postfix_exp[j] = s.peep(); // pop element
					s.pop();
					j++;
				}
			}
			s.pop();
		}
		// check if valid operator
		else if(*infix == '^' || *infix == '*' || *infix == '/' || *infix == '%' || *infix == '+' || *infix == '-'){
			// push if precedence if incoming operator > operator on top of stack
			if(s.is_empty() || (precedence(*infix) > precedence(s.peep()))){
				s.push(*infix);
				postfix_exp[j] = ' '; // add space
				j++;
			}
			else if(precedence(*infix) < precedence(s.peep())){
				// go on popping till precedence of incoming operator <= operator on top
				while((precedence(*infix) <= precedence(s.peep())) && !s.is_empty()){
					postfix_exp[j] = ' '; // add space before operator
					j++;
					postfix_exp[j] = s.peep(); // append operator to output
					s.pop();
					j++;
				}
				s.push(*infix); // push current operator
				postfix_exp[j] = ' '; // add space to output
				j++;
			}
			else if(precedence(*infix) == precedence(s.peep())){
				// if same precedence, check associativity
				if(!associativity(*infix)){ // if right to left
					s.push(*infix); // push
					postfix_exp[j] = ' '; // add space to output
					j++;
				}
				else{
					// else pop operators from stack till character has same precedence as that of operator on top of stack
					while(precedence(*infix) == precedence(s.peep())){
						postfix_exp[j] = ' '; // add space before operator
						j++;
						postfix_exp[j] = s.peep(); // append operator
						s.pop();
						j++;
					}
					s.push(*infix); // push current operator
					postfix_exp[j] = ' ';
					j++;
				}
			}
		}
		else{ // display error
			std::cout << "Invalid character detected. The infix to postfix converter only handles '(){}[]' brackets and alpha-numeric characters without spaces.\n\nPlease re-enter correct expression.\n";
			return NULL;
		}
		infix++;
	}
	// pop any remaining operators on stack
	while(!s.is_empty()){
		postfix_exp[j] = ' '; // add space before popping
		j++;
		postfix_exp[j] = s.peep(); // append operator
		s.pop();
		j++;
	}
	postfix_exp[j] = '\0'; // set last char of array
	return postfix_exp; // return base address
}

void Convert::evaluate_postfix(char postfix_exp[]){
	std::cout << "\nEVALUATING POSTFIX EXPRESSION...\n";
	Stack<int> s; // stack object of int data type

	for(int i = 0; i < strlen(postfix_exp); i++){ // loop through all characters of array
		if(postfix_exp[i] == ' ') // a space character is used to differentiate between two multi-digit numbers
			continue;
		else if(isdigit(postfix_exp[i]) == true){
			std::string number_str = ""; // empty string to get number
			int number;
			while(postfix_exp[i] != ' '){
				number_str += postfix_exp[i]; // append digit to number string till ' ' is encountered
				i++;
			}
//			i--;
			number = atoi(number_str.c_str()); // convert string to int
			s.push(number);
		}
		// check if valid operator
		else if(postfix_exp[i] == '^' || postfix_exp[i] == '*' || postfix_exp[i] == '/' || postfix_exp[i] == '%' || postfix_exp[i] == '+' || postfix_exp[i] == '-'){
			int operand_1, operand_2;
			// pop 2 operands from stack when an operator in encountered
			operand_2 = s.peep();
			s.pop();
			operand_1 = s.peep();
			s.pop();
			switch(postfix_exp[i]){ // switch the operator
				int result;
				case '^':{
					result = pow(operand_1, operand_2); // calculate result
					s.push(result); // push result
					break;
				}
				case '*':{
					result = operand_1 * operand_2;
					s.push(result);
					break;
				}
				case '/':{
					result = operand_1 / operand_2;
					s.push(result);
					break;
				}
				case '%':{
					result = operand_1 % operand_2;
					s.push(result);
					break;
				}
				case '+':{
					result = operand_1 + operand_2;
					s.push(result);
					break;
				}
				case '-':{
					result = operand_1 - operand_2;
					s.push(result);
					break;
				}
			}
		}
		else{
			std::cout << "\nPlease enter numeric expression only.\n";
			return;
		}
	}
	// if reached here, stack will have only one element i.e. the answer
	int answer = s.peep();
	std::cout << "\nANSWER IS: " << answer << "\n";
}

char* Convert::infix_to_prefix (char infix_exp[]){
	std::cout << "\nCONVERTING INFIX TO PREFIX...\n";
	Stack<char> s;
	char prefix_exp[30]; // declare empty string, keep on appending it (this is the output stream)
	bool flag = false; // flag for validation
	int j = 0, k = strlen(infix_exp) - 1;
	while(k >= 0){ // loop through all characters from the end
		if(isalnum(infix_exp[k])){ // append to output if char is alpha-numeric
			prefix_exp[j] = infix_exp[k];
			j++;
		}

		else if(infix_exp[k] == ')' || infix_exp[k] == '}' || infix_exp[k] == ']'){ // check if character is any closing parenthesis
			s.push(infix_exp[k]);
			prefix_exp[j] = ' '; // add space in output
			j++;
		}
		else if(infix_exp[k] == '(' || infix_exp[k] == '{' || infix_exp[k] == '['){ // check if character is any opening parenthesis
			while(true){ // pop operators till closing parenthesis is not encountered
				if(s.peep() == ')' || s.peep() == '}' || s.peep() == ']')
					break;
				else{
					prefix_exp[j] = ' '; // add space before popping
					j++;
					prefix_exp[j] = s.peep();
					s.pop();
					j++;
				}
			}
			s.pop(); // pop ')'
		}
		// check if valid operator
		else if(infix_exp[k] == '^' || infix_exp[k] == '*' || infix_exp[k] == '/' || infix_exp[k] == '%' || infix_exp[k] == '+' || infix_exp[k] == '-'){
			// push if precedence if incoming operator > operator on top of stack
			if(s.is_empty() || (precedence(infix_exp[k]) > precedence(s.peep()))){
				s.push(infix_exp[k]);
				prefix_exp[j] = ' '; // add space to output
				j++;
			}
			else if(precedence(infix_exp[k]) < precedence(s.peep())){
				// go on popping till precedence of incoming operator <= operator on top
				while((precedence(infix_exp[k]) < precedence(s.peep())) && !s.is_empty()){
					prefix_exp[j] = ' '; // add space before popping
					j++;
					prefix_exp[j] = s.peep();
					s.pop();
					j++;
				}
				s.push(infix_exp[k]);
				prefix_exp[j] = ' '; // add space to output
				j++;
			}
			else if(precedence(infix_exp[k]) == precedence(s.peep())){
				// if same precedence, check associativity
				if(associativity(infix_exp[k])){ // if left to right
					s.push(infix_exp[k]); // push
					prefix_exp[j] = ' ';
					j++;
				}
				else{
					// else pop operators from stack till character has same precedence as that of operator on top of stack
					while(precedence(infix_exp[k]) == precedence(s.peep())){
						prefix_exp[j] = ' '; // add space before popping
						j++;
						prefix_exp[j] = s.peep(); // append operator
						s.pop();
						j++;
					}
					s.push(infix_exp[k]); // push current operator
					prefix_exp[j] = ' '; // add space to output
					j++;
				}
			}
		}
		else{ // display error
			std::cout << "Invalid character detected. The infix to prefix converter only handles '(){}[]' brackets and alpha-numeric characters without spaces.\n\nPlease re-enter correct expression.\n";
			return NULL;
		}
		k--;
	}
	// pop remaining elements from stack
	while(!s.is_empty()){
		prefix_exp[j] = ' '; // space before operator
		j++;
		prefix_exp[j] = s.peep(); // append to output
		s.pop();
		j++;
	}
	prefix_exp[j] = '\0'; // set last char of array
	// since we looped from the end string is reversed so we'll have to reverse it again to get the correct expression
	static char reversed [30];
	for(int i = strlen(prefix_exp) - 1; i >= 0; i--){
		reversed[strlen(prefix_exp) - i - 1] = prefix_exp[i]; // append character to reverse string
	}
	return reversed; // return base address of reversed
}

void Convert::evaluate_prefix(char prefix_exp[]){
	std::cout << "\nEVALUATING PREFIX EXPRESSION...\n";
	Stack<int> s; // stack object of int data type
	int i = strlen(prefix_exp) - 1;
	for(int i = strlen(prefix_exp) - 1; i >= 0; i--){ // loop through all characters of string
		if(prefix_exp[i] == ' ') // a space character is used to differentiate between two multi-digit numbers
			continue;
		else if(isdigit(prefix_exp[i]) == true){
			std::string number_str = "", reversed = "";
			int number;
			while(prefix_exp[i] != ' '){
				number_str += prefix_exp[i];
				i--;
			}
			// reverse number since we are scanning from right to left
			for(int k = number_str.length() - 1; k >= 0; k--){
				reversed += number_str[k]; // append character to reverse string
			}
//			i++;
			number = atoi(reversed.c_str()); // convert string to int
			s.push(number);
		}
		// check if valid operator
		else if(prefix_exp[i] == '^' || prefix_exp[i] == '*' || prefix_exp[i] == '/' || prefix_exp[i] == '%' || prefix_exp[i] == '+' || prefix_exp[i] == '-'){
			int operand_1, operand_2;
			operand_2 = s.peep();
			s.pop();
			operand_1 = s.peep();
			s.pop();
			switch(prefix_exp[i]){
				int result;
				case '^':{
					result = pow(operand_2, operand_1); // second argument is the power
					s.push(result);
					break;
				}
				case '*':{
					result = operand_1 * operand_2;
					s.push(result);
					break;
				}
				case '/':{
					result = operand_2 / operand_1; // since we're scanning right to left dividend will be on top of stack
					s.push(result);
					break;
				}
				case '%':{
					result = operand_2 % operand_1; // since we're scanning right to left dividend will be on top of stack
					s.push(result);
					break;
				}
				case '+':{
					result = operand_1 + operand_2;
					s.push(result);
					break;
				}
				case '-':{
					result = operand_2 - operand_1; // 2 - 1 since we're scanning from right to left
					s.push(result);
					break;
				}
			}
		}
		else{
			std::cout << "\nPlease enter numeric expression only.\n";
			return;
		}
	}
	int answer = s.peep();
	std::cout << "\nANSWER IS: " << answer;
}

Convert::~Convert() {
	// TODO Auto-generated destructor stub
}

