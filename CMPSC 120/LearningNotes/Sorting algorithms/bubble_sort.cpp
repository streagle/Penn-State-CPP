#include <iostream>
#include <iomanip>

using namespace std;

/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements 
if they are in wrong order. It is not suitable for large datasets as its average 
and worst case complexity are of Ο(n^2) where n is the number of items.
*/

// Function to perform bubble sort on an array
//n should be the size of the array
void bubble_sort(int arr[], int n)
{
    // Loop through each element in the array
    for (int i = 0; i < n - 1; i++)
    {
        // Loop through the array from the beginning to the last unsorted element
        for (int j = 0; j < n - i - 1; j++)
        {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                // Output the array after each swap
                for (int k = 0; k < n; k++)
                {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }
    }
}

int main()
{
    // Initialize an array with unsorted elements
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Call bubble_sort function to sort the array
    bubble_sort(arr, 7);

    // Output the sorted array
    cout << "Sorted array: \n";
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}