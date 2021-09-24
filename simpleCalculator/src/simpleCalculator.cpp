//============================================================================
// Name        : simpleCalculator.cpp
// Author      : Neil Deshpande 23121
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, ANSI-style
//============================================================================

#include <iostream>
#include <cmath>

using namespace std;

// define class Calculator
class Calculator{

public:

	// declare member functions
	int menu(int);
	void add();
	void subtract();
	void multiply();
	float division(double, double);
	void oddEven();
	bool isPrime();

};

// define above declared member function one-by-one

int Calculator::menu(int x){

	// display calculator operations
	cout << "\n\nList of operations:" << endl << "\n1: Add" << "\t2: Subtract" << "\t3: Multiply" << "\t4: Divide" << "\t5: Calculate Remainder" << "\t6: Check if odd or even" << "\t\t7: Check if prime" << "\t8: Exit";

	// take choice input
	cout << "\n\nPlease type the sr. number of the operation you want to perform: " << endl;
	cin >> x;

	return x;

}

void Calculator::add(){

	// declare variables
	float a, b, s;

	// take inputs
	cout << "\nEnter number 1: ";
	cin >> a;
	cout << "\nEnter number 2: ";
	cin >> b;

	// perform operation and display result
	s = a + b;
	cout << "\nThe addition of the numbers entered is : " << s;

}

void Calculator::subtract(){

	// declare variables
	float a, b, d;

	// take inputs
	cout << "\nEnter number 1: ";
	cin >> a;
	cout << "\nEnter number 2: ";
	cin >> b;

	// perform operation and display result
	d = a - b;
	cout << "\nThe difference of the numbers entered is : " << d;

}

void Calculator::multiply(){

	// declare variables
	float a, b, m;

	// take inputs
	cout << "\nEnter number 1: ";
	cin >> a;
	cout << "\nEnter number 2: ";
	cin >> b;

	// perform operation and display result
	m = a * b;
	cout << "\nThe multiplication of the numbers entered is : " << round(m);

}

float Calculator::division(double x, double y){

	// declare variables
	float q;

	// perform operation and display result
	q = x / y;
	return q;

}

void Calculator::oddEven(){

	// declare variables
	int a;

	// take inputs
	cout << "Enter the integer to be checked: ";
	cin >> a;

	// perform operations and display result
	if(a % 2 == 0){

		cout << "\nThe entered integer is even.";

	}

	else{

		cout << "\nThe entered integer is odd.";

	}

}

bool Calculator::isPrime(){

	// take inputs
	int n;
	cout << "Enter integer to be checked: ";
	cin >> n;

    // validate
    if (n <= 1)

        return false;

    // check from 2 to n-1
    for (int i = 2; i < n; i++)

        if (n % i == 0)

            return false;

    return true;

}

int main(){

	// declare variable for choice
	int x;
	Calculator c;

	// display a welcome message
	cout << "Welcome to myCalculator." << endl;

	// display menu
	x = c.menu(x);

	// check the choice and call the respective function
	while(x != 8){

		switch(x){

			case 1:

				// call function
				c.add();
				break;

			case 2:

				// call function
				c.subtract();
				break;

			case 3:

				// call function
				c.multiply();
				break;

			case 4:

				//declare variables
				float ans;
				double a, b;

				// take inputs
				cout << "Enter dividend: ";
				cin >> a;
				cout << "Enter divisor: ";
				cin >> b;

				// call function
				ans = c.division(a, b);
				cout << "\nThe division of the numbers entered is : " << ans;
				break;

			case 5:

				// declare variables
				double rem, x, y;

				// take inputs
				cout << "Enter dividend: ";
				cin >> x;
				cout << "Enter divisor: ";
				cin >> y;

				// call function
				rem = remainder(x, y);
				cout << "Remainder of the operation is: " << rem;
				break;

			case 6:

				// call function
				c.oddEven();
				break;

			case 7:

				// declare variable
				bool result;

				// call function
				result = c.isPrime();

				// display result
				if(result == true){

					cout << "\nEntered integer is prime.";

				}

				else{

					cout << "\nEntered integer is not prime.";

				}
				break;

			default:
				cout << "\nPlease select a valid sr. number!";

		}

		x = c.menu(x);

	}

	cout << "\nThe program has terminated. Thank you for using our calculator!";

	return 0;

}
