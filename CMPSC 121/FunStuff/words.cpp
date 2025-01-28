#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string word, pronunciation;
    ofstream outFile("words.txt", ios::app); // Open file in append mode

    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    char choice;
    do {
        cout << "Enter a word: ";
        getline(cin, word);

        cout << "Enter its pronunciation: ";
        getline(cin, pronunciation);

        outFile << word << " = " << pronunciation << endl;

        cout << "Do you want to enter another word? (y/n): ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the buffer

    } while (choice == 'y' || choice == 'Y');

    outFile.close();
    cout << "Words and pronunciations saved to words.txt" << endl;

    return 0;
}