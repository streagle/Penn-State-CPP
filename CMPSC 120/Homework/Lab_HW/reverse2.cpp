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
// Assignment: Lab 11
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;
// Methods

bool is_palindrome(string str);
string reverse(string aSentence);

bool is_palindrome(string str)
{
    int i = 0;
    int j = str.length() - 1;
    while (i < j)
    {
        if (tolower(str[i]) != tolower(str[j]))
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

string reverse(string aSentence)
{
    string reversed = "";
    bool firstWord = true;
    for (int i = 0; i < aSentence.length(); i++)
    {
        if (firstWord)
        {
            if (isupper(aSentence[i]))
            {
                reversed += tolower(aSentence[i]);
            }
            else if (islower(aSentence[i]))
            {
                reversed += toupper(aSentence[i]);
            }
            else
            {
                reversed += aSentence[i];
            }
            if (aSentence[i] == ' ')
            {
                firstWord = false;
            }
        }
        else
        {
            reversed += aSentence[i];
        }
    }
    return reversed;
}

int main()
{
    // Variables
    string word;

    cout << "Enter a word: ";
    getline(cin, word);

    if (is_palindrome(word))
    {
        cout << word << " is a palindrome." << endl;
    }
    else
    {
        cout << word << " is not a palindrome." << endl;
    }

    cout << endl;

    cout << "Please enter a string below:" << endl;
    getline(cin, word);

    cout << "The modified string is: " << endl << reverse(word) << endl;

    // Inputs

    // Processes

    // Outputs

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   OUTPUT                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"reverse2"
Enter a word: Racecar
Racecar is a palindrome.

Please enter a string below:
cGyver premiered in 1985.
The modified string is: 
CgYVER premiered in 1985.
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/

/* -------------------------------------------------------------------------- */
/*                                  OUTPUT 2                                  */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"reverse2"
Enter a word: reverse
reverse is not a palindrome.

Please enter a string below:
Bedford–Stuyvesant, Brooklyn is called Bed-Stuy.
The modified string is: 
bEDFORD–sTUYVESANT, Brooklyn is called Bed-Stuy.
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/