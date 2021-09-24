/*
 * FileHandling.h
 *
 *  Created on: 10-Dec-2020
 *      Author: Neil
 */

#ifndef FILEHANDLING_H_
#define FILEHANDLING_H_

#include<iostream>

using namespace std;

struct student{// structure for data of student
	int roll, div;
	string name, address;
};

class FileHandling{
	student s; // structure object
	string FILE_PATH="database.txt"; // file path
public:
	FileHandling();

	void createDatabase();
	void searchDatabase();
	void addEntries();
	void deleteEntry();
	void displayDatabase();

	virtual ~FileHandling();

};

#endif /* FILEHANDLING_H_ */
