/*
 * Queue.cpp
 *
 *  Created on: 04-Nov-2020
 *      Author: Neil
 */

#include "Queue.h"

Queue::Queue() {
	// TODO Auto-generated constructor stub
	front = -1;
	rear = -1;
	counter = 0;
}

bool Queue::is_full(){
	if (front == (rear + 1) % SIZE){ // front is 1 index ahead of end
		return true;
	}
	return false;
}

bool Queue::is_empty(){
	if (front == -1) // front is set to -1 when last element is dequeued
		return true;
	return false;
}

ticket_counter Queue::ask_customer(){
	ticket_counter customer; // customer details
	bool ticket_flag = false, name_flag = false; // flags for validations
	do{
		std::cout << "\nYour good name? : ";
		getline(std::cin, customer.name); // get full name
		for(int i = 0; i < customer.name.length(); i++){ // loop through all characters of the name string
			// check if character is a digit
			if(isdigit((int)customer.name[i]) == true){
				// if yes, set flag for re-iteration of do while loop and display error
				name_flag = true;
				std::cout << "\nPlease enter valid input. Name can only have characters in it.\n";
				break; // exit for loop
			} else {
				// set flag to exit do-while loop
				name_flag = false;
				continue; // go to next character of name string
			}
		}
	} while(name_flag == true); // iterate do while loop till correct name format is entered
	return customer; // return the customer structure
}

void Queue::enqueue(){
	// check if queue is full
	if(is_full()){
		std::cout << "\nOverflow. This customer line is full.\n"; // display appropriate message if full
	}else{
		rear = (rear + 1) % SIZE; // set rear to the next index in the array (0th if at last index)
		ticket_counter customer = ask_customer(); // get data for new customer in variable of ticket_counter data type
		tc[rear] = customer; // store new customer details at index having rear's value
		if(front == -1){ // increment front if new customer is 1st entry in the queue
			front = rear;
		}
		counter ++;
		std::cout << "\nEnqueue successful."; // display success message
		std::cout << "\n\nFront = " << front << "\nEnd = " << rear << "\nCounter = " << counter; // display values of all queue variables
	}
}

void Queue::dequeue(){
	if(is_empty()) // check if queue is empty
		std::cout << "\nUnderflow. The customer line is already empty.\n"; // display appropriate message
	else{
		bool ticket_flag = false;
		do{
			std::cout << "\nHow many tickets do you require? (max 3 per customer) : ";
			std::cin >> tc[front].no_of_tickets;
			if(std::cin.good()){ // check if there was any error while storing the user input i.e. data type mismatch
				// if not execute following block
				if(tc[front].no_of_tickets > 3){ // limit number of tickets to 3 for each customer
					ticket_flag = true; // if > 3 set flag to reiterate do while loop
					std::cout << "\nSorry, you can get a maximum of 3 tickets.\n"; // display error mssg
					continue; // move to next iteration of do while loop
				}
				ticket_flag = false; // if < 3 set flag to exit do while loop
			}
			else{ // if there was some error while storing input, execute following block
				ticket_flag = true; // set flag to reiterate do while loop
				std::cout << "\nPlease enter an integer.\n"; // display error mssg
				std::cin.clear(); // clear input stream
				std::cin.ignore();
			}
		} while(ticket_flag == true); // keep on iterating the loop till validations are met by the user input
		front = (front + 1) % SIZE; // increment front to point to next index in the array (0th if at last index)
		if(front == (rear + 1) % SIZE) // if all customers are removed set front to -1, this is done to avoid ambiguity
			front = -1;
		counter--;
		std::cout << "\nThank you for buying the ticket(s)\n";
		std::cout << "\n\nFront = " << front << "\nEnd = " << rear << "\nCounter = " << counter; // display values of all queue variables
	}
}

void Queue::display(){
	if(is_empty() == true){
		std::cout << "\nCustomer queue is empty.\n\nFront = " << front << "\nEnd = " << rear;
	}else{
		std::cout << "\nQueue is:\n\n";
		std::cout << "Customer Name\n\n"; // table headers
		for(int i = front; i != rear; i = (i + 1) % SIZE){ // loop through all existing elements of array from front to end, i becomes 0 if at last index
			std::cout << tc[i].name << "\n"; // display in proper format
		}
		std::cout << tc[rear].name << "\n" << "\n\nFront = " << front << "\nEnd = " << rear << "\nCounter = " << counter; // display content at end index since its not included in for loop
	}
}

Queue::~Queue() {
	// TODO Auto-generated destructor stub
}

