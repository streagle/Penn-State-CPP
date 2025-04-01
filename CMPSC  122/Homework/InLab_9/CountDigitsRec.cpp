// driver for project 5
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
// Assignment: InLab 09
//
#include <iostream>
using namespace std;

int CountDigits(int n){
    if (n == 0) {
        return 0;
    }
    return 1 + CountDigits(n / 10);
}

void TestCountDigits(int n) {
    cout << "The number " << n << " has " << CountDigits(n) << " digit(s)" << endl;
}

int main()
{
    TestCountDigits(12345);
    TestCountDigits(3);
    TestCountDigits(857);
    TestCountDigits(1985);

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"CountDigitsRec"
The number 12345 has 5 digit(s)
The number 3 has 1 digit(s)
The number 857 has 3 digit(s)
The number 1985 has 4 digit(s)
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/


