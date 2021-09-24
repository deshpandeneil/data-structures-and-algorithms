//============================================================================
// Name        : ThreadedBinaryTree.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"TBT.h"
using namespace std;

int main() {
	int choice;
	TBT t;
	do{
		// display menu
		cout << "\n\nMENU\n\n1. Insert value\n2. Traversals\n3. Exit\n\nEnter your choice: "<<endl;
		cin >> choice; // take user input
		switch(choice){ // call appropriate function based on user input
		//to insert a new element
		case 1:
			t.create();
			t.inorder();
			break;
		// to display in preorder
		case 2:
			cout << "\nTRAVERSALS\n";
			t.inorder();
			t.preorder();
			break;
		case 3:
			return 0; // exit program
		default:
			cout << "\nPlease select valid option\n"<<endl;
			cin.clear();
			cin.ignore();
			break;
		}
	}while(true);

}
