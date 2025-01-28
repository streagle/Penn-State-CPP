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
int *reverseArray(int *num_array, int array_size);

int *reverseArray(int *num_array, int array_size)
{
    int *reversed_array = new int[array_size];
    for (int i = 0; i < array_size; i++)
    {
        reversed_array[i] = num_array[array_size - i - 1];
    }
    return reversed_array;
}

int main()
{
    // Variables
    int array_size;
    int *num_array;
    int *reversed_array;

    // Inputs
    do {
        cout << "Enter the size of the array: ";
        cin >> array_size;
        if (array_size < 1)
        {
            cout << "The array size must be greater than 0, try again." << endl;
        }
    } while (array_size < 1);

    num_array = new int[array_size];

    for (int i = 0; i < array_size; i++)
    {
        cout << "Please enter number " << i + 1 << ": ";
        cin >> num_array[i];
    }

    cout << "The original array is: ";
    for (int i = 0; i < array_size; i++)
    {
        cout << num_array[i] << " ";
    }
    cout << endl;

    reversed_array = reverseArray(num_array, array_size);

    cout << "The reversed array is: ";
    for (int i = 0; i < array_size; i++)
    {
        cout << reversed_array[i] << " ";
    }
    cout << endl;

    // Deallocate memory

    delete[] num_array;
    delete[] reversed_array;

    return 0;
}

/* -------------------------------------------------------------------------- */
/*                                   Output                                   */
/* -------------------------------------------------------------------------- */
/*
ryanreagle@Ryans-MacBook-Pro-2 output % ./"reverse"
Enter the size of the array: -2
The array size must be greater than 0, try again.
Enter the size of the array: 5
Please enter number 1: 15
Please enter number 2: 36
Please enter number 3: 9
Please enter number 4: 90
Please enter number 5: 21
The original array is: 15 36 9 90 21 
The reversed array is: 21 90 9 36 15 
ryanreagle@Ryans-MacBook-Pro-2 output % 
*/