//============================================================================
// Name        : MatrixManipulation.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"MatrixManipulations.h"
using namespace std;

int main() {
	MatrixManipulations mm;
	int choice;

	do{
		// display menu
		cout << "\n\nMENU\n\n1. Enter matrices\n2. Display matrices\n3. Add matrices\n4. Subtract matrices\n5. Multiply matrices\n6. Find transpose of a matrix\n7. Exit\n\nEnter your choice: ";
		cin >> choice; // take user choice;

		// validate if input data type is integer
		if(!cin.good()){
			cout << "\nPlease enter correct data type\n";
			cin.clear();
			cin.ignore();
			continue;
		}

		// switch choice and call appropriate functions
		switch(choice){
		case 1:
			mm.input();
			 break;
		case 2:
			mm.display();
			break;
		case 3:
			mm.add();
			 break;
		case 4:
			mm.subtract();
			break;
		case 5:
			mm.multiply();
			 break;
		case 6:
			char t;
			cout << "\nEnter the matrix you want to be transposed ('A' or 'B'): ";
			cin >> t;
			if(t == 'A' || t == 'B')
				mm.transpose(t);
			else
				cout << "\nSuch a matrix does not exist\n";
			break;
		case 7:
			 return 0;
		default:
			cout << "\nPlease select correct option.\n";
		}
	} while(true);

	return 0;
}
