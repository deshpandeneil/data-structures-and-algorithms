//============================================================================
// Name        : assignment_4.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Tree.h"
#include <iostream>
#include <cstring>
using namespace std;

int menu(){
	int option;
	bool flag; // flag variable for validations
	do{
		cout << "\n\nMenu\n\n1. Create tree from postfix expression\n2. Create tree from prefix expression\n3. Inorder (recursive)\n4. Postorder (recursive)\n5. Preorder (recursive)\n6. Inorder (non-recursive)\n7. Postorder (non-recursive)\n8. Preorder (non-recursive)\n9. Exit\n\nEnter the serial number of the operation you want to perform: ";
		cin >> option;
		if(cin.good()){ // means that input has been properly taken and there was no error raised while taking input
			flag = false; // set flag to false to exit do while loop
		}
		else{ // if there was some error raised this block is executed
			flag = true;  // set flag to true to re-iterate do while loop
			cout << "\nPlease enter an integer.\n";
			cin.clear(); // clear input stream
			cin.ignore();
		}
	}while(flag == true); // reiterate do while loop if flag is set
	return option; // return user choice
}

int main() {
	Tree t;
	char input_exp[20];
//	input_exp[0] = '\0';
	int option = menu();
	do{
		switch(option){
		case 1:{
			cout << "Enter the postfix expression: ";
			cin >> input_exp;
			t.create_from_postfix(input_exp);
			break;
		}

		case 2:{
			cout << "Enter the prefix expression: ";
			cin >> input_exp;
			t.create_from_prefix(input_exp);
			break;
		}

		case 3:{
			if(input_exp[0] == '\0')
				cout << "\nPlease enter an expression first.\n";
			else{
				cout << "\nINORDER: ";
				t.recursive_inorder(t.get_root());
			}
			break;
		}

		case 4:{
			if(input_exp[0] == '\0')
				cout << "\nPlease enter an expression first.\n";
			else{
				cout << "\nPOSTORDER: ";
				t.recursive_postorder(t.get_root());
			}
			break;
		}

		case 5:{
			if(input_exp[0] == '\0')
				cout << "\nPlease enter an expression first.\n";
			else{
				cout << "\nPREORDER: ";
				t.recursive_preorder(t.get_root());
			}
			break;
		}

		case 6:{
			if(strlen(input_exp) == 0)
				cout << "\nPlease enter an expression first.\n";
			else{
				cout << "\nINORDER: ";
				t.inorder(t.get_root());
			}
			break;
		}

		case 7:{
			if(strlen(input_exp) == 0)
				cout << "\nPlease enter an expression first.\n";
			else{
				cout << "\nPOSTORDER: ";
				t.postorder(t.get_root());
			}
			break;
		}

		case 8:{
			if(input_exp[0] == '\0')
				cout << "\nPlease enter an expression first.\n";
			else{
				cout << "\nPREORDER: ";
				t.preorder(t.get_root());
			}
			break;
		}

		case 9:{
			break;
		}
		}
		option = menu();
	} while(option != 9);
	return 0;
}
