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
// Assignment: Lab 10
//

#include <iostream>
#include <iomanip>

using namespace std;
// Methods
void getScores(double *scores, int size);
void sortScores(double *scores, int size);
double computeAverage(double *scores, int size);

void getScores(double *scores, int size)
{
    for (int i = 0; i < size; i++)
    { 
        do
        {
            cout << "Enter score " << i + 1 << ": ";
            cin >> scores[i];
            if (scores[i] < 0)
            {
                cout << "Score cannot be negative." << endl;
            }

        } while (scores[i] < 0);
    }
}

void sortScores(double *scores, int size)
{
    double temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (scores[i] > scores[j])
            {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }
}

double computeAverage(double *scores, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += scores[i];
    }
    return sum / size;
}

int main()
{
    // Variables
    int size;
    double *scores;
    double average;

    // Inputs
    do
    {
        cout << "Enter the number of scores: ";
        cin >> size;
        if (size < 2)
        {
            cout << "The number of scores must be greater than 1." << endl;
        }
    } while (size < 2);

    // Processes

    scores = new double[size];
    getScores(scores, size);
    sortScores(scores, size);
    average = computeAverage(scores, size);

    // Outputs
    cout << "The scores in ascending order are: ";
    for (int i = 0; i < size; i++)
    {
        cout << scores[i] << endl;
    }
    cout << endl;
    cout << "The average of the scores is: " << average << endl;

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   output                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"scores"
Enter the number of scores: 1
The number of scores must be greater than 1.
Enter the number of scores: 5
Enter score 1: 85.5
Enter score 2: -20
Score cannot be negative.
Enter score 2: 99
Enter score 3: 53.8
Enter score 4: 78.2
Enter score 5: 89
The scores in ascending order are: 53.8
78.2
85.5
89
99

The average of the scores is: 81.1
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/