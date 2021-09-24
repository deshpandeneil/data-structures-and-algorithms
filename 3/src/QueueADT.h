/*
 * QueueADT.h
 *
 *  Created on: 09-Sep-2020
 *      Author: Neil
 */

#ifndef QUEUEADT_H_
#define QUEUEADT_H_

#define SIZE 5

// define structure
struct printer{
	int page_number;
	char page_header[25], page_content[100], page_footer[25];
};

// class definition
class QueueADT {
	printer p[SIZE]; // array of printer data type
	int front, end, counter; // variables for implementing queue logic
public:
	QueueADT(); // constructor
	void insert(); // function to insert an element in the queue
	void delete_entry(); // function to delete an element in the queue
	printer get_data(); // function to get data for a new element
	bool is_empty(); // function to check if queue is empty
	bool is_full(); // function to check if queue is full
	void display();// function to display the elements of the queue
	virtual ~QueueADT(); // destructor
};

#endif /* QUEUEADT_H_ */
