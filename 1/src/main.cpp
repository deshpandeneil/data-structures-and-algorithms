//============================================================================
// Name        : studentDatabase.cpp
// Author      : Neil Deshpande 23121
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// define structure student

struct DOB{
	int dd, mm, yyyy;
};

struct student{

	// define data members

	DOB dob;

	string name, addr, rollNoStr, phNo;
	int rollNo;
	double total, sgpa, mrks[5];

};

// define class Database

class Database{

	// define data members

	student s[15];

	// declare member functions

public:

	string menu();
	int insertData(int, int);
	bool validateRollNo(string);
	bool validateDob(int, int, int);
	bool exists(int, int);
	void displayData(int);
	void sortByRollNo(int);
	void sortByName(int);
	void searchBySGPA(double, int);
	void searchByName(string, int);
	void sortBySGPA(int, int, int, int, int);

	// default constructor

	Database(){
		// empty
	}

};

// define above member functions one-by-one

// function to display menu

string Database::menu(){

	// variable to store user choice

	string option;

	// display menu

	cout << "\nMENU\n\n1. Insert Data\n2. Display Data\n3. Sort Data by roll number (bubble sort)\n4. Search by SGPA (linear search)\n5. Sort Database by name (insertion sort)\n6. Search by name (binary search)\n7. Sort by SGPA (quick sort)\n8. Exit\n"<< endl;

	// prompt user to enter his choice

	cout << "Enter the serial number of the operation you want to perform: ";
	cin >> option;

	// return user's option

	return option;

}

bool Database::validateDob(int dd, int mm, int yyyy){
	if(dd > 31 || dd < 1 || mm > 12 || mm < 1 || yyyy > 2020){
		return false;
	}
	if(mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12){
		if(dd > 31){
			return false;
		}
	}
	if(mm == 4 or mm == 6 or mm == 9 or mm == 11){
		if(dd > 30){
			return false;
		}
	}
	if(mm == 2){
		if(dd > 28){
			return false;
		}
	}
	return true;

}

// function to validate if entered roll number is an integer or not
// takes roll number string as input

bool Database::validateRollNo(string rollToCheck){

	// loop through all indexes of string

    for(int j = 0; j < rollToCheck.length(); j++){

    	// check if character is a not digit

        if(isdigit((int)rollToCheck[j]) == false){

        	// return false if element at index is not a digit

            return false;

        }

    }

    // by default return true

    return true;

}

// function to check if roll number already exists in database
// it takes roll number and student counter as parameters

bool Database::exists(int rollNo, int studentCounter){

	// loop through all elements which have data stored in it

    for(int i = 0; i < studentCounter; i++){

    	// check if roll number of element matches with passed roll number

        if(s[i].rollNo == rollNo){

        	// if a match is found, return true

            return true;

        }

    }

    // if match is not found, return false

    return false;

}

// function to insert data in the array/database
// takes two parameters, the number of entries and the location counter to decide the entry position in the array

