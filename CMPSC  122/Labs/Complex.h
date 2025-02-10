// Academic Integrity Affidavit:
// I certify that this program code is my work. Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: <Ryan Reagle>
// Section: <003L>
// Assignment: Lab 04
//

//
// A Complex object holds one Complex number
//

#ifndef COMPLEX_H
#define COMPLEX_H
class Complex
{ // not fully commented
public:
   Complex(double re = 0.0, double im = 0.0); // default constructor
   Complex add(const Complex &z);
   Complex subtract(const Complex &z);
   Complex multiply(const Complex &z);
   Complex divide(const Complex &z);
   double modulus();
   bool equal(const Complex &z);
   void print(bool is_parenthesis = false);

private:
   double re; // real part
   double im; // imaginary part
};

#endif
