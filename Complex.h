// Chris Moroney
// Iverson
// CS212 online section
// Program 3
// Due 28 May 2019

// used for ostream and istream to place data in a stream to be inputted or outputted
#include <sstream>
// used to be able to use strings and to clearly define an input/output (cout, cin)
#include <iostream>

using namespace std;

class Complex {
	// operators that direct access to the private fields because they couldn't be called on
	// individually from the public
	friend Complex& operator<<(Complex& realNum, const int imaginaryNum);
	friend ostream& operator<<(ostream& returnStream, const Complex& complex);
	friend istream& operator>>(istream& inputStream, Complex& complex);

private:
	// real number, needs to be private so that the Complex number can be defined clearly, and can be differentiated
	double m_a;
	// imaginary number, needs to be private for same reason
	double m_b;
public:
	// constructors
	Complex();
	Complex(double);
	Complex(double, double);
	// retreivers
	double getRealPart() const;
	double getImaginaryPart() const;
	// basic math tools to be used for refernce in each overload operator
	Complex add(const Complex&) const;
	Complex subtract(const Complex&) const;
	Complex multiply(const Complex&) const;
	Complex divide(const Complex&) const;
	double abs() const;
	// toString method
	string toString() const;
	// overload operators that are specific to the complex number
	double& operator[](const int& index);
	Complex &operator+=(Complex &secondComplex);
	Complex &operator-= (Complex &secondComplex);
	Complex &operator*=(Complex &secondComplex);
	Complex &operator/=(Complex &secondComplex);
	Complex operator=(Complex);
	// prefixes
	Complex &operator++(); 
	Complex &operator--(); 
	// postfixes
	Complex operator++(int dummy); 
	Complex operator--(int dummy); 
	// unary(s)
	Complex operator+();   
	Complex operator-(); 
	
};

// overload operators that are considered a non-member function
Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);


// constructors

// default constructor, both the real number and imaginary number are 0
Complex::Complex(){
	m_a = 0;
	m_b = 0;
}
// constructor where real number is provided, but imaginary number is 0
Complex::Complex(double a){
	m_a = a;
	m_b = 0;
}
// constructor where both real number and imaginary number are defined
Complex::Complex(double a, double b){
	m_a = a;
	m_b = b;
}

// retrievers

// returns the value of the real Number
double Complex::getRealPart() const{
	return m_a;
}
// returns the value of the imaginary number
double Complex::getImaginaryPart() const{
	return m_b;
}


// basic math tools

// adds the real number and imaginary number to that of an already existing complex number
// class specific because a complex number is calling on the method to add that complex number to itself
Complex Complex::add(const Complex& secondComplex) const {
	double newReal = m_a + secondComplex.getRealPart();
	double newImaginary = m_b + secondComplex.getImaginaryPart();
	return Complex(newReal, newImaginary);
}
// subtracts the real number and imaginary number to that of an already existing complex number
// class specific because a complex number is calling on the method to subtract that complex number to itself
Complex Complex::subtract(const Complex& secondComplex) const {
	double newReal = m_a - secondComplex.getRealPart();
	double newImaginary = m_b - secondComplex.getImaginaryPart();
	return Complex(newReal, newImaginary);
}
// multiplies the real number and imaginary number to that of an already existing complex number
// class specific because a complex number is calling on the method to multiply that complex number to itself
Complex Complex::multiply(const Complex& secondComplex) const {
	double newReal = m_a * secondComplex.getRealPart() - m_b * secondComplex.getImaginaryPart();
	double newImaginary = m_b * secondComplex.getRealPart() + m_a * secondComplex.getImaginaryPart();
	return Complex(newReal, newImaginary);
}
// divides the real number and imaginary number by that of an already existing complex number
// class specific because a complex number is calling on the method to divides by that complex number
Complex Complex::divide(const Complex& secondComplex) const {
	double newReal = (m_a * secondComplex.getRealPart() + m_b * secondComplex.getImaginaryPart())
		/ (pow(secondComplex.getRealPart(), 2.0) + pow(secondComplex.getImaginaryPart(), 2.0));
	double newImaginary = (m_b * secondComplex.getRealPart() - m_a * secondComplex.getImaginaryPart())
		/ (pow(secondComplex.getRealPart(), 2.0) + pow(secondComplex.getImaginaryPart(), 2.0));
	return Complex(newReal, newImaginary);
}
// using the graph visual from Canvas, the absolute value is the line formed between the 
// real number and imaginary number, to enclose a triangle. The equation for the length of the line 
// is as follow:
double Complex::abs() const {
	return sqrt(pow(m_a, 2) + pow(m_a, 2));
}