int Database::insertData(int studentCounter, int n){

	// continue taking entries for entered number of students by the user

	for(int i = 0; i < n; i++){

		// variable for name validation

	    bool nameFlag;

	    // clear input stream for first iteration

	    if(i == 0){
    			cin.ignore();
    	}

	    do{
	    	// prompt user to enter name of student

    		cout << "\nEnter name of student " << studentCounter + 1 << ": ";
    		getline(cin, s[studentCounter].name, '\n');

    		// loop through all characters of the name string

    		for(int j = 0; j < s[studentCounter].name.length(); j++){

    			// check if character is a digit

    		    if(isdigit((int)s[studentCounter].name[j]) == true){

    		    	// set flag for re-iteration and display error

    		        nameFlag = true;
    		        cout << "\nPlease enter valid input. Name can only have characters in it.\n";
    		        break;

    		    } else {

    		    	// set flag to exit do-while loop

    		        nameFlag = false;
    		        continue;

    		    }

    		}

        } while(nameFlag == true); // loop continuously till correct name format is not entered

		// variable for roll number validation

        bool rollFlag;

        do{

        	// prompt user to enter roll number

    		cout << "Enter roll number of student " << studentCounter + 1 << ": ";
    		cin >> s[studentCounter].rollNoStr;

    		// call validation function to check if any characters are present in the roll number

    		bool isValid = validateRollNo(s[studentCounter].rollNoStr);

    		// if roll number is invalid, prompt user to re-enter correct input

    		if(isValid == false){

    			// set flag to iterate through do-while loop again

    		    rollFlag = true;
    		    cout << "\nPlease enter valid input. Roll number can only have positive integers in it.\n";

    		    // goes to the end of do-while loop to check for condition

    		    continue;

    		}

    		// if valid, convert the roll number from string to int and store

	        s[studentCounter].rollNo = atoi(s[studentCounter].rollNoStr.c_str());

	        if(s[studentCounter].rollNo < 1 || s[studentCounter].rollNo > 15){
	        	cout << "\nYour class can have at most 15 students and hence roll numbers from 0 to 15 only\n";
	        	rollFlag = true;
	        	continue;
	        }

	        // check if roll number already exists in the database

    		bool check = exists(s[studentCounter].rollNo, studentCounter);

	        if(check == true){

	        	// if it exists, set flag for next iteration of do-while loop

	            rollFlag = true;

	            // prompt user to re-enter the roll number

	            cout << "\nThis roll number already exists in the database.\n";
	            continue;

	        }

	        // if passes all validation tests above set flag to exit do-while loop

	        else{

	            rollFlag = false;

	        }

        } while(rollFlag == true); // loop continuously till correct number format is not entered


		// variable for phone number validation

        bool phFlag;

        do{

    		cout << "Enter phone number of student " << studentCounter + 1 << ": ";
    		cin >> s[studentCounter].phNo;

    		// loop through all characters of the phone number string

    		for(int j = 0; j < s[studentCounter].phNo.length(); j++){

    			// check if character is a not digit

    		    if(isdigit((int)s[studentCounter].phNo[j]) == false or s[studentCounter].phNo.length() > 10){

    		    	// set flag for re-iteration and display error

    		        phFlag = true;
    		        cout << "\nPlease enter valid input. Phone number can only have 10 positive integers in it.\n";
    		        break;

    		    } else {

    		    	// set flag to exit do-while loop

    		        phFlag = false;
    		        continue;

    		    }

    		}

    		if(s[studentCounter].phNo.length() != 10){
    			cout << "\nPhone number must have 10 digits in it\n";
				phFlag = true;
				continue;
			}

        } while(phFlag == true); // loop continuously till correct number format is not entered

        bool dobFlag;

        do{
        	cout << "Enter date of birth\ndd: ";
			cin >> s[studentCounter].dob.dd;
			cout << "mm: ";
			cin >> s[studentCounter].dob.mm;
			cout << "yyyy: ";
			cin >> s[studentCounter].dob.yyyy;
			bool check = validateDob(s[studentCounter].dob.dd, s[studentCounter].dob.mm, s[studentCounter].dob.yyyy);
			if(check == false){
				dobFlag = true;
				cout << "Please enter valid DOB.\n\n";
				continue;
			} else{
				dobFlag = false;
			}
        } while(dobFlag == true);


        // take address input

		cout << "Enter address of student " << studentCounter + 1 << ": ";

		// ignore input stream since there may exist a \n in it

		cin.ignore();
		getline(cin, s[studentCounter].addr, '\n');

		// variable for marks validation

		bool mrksFlag;

		// initialize total marks to zero

		s[studentCounter].total = 0;

		// take inputs for 5 subjects

		for(int j = 0; j < 5; j++){

		    do{

    		    cout << "Enter marks of subject " << j + 1 << ": ";
    		    cin >> s[studentCounter].mrks[j];

    		    // check if marks are not within required range

    		    if(s[studentCounter].mrks[j] > 100 or s[studentCounter].mrks[j] < 0){

    				// set flag to re-iterate do-while loop

    				mrksFlag = true;

    				// prompt user to re-enter in correct format

    				cout << "\nEnter valid marks! Marks can only have positive values less than one hundred.\n" << endl;

			    } else {

    				// set flag to exit do-while loop and continue next iteration of for loop

    				mrksFlag = false;

			    }

		    } while(mrksFlag == true); // loop continuously till correct marks format is not entered

		    // add entered marks to total

    		s[studentCounter].total += s[studentCounter].mrks[j];

		}

		// calculate SGPA after all marks have been entered

		s[studentCounter].sgpa = (s[studentCounter].total / 500) * 10;

		// ignore input stream before taking entry of next student

		cin.ignore();

		// increment student counter

		studentCounter ++;

	}

	// return the student counter for further use in other functions

	return studentCounter;

}

