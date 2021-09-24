//============================================================================
// Name        : assignment_5.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BST.h"
using namespace std;

int main() {
	BST bst;
	int option;
	do{
		cout << "\n\nMENU\n\n1. Recursive Insert\n2. Insert\n3. Recursive Traversals\n4. Search\n5. Mirror\n6. Copy\n7. Calculate Height\n8. Delete Node\n9. Level order traversal\n10. Exit\n\nEnter your choice: ";
		cin >> option;
		switch(option){
		case 1:
			int data1;
			cout << "\nEnter element to be inserted: ";
			cin >> data1;
			bst.set_root(bst.recurssive_insert(bst.get_root(), data1));
			break;
		case 2:
			int data2;
			cout << "\nEnter element to be inserted: ";
			cin >> data2;
			bst.insert(data2);
			break;
		case 3:
			cout << "\nInorder: ";
			bst.recursive_inorder(bst.get_root());
			cout << "\nPostorder: ";
			bst.recursive_postorder(bst.get_root());
			cout << "\nPreorder: ";
			bst.recursive_preorder(bst.get_root());
			break;
		case 4:
			int data3;
			cout << "\nEnter element to be searched: ";
			cin >> data3;
			bst.recurssive_search(bst.get_root(), data3);
			break;
		case 5:
			cout << "\nBefore Mirroring: \n\nInorder: ";
			bst.recursive_inorder(bst.get_root());
			bst.mirror(bst.get_root());
			cout << "\n\nCurrent tree has now been mirrored.\n";
			cout << "\nAfter Mirroring: \n\nInorder: ";
			bst.recursive_inorder(bst.get_root());
			break;
		case 6:
			bst_node* temp;
			cout << "\nCopying...\n";
			temp = bst.copy(bst.get_root());
			cout << "\nBST has been copied.\n\nInorder (copied tree): ";
			bst.recursive_inorder(temp);
			break;
		case 7:{
			int height;
			cout << "\nCalculating height...\n";
			height = bst.height(bst.get_root());
			cout << "\nHeight of BST is: " << height;
			break;
		}
		case 8:{
			int data4;
			cout << "\nEnter the data you want to delete: ";
			cin >> data4;
			cout << "\nBefore deleting:\n\nInorder: ";
			bst.recursive_inorder(bst.get_root());
			bst.set_root(bst.recurssive_delete(bst.get_root(), data4));
			cout << "\n\nAfter deleting:\n\nInorder: ";
			bst.recursive_inorder(bst.get_root());
			break;
		}
		case 9:
			cout << "\nLevel order: ";
			bst.level_order(bst.get_root());
			break;
		case 10:
			cout << "\nThank you for viewing this demo.\n";
			return 0;
		default:
			cout<<"\nPlease enter a valid choice.\n"<<endl;
			break;
		}
	}while(true);
	return 0;
}
