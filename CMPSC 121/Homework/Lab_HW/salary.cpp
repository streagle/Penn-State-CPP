
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
// Assignment: Lab 4
//


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>

using namespace std;
// Methods

int main()
{
    // Variables

    double salary, tenure, years;
    string name;

    // Inputs
    cout << "Enter the persons name: ";
    getline(cin, name);
    cout << "How many years of experience does the person have? ";
    cin >> years;
    cout << "How long (in years) is their tenure? ";
    cin >> tenure;
    cout << endl;

    // Processes

    salary = (2000 * years) + (1000 * tenure) + 50000;

    // Outputs

    cout << "The salary for " << name << " is $" << salary << endl;

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"salary"
Enter the persons name: Ryan Reagle
How many years of experience does the person have? 10
How long (in years) is their tenure? 6

The salary for Ryan Reagle is $76000
ryanreagle@Ryans-MacBook-Pro-2 output % 

*/