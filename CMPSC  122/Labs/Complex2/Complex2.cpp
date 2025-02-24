//
// Name: skeleton template for overloading operators
//
// One Complex object holds one Complex number

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
// Assignment: Lab 05
//

#include "Complex2.h"

//------------------------------ Complex ------------------------------------
// default constructor:  parameters are real and imaginary parts respectively
Complex::Complex(double re, double im)
{
   this->re = re;
   this->im = im;
}

//(a)------------------------------- add -------------------------------------
// overloaded +: addition of 2 complex numbers, current object and parameter

Complex Complex::operator+(Complex &z)
{
   Complex sum;
   sum.re = re + z.re;
   sum.im = im + z.im;
   return sum;
}

//(b)------------------------------ subtract ---------------------------------
// overloaded -: subtract 2 complex numbers, current object and parameter

Complex Complex::operator-(Complex &z)
{
   Complex diff;
   diff.re = re - z.re;
   diff.im = im - z.im;
   return diff;
}

//(c)------------------------------ multiply ---------------------------------
// overloaded *: multiply 2 complex numbers, current object and parameter

Complex Complex::operator*(Complex &z)
{
   Complex product;
   product.re = re * z.re - im * z.im;
   product.im = re * z.im + im * z.re;
   return product;
}

//(d)-------------------------------- divide ---------------------------------
// overloaded /: divide 2 complex numbers, current object and parameter
// check division by zero condition

Complex Complex::operator/(Complex &z)
{
   Complex quotient;
   double denom = z.re * z.re + z.im * z.im;
   if (denom == 0)
   {
      cout << "Division by zero is not allowed." << endl;
      return Complex();
   }
   quotient.re = (re * z.re + im * z.im) / denom;
   quotient.im = (im * z.re - re * z.im) / denom;
   return quotient;
}

//(e)-------------------------------- equal ----------------------------------
// overloaded ==: equal comparison of current Complex object and parameter

bool Complex::operator==(Complex &z)
{
   return re == z.re && im == z.im;
}

//(f)------------------------------- not equal -------------------------------
// overloaded !=: not equal comparison of current Complex object and parameter

bool Complex::operator!=(Complex &z)
{
   return re != z.re || im != z.im;
}

//(g)-------------------------------- print-----------------------------------
// overloaded print()

void Complex::print(ostream &os)
{
   os << re << " + " << im << "i";
}

//(h)--------------------------------- << -------------------------------------
// overloaded << (output operator)
ostream &operator<<(ostream &os, Complex &z)
{
   z.print(os);
   return os;
}
