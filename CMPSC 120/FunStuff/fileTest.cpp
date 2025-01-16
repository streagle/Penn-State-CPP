#include <iostream>
#include <fstream>
#include <string>

//!!need to use ../ before file name for relative path due to using a Mac but must remove it before submitting it.
using namespace std;
int main() {
    ifstream inputFile("../test.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cout << "Failed to open the file." << endl;
    }
    return 0;
}