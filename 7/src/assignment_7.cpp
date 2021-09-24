//============================================================================
// Name        : assignment_7.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"Graph.h"
using namespace std;

int main() {
	Graph g;
	int option;
	do{
		cout << "\n\nMENU\n\n1. Create Adjacency MAtrix\n2. Display Graph Matrix\n3. Prims's Algorithm\n4. Kruskal's Algorithm\n5. Exit\n\nEnter your choice: ";
		do{
			cin >> option;
			cin.ignore();
			if(!cin.good()){
				cout << "\nPlease enter valid data type\n";
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
			break;
		}while(true);
		switch(option){
		case 1:{

			g.create_adj_matrix();
			break;
		}
		case 2:
			g.display_matrix();
			break;
		case 3:{
			int start;
			do{
				cout << "\nEnter the node at which you want to start: ";
				cin >> start;
				if(!cin.good()){
					cout << "\nPlease enter valid data type\n";
					continue;
				}
				break;
			}while(true);
			g.prims(start);
			break;
		}
		case 4:
			g.kruskals();
			break;
		case 5:
			return 0;
		default:
			cout << "\nPlease enter a valid choice\n";
			break;
		}
	}while(true);
	return 0;
}
