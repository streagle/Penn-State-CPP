
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
// Assignment: Homework 4
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
    double total, rate, timesCompounded, interest, principal;

    // Inputs
    cout << "Enter the principal amount: ";
    cin >> principal;
    cout << "Enter the interest rate: ";
    cin >> rate;
    cout << "Enter the number of times compounded: ";
    cin >> timesCompounded;
    cout << endl;

    // Processes

    total = principal * pow((1 + (rate / 100) / timesCompounded), timesCompounded);
    interest = total - principal;

    // Outputs
    cout << "interest rate:    " << setw(19) << rate << "%" << endl;
    cout << "times compounded: " << setw(19) << timesCompounded << endl;

    cout << "principal:" << setw(13) << "$" << fixed << setprecision(2) << setw(14) << principal << endl;
    cout << "interest:" << setw(14) << "$" << fixed << setprecision(2) << setw(14) << interest << endl;
    cout << "Ammount in Savings:" << setw(4) << "$" << fixed << setprecision(2) << setw(14) << total << endl;

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   output                                   */
/* -------------------------------------------------------------------------- */

/*

ryanreagle@Ryans-MacBook-Pro-2 output % ./"savings"
Enter the principal amount: 1000
Enter the interest rate: 4.25
Enter the number of times compounded: 12

interest rate:                   4.25%
times compounded:                  12
principal:            $       1000.00
interest:             $         43.34
Ammount in Savings:   $       1043.34
ryanreagle@Ryans-MacBook-Pro-2 output %

*/