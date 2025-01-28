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
/*
Insertion Sort is a sorting algorithm that builds the final sorted array (or list) one item at a time.
 It is much less efficient on large lists than more advanced algorithms 
 such as quicksort, heapsort, or merge sort.

The typical complexity of insertion sort is O(n^2) where n is the number of items.

An example of insertion sort is the way cards are sorted in a player's hand in a card game.
*/


// Function to perform insertion sort on an array
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Current element to be inserted
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Insert the key at the correct position

        // Output the array after each insertion
        cout << "Step " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Initialize array with unsorted elements
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Perform insertion sort on the array
    insertion_sort(arr, 7);

    // Output the sorted array
    cout << "Sorted array: \n";
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
