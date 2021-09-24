//============================================================================
// Name        : assignment_10.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include"FileHandling.h"
using namespace std;

int main() {
	FileHandling file;
	int choice;
	do{ // loop till user wants to exit
		cout<<"\n\nMENU\n\n"<<endl;
		cout<<"1. Create Database\n2. Add Entry\n3. Delete Entry\n4. Search Database\n5. Display database\n6. Exit\n\nPlease enter your choice: ";
		cin>>choice; // take choice from user
		switch(choice){ // call appropriate function
		case 1:
			file.createDatabase();
			break;
		case 2:
			file.addEntries();
			break;
		case 3:
			file.deleteEntry();
			break;
		case 4:
			file.searchDatabase();
			break;
		case 5:
			file.displayDatabase();
			break;
		case 6:
			return 0;
		default:
			cout<<"\nInvalid choice\n";
			break;
		}
	}while(true);
}
