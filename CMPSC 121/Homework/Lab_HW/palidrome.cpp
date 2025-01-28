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
#include <cctype>
#include <string>


using namespace std;
//Methods
bool isPalindrome(const string &input, int first=0, int last=0);

bool isPalindrome(const string &input, int first, int last)
{

    last = input.size() - 1;
    while (first < last) {
        // Skip non-alphabetic characters
        while (first < last && !isalpha(input[first])) {
            cout << "Skipping: '" << input[first] << "'" << endl;
            first++;
        }

        //Skip non-alphabetic characters
        while (first < last && !isalpha(input[last])) {
            cout << "Skipping: '" << input[last] << "'" << endl;
            last--;
        }

        //Check if the first and last characters are the same
        if (first >= last) {
            cout << "Checking: " << input << endl;
            return true;
        }
        //Outputs the remaining string
        cout << "Checking: " << input.substr(first, last - first + 1) << endl;

        //Outputs if the characters do not match
        if (tolower(input[first]) != tolower(input[last])) {
            cout << "Characters " << input[first] << " and " << input[last] << " do not match." << endl;
            return false;
        }

        first++;
        last--;
    }
    return true;
}


int main(){
//Variables

char repeat = 'n';
//Inputs
do{
string userInput = "";

cout << "Please enter a string: ";
getline(cin, userInput);

//Processes

bool result = isPalindrome(userInput);

//Outputs
if (result == true)
{
    cout << "The string is a palindrome." << endl;
}
else
{
    cout << "The string is not a palindrome." << endl;
}
cout << "Would you like to enter another string? (y/n): ";
cin >> repeat;
cin.ignore();
} while (repeat == 'y' || repeat == 'Y');

return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
    ryanreagle@Ryans-MacBook-Pro-2 output % ./"palidrome"
Please enter a string: racecar
Checking: racecar
Checking: aceca
Checking: cec
The string is a palindrome.
Would you like to enter another string? (y/n): y
Please enter a string: racebar
Checking: racebar
Checking: aceba
Checking: ceb
Characters c and b do not match.
The string is not a palindrome.
Would you like to enter another string? (y/n): n
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/