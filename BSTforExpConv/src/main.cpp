/*
 * main.cpp
 *
 *  Created on: 13-Dec-2020
 *      Author: Neil
 */




#include<iostream>
#include"ConstructBST.h"
using namespace std;

int main(){
	int option;
	ConstructBST bst;
	do{ // loop till user does not exit
		// display menu
		cout << "\n\nMENU\n\n1. Enter Preorder and Postorder expressions\n2. Display Preorder and Postorder expressions\n3. Construct BST from Preorder and Postorder expressions\n4. Display BST in inorder\n5. Exit\n\nEnter your choice: ";
		cin >> option; // take user input
		if(!cin.good()){ // input validation
			cout << "\nPLease enter correct data type\n";
			cin.clear();
			cin.ignore();
			continue;
		}
		else{
			switch(option){ // call appropriate function
			case 1:
				bst.input();
				break;
			case 2:
				bst.display();
				break;
			case 3:
				bst.construct();
				break;
			case 4:
				cout << "\n\nINORDER\n\n";
				bst.inorder(bst.getRoot());
				break;
			case 5:
				return 0;
			default:
				cout << "\nPlease choose a correct option\n";
				break;
			}
		}
	} while(true);
	return 0;
}
