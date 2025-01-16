#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

int main() {
    vector<int> grades;
    int numCourses, grade, total = 0;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter grade for course " << i + 1 << ": ";
        cin >> grade;
        grades.push_back(grade);
        total += grade;
    }

    cout << "\nCourse Grades:\n";
    for (int i = 0; i < numCourses; ++i) {
        cout << "Course " << i + 1 << ": " << grades[i] << endl;
    }

    double average = static_cast<double>(total) / numCourses;
    cout << "\nAverage Grade: " << fixed << setprecision(2) << average << endl;

    return 0;
}
