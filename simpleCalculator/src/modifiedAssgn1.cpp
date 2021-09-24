//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int menu(int x){
//
//	// display calculator operations
//	cout << "\n\nList of operations:" << endl << "\n1: Add" << "\t2: Subtract" << "\t3: Multiply" << "\t4: Divide" << "\t5: Calculate Remainder" << "\t6: Exit";
//
//	// take choice input
//	cout << "\n\nPlease type the sr. number of the operation you want to perform: " << endl;
//	cin >> x;
//
//	return x;
//
//}
//
//void add(){
//
//	// declare variables
//	float a, b, s;
//
//	// take inputs
//	cout << "\nEnter number 1: ";
//	cin >> a;
//	cout << "\nEnter number 2: ";
//	cin >> b;
//
//	// perform operation and display result
//	s = a + b;
//	cout << "\nThe addition of the numbers entered is : " << s;
//
//}
//
//void subtract(){
//
//	// declare variables
//	float a, b, d;
//
//	// take inputs
//	cout << "\nEnter number 1: ";
//	cin >> a;
//	cout << "\nEnter number 2: ";
//	cin >> b;
//
//	// perform operation and display result
//	d = a - b;
//	cout << "\nThe difference of the numbers entered is : " << d;
//
//}
//
//void multiply(){
//
//	// declare variables
//	float a, b, m;
//
//	// take inputs
//	cout << "\nEnter number 1: ";
//	cin >> a;
//	cout << "\nEnter number 2: ";
//	cin >> b;
//
//	// perform operation and display rounded result
//	m = a * b;
//	cout << "\nThe multiplication of the numbers entered is : " << round(m);
//
//}
//
//float division(double x, double y){
//
//	// declare variables
//	float q;
//
//	// perform operation and display result
//	q = x / y;
//	return q;
//
//}
//
//void oddEven(){
//
//	// declare variables
//	int a;
//
//	// take inputs
//	cout << "Enter the integer to be checked: ";
//	cin >> a;
//
//	// perform operations and display result
//	if(a % 2 == 0){
//
//		cout << "\nThe entered integer is even.";
//
//	}
//
//	else{
//
//		cout << "\nThe entered integer is odd.";
//
//	}
//
//}
//
//bool isPrime(){
//
//	// take inputs
//	int n;
//	cout << "Enter integer to be checked: ";
//	cin >> n;
//
//    // validate
//    if (n <= 1)
//
//        return false;
//
//    // check from 2 to n-1
//    for (int i = 2; i < n; i++)
//
//        if (n % i == 0)
//
//            return false;
//
//    return true;
//
//}
//
//int main(){
//
//	// declare variable for choice
//	int x;
//
//	// display a welcome message
//	cout << "Welcome to myCalculator." << endl;
//
//	// display menu
//	x = menu(x);
//
//	// check the choice and call the respective function
//	while(x != 6){
//
//		switch(x){
//
//			case 1:
//
//				// call function
//				add();
//				break;
//
//			case 2:
//
//				// call function
//				subtract();
//				break;
//
//			case 3:
//
//				// call function
//				multiply();
//				break;
//
//			case 4:
//
//				//declare variables
//				float ans;
//				double a, b;
//
//				// take inputs
//				cout << "Enter dividend: ";
//				cin >> a;
//				cout << "Enter divisor: ";
//				cin >> b;
//
//				// call function
//				ans = division(a, b);
//				cout << "\nThe division of the numbers entered is : " << ans;
//				break;
//
//			case 5:
//
//				// declare variables
//				double rem, x, y;
//
//				// take inputs
//				cout << "Enter dividend: ";
//				cin >> x;
//				cout << "Enter divisor: ";
//				cin >> y;
//
//				// call function
//				rem = remainder(x, y);
//				cout << "Remainder of the operation is: " << rem;
//				break;
//
//			default:
//				cout << "\nPlease select a valid sr. number!";
//
//		}
//
//		x = menu(x);
//
//	}
//
//	cout << "\nThe program has terminated. Thank you for using our calculator!";
//
//	return 0;
//
//}
