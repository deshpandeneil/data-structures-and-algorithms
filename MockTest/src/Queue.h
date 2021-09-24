/*
 * Queue.h
 *
 *  Created on: 04-Nov-2020
 *      Author: Neil
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include<iostream>

#define SIZE 5 // max size of queue array

struct ticket_counter{
	int no_of_tickets; // number of tickets for customer
	std::string name; // name of customer
};

class Queue {
	ticket_counter tc[SIZE]; // create array
	int front, rear, counter; // queue elements
public:
	Queue();

	ticket_counter ask_customer();

	void enqueue();
	void dequeue();

	bool is_empty();
	bool is_full();

	void display();

	virtual ~Queue();
};

#endif /* QUEUE_H_ */
