/*
 * MatrixManipulations.h
 *
 *  Created on: 10-Dec-2020
 *      Author: Neil
 */

#ifndef MATRIXMANIPULATIONS_H_
#define MATRIXMANIPULATIONS_H_

class MatrixManipulations {
	int r1, c1, r2, c2, *a, *b, *c;
public:
	MatrixManipulations();

	// utility functions
	void input();
	void display();

	// arithmetic functions
	void add();
	void subtract();
	void multiply();
	void transpose(char);

	virtual ~MatrixManipulations();
};

#endif /* MATRIXMANIPULATIONS_H_ */