//toString 

// returns a string that prints out the contents of a complex number in form of (a + bi)
string Complex::toString() const {
	stringstream returnString;
	returnString << m_a;
	if (m_b != 0)
		returnString << " + " << m_b << "i";
	return returnString.str();
}


// overload operators


// returns either the value of the real or imaginary number, depending on the input (i) of the 
// complex number
double& Complex::operator[](const int& i) {
	if (i == 0) {
		return m_a;
	} else {
		return m_b;
	}	
}
// returns a complex number that is added to and equaled to its active value (not just added for an instance)
// uses the pointer so that we know that this value is being changed and still stay with this variable to this complex number
Complex& Complex::operator+=(Complex& adder) {
	*this = this->add(adder);
	return *this;
}
// returns a complex number that is subtracted to and equaled to its active value (not just subtracted for an instance)
// uses the pointer so that we know that this value is being changed and still stay with this variable to this complex number
Complex& Complex::operator-=(Complex& subtracter) {
	*this = this->subtract(subtracter);
	return *this;
}
// returns a complex number that is multiplied to and equaled to its active value (not just multplied for an instance)
// uses the pointer so that we know that this value is being changed and still stay with this variable to this complex number
Complex& Complex::operator*=(Complex& multiplier) {
	*this = this->multiply(multiplier);
	return *this;
}
// returns a complex number that is divided by and equaled to its active value (not just divided for an instance)
// uses the pointer so that we know that this value is being changed and still stay with this variable to this complex number
Complex& Complex::operator/=(Complex& divider) {
	*this = this->divide(divider);
	return *this;
}
// sets the real and imaginary values of the calling complex number to the components of the called complex number
Complex Complex::operator=(Complex equaler) {
	m_a = equaler.m_a;
	m_b = equaler.m_b;
	return equaler;
}
// Prefix that adds one (or whatever other value) before setting it equal to the real number
Complex& Complex::operator++() {
	++m_a;
	return *this;
}
// // Prefix that subtracts one (or whatever other value) before setting it equal to the real number
Complex& Complex::operator--() {
	--m_a;
	return *this;
}
// Postfix that sets the real number equal to a value, and then returns adjusted to whatever added number
Complex Complex::operator++(int makePostFixInstead) {
	Complex returnComplex(m_a, m_b);
	m_a += 1;
	return returnComplex;
}
// Postfix that sets the real number equal to a value, and then returns adjusted to whatever subtracted number
Complex Complex::operator--(int makePostFixInstead) {
	Complex returnComplex(m_a, m_b);
	m_a -= 1;
	return returnComplex;
}
// Unary that sets both the real and imaginary number to postive for an instant 
Complex Complex::operator+() {
	return *this;
}
// Unary that sets both the real and imaginary number to negative for an instant 
Complex Complex::operator-() {
	return Complex(-m_a, -m_b);
}


// these are all the friend methods. 


// moves value inside Complex one to the left, so imaginary number shifts over (similar
// to bits) to the real number, and set the new imaginary number to be 0 for now. 
Complex& operator<<(Complex& realNum, const int imaginaryNum){
	realNum.m_a = imaginaryNum;
	realNum.m_b = 0;
	return realNum;
}

// ostream allows for our data to be able to be inputed and then printed. Complex needed in order
// to specify which variables from which complex will be printed
ostream &operator<<(ostream &returnStream, const Complex &complex){
  if (complex.m_b == 0)
    returnStream << complex.m_a;
  else
    returnStream << complex.m_a << " + " << complex.m_b << "i";
  return returnStream;
}

// istream allows for our data to be able to be inputted. 
istream &operator>>(istream &inputStream, Complex &complex){
  cout << "Enter a and b for (a + bi): ";
  inputStream >> complex.m_a;
  inputStream >> complex.m_b;
  return inputStream;
}


// non-member function

// adds two complex numbers together
Complex operator+(const Complex& first, const Complex& second) {
	return first.add(second);
}
// subtracts two complex numbers together
Complex operator-(const Complex& first, const Complex& second) {
	return first.subtract(second);
}
// multiplies two complex numbers together
Complex operator*(const Complex& first, const Complex& second) {
	return first.multiply(second);
}
// divides two complex numbers by eachother
Complex operator/(const Complex& first, const Complex& second) {
	return first.divide(second);
}

