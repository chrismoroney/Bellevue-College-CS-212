#include "Complex.h"
// Testing program to follow operator overloading assignment
// by W.P. Iverson, April 2019
// for CS212 class

int main()
{
	Complex number0();
	Complex number1(3.5,5.5);
	Complex number2(-3.5,1);
	Complex number3(3);

	cout << (number1.add(number2)) << endl;		// 0 + 6.5i
	cout << (number1.subtract(number2)) << endl;	// 7 + 4.5i
	cout << (number1.multiply(number2)) << endl;	// -17.75 + -15.75i
	cout << (number1.divide(number2)) << endl;		// -0.509434 + -1.71698i
	cout << "|" << number1 << "|" << " = " << number1.abs() << endl;  // 6.5192

	cout << "(" << number1 << ")" << " + " << "(" << number2 << ") = " << (number1 + number2) << endl;
	cout << "(" << number1 << ")" << " - " << "(" << number2 << ") = " << (number1 - number2) << endl;
	cout << "(" << number1 << ")" << " * " << "(" << number2 << ") = " << (number1 * number2) << endl;
	cout << "(" << number1 << ")" << " / " << "(" << number2 << ") = " << (number1 / number2) << endl;

	// overloaded []
	number1[0] = 3.4;
	cout << number1[0] << endl;			// 3.4
	cout << -number1 << endl;			// -3.4 + -5.5i
	cout << number2++ << endl;			// -3.5 + 1i
	cout << number2 << endl;			// -2.5 + 1i
	cout << ++number2 << endl;			// -1.5 + 1i
	cout << number2-- << endl;			// -1.5 + 1i
	cout << number2 << endl;			// -2.5 + 1i
	cout << --number2 << endl;			// -3.5 + 1i
	cout << (3 + number2) << endl;		// -0.5 + 1i
	cout << (number2 += number1) << endl;		// -0.1 + 6.5i
	cout << (number2 *= number1) << endl;		// -36.09 + 21.55i

	cout << "Type in the last complex number (a b): ";
	cin >> number3;
	cout << number3.to_string() << endl;

	// overloaded with writing operators???
	// now we know why its called "overload"
	return 0;
}
