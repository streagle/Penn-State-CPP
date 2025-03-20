#include <iostream>

using namespace std;

int main() {
    // Variables
    int numbers[5] = {1, 5, 3, 8, 5};
    int position;

    // Inputs
    cout << "Enter the position of the number you want to see: ";
    cin >> position;
    position = position - 1;

    cout << "The number at position " << position + 1 << " is: " << numbers[position] << endl;

    return 0;
}
