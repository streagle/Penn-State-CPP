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
// Assignment: Homework 08
//
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
// Prototypes
int getUserSelection();
void determineWinner(int uChoice, int cChoice, int &uScore, int &cScore);

// Methods

void determineWinner(int uChoice, int cChoice, int &uScore, int &cScore)
{
    if (uChoice == -1)
    {
        return;
    }
    string choices[3] = {"rock", "paper", "scissors"};
    if (uChoice == 1 && cChoice == 3)
    {
        cout << "User: " << choices[uChoice - 1] << ", Computer: " << choices[cChoice - 1] << endl;
        cout << "User wins!" << endl;
        uScore++;
    }
    else if (uChoice == 2 && cChoice == 1)
    {
        cout << "User: " << choices[uChoice - 1] << ", Computer: " << choices[cChoice - 1] << endl;
        cout << "You win!" << endl;
        uScore++;
    }
    else if (uChoice == 3 && cChoice == 2)
    {
        cout << "User: " << choices[uChoice - 1] << ", Computer: " << choices[cChoice - 1] << endl;
        cout << "You win!" << endl;
        uScore++;
    }
    else if (uChoice == cChoice)
    {
        cout << "User: " << choices[uChoice - 1] << ", Computer: " << choices[cChoice - 1] << endl;
        cout << "It's a tie!" << endl;
    }
    else
    {
        cout << "User: " << choices[uChoice - 1] << ", Computer: " << choices[cChoice - 1] << endl;
        cout << "You lose!" << endl;
        cScore++;
    }
}


int getUserSelection()
{
    int choice;
    do
    {
        cout << "Make your choice (1: rock, 2: paper, 3: scissors, -1: quit): ";
        cin >> choice;
        
        if (choice != 1 && choice != 2 && choice != 3 && choice != -1)
        {
            cout << "Invalid choice, try again!" << endl;
        }
    } while (choice != 1 && choice != 2 && choice != 3 && choice != -1);
    return choice;
}


int main()
{
    // Variables

    int uChoice, cChoice, uScore = 0, cScore = 0;

    do
    {
        uChoice = getUserSelection();
        cChoice = rand() % 3 + 1;

        determineWinner(uChoice, cChoice, uScore, cScore);
        cout << "User: " << uScore << ", Computer: " << cScore << endl;
    } while (uChoice != -1);

    if (uScore > cScore)
    {
        cout << "User wins with a score of " << uScore << " to " << cScore << "!" << endl;
    }
    else if (uScore < cScore)
    {
        cout << "Computer wins with a score of " << cScore << " to " << uScore << "!" << endl;
    }
    else
    {
        cout << "It's a tie with a score of " << uScore << " to " << cScore << "!" << endl;
    }


    return 0;
}