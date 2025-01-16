#include <iostream>

using namespace std;

// Function prototype
void swap(int* a, int* b);

int main() {
    // Array to store three integers
    int arr[3];

    // Input three elements from the user
    cout << "Enter three integers: ";
    for (int i = 0; i < 3; ++i) {
        cin >> arr[i];
    }

    cout << "Original array: " << endl;
    for (int i = 0; i < 3; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sorting in descending order using swap function
    if (arr[0] < arr[1]) swap(&arr[0], &arr[1]);
    if (arr[0] < arr[2]) swap(&arr[0], &arr[2]);
    if (arr[1] < arr[2]) swap(&arr[1], &arr[2]);

    
    // Display the sorted array
    cout << "The output array (from biggest to smallest): " << endl;
    for (int i = 0; i < 3; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Function definition
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
