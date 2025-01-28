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
// Assignment: HW 09
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
// Methods

// allow the user to vote for a candidate by typing their name untill the user enters quit
void vote(string candidates[], int votes[], int size)
{
    string userVote;
    // Ignore any newline leftover in the input buffer

    cout << "Who do you want to vote for (";
    for (int i = 0; i < size; i++)
    {
        cout << candidates[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << " or quit to quit)? ";
    getline(cin, userVote);

    while (userVote != "quit")
    {
        bool validVote = false;

        for (int i = 0; i < size; i++)
        {
            if (userVote == candidates[i])
            {
                votes[i]++;
                validVote = true;
                break;
            }
        }

        if (!validVote)
        {
            cout << "Invalid candidate." << endl;
        }

        cout << "Who do you want to vote for (";
        for (int i = 0; i < size; i++)
        {
            cout << candidates[i];
            if (i < size - 1)
            {
                cout << ", ";
            }
        }
        cout << " or quit to quit)? ";
        getline(cin, userVote);
    }
}

// display the results of the election
void displayResults(string candidates[], int votes[], int size) {
    int maxVotes = votes[0];
    int winnerIndex = 0;

    // Find the index of the candidate with the highest votes
    for (int i = 1; i < size; i++) {
        if (votes[i] > maxVotes) {
            maxVotes = votes[i];
            winnerIndex = i;
        }
    }

    cout << "Election Results" << endl;
    cout << "-----------------------------" << endl;
    cout << left << setw(15) << "Candidate" << setw(10) << "Votes" << "Status" << endl;
    cout << "-----------------------------" << endl;

    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << candidates[i]
             << setw(10) << votes[i];
        
        // Add "Winner" if this candidate is the winner
        if (i == winnerIndex) {
            cout << "**Winner**";
        }
        cout << endl;
    }
}



int main()
{
    // Variables
    const int size = 4;
    string candidates[size] = {"Tim", "Satya", "Sunder", "Elon"};
    int *votes;


    // Processes
    votes = new int[size];

    

    for (int i = 0; i < size; i++)
    {
        votes[i] = 0;
    }

    vote(candidates, votes, size);

    displayResults(candidates, votes, size);

    // Outputs

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                 test case                                  */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"ballotBox"
Who do you want to vote for (Tim, Satya, Sunder, Elon or quit to quit)? Bill
Invalid candidate.
Who do you want to vote for (Tim, Satya, Sunder, Elon or quit to quit)? Tim
Who do you want to vote for (Tim, Satya, Sunder, Elon or quit to quit)? Satya
Who do you want to vote for (Tim, Satya, Sunder, Elon or quit to quit)? Sunder
Who do you want to vote for (Tim, Satya, Sunder, Elon or quit to quit)? Bill
Invalid candidate.
Who do you want to vote for (Tim, Satya, Sunder, Elon or quit to quit)? Elon
Who do you want to vote for (Tim, Satya, Sunder, Elon or quit to quit)? Elon
Who do you want to vote for (Tim, Satya, Sunder, Elon or quit to quit)? quit
Election Results
-----------------------------
Candidate      Votes     Status
-----------------------------
Tim            1         
Satya          1         
Sunder         1         
Elon           2         **Winner**
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/