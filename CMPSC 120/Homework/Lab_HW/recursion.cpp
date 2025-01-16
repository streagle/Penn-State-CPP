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
// Assignment: Lab 13
//
#include <iostream>
#include <iomanip>

using namespace std;
// Methods
int f(int n);

int f(int n)
{
    if (n == 0)
    {
        return 5;
    }
    else
    {
        return 2 * f(n - 1) - 3;
    }
}

int main()
{
    // Variables
    int n = 0;

    // Inputs
    do
    {
        cout << "Enter a number greater than or equal to 0: ";
        cin >> n;
        if (n < 0)
        {
            cout << "Invalid input. Please try again." << endl;
        }
    } while (n < 0);

    // Outputs
    for (int i = 0; i <= n; i++)
    {
        cout << "f(" << i << ") = " << f(i) << endl;
    }

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"recursion"
Enter a number greater than or equal to 0: -1
Invalid input. Please try again.
Enter a number greater than or equal to 0: 7
f(0) = 5
f(1) = 7
f(2) = 11
f(3) = 19
f(4) = 35
f(5) = 67
f(6) = 131
f(7) = 259
ryanreagle@Ryans-MacBook-Pro-2 output %
*/