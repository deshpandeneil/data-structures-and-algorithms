//============================================================================
// Name        : complex.cpp
// Author      : Neil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class complex {

	// declare data members

	float real, img;

	// declare member functions

public:

	// default constructor
	  complex() {
		real = 0;
		img = 0;
	}

	// parameterized constructor
	  complex(float x, float y) {
		real = x;
		img = y;
	}

	// getter function for real part
	  float getReal() {
		return real;
	}

	// getter function for img part
	  float getImg() {
		return img;
	}

	// setter function to set values of data members
	  void assign(float x, float y) {
		real = x;
		img = y;
	}

	// add function to add two complex numbers
	// it takes two objects of class complex as parameters
	// result is stored in calling object
	  void Add(complex o1, complex o2) {
		real = o1.getReal() + o2.getReal();
		img = o1.getImg() + o2.getImg();
	}

	// add function to subtract two complex numbers
	// it takes two objects of class complex as parameters
	// result is stored in calling object
	  void Sub(complex o1, complex o2) {
		real = o1.getReal() - o2.getReal();
		img = o1.getImg() - o2.getImg();
	}

	// add function to multiply two complex numbers
	// it takes two objects of class complex as parameters
	// result is stored in calling object
	  void Mul(complex o1, complex o2) {
		real = (o1.getReal() * o2.getReal()) + ((o1.getImg() * o2.getImg()) * (-1));
		img = (o1.getReal() * o2.getImg()) + (o1.getImg() * o2.getReal());
	}

	// add function to divide two complex numbers
	// it takes two objects of class complex as parameters
	// result is stored in calling object
	  void Div(complex o1, complex o2) {
		float denominator = ((o2.getReal() * o2.getReal()) + (o2.getImg() * o2.getImg()));
		real = ((o1.getReal() * o2.getReal()) + (o1.getImg() * o2.getImg())) / denominator;
		img = ((o2.getReal() * o1.getImg()) - (o1.getReal() * o2.getImg())) / denominator;
	}

	// display function to display the complex number in rectangular form
	  void display(complex o) {

		// check if img part is +ve or -ve and display with proper signs
		if(o.getImg() > 0) {
			cout << o.getReal() << " + " << abs(o.getImg()) << "i";
		} else {
			cout << o.getReal() << " - " << abs(o.getImg()) << "i";
		}
	}
};

int main() {

	// declare a menu variable to drive menu
	int option;
	float x, y, a, b;

	// display menu and prompt user to select an option
	cout << "\nMENU\n\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit";
	cout << "\n\nEnter the serial number of the operation you want to perform: ";

	// take user input into menu variable
	cin >> option;

	// make a do-while loop to carry out operations continuously
	do {
		// if exit menu option is selected then exit do-while loop
		// else proceed
		if(option == 5) {
			break;
		}

		// take user input for real and imaginary part of complex number 1
		cout <<("\nEnter real part of number 1: ");
		cin >> x;
		cout <<("Enter imaginary part of number 1: ");
		cin >> y;

		// create object of class complex
		// object is created using default constructor
		complex c1;
		// set above entered values to the object's data members using setter function
		c1.assign(x, y);

		// take user input for real and imaginary part of complex number 2
		cout <<("Enter real part of number 2: ");
		cin >> a;
		cout <<("Enter imaginary part of number 2: ");
		cin >> b;

		// create another object of class complex
		// pass above entered values as parameters to its constructor
		complex c2(a, b);

		// create third object to store results of operation
		complex c;

		// switch the menu variable and call respective operation function
		switch(option) {
		case 1:

			c.Add(c1, c2);
			cout <<("\nSum of entered complex numbers is: ");
			c.display(c);
			break;

		case 2:

			c.Sub(c1, c2);
			cout <<("\nSubtraction of entered complex numbers is: ");
			c.display(c);
			break;

		case 3:

			c.Mul(c1, c2);
			cout <<("\nMultiplication of entered complex numbers is: ");
			c.display(c);
			break;

		case 4:

			c.Div(c1, c2);
			cout <<("\nDivision of entered complex numbers is: ");
			c.display(c);
			break;

			// enter the default message for validation
		default:

			cout <<("Please enter a valid option number.");
		}

		// display menu again and prompt user to select an option
		cout <<("\nMENU\n\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit");
		cout <<("\n\nEnter the serial number of the operation you want to perform: ");

		// take user input into menu variable
		cin >> option;

	} while(option != 5); // exit do-while loop if exit menu option is selected otherwise re-iterate

	cout <<("\nThank you for viewing this demo.");

	return 0;

}
