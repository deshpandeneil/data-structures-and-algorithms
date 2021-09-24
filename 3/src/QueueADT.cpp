/*
 * QueueADT.cpp
 *
 *  Created on: 09-Sep-2020
 *      Author: Neil
 */

#include <iostream>
//#include <windows.h>
#include <unistd.h>
#include <iomanip>
#include "QueueADT.h"
using namespace std;

// constructor
QueueADT::QueueADT() {
	// TODO Auto-generated constructor stub
	// initialize queue variables for an empty queue
	front = -1;
	end = -1;
	counter = 0;
}

// function to insert an element in the queue
void QueueADT::insert(){
	// check if queue is full
	if(is_full() == true){
		cout << "\nOverflow. Cannot insert any more entries."; // display appropriate message if full
	}else{
		end = (end + 1) % SIZE; // set end to the next index in the array (0th if at last index)
		printer p1 = get_data(); // get data for new element in variable of printer datatype
		p[end] = p1; // store new element at index having ends value
		if(front == -1){ // increment front if new element is 1st entry in the queue
			front = end;
		}
		cout << "\nInsertion successful."; // display success message
		counter++; // increment counter
		cout << "\n\nFront = " << front << "\nEnd = " << end << "\nCounter = " << counter; // display values of all queue variables
	}
}

// function to delete an element in the queue
void QueueADT::delete_entry(){
	if(is_empty() == true){ // check if queue is empty
		cout << "\nUnderflow. Cannot delete any more elements."; // display appropriate message
	}else{
		sleep(3); // delay of 3 seconds

		// displaying data members in "page" format

		cout << "\n-----------------------------------------------------------------\n";
		cout << "|\t\t" << setw(18) <<  p[front].page_header << setw(18) << "\t\t|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|\t\t" << setw(18) <<  p[front].page_content << setw(18) << "\t\t|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "|\t\t" << setw(18) <<  p[front].page_footer << setw(18) << "\t\t|\n";
		cout << "|" << setw(65) << "|\n";
		cout << "-----------------------------------------------------------------\n";

		// end of page

		cout << "\nPage has been printed successfully\n"; // success message
		front = (front + 1) % SIZE; // increment front to point to next index in the array (0th if at last index)
		counter--; // decrement counter
		if(front == (end + 1) % SIZE) // if all elements are removed set front to -1, this is done to avoid ambiguity
			front = -1;
		cout << "\n\nFront = " << front << "\nEnd = " << end << "\nCounter = " << counter; // display values of all queue variables
	}
}

// function to check if queue is empty
bool QueueADT::is_empty(){
	if (front == -1) // front is set to -1 when last element is deleted
		return true;
	return false;
}

// function to check if queue is full
bool QueueADT::is_full(){
	if (front == (end + 1) % SIZE){ // front is 1 index ahead of end
		return true;
	}
	return false;
}

// function to get data for a new element
printer QueueADT::get_data(){
	printer p1; // declare variable of printer datatype
	bool flag = false; // flag variable for validation
	string page_num_str; // string for page number
	do{
		cout << "\n\nEnter page number you want to print: "; // prompt user to enter page number
		if(flag == true){ // if ongoing iteration is not 1st this will get executed
			cin.ignore();
		}
		cin >> page_num_str;
		for(int i = 0; i < page_num_str.length(); i++){ // loop through all indexes of the string
			if(isdigit((int)page_num_str[i]) == false){ // check if element at index is not a digit
				flag = true; // set flag for next itration
				cout << "\nPlease enter a number."; // display error message
				break; // break from for loop
			}else{
				flag = false; // set flag as false for current iteration
				continue; // continue with next iteration
			}
		}
	}while(flag == true); // keep asking for input untill an integer is entered
	p1.page_number = atoi(page_num_str.c_str()); // convert string to int and store value in array
	cout << "\nEnter page header: ";
	cin.ignore();
	cin.getline(p1.page_header, 25);
	cout << "\nEnter page content: ";
	cin.getline(p1.page_content, 100); // limit the number of input characters to 100
	cout << "\nEnter page footer: ";
	cin.getline(p1.page_footer, 25); // limit the number of input characters to 25
	return p1; // return printer variable with entered values
}

// function to display the elements of the queue
void QueueADT::display(){
	if(is_empty() == true){
		cout << "\nQueue is empty.\n\nFront = " << front << "\nEnd = " << end;
	}else{
		cout << "\nQueue is (page numbers):\n\n";
		cout << "Page Number\t\tPage Header\t\t\t\tSize\n\n"; // table headers
		for(int i = front; i != end; i = (i + 1) % SIZE){ // loop through all existing elements of array from front to end, i becomes 0 if at last index
			cout << p[i].page_number << "\t\t" << setw(18) <<  p[i].page_header << setw(18) << "\t\t" << sizeof(p[i]) << endl; // display in proper format
		}
		cout  << p[end].page_number << "\t\t\t" << p[end].page_header<< "\t\t\t\t" << sizeof(p[end])  << "\n\nFront = " << front << "\nEnd = " << end << "\nCounter = " << counter; // display content at end index since its not included in for loop
	}
}

// destructor
QueueADT::~QueueADT() {
	// TODO Auto-generated destructor stub
}