// function to display database, takes student counter as parameter

void Database::displayData(int studentCounter){

	// print headings
	cout << "\n=====================================================================================================\n";
	cout << "\nSr. No.\t\tName\t\t\t\t Roll No.\t          Total\t     SGPA\n";
	cout << "\n=====================================================================================================\n";

	// print database contents which have been filled

	for(int i = 0; i < studentCounter; i++){

		cout << "\n" << i + 1 << "\t|\t";
		cout << left << setfill(' ') << setw(25);
		cout << s[i].name << "\t|  ";
		cout << left << setfill(' ') << setw(6);
		cout << s[i].rollNo << "  |\t\t|   " << s[i].total << "\t |   "<< s[i].sgpa << "\t  |";

	}

	cout << "\n\n";

}

// function to sort data according to roll number (bubble sort)

// it takes array size as input

void Database::sortByRollNo(int studentCounter){

	int swaps = 0, comparisons = 0;
    student temporary; // temporary variable to hold student data type while swapping

    cout << "\n\nSorting...\n\n"; // display process name
    cout << "=======================================================================================================================================\n\n";
    cout << "Pass\t\t";
	cout << left << setfill(' ') << setw(25);
    cout << "List";
    cout << "\t\t\t\t\t\tComparisons\t\t\tSwap\n\n"; // display table headers
    	cout << "=======================================================================================================================================\n\n";

    for(int i = 0; i < studentCounter - 1; i ++){ // we need to make only n - 1 passes since in last pass only one element remains

    	cout << (i + 1) << "\t\t"; // display appropriate table entry data

    	for(int k = 0; k < studentCounter; k++){

    		cout << s[k].rollNo << ",";

    	}

    	// loop through all indexes of array till second last element
    	// last element is not considered otherwise comparison index will go out of bound

    	bool flag = false;

        for(int j = 0; j <  studentCounter - i - 1; j++){

        	if(j == 0){ // this if-else ladder has been added to present pass table in proper format with proper spacing

        		cout << left << setfill(' ') << setw(25);
        		cout << "\t";
        		cout << "    " << s[j].rollNo << "," << s[j + 1].rollNo << "\t\t\t";

        	} else {

        		cout << "\t\t\t";
				cout << left << setfill(' ') << setw(25);
        		cout << "\t\t\t\t\t";
        		cout << s[j].rollNo << "," << s[j + 1].rollNo << "\t\t\t";
        	}

            if(s[j].rollNo > s[j + 1].rollNo){ // if current index element is greater than element at next index the swap the two

            	flag = true;

            	cout <<"YES\n"; // print 'yes' under swap status field in pass table
            	swaps++;

                temporary = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temporary;

            } else { // if condition is not satisfied, do no operations

            	cout <<"NO\n"; // print 'no' under swap status field in pass table

            }
            comparisons++;

        }

        if(flag == false){
        	break;
		}

    }
    cout << "\n\nAnalysis\n\nInput Size: " << studentCounter << "\nTotal Comparisons: " << comparisons << "\nTotal swaps: " << swaps;
    int best = studentCounter - 1;
	int worst =  (studentCounter * (studentCounter - 1)) / 2;
    cout << "\n\nCase: ";
    if(comparisons == best){
    	cout << "Best";
	}
	else if(comparisons == worst){
		cout << "Worst";
	}
	else{
		cout << "Average";
	}


    cout << "\n\nData has been sorted in ascending order according to roll number.\n"; // display success message after sorting

}

