//============================================================================
// Name        : heap_sort.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"heap.h"
using namespace std;

int main(){
	heap h;
	int option;
	do{
		// display menu
		cout << "\n\nMENU\n\n1. Enter elements in array\n2. Sort\n3. Display array\n4. Exit\n\nEnter your choice: ";
		cin >> option; // input user option
		switch(option){
		case 1:
			h.input(); // fill array with user input
			h.display();
			break;
		case 2:
			std::cout << "\nBefore sorting...\n";
			h.display();
			h.heapsort();
			std::cout << "\n\nAfter sorting...\n";
			h.display();
			break;
		case 3:
			h.display();
			break;
		case 4:
			return 0;
		default:
			cout << "\nPlease enter a correct choice\n";
			cin.clear();
			cin.ignore();
			break;
		}
	} while(true); // keep looping until user does not exit
	return 0;
}
