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


class Student {
private:
    string name;
    double gpa;

public:

    string getName() {return name;}
    void setName(string n) {name = n;}
    double getGpa() {return gpa;}
    void setGpa(double g) {gpa = g;}

};

int main() {

Student stu1;
Student stu2;
stu1.setName("Lily");
stu1.setGpa(3.2);
stu2.setName("John");
stu2.setGpa(3.5);
cout << stu1.getName() << endl;
cout << stu1.getGpa() << endl;
cout << stu2.getName() << endl;
cout << stu2.getGpa() << endl;
return 0;
}