// function to search database for a particular SGPA and print that entry (linear search)
// it takes SGPA and array size as parameter inputs

void Database::searchBySGPA(double score, int studentCounter){

    int occurence = 0; // occurrence acts as a counter to display status of search

    cout << "\n\nSearching...\n\n"; // display process name

	cout << "=================================================================\n";
    cout << "Index\t\tData at Index\t\tKey\t\tMatch\n\n"; // display pass table headers
    cout << "=================================================================\n\n";

    for(int j = 0; j < studentCounter; j++){ // loop through all elements of array

    	cout << (j + 1) << "\t\t" << s[j].sgpa << "\t\t\t" << score << "\t\t"; // display all data at current index

    	if(s[j].sgpa == score){ // check if key matches data at index and display appropriate data in table

    		cout << "YES\t" << endl;

    	} else {

    		cout << "NO\t" << endl;

    	}

    }

    // display table of matching results

    for(int i = 0; i < studentCounter; i++){

        if(score == s[i].sgpa){ // check if key matches data at index

            occurence++; // increment occurrence counter after getting each match

            if(occurence == 1){ // display table headers only when at least one element is matched

            	cout << "\n====================================================================================================\n";

	            cout << "\nSr. No.\t\tName\t\t\t\t Roll No.\t          Total\t     SGPA\n";

            	cout << "\n====================================================================================================\n";

            }

    		cout << "\n" << i + 1 << "\t|\t";
    		cout << left << setfill(' ') << setw(25);
    		cout << s[i].name << "\t|  ";
    		cout << left << setfill(' ') << setw(6);
    		cout << s[i].rollNo << "  |\t\t|   " << s[i].total << "\t |   "<< s[i].sgpa << "\t|";

        }

    }

    if(occurence ==0){ // if there is no occurrence of key display failure message

        cout << "\nNo match found.\n" << endl;

    } else {

        cout << "\n\n";

    }


}

// function to sort array alphabetically according to name (insertion sort)
// it takes array size as input parameter

void Database::sortByName(int studentCounter){

	student key; // create a key of student data type
	int j, swaps = 0; // variable for doing operations on indexes preceding key index
	cout << "=====================================================================================================================================================================";
	cout << "\n\nPass No.\t\t";
	cout << left << setfill(' ') << setw(25);
	cout << "list";
	cout << "\t\t\t\t\t\t\t\t\tNo. of comparisons\t\tNo. of swap\n" << endl;
	cout << "=====================================================================================================================================================================\n\n";
	for(int i = 1; i < studentCounter; i++){ // loop from first to last index of array

		key = s[i]; // take value of current index into key
		cout << i << "\t\t";
		for(int k = 0; k < studentCounter; k++){

			cout << s[k].name << ",";

		}
//		cout << left << setfill(' ') << setw(25);
		j = i - 1; // set j to 1 index lower than i
		while(j >= 0 && s[j].name.compare(key.name) > 0){ // compare data at index j with entered name

			swaps++;
			s[j + 1] = s[j]; // shift element at index j to the index above
			j = j - 1; // decrement j by 1 to do the same operation for all preceding indexes (as long as while condition is satisfied)

		}

		s[j + 1] = key; // insert the key data at its appropriate location in the array

		cout << "\t\t" << swaps + 1 << "\t\t\t\t" << swaps <<endl;

	}
	cout << "\n\nAnalysis\n\nInput Size: " << studentCounter << "\nTotal Comparisons: " << swaps + 1 << "\nTotal swaps: " << swaps;
    int best = 1;
	int worst =  ((studentCounter * studentCounter) - studentCounter) / 2;
    cout << "\n\nCase: ";
    if((swaps + 1) == best){
    	cout << "Best" << endl;
	}
	else if((swaps + 1) == worst + 1){
		cout << "Worst" << endl;
	}
	else{
		cout << "Average" << endl;
	}

}

