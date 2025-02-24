//
// Name: key solution header for complex number
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
#ifndef COMPLEX2_H
#define COMPLEX2_H
#include <iostream>
using namespace std;

class Complex {     // complex number class
    public:
        Complex(double re = 0.0, double im = 0.0);   // default constructor
        Complex operator+(Complex & z);
        // add the prototypes of required methods here.
        Complex operator-(Complex & z);
        Complex operator*(Complex & z);
        Complex operator/(Complex & z);
        bool operator==(Complex & z);
        bool operator!=(Complex & z);
        void print(ostream& os);

    private:
        double re;
        double im;

        // add the private prototypes methods here from
        // previous LabProj4 and add those functions source
        // in this project 
        Complex add(const Complex & z);
        Complex subtract(const Complex & z);
        Complex multiply(const Complex & z);
        Complex divide(const Complex & z);
        bool equals(const Complex & z);
        bool notEquals(const Complex & z);
        /*
        ...
        
        */
        // Or you can implement the overloaded operators 
        // by adding the LabProj 4 source code into the them
};

ostream & operator<<(ostream & os, Complex & z);
// May generate linker issue if the code is implemented here.
// The code should be implemented in .cpp source file

#endif

