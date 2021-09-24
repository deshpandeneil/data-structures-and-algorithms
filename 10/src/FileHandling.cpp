/*
 * FileHandling.cpp
 *
 *  Created on: 10-Dec-2020
 *      Author: Neil
 */

#include "FileHandling.h"

#include<fstream>
#include<cctype>
#include<iomanip>


FileHandling::FileHandling() {
	// TODO Auto-generated constructor stub

}

void FileHandling::createDatabase(){
	fstream file;//create new file object
	file.open(FILE_PATH, ios::out);//open file in output mode
	int n;

	cout << "How many records do you wish to enter?: ";
	do{ // loop till proper data type is not entered
		cin >> n;
		if(!cin.good()){
			cout << "\nPlease enter a +ve integer: ";
			cin.clear();
			cin.ignore();
		}
		else
			break;
	}while(true);

	for(int i = 0; i < n; i++){ // loop n times
		cout << "Enter name of student " << i + 1 << ": ";
		cin.ignore();
		getline(cin, s.name, '\n'); // name

		cout << "Enter Address of student " << i + 1 << ": ";
		getline(cin, s.address); // address

		cout << "Enter Roll Number of student " << i + 1 << ": ";
		do{ // loop till proper data type is not entered
			cin >> s.roll;
			if(!cin.good()){
				cout << "\nPlease enter a +ve integer: ";
				cin.clear();
				cin.ignore();
			}
			else
				break;
		}while(true);

		cout<<"Enter Division (1 to 11) of student " << i + 1 << ": ";
		do{ // loop till proper data type is not inserted
			cin>>s.div;
			if(!cin.good()){
				cout << "\nPlease enter a +ve integer: ";
				cin.clear();
				cin.ignore();
				continue;
			}
			else if(s.div < 1 || s.div > 11){ // check if division is within limits
				cout<<"\nDivision should be between 1 and 11 only. Enter again: ";
				continue;
			}
			else
				break;
		}while(true);
		file.write((char*)&s, sizeof(s));//write the details of student in file
	}

	file.close();//close file

}

void FileHandling::addEntries(){
	fstream file;//create new file object
	file.open(FILE_PATH, ios::app);//open file in output mode
	int n;

	cout << "How many records do you wish to enter?: ";
	do{ // loop till proper data type is not entered
		cin >> n;
		if(!cin.good()){
			cout << "\nPlease enter a +ve integer: ";
			cin.clear();
			cin.ignore();
		}
		else
			break;
	}while(true);

	for(int i = 0; i < n; i++){ // loop n times
		cout << "Enter name of new student " << i + 1 << ": ";
		cin.ignore();
		getline(cin, s.name, '\n'); // name

		cout << "Enter Address of new student " << i + 1 << ": ";
		getline(cin, s.address); // address

		cout << "Enter Roll Number of new student " << i + 1 << ": ";
		do{ // loop till proper data type is not entered
			cin >> s.roll;
			if(!cin.good()){
				cout << "\nPlease enter a +ve integer: ";
				cin.clear();
				cin.ignore();
			}
			else
				break;
		}while(true);

		cout<<"Enter Division (1 to 11) of new student " << i + 1 << ": ";
		do{ // loop till proper data type is not inserted
			cin>>s.div;
			if(!cin.good()){
				cout << "\nPlease enter a +ve integer: ";
				cin.clear();
				cin.ignore();
				continue;
			}
			else if(s.div < 1 || s.div > 11){ // check if division is within limits
				cout<<"\nDivision should be between 1 and 11 only. Enter again: ";
				continue;
			}
			else
				break;
		}while(true);
		file.write((char*)&s, sizeof(s));//write the details of student in file
	}

	file.close();//close file
}

void FileHandling::deleteEntry(){
	int key;
	// open database file in input mode
	// open new temp file in output mode
	fstream file(FILE_PATH,ios::in), temp("temp.txt", ios::out);
	cout << "Enter Roll Number to be deleted: ";
	do{ // loop till valid data type is not entered
		cin >> key; // take roll number to be deleted
		if(!cin.good()){
			cout << "\nPlease enter a +ve integer: ";
			cin.clear();
			cin.ignore();
		}
		else
			break;
	}while(true);
	while (file.read((char*)&s, sizeof(student))){ // run until file has data present in it
		if(s.roll != key) // if roll number is not matching write the data from database file to temp
			temp.write((char*)&s, sizeof(student));
		else
			continue; // if roll number found skip that data
	}

	file.close();//close and save both files
	temp.close();

	remove("database.txt"); // remove old file
	rename("temp.txt", "database.txt"); // rename new file to same name as old one

}

void FileHandling::searchDatabase(){
	fstream file(FILE_PATH,ios::in); // open file in input mode
	int key;
	cout << "Enter Roll Number you want to search: ";
	do{ // loop till valid data type is not entered
		cin >> key; // take roll number to be deleted
		if(!cin.good()){
			cout << "\nPlease enter a +ve integer: ";
			cin.clear();
			cin.ignore();
		}
		else
			break;
	}while(true);
	cout<<"==================================================\n";
	cout<<"Roll no."<<setw(10)<<"Name"<<setw(10)<<"Division"<<setw(10)<<"Address\n";
	cout<<"==================================================\n";
	while(file.read((char*)&s,sizeof(s))){ // run until file has data present in it
		if(s.roll==key){ // if found print it
			cout << s.roll << setw(15) << s.name << setw(10) << s.div << setw(10) << s.address;
			return; // get out of function if found
		}
	}
	cout<<"Student with the entered roll number not found\n";
}

void FileHandling::displayDatabase(){
	fstream file(FILE_PATH, ios::in);//open file in input mode
	if(!file){//check if file can be opened
		cout<<"\nFile cannot be opened or does not exist.\n";
		return;
	}//display data
	cout << "==================================================\n";
	cout << "Sr.No." << setw(10) << "Roll No." << setw(10) << "Name" << setw(10) << "Division" << setw(10) << "Address\n";
	cout<<"==================================================\n";
	int i=0;
	while(file.read((char*)&s,sizeof(s))){
		cout << i+1 << setw(10) << s.roll << setw(15) << s.name << setw(10) << s.div << setw(10) << s.address << "\n";
		i++;
	}
	file.close();//close file
}

FileHandling::~FileHandling(){
	// TODO Auto-generated destructor stub
}