// function to search name (binary search)
// it takes search key and array size as input parameters

void Database::searchByName(string searchName, int studentCounter){

	sortByName(studentCounter); // first sort the array alphabetically

	int occurence = 0, index, pass = 1; // create counter variable
	cout << "\n\n=========================================================================\n";
	cout << "\nPass\tLower\tUpper\tMid\tData at mid\t\t\tMatch\n"; // display pass table headers
	cout << "\n=========================================================================\n";

	int lower = 0, upper = studentCounter - 1, mid; // set lower and upper limit variables to first and last indexes of array

	while(lower <= upper){ // continue iterations till condition is satisfied

		cout << pass << "\t" << lower << "\t" << upper << "\t"; // display appropriate pass table contents
		pass++;
		mid = (upper + lower) / 2; // calculate middle index for each iteration
		cout << mid << "\t"; // display mid value in pass table

		if(s[mid].name.compare(searchName) == 0){ // compare entered string and data at index

			occurence++; // if matched then increment counter variable
			index = mid;
			cout << left << setfill(' ') << setw(25);
    		cout << s[mid].name << "\t" << "YES" << endl; // display appropriate data in pass table

		} else {

            cout << left << setfill(' ') << setw(25);
			cout << s[mid].name << "\t" << "NO" << endl; // display appropriate data in pass table

		}

		if(s[mid].name.compare(searchName) > 0){ // if search name exists on left side of mid then change value of upper limit

			upper = mid - 1;

		} else { // else change value of lower limit

			lower = mid + 1;

		}

	}

	if(occurence == 0){ // if occurrence counter is 0 display failure message

		cout << "\nNo entries for the given name found.";

	} else {

		cout << "\nFirst occurence of entered name found at index " << index << "\n\n";

	}

}

// function to sort the array according to sgpa (quicksort)
// it takes lower and upper limit of array size as parameters

void Database::sortBySGPA(int low, int high, int studentCounter, int swps, int comp) {

		int swaps = swps;
		int comparisons = comp;

		if (low < high) { // execute sort code only if lower limit is less than upper limit

			double pivot = s[low].sgpa; // select first element as pivot
			int i = (low + 1); // set starting index of i
			int j = high; // set starting index of j

			do {
				comparisons ++;
				while (s[i].sgpa > pivot && i <= high) { // i searches for element greater than pivot from left side of array
					i++;
				}
				comparisons ++;
				while (s[j].sgpa < pivot && j >= low) { // j searches for element less than pivot from right side of array
					j--;
				}

				if (i < j) { // swap the first occurrences of i and j if i is less than j
					student key = s[i];
					s[i] = s[j];
					s[j] = key;
					swaps++;
					i++; // set i for next iteration
					j--; // set j for next iteration
				}
			} while (i <= j); // re-iterate till i and j don't cross each other

			cout << "\n" << low << "\t" << high << "\t";

			for(int k = 0; k < studentCounter; k++){
				cout << s[k].sgpa << ",";
			}

			// if we reach here i and j have crossed each other
            // since j finds elements less than pivot we need to swap pivot with j

			student temporary = s[low];
			s[low] = s[j];
			s[j] = temporary;
			swaps++;

			cout << "\t\t\t" << pivot << "\t\t" << comparisons << "\t\t\t" << swaps;

			// now the array is divided into two halves in [less than pivot - pivot - greater than pivot] format
			// now we need to sort the two sub-arrays formed with the same process

			sortBySGPA(low, j - 1, studentCounter, swaps, comparisons); // set j to 1 index lower than new pivot index to sort left half
			sortBySGPA(j + 1, high, studentCounter, swaps, comparisons); // set i to 1 index greater than new pivot index to sort right half
		}

}

