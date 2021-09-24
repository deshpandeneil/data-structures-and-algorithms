//============================================================================
// Name        : decToBin.cpp
// Author      : Neil Deshpande
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int dec, i;
	int bin[10];
	cout << "\n\nEnter the decimal number to convert (less than 1024): ";
	cin >> dec;
	for(i = 0; dec > 0; i++){
		bin[i] = dec % 2;
		dec = dec / 2;
	}
	cout << "\n\nBinary value of entered decimal number is: ";
	for(int j = i - 1; j >= 0; j--)
		cout << bin[j];
	return 0;
}
