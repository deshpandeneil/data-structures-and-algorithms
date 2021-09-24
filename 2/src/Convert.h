/*
 * Convert.h
 *
 *  Created on: 30-Sep-2020
 *      Author: Neil
 */

#ifndef CONVERT_H_
#define CONVERT_H_

#include <iostream>

class Convert {
public:
	Convert();

	bool associativity(char);
	int precedence(char);

	char* infix_to_postfix(char*);
	void evaluate_postfix(char*);

	char* infix_to_prefix(char*);
	void evaluate_prefix(char*);

	virtual ~Convert();
};

#endif /* CONVERT_H_ */
