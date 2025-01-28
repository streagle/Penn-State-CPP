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
// Assignment: Homework 01(Simple Output)
//

#include <iostream>
using namespace std;
int main()
{
string first_name;
cout << "Please enter your first name: ";
cin >> first_name;
cout << "Hello there, " << first_name << "!" << endl;
cout << "Different ways of outputs:" << endl << endl;
cout << first_name << first_name << first_name << endl;
cout << first_name << "  " << first_name << "  " << first_name;
cout << endl << endl;
cout << first_name << "\n";
cout << first_name << "\n";
cout << first_name << "\n";
}
//Answer 1:The cin << First Name allows the user to input thir first name

//Answer 2:The line "cout << endl << endl;" produces a new line at the end of the line 
//with "cout << first_name << "  " << first_name << "  " << first_name;" along with a blank line below it.

// Final Output (For Grading)
/*
Please enter your first name: Ryan
Hello there, Ryan!
Different ways of outputs:

RyanRyanRyan
Ryan  Ryan  Ryan

Ryan
Ryan
Ryan
*/