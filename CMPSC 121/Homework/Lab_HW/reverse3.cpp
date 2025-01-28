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
// Assignment: HW 13
//
#include <iostream>
#include <iomanip>


using namespace std;
//Methods

void reverseString(string input, int size);

void reverseString(string input, int size)
{
    if (size == 0)
    {
        return;
    }
    cout << input[size - 1];
    reverseString(input, size - 1);
}



int main(){
//Variables
string user_input = "";
string reversed_string = "";
char choice = ' ';




//Inputs
do{
cout << "Please enter a string: ";
getline(cin, user_input);



//Processes
reverseString(user_input, user_input.size());

cout << endl;
cout << "Would you like to enter another string? (Y/N): ";
cin >> choice;
cin.ignore();
} while (choice == 'Y' || choice == 'y');






//Outputs



return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*

*/