// main program starts here

int main() {

	// create class object

	Database db;
	bool optionFlag;

	// take menu operation input from user and execute respective function

	int option;
	string optionStr;

	// student counter to keep track of the number of entries filled in the array of structure

	int studentCounter = 0;

	do{

		optionStr = db.menu(); // create variable, call menu function and store user option in variable

//		bool emptyFlag;

		for(int j = 0; j < optionStr.length(); j++){

			// check if character is a not digit

		    if(isdigit((int)optionStr[j]) == false or optionStr.length() > 10){

		    	// set flag for re-iteration and display error

		        optionFlag = true;
		        cout << "\nPlease enter valid input.\n";
		        break;

		    } else {

		    	// set flag to exit do-while loop

		        optionFlag = false;
		        continue;

		    }

		}

		if(optionFlag == false){
			if(optionStr != "1" && optionStr != "8" && studentCounter == 0){
				optionFlag = true;
				cout << "\nYou need to make at least one entry before performing any other operations.\n";
				continue;
			} else {
				optionFlag = false;
			}
		}

//		option = atoi(optionStr.c_str());

	} while(optionFlag == true);

	option = atoi(optionStr.c_str());

	if(option == 8){ // if user selects exit at first go, exit

		cout << "\nThank you for using the database. See you soon!";
		return 0;

	}

	do{

		switch(option){ // switch user option variable

		case 1:{

			if(studentCounter == 15){
				cout << "\nDatabase full! You cannot accomodate any more students in your class.\n";
				break;
			}
			int n; // declare count variable

			// prompt user and take appropriate input

			cout << "\nEnter the number of students for whom you want to insert data (N): ";
			cin >> n;

			if(n < 1 || n > 15){
				cout << "\nN must be a positive integer less than or equal to 15 only\n";
			}
			else{
				// update student counter and call the insertion function
				studentCounter = db.insertData(studentCounter, n); // pass array size and count to function
			}
			break;

		}

		case 2:

			db.displayData(studentCounter); // display all data in array by calling display function and pass array size
			break;

		case 3:

			db.sortByRollNo(studentCounter); // call function to sort array by roll number and pass array size
			break;

		case 4:{

		    double score; // create variable for user input

		    // prompt user to input SGPA

		    cout << "\nEnter the SGPA you want to search: ";
		    cin >> score;

		    db.searchBySGPA(score, studentCounter); // call search function and pass user entered score and array size
		    break;

		}

		case 5:

		    db.sortByName(studentCounter); // call sort by name function and pass array size as parameter
		    break;

		case 6:{

			string searchName; // create variable for user input

			// prompt user to input name to be searched

 		    cout << "\nEnter the name you want to search: ";
 			cin.ignore();
 			getline(cin, searchName);

		    db.searchByName(searchName, studentCounter); // call search by name function and pass search string and array size as parameters
		    break;

		}

		case 7:{
			cout << "\n====================================================================================================================================\n";
			cout << "\nLow" << "\tHigh" << "\tList" << "\t\t\t\t\t\t\t\t\t\tPivot" << "\t    Comparisons\tSwaps" << endl;
			cout << "\n====================================================================================================================================\n";
			int swaps = 0, comparisons = 0;
			db.sortBySGPA(0, studentCounter - 1, studentCounter, swaps, comparisons);
			break;
		}

		default: // display default message

			cout << "\nPlease select appropriate option.\n";
			break;

		}

		// ask user for next menu choice

		optionStr = db.menu();
		option = atoi(optionStr.c_str());


	} while(option != 8); // re-iterate loop till condition is satisfied

	// exit message

	cout << "\nThank you for using the database. See you soon!";

	return 0;

}
