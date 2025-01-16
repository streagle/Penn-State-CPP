
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

    string item1, item2, item3, item4;
    double price1, price2, price3, price4, total;

    // Inputs
    cout << "Enter 4 one-word (maximum 10 letters) items to purchase: " << endl;
    cin >> item1 >> item2 >> item3 >> item4;
    cout << "Enter their prices in US Dollars (<= $1,000): " << endl;
    cin >> price1 >> price2 >> price3 >> price4;

    // Processes
    total = price1 + price2 + price3 + price4;

    // output the prices with 2 decimal points

    // Outputs

    cout << "+-----------------+-----------+" << endl;
    cout << "|";
    cout << setw(20) << "Receipt";
    cout << setw(10) << "|" << endl;
    cout << "+-----------------+-----------+" << endl;

    cout << "|";
    cout << setw(1) << item1;
    cout << setw(19 - item1.length()) << "|$";
    cout << setw(10) << fixed << setprecision(2) << price1;
    cout << setw(1) << "|" << endl;

    cout << "|";
    cout << setw(1) << item2;
    cout << setw(19 - item2.length()) << "|$";
    cout << setw(10) << fixed << setprecision(2) << price2;
    cout << setw(1) << "|" << endl;

    cout << "|";
    cout << setw(1) << item3;
    cout << setw(19 - item3.length()) << "|$";
    cout << setw(10) << fixed << setprecision(2) << price3;
    cout << setw(1) << "|" << endl;

    cout << "|";
    cout << setw(1) << item4;
    cout << setw(19 - item4.length()) << "|$";
    cout << setw(10) << fixed << setprecision(2) << price4;
    cout << setw(1) << "|" << endl;

    cout << "+-----------------+-----------+" << endl;
    cout << "|";
    cout << setw(1) << "Total: $";
    cout << setw(21) << fixed << setprecision(2) << total;
    cout << setw(1) << "|" << endl;
    cout << "+-----------------+-----------+" << endl;

    
    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"reciept"
Enter 4 one-word (maximum 10 letters) items to purchase: 
Yogurt
Apple
Butter
Bread
Enter their prices in US Dollars (<= $1,000): 
0.75
8.00
12.99
2.85
+-----------------+-----------+
|             Receipt         |
+-----------------+-----------+
|Yogurt           |$      0.75|
|Apple            |$      8.00|
|Butter           |$     12.99|
|Bread            |$      2.85|
+-----------------+-----------+
|Total: $                24.59|
+-----------------+-----------+
ryanreagle@Ryans-MacBook-Pro-2 output % 

*/