/*
 * heap.h
 *
 *  Created on: 25-Nov-2020
 *      Author: Neil
 */

#ifndef HEAP_H_
#define HEAP_H_

//#define SIZE 10 // set a constant size for array

class heap {
	int *array, size = 0; // array with the set size
public:
	heap();

	// utility functions
	void input();
	void display();

	// heap functions
	void heapify(int, int);
	void heapsort();

	virtual ~heap();
};

#endif /* HEAP_H_ */
