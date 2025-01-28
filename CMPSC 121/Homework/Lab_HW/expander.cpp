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
// Assignment: Homework 10
//
#include <iostream>
#include <iomanip>


using namespace std;
// Methods
int *expandArray(int *org_array, int array_size);

int *expandArray(int *org_array, int array_size)
{
    int *expanded_array = new int[array_size * 2];
    for (int i = 0; i < array_size; i++)
    {
        expanded_array[i] = org_array[i];
    }
    for (int i = array_size; i < array_size * 2; i++)
    {
        expanded_array[i] = 0;
    }
    return expanded_array;
}

int main()
{
    // Variables

    int array_size;
    int *org_array;
    int *expanded_array;

    // Inputs
    do
    {
        cout << "Enter the size of the array: ";
        cin >> array_size;
        if (array_size <= 1)
        {
            cout << "Array size must be greater than 1." << endl;
        }
    } while (array_size <= 0);

    // Processes

    org_array = new int[array_size];

    for (int i = 0; i < array_size; i++)
    {
        cout << "Please enter number " << i + 1 << ": ";
        cin >> org_array[i];
    }

    cout << "The original array is: ";

    for (int i = 0; i < array_size; i++)
    {
        cout << org_array[i] << " ";
    }

    cout << endl;

    expanded_array = expandArray(org_array, array_size);

    cout << "The expanded array is: ";

    for (int i = 0; i < array_size * 2; i++)
    {
        cout << expanded_array[i] << " ";
    }

    cout << endl;

    // Deallocate memory

    delete[] org_array;

    delete[] expanded_array;

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   output                                   */
/* -------------------------------------------------------------------------- */

/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"expander"
Enter the size of the array: 0
Array size must be greater than 1.
Enter the size of the array: 5
Please enter number 1: 10
Please enter number 2: 20
Please enter number 3: 30
Please enter number 4: 40
Please enter number 5: 50
The original array is: 10 20 30 40 50 
The expanded array is: 10 20 30 40 50 0 0 0 0 0 
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/