#include <iostream>
using namespace std;

int main() {
    int size;
    do {
        cout << "Enter the size of the matrix: ";
        cin >> size;
    } while (size <= 0);

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            cout << (row == col ? "1 " : "0 ");
        }
        cout << endl;
    }
    return 0;
}
