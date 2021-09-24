/*
 * heap.cpp
 *
 *  Created on: 25-Nov-2020
 *      Author: Neil
 */

#include "heap.h"
#include<iostream>

heap::heap() {
	// TODO Auto-generated constructor stub
	do{
		std::cout << "\nEnter size of input array: ";
		std::cin >> size;
		if(!std::cin.good()){ // check if data type matched
			std::cout << "\nPlease enter an integer\n";
			std::cin.clear();
			std::cin.ignore();
			continue;
		}
		else
			break;
	} while(true); // keep on asking for input till correct data type is not entered
	array = new int [size];
}

void heap::input(){
	for(int i = 0; i < size; i++){ // ask user for elements one by one
		do{
			std::cout << "Enter element " << i+1 << ": ";
			std::cin >> array[i];
			if(!std::cin.good()){ // check if data type matched
				std::cout << "\nPlease enter an integer\n";
				std::cin.clear();
				std::cin.ignore();
				continue;
			}
			else
				break;
		} while(true); // keep on asking for input till correct data type is not entered
	}
}

void heap::display(){
	std::cout << "\nArray is:\n\n";
	for(int i = 0; i < size; i++){
		std::cout << " - " << array[i];
	}
}

void heap::heapify(int n, int root){
	int temp;
	int largest = root; // initialize largest as i
	int left_child = 2 * root + 1; //left child address
	int right_child = 2 * root + 2; // right child address
	std::cout << "\n\nCurrently at node: " << array[largest];
	std::cout << "\nComparing current node with left and right children\n";
	if (left_child < n && array[left_child] > array[largest]){
		largest = left_child; // update largest
		std::cout << "\nLeft Child > Current Node\nLeft Child: " << array[left_child];
	}

	if (right_child < n && array[right_child] > array[largest]){
		largest = right_child; // update largest
		std::cout << "\nRight Child > Current Node\nRight Child: " << array[right_child];
	}

	if (largest != root) { // swap first and last element of array
		std::cout << "\n\nRoot is not the Largest in array\n\nBefore swapping...\n";
		display();
		temp = array[root]; // swap elements using temporary variable
		array[root] = array[largest];
		array[largest] = temp;
		std::cout << "\n\nAfter swapping...\n";
		display();
		heapify(n, largest); // recursively heapify the affected subtree
	}

	else
		std::cout << "\nHeap property maintained at current node\n";
}

void heap::heapsort(){
	int temp;
	for (int i = size / 2 - 1; i >= 0; i--) // build heap, rearrange array
		heapify(size, i);
	for (int i = size - 1; i > 0; i--){ // extract element from heap one by one
		// move current root to end of array
		std::cout << "\nSwapping first (" << array[0] << ") and last element (" << array[i] << ") of array...\n";
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		std::cout << "\nDiscarding last element (" << array[i] << ") form heap...\n\nHeapifying reduced array...\n";
		heapify(i, 0); // call heapify on reduced heap
	}
}

heap::~heap() {
	// TODO Auto-generated destructor stub
}

