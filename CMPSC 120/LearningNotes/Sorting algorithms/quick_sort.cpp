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

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Quick sort function
void quick_sort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    // Choose the pivot element, here we are choosing the middle element
    int pivot = arr[(left + right) / 2];

    cout << "Pivot: " << pivot << " (from index " << (left + right) / 2 << ")" << endl;

    // Partition the array into two halves
    while (i <= j) {
        // Find an element on the left that should be on the right
        while (arr[i] < pivot) {
            cout << "arr[" << i << "] = " << arr[i] << " is less than pivot " << pivot << endl;
            i++;
        }
        // Find an element on the right that should be on the left
        while (arr[j] > pivot) {
            cout << "arr[" << j << "] = " << arr[j] << " is greater than pivot " << pivot << endl;
            j--;
        }
        // Swap elements and move the indices towards the center
        if (i <= j) {
            cout << "Swapping arr[" << i << "] = " << arr[i] << " and arr[" << j << "] = " << arr[j] << endl;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    // Print the array after partitioning
    cout << "Array after partitioning: ";
    printArray(arr, 7);

    // Recursively apply the same logic to the left and right subarrays
    if (left < j) {
        cout << "Recursively sorting left part: " << left << " to " << j << endl;
        quick_sort(arr, left, j);
    }
    if (i < right) {
        cout << "Recursively sorting right part: " << i << " to " << right << endl;
        quick_sort(arr, i, right);
    }
}

int main() {
    // Variables
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    cout << "Original array: ";
    printArray(arr, size);

    // Processes
    quick_sort(arr, 0, size - 1);

    // Outputs
    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}