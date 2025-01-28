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
// Assignment: Homework 02
//

#include <iostream>

using namespace std;

int main(){
//Variables
double number, total = 0;

//Inputs
for (int i = 0; i < 5; i++)
{
    cout << "Enter number " << i + 1 << ": ";
    cin >> number;
    total += number;
}

//Processes

//Outputs
cout << "The total of the numbers is: " << total << endl;
cout << "The average of the numbers is: " << total/5 << endl;

return 0;
}


/* -------------------------------------------------------------------------- */
/*                                 CODE OUTPUT                                */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"average"
Enter number 1: 10
Enter number 2: 5
Enter number 3: 2.5
Enter number 4: 8
Enter number 5: 20
The total of the numbers is: 45.5
The average of the numbers is: 9.1
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/