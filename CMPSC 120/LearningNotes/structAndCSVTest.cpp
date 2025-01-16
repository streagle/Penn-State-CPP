#include <iostream>
#include <string>
#include <fstream>

// This program will use Structs to read the name and grades from a CSV file called reportCard.csv
using namespace std;

// Struct
struct student {
    string name;
    int grades[3];
};

int main() {
    // Variables
    string line;
    ifstream file;
    int i = 0;
    int j = 0;
    int lineCount = 0;

    // Inputs
    file.open("../reportCard.csv");

    // Count the number of lines in the file
    while (getline(file, line)) {
        lineCount++;
    }

    // Reset the file stream to the beginning of the file
    file.clear();
    file.seekg(0, ios::beg);
    //Format: file.seekg(offset(0 for no offset), direction(begin(beg), current(cur), end))

    student* students = new student[lineCount];

    // Processes
    if (file.is_open()) {
        while (getline(file, line)) {
            students[i].name = line.substr(0, line.find(","));
            line = line.substr(line.find(",") + 1);
            for (j = 0; j < 3; j++) {
                students[i].grades[j] = stoi(line.substr(0, line.find(",")));
                line = line.substr(line.find(",") + 1);
            }
            i++;
        }
        file.close();
    } else {
        cout << "Error opening file." << endl;
    }

    // Outputs
    for (i = 0; i < lineCount; i++) {
        cout << "Name: " << students[i].name << endl;
        cout << "Grades: ";
        for (j = 0; j < 3; j++) {
            cout << students[i].grades[j] << " ";
        }
        cout << endl;
    }

    delete[] students;
    return 0;
}
