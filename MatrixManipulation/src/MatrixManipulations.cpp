/*
 * MatrixManipulations.cpp
 *
 *  Created on: 10-Dec-2020
 *      Author: Neil
 */

#include "MatrixManipulations.h"
#include<iostream>

using namespace std;

MatrixManipulations::MatrixManipulations() {
	// TODO Auto-generated constructor stub

	// initialize all data members
	r1 = r2 = c1 = c2 = 0;
	a = b = c = NULL;

}

void MatrixManipulations::input(){
	// ask for dimensions of matrix A
	cout << "\nEnter number of rows in matrix A: ";
	cin >> r1;
	cout << "\nEnter number of columns in matrix A: ";
	cin >> c1;

	// ask for dimensions of matrix B
	cout << "\nEnter number of rows in matrix B: ";
	cin >> r2;
	cout << "\nEnter number of columns in matrix B: ";
	cin >> c2;

	// allocate appropriate size of memory to both matrices
	a = new int [r1 * c1];
	b = new int [r2 * c2];

	// take user input for matrix A
	for(int i = 0; i < r1; i++){
		for(int j = 0; j < c1; j++){
			cout << "\nEnter A[" << i << ", " << j << "]: ";
			cin >> a[i * c1 + j];
		}
	}

	// take user input for matrix B
	for(int i = 0; i < r2; i++){
		for(int j = 0; j < c2; j++){
			cout << "\nEnter B[" << i << ", " << j << "]: ";
			cin >> b[i * c2 + j];
		}
	}
}

void MatrixManipulations::display(){
	// display matrix A
	cout << "\nMATRIX A:\n\n";
	for(int i = 0; i < r1; i++){
		for(int j = 0; j < c1; j++){
			cout << a[i * c1 + j] << "\t";
		}
		cout << "\n";
	}

	// display matrix B
	cout << "\nMATRIX B:\n\n";
	for(int i = 0; i < r2; i++){
		for(int j = 0; j < c2; j++){
			cout << b[i * c2 + j] << "\t";
		}
		cout << "\n";
	}
}

void MatrixManipulations::add(){
	// check if matrices can be added
	if(r1 * c1 == r2 * c2){
		c = new int [r1 * c1]; // if yes allocate appropriate memory size to resultant matrix

		for(int i = 0; i < r1; i++){ // traverse matrix row wise
			for(int j = 0; j < c1; j++){
				c[i * c1 + j] = a[i * c1 + j] + b[i * c2 + j]; // add corresponding elements of A and B and store in C
			}
		}

		display();

		// display C
		cout << "\nMATRIX C:\n\n";
		for(int i = 0; i < r1; i++){
			for(int j = 0; j < c1; j++){
				cout << c[i * c1 + j] << "\t";
			}
			cout << "\n";
		}
	}

	else
		cout << "\nEntered matrices are not of the same order, they cannot be added.\n";
}

void MatrixManipulations::subtract(){
	// check if matrices can be subtracted
	if(r1 * c1 == r2 * c2){
		c = new int [r2 * c2]; // if yes allocate appropriate memory size to resultant matrix

		for(int i = 0; i < r1; i++){ // traverse matrix row wise
			for(int j = 0; j < c1; j++){
				c[i * c2 + j] = a[i * c1 + j] - b[i * c2 + j]; // subtract corresponding elements of A and B and store in C
			}
		}

		display();

		// display C
		cout << "\nMATRIX C:\n\n";
		for(int i = 0; i < r2; i++){
			for(int j = 0; j < c2; j++){
				cout << c[i * c2 + j] << "\t";
			}
			cout << "\n";
		}
	}

	else
		cout << "\nEntered matrices are not of the same order, they cannot be subtracted.\n";
}

void MatrixManipulations::multiply(){
	// check if matrices can be multiplied
	if(c1 == r2){
		c = new int [r1 * c2]; // if yes allocate appropriate memory size to resultant matrix

		for(int i = 0; i < r1; i++){ // traverse matrix row wise
			for(int j = 0; j < c2; j++){
				c[i * c2 + j] = 0; // initialize matrix C since result of multiplication is added to previous value
			}
		}

		for(int i = 0; i < r1; ++i){
			for(int j = 0; j < c2; ++j){
				for(int k = 0; k < c1; ++k){
					c[i * c2 + j] += a[i * c1 + k] * b[k * c2 + j]; // multiply row of A and column of B and add to element in C
				}
			}
		}

		display();

		// display C
		cout << "\nMATRIX C:\n\n";
		for(int i = 0; i < r1; i++){
			for(int j = 0; j < c2; j++){
				cout << c[i * c2 + j] << "\t";
			}
			cout << "\n";
		}
	}
	else
		cout << "\nEntered matrices cannot be multiplied. Number of columns in A must be equal to number of rows in B for multiplication.\n";
}

void MatrixManipulations::transpose(char t){
	if(t == 'A'){
		c = new int [r1 * c1];

		for (int i = 0; i < r1; i++) {
			for(int j = 0; j < c1; j++) {
				c[j * c1 + i] = a[i * c1 + j]; // Cji = Aij
			}
		}

		display();

		// display C
		cout << "\nMATRIX C:\n\n";
		for(int i = 0; i < r1; i++){
			for(int j = 0; j < c1; j++){
				cout << c[i * c1 + j] << "\t";
			}
			cout << "\n";
		}
	}
	else if(t == 'B'){
		c = new int [r2 * c2];

		for (int i = 0; i < r2; i++) {
			for(int j = 0; j < c2; j++) {
				c[j * c2 + i] = b[i * c2 + j]; // Cji = Bij
			}
		}

		display();

		// display C
		cout << "\nMATRIX C:\n\n";
		for(int i = 0; i < r2; i++){
			for(int j = 0; j < c2; j++){
				cout << c[i * c2 + j] << "\t";
			}
			cout << "\n";
		}
	}
	else
		cout << "\nSome error has occurred.\n";
}

MatrixManipulations::~MatrixManipulations() {
	// TODO Auto-generated destructor stub
}

