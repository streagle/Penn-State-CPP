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
// a Complex object holds one Complex number
//
#include "Complex.h"
#include <iostream>
#include <cmath>
using namespace std;


//------------------------------ Complex ------------------------------------
// default constructor:  parameters are real and imaginary parts respectively
Complex::Complex(double re, double im)
{
   this->re = re;
   this->im = im;
}

//(a)------------------------------- add ------------------------------------
// addition of 2 complex number, current object and parameter
Complex Complex::add(const Complex & z)
{
   Complex c;

   c.re = re + z.re;
   c.im = im + z.im;
   return c;
}

//(b)---------------------------- subtract ----------------------------------
// subtraction of 2 complex number, current object and parameter

Complex Complex::subtract(const Complex & z)
{
   Complex c;

   c.re = re - z.re;
   c.im = im - z.im;
   return c;
}


//(c)---------------------------- multiply ----------------------------------
// multiplication of 2 complex number, current object and parameter

Complex Complex::multiply(const Complex & z)
{
   Complex c;

   c.re = re * z.re - im * z.im;
   c.im = re * z.im + im * z.re;
   return c;
}

//(d)------------------------------ divide ----------------------------------
// division of 2 complex number, current object and parameter,
// division by zero crashes
Complex Complex::divide(const Complex & z)
{
   Complex c;

   if (z.re == 0 && z.im == 0)
   {
      cout << "DIVIDE BY ZERO ERROR!!!" << endl;
   }
   c.re = (re * z.re + im * z.im) / (z.re * z.re + z.im * z.im);
   c.im = (im * z.re - re * z.im) / (z.re * z.re + z.im * z.im);
   return c;
}

//(e)------------------------------ equality ---------------------------------
// equality of 2 complex number, current object and parameter
bool Complex::equal(const Complex & z)
{
   return re == z.re && im == z.im;

}

//(f)------------------------------ modulus ---------------------------------
// modulus value of a complex number
double Complex::modulus()
{
   return sqrt(re * re + im * im);
}



//(g)------------------------------ print -----------------------------------
// print the complex number with the format: a + bi (or a - bi)
// enclosed the complex number with parenthesis if is_parenthesis is true
// e.g., is_parenthesis = true: (4 + 2i), (-10 +7i), etc. 
void Complex::print(bool is_parenthesis)
{
   if (is_parenthesis)
      cout << "(";
   cout << re;
   if (im >= 0)
      cout << " + " << im << "i";
   else
      cout << " - " << -im << "i";
   if (is_parenthesis)
      cout << ")";
}








