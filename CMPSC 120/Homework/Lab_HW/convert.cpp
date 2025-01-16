
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
// Assignment: Homework 3
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
//Methods



int main(){
//Variables

int cents,dollars,quarters, dimes, nickels, pennies;




//Inputs
cout << "enter the number of cents to convert:";
cin >> cents;

//Logic
dollars = cents / 100;
cents = cents % 100;
quarters = cents / 25;
cents = cents % 25;
dimes = cents / 10;
cents = cents % 10;
nickels = cents / 5;
cents = cents % 5;
pennies = cents;

//Outputs
cout << "Dollars: " << dollars << endl;
cout << "Quarters: " << quarters << endl;
cout << "Dimes: " << dimes << endl;
cout << "Nickels: " << nickels << endl;
cout << "Pennies: " << pennies << endl;


return 0;
}

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"convert"
enter the number of cents to convert:1292
Dollars: 12
Quarters: 3
Dimes: 1
Nickels: 1
Pennies: 2
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/